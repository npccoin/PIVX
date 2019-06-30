
Debian
====================
This directory contains files used to package npccoind/npccoin-qt
for Debian-based Linux systems. If you compile npccoind/npccoin-qt yourself, there are some useful files here.

## npccoin: URI support ##


npccoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install npccoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your npccoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/npccoin128.png` to `/usr/share/pixmaps`

npccoin-qt.protocol (KDE)

