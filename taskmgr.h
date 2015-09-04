#ifndef TASKMGR_H
#define TASKMGR_H
/*
#include <comms/comms.h>   // communication btwn LP and Pi
#include <utils/utils.h>  //shared objects need between files 
*/
#include "utils.h"      // local shared objects
#include "result.h"     // return statuses
#include "comms.h"
#include <stdio.h>
#include <stdlib.h>
/* @getTasking
    Check a queue for new tasking, then it will pop that task off 
    //Create a new struct spy_task_handler 
    //Finally it will create a thread to call processTasking
//NOTE: Contains locks on the queue/list
*/
enum HRet getTasking(int task);
/* @processTasking
//Reads the task and executes the task, will 
//NOTE: contain locks over all critical resources
*/
void processTasking();
/* @prepareToSendTasking
    Check the sending queue for tasking, then creates a thread
    to send the message back to client
//NOTE: contains lock over list
*/
void prepareToSendTasking();
/* @prepareMessage
    Converts the structure into a flexiable message
//NOTE: may contain a lock over list
*/
void prepareMessage(struct spy_task_handler *myTask, char* msg);
/* @sendMessage
*   Creates the message, encrypts the message, and 
*   sends off the message to client.  Finally frees the memory
*/
void sendMessage(void* task); 
#endif
