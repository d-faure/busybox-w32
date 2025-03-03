/* vi: set sw=4 ts=4: */
/*
 * Mini reset implementation for busybox
 *
 * Copyright (C) 1999-2004 by Erik Andersen <andersen@codepoet.org>
 * Written by Erik Andersen and Kent Robotti <robotti@metconnect.com>
 *
 * Licensed under GPLv2 or later, see file LICENSE in this source tree.
 */
//config:config RESET
//config:	bool "reset (345 bytes)"
//config:	default y
//config:	help
//config:	This program is used to reset the terminal screen, if it
//config:	gets messed up.

// NOTE: For WIN32 this applet is NOFORK so we can change the screen
//       buffer for the current process.

//applet:IF_PLATFORM_MINGW32(IF_RESET(APPLET_NOFORK(reset, reset, BB_DIR_USR_BIN, BB_SUID_DROP, reset)))
//applet:IF_PLATFORM_POSIX(IF_RESET(APPLET_NOEXEC(reset, reset, BB_DIR_USR_BIN, BB_SUID_DROP, reset)))

//kbuild:lib-$(CONFIG_RESET) += reset.o

//usage:#define reset_trivial_usage
//usage:       ""
//usage:#define reset_full_usage "\n\n"
//usage:       "Reset terminal (ESC codes) and termios (signals, buffering, echo)"

/* "Standard" version of this tool is in ncurses package */

#include "libbb.h"

#define ESC "\033"

#if ENABLE_STTY
int stty_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
#endif

int reset_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
int reset_main(int argc UNUSED_PARAM, char **argv UNUSED_PARAM)
{
#if !ENABLE_PLATFORM_MINGW32
	static const char *const args[] ALIGN_PTR = {
		"stty", "sane", NULL
	};

	/* no options, no getopt */

	if (/*isatty(STDIN_FILENO) &&*/ isatty(STDOUT_FILENO)) {
		/* See 'man 4 console_codes' for details:
		 * "ESC c"        -- Reset
		 * "ESC ( B"      -- Select G0 Character Set (B = US)
		 * "ESC [ m"      -- Reset all display attributes
		 * "ESC [ J"      -- Erase to the end of screen
		 * "ESC [ ? 25 h" -- Make cursor visible
		 */
		printf(ESC"c" ESC"(B" ESC"[m" ESC"[J" ESC"[?25h");
		/* http://bugs.busybox.net/view.php?id=1414:
		 * people want it to reset echo etc: */
#if ENABLE_STTY
		return stty_main(2, (char**)args);
#else
		/* Make sure stdout gets drained before we execvp */
		fflush_all();
		execvp("stty", (char**)args);
#endif
	}
#else
	if (isatty(STDOUT_FILENO)) {
		// "ESC [ m"        -- Reset all display attributes
		// "ESC [ ? 1049 l" -- Use normal screen buffer
		// reset_screen     -- Reset cursor and clear screen buffer
		full_write1_str(ESC"[m" ESC"[?1049l");
		reset_screen();
	}
#endif
	return EXIT_SUCCESS;
}
