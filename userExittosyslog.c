/***********************************************************************
* IBM Tivoli Storage Manager                                           * 
* Server Component                                                     *
*                                                                      *
* 5639-B9300 (C) Copyright IBM Corporation 1997, 2007 (Unpublished)    * 
***********************************************************************/

/***********************************************************************
 * Name:            userExitSample.c
 *
 * Description:     Example user-exit program that is invoked by
 *		    the TSM Server 
 *
 * Environment:     *********************************************
 *                  ** This is a platform-specific source file **
 *                  ** versioned for: "AIX 5L"                 **
 *                  *********************************************
 *
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include "userExitSample.h"

/**************************************
 *** Do not modify below this line. ***
 **************************************/
 

/******************************************************************
 * Procedure:  adsmV3UserExit
 * If the user-exit is specified on the server, a valid and
 * appropriate event will cause an elEventRecvData structure 
 * (see userExitSample.h) to be passed to a procedure named 
 * adsmV3UserExit that returns a void.
 *
 * INPUT :   A (void *) to the elEventRecvData structure
 * RETURNS:  Nothing
 ******************************************************************/

void adsmV3UserExit( void *anEvent )
{
  /* Typecast the event data passed */
  elEventRecvData *eventData = anEvent;

  /**************************************
   *** Do not modify above this line. ***
   **************************************/

  if( ( eventData->eventNum == USEREXIT_END_EVENTNUM     ) ||
      ( eventData->eventNum == END_ALL_RECEIVER_EVENTNUM ) )
  {
    /* Server says to end this user-exit.  Perform any cleanup, *
     * but do NOT exit() !!!                                    */
    return;
  }

  /* Field Access:  eventData->.... */
  /* Your code here ... */
openlog(eventData->serverName,LOG_PID,LOG_LOCAL0);
syslog(LOG_WARNING, (char *)eventData->event);
closelog();

  /* Be aware that certain function calls are process-wide and can cause
   * synchronization of all threads running under the TSM Server process!
   * Among these is the system() function call.  Use of this call can
   * cause the server process to hang and otherwise affect performance.
   * Also avoid any functions that are not thread-safe.  Consult your 
   * system's programming reference material for more information.
   */

  return;
} /* End of adsmV3UserExit() */


