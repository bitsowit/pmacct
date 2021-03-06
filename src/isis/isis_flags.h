/*
 * IS-IS Rout(e)ing protocol - isis_flags.h
 *                             Routines for manipulation of SSN and SRM flags
 *
 * Copyright (C) 2001,2002   Sampo Saaristo
 *                           Tampere University of Technology      
 *                           Institute of Communications Engineering
 *
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public Licenseas published by the Free 
 * Software Foundation; either version 2 of the License, or (at your option) 
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
 * more details.

 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef _ISIS_FLAGS_H_
#define _ISIS_FLAGS_H_

/* The grand plan is to support 1024 circuits so we have 32*32 bit flags
 * the support will be achived using the newest drafts */
#define ISIS_MAX_CIRCUITS 32 /* = 1024 */	/*FIXME:defined in lsp.h as well */

#if (!defined __ISIS_FLAGS_C)
#define EXT extern
#else
#define EXT
#endif
EXT void flags_initialize (struct flags *);
EXT struct flags *new_flags (int);
EXT long int flags_get_index (struct flags *);
EXT void flags_free_index (struct flags *, long int);
EXT int flags_any_set (u_int32_t *);
#undef EXT

#define ISIS_SET_FLAG(F,C) \
        F[C->idx>>5] |= (1<<(C->idx & 0x1F));

#define ISIS_CLEAR_FLAG(F,C) \
        F[C->idx>>5] &= ~(1<<(C->idx & 0x1F));

#define ISIS_CHECK_FLAG(F, C)  F[(C)->idx>>5] & (1<<(C->idx & 0x1F))

/* sets all u_32int_t flags to 1 */
#define ISIS_FLAGS_SET_ALL(FLAGS) \
        memset(FLAGS,0xFF,ISIS_MAX_CIRCUITS*4);

#define ISIS_FLAGS_CLEAR_ALL(FLAGS) \
        memset(FLAGS,0x00,ISIS_MAX_CIRCUITS*4);

#endif /* _ISIS_FLAGS_H_ */
