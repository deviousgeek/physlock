Physlock extended to support displaying /etc/issue
==================================================

Basically, the same as Physlock except it reads and shows the contents of
whatever is in `/etc/issue`. Cool for awesome ANSI art lock screens!

A sample has been provided of Ryu from https://git.io/ryucolor, but
adjusted to fit 1080p screens better!

Additionally we are able to replace escape sequences, similarly to those
support by `agetty(8)`, with:

| Escape Sequence | Result |
| --------------- | ------ |
| `\m` | Print machine architecture (e.g. `x86_64`) |
| `\n` | Print machine name |
| `\r` | Print OS version |
| `\s` | Print OS name |
| `\v` | Print OS extra info |
| `\d` or `\t` | Display date in ISO-8601 format or `HH:MM:SS` |
| `\l` | Print tty number (e.g. "tty1", etc.) |
| `\u` or `\U` | Print number of users logged in (including you) |

About
-----

Control physical access to a linux computer by locking all of its virtual
terminals / consoles.

physlock is an alternative to vlock, it is equivalent to `vlock -an'. It is
written because vlock blocks some linux kernel mechanisms like hibernate and
suspend and can therefore only be used with some limitations.
physlock is designed to be more lightweight, it does not have a plugin
interface and it is not started using a shell script wrapper.

physlock relies on the utmp file to contain an entry for the active console
whose `ut_line` field is set to its device name, i.e. "tty1". Some graphical
login managers do not write such entries per default. You have to manually set
up `sessreg(1)` in order to use physlock with such a login manager.

Installation
------------
physlock is built using the commands:

    $ make
    # make install

Please note, that the latter one requires root privileges.
By default, physlock is installed using the prefix "/usr/local", so the full
path of the executable will be "/usr/local/bin/physlock".

You can install it into a directory of your choice by changing the second
command to:

    # make PREFIX="/your/dir" install

Please also note, that the physlock executable will have root ownership and the
setuid bit set.

All build-time specific settings are set via preprocessor macros in the file
"config.h". Please check and change them, so that they fit your needs.

Usage
-----
The behaviour of physlock is completely controlled via command-line arguments,
it does not rely on environment variables.
physlock uses the utmp file to identify the owner of the current session (i.e.
active tty) and prompts for her password to unlock the computer.

The following command-line arguments are supported:

    -d       fork and detach, parent returns after everything is set up
             (useful for suspend/hibernate scripts)
    -h       print short usage help and exit
    -l       only lock console switching
    -L       only enable console switching
    -m       mute kernel messages on console while physlock is running
    -s       disable sysrq key while physlock is running
    -v       print version information and exit
    -z       disable printing the /etc/issue file
