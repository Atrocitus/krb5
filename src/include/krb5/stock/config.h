/*
 * Copyright 1990,1991,1994 by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America may
 *   require a specific license from the United States Government.
 *   It is the responsibility of any person or organization contemplating
 *   export to obtain such a license before exporting.
 * 
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of M.I.T. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 * 
 *
 * Configuration definition file.
 */


#ifndef KRB5_CONFIG__
#define KRB5_CONFIG__

#ifndef KRB5_AUTOCONF__
#define KRB5_AUTOCONF__
#include "autoconf.h"
#endif

#ifdef SYSV
/* Change srandom and random to use rand and srand */
/* Taken from the Sandia changes.  XXX  We should really just include */
/* srandom and random into Kerberos release, since rand() is a really */
/* bad random number generator.... [tytso:19920616.2231EDT] */
#define random() rand()
#define srandom(a) srand(a)
#ifndef unicos61
#define utimes(a,b) utime(a,b)
#endif  /* unicos61 */
#endif /* SYSV */

/* XXX these should be parameterized soon... */
#define PROVIDE_DES_CBC_MD5
#define PROVIDE_DES_CBC_CRC
#define PROVIDE_RAW_DES_CBC
#define PROVIDE_CRC32
#define PROVIDE_DES_CBC_CKSUM
#define PROVIDE_RSA_MD4
#define PROVIDE_RSA_MD5

#define DEFAULT_PWD_STRING1 "Enter password:"
#define DEFAULT_PWD_STRING2 "Re-enter password for verification:"

#define	KRB5_KDB_MAX_LIFE	(60*60*24) /* one day */
#define	KRB5_KDB_MAX_RLIFE	(60*60*24*7) /* one week */
#define	KRB5_KDB_EXPIRATION	2145830400 /* Thu Jan  1 00:00:00 2038 UTC */

/*
 * For paranoid DOE types that don't want to give helpful error
 * messages to the client....er, attacker
 */
#undef KRBCONF_VAGUE_ERRORS

/*
 * Define this if you want the KDC to modify the Kerberos database;
 * this allows the last request information to be updated, as well as
 * the failure count information.
 * 
 * Note that this doesn't work if you're using slave servers!!!  It
 * also causes the database to be modified (and thus need to be
 * locked) frequently.
 */
#undef KRBCONF_KDC_MODIFIES_KDB
    
/* 
 * Windows requires a different api interface to each function. Here
 * just define it as NULL.
 */
#define API
#define FAR

#endif /* KRB5_CONFIG__ */

