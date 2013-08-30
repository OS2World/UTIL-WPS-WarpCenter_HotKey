WarpCenter HotKey             (C) 1997 Samuel Audet <guardia@cam.org>

THIS IS A FREEWARE UTILITY!!  Please send an e-mail if are using this
program, thank you!

Installation
------------

Copy WCKEY.DLL in \OS2\DLL, then run install.cmd and reboot your machine.
You will be then able to open WarpCenter's OS/2 Warp button using alt-"key
beside one" which will simulate a mouse click on it.

You can then navigate with the arrows, esc, enter and ctrl-enter (to open
object propreties).  There does not seem to be any key equivalent to "mouse
button 2" to open a folder.


Notes
-----

I always wondered why WarpCenter never had any keyboard navigation feature
at all.  Anyways, frankly this was very simple to do.  Alt-"key beside one"
is a very _rare_ hotkey used, and a very natural one too, so I though I
might as well use it for something.  Note that if you press anything else
with alt-"key beside one", it will not work (ie.: shift-alt-"key beside one").

At the moment, it loads as a system DLL.  It saves memory, but it only
loads once and does not unload.  I would like to make it a dummy subclass
of WarpCenter to be able to add a page to its settings notebook, and maybe
even allow the choice of the hotkey.  It would also load each time the
WarpCenter does, allowing more connivance between them.  However, I will
have to learn WPS programming first.

Also, I do not know how to program "Win95 keys", and since I do not have a
"Win95 keyboard", I will not be able to implent support for these.


Legal stuff
-----------

This freeware product is used at your own risk, although it is highly
improbable it can cause any damage.

If you plan on using the source codes or copying me, please give me the
credits, thanks.

Source code is included, and done with VisualAge C++ 3.0.


Contacting the author
---------------------

Samuel Audet

E-mail:    guardia@cam.org
Homepage:  http://www.cam.org/~guardia
Snail Mail:

   377, rue D'Argenteuil
   Laval, Quebec
   H7N 1P7   CANADA
