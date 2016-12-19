/* physlock: issue.h
 * Copyright (c) 2013 Bert Muennich <be.muennich at gmail.com>
 *
 * This file contains functions that are based on agetty(8) by
 * Peter Orbaek <poe@daimi.aau.dk> and Werner Fink <werner@suse.de>.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef ISSUE_H
#define ISSUE_H

#include <stdio.h>

#include "vt.h"

// This sugar makes using singular/plural more simple
#define P_(singular, plural, n) ((n) == 1 ? (singular) : (plural))

/*
 * This function reads and print out the /etc/issue file, replacing escape
 * sequences like '\l', '\u', and '\t' - in the same manner as agetty(8).
 * This function only implements a subset of the escape sequences supported
 * by agetty(8)!!!
 */
void print_issue_file(vt_t, int);

#endif /* ISSUE_H */
