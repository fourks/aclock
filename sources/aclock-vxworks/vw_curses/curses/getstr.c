/*
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef lint
static char sccsid[] = "@(#)getstr.c	5.3 (Berkeley) 6/30/88";
#endif /* not lint */

# include	"curses.ext"

/*
 *	This routine gets a string starting at (_cury,_curx)
 *	Note: do not add semaphore locking here! wgetch() must be able
 *            to release semaphore for blocking read.
 */
wgetstr(win,str)
reg WINDOW	*win; 
reg char	*str; {

	while ((*(signed char *)str = wgetch(win)) != ERR && *str != '\n')
		str++;
	if (*(signed char *)str == ERR) {
		*str = '\0';
		return ERR;
	}
	*str = '\0';
	return OK;
}
