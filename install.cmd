/* Install WCKEY.DLL entry into USER INI file */

call RxFuncAdd 'SysLoadFuncs', 'RexxUtil', 'SysLoadFuncs'
call SysLoadFuncs

string = SysIni("USER","SYS_DLLS","LoadOneTime")
flag = 0
do wrd = 1 to WORDS(string)
  if left(word(string,wrd),5) = 'WCKEY' then
     flag = 1
end
if flag = 0 then
do
   string = left(string,length(string)-1) 'WCKEY'||d2c(0)
   if SysIni("USER","SYS_DLLS","LoadOneTime",string) = '' then
   do
      say 'WCKEY.DLL successfully installed.'
      say 'Make sure you have copied WCKEY.DLL in \OS2\DLL.'
   end
   else
      say 'An error occured while installing WCKEY.DLL in OS2.INI.'
end
else
   say "WCKEY.DLL already installed."
