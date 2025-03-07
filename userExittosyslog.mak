#***********************************************************************
#* Tivoli Storage Manager (TSM)                                         * 
#* Server Component                                                     *
#*                                                                      *
#* IBM Confidential                                                     *
#* (IBM Confidential-Restricted when combined with the Aggregated OCO   *
#* Source Modules for this Program)                                     * 
#*                                                                      *
#* OCO Source Materials                                                 *
#*                                                                      *
#* 5648-020 (C) Copyright IBM Corporation 1990, 2007 (Unpublished)      * 
#***********************************************************************
#
#***********************************************************************
#* Name:            Makefile.userExit.smp
#*
#* Description:     Sample makefile for a user-exit
#*
#* Environment:     *********************************************
#*                  ** This is a platform-specific source file **
#*                  ** versioned for:   "AIX 5L"               **
#*                  *********************************************
#*
#* Change activity: Version 3, Release 1  -  April 1997 IBM Corporation
#*  33294 - Updated to reflect new 64-bit flags
#***********************************************************************

all: userExittosyslog

userExittosyslog: userExittosyslog.c userExitSample.h userExittosyslog.exp
	cc_r -G -q64 -o userExittosyslog userExittosyslog.c -bE:userExittosyslog.exp

