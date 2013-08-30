#define INCL_WIN
#define INCL_DOSMODULEMGR
#define INCL_DOSPROCESS

#include <os2.h>
#include <malloc.h>
#include <string.h>

BOOL EXPENTRY WinHookProc(HAB hab,PQMSG pqmsg,USHORT usRemove );
void findwc(void);
BOOL EXPENTRY HookInit(void);

int _CRT_init(void);
void _CRT_term(void);

HWND wchwnd = 0;
HSWITCH hswitch = 0;

HAB mainhab;

BOOL EXPENTRY WinHookProc(HAB hab,PQMSG pqmsg,USHORT usRemove )
{
   if ((pqmsg->msg == WM_CHAR) &&                  /* character message */
      !(SHORT1FROMMP(pqmsg->mp1) & KC_CTRL) &&     /* CTRL not active */
      !(SHORT1FROMMP(pqmsg->mp1) & KC_SHIFT) &&    /* SHIFT not active */
       (SHORT1FROMMP(pqmsg->mp1) & KC_ALT) &&      /* ALT active */
      !(SHORT1FROMMP(pqmsg->mp1) & KC_KEYUP) &&    /* key down */
       (SHORT1FROMMP(pqmsg->mp1) & KC_SCANCODE) && /* valid scan code */
       (CHAR4FROMMP(pqmsg->mp1) == 41))            /* 'the key beside 1' */
   {
      /* if we don't know where the warpcenter is, find it */
      if (wchwnd == 0)
         findwc();

      /* switch to warpcenter and simulate a mouse click */
      if (wchwnd != 0)
      {
         WinSwitchToProgram(hswitch);
         WinPostMsg(wchwnd, WM_BUTTON1DOWN, MPFROM2SHORT(1,1), MPFROMLONG(0));
         WinPostMsg(wchwnd, WM_BUTTON1UP, MPFROM2SHORT(1,1), MPFROMLONG(0));
      }
   }
   return(FALSE);
}

/* find warpcenter window handle */
void findwc()
{
   int i,count,buffersize;
   PSWBLOCK pswblock;

   count = WinQuerySwitchList(mainhab,NULL,0);
   buffersize = count * sizeof(SWENTRY) + sizeof(ULONG);
   pswblock = (PSWBLOCK) _alloca(buffersize);
   count = WinQuerySwitchList(mainhab,pswblock,buffersize);
   if (pswblock != NULL)
      for (i = 0 ; i < count ; i++)
         if (!strcmp(pswblock->aswentry[i].swctl.szSwtitle, "WarpCenter"))
         {
            wchwnd = pswblock->aswentry[i].swctl.hwnd;
            hswitch = pswblock->aswentry[i].hswitch;
            break;
         }
   return;
}

BOOL EXPENTRY HookInit()
{
   HMODULE hmDll;

   /* find desktop anchor */
   mainhab = WinQueryAnchorBlock(HWND_DESKTOP);

   /* setting hook */
   if(DosQueryModuleHandle("wckey", &hmDll))
      return FALSE;
   WinSetHook(mainhab, NULLHANDLE, HK_INPUT, (PFN)WinHookProc, hmDll);

   return(TRUE);
}

BOOL EXPENTRY _DLL_InitTerm(ULONG hmDll, ULONG flag)
{
   if (!flag)
      if (_CRT_init() == -1)
         return(FALSE);
   else
   {
      /* if terminating, release hook */
      WinReleaseHook(mainhab, NULLHANDLE, HK_INPUT, (PFN)WinHookProc, hmDll);
      _CRT_term();
   }
   return(TRUE);
}

