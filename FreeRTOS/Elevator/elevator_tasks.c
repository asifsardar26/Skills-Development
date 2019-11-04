/*
 * elevator_tasks.c
 *
 *  Created on: 4 nov. 2019
 *      Author: A551226
 */

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

#include "elevator_types.h"

/* Priorities at which the tasks are created. */
#define mainQUEUE_RECEIVE_TASK_PRIORITY   ( tskIDLE_PRIORITY + 2 )
#define mainQUEUE_SEND_TASK_PRIORITY    ( tskIDLE_PRIORITY + 1 )

/*
 * The tasks for the
 */
static void prvQueueReceiveTask( void *pvParameters );
static void prvQueueSendTask( void *pvParameters );
