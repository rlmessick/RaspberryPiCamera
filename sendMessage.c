#include "taskmgr.h"

void sendMessage(void* task)
{
    struct myTask_handler *myTask = (struct myTask_handler*) task;
    char *msg = NULL;

    //prepareMessage(myTask->task, msg);
    //encrypt message here
        //encryptMessage(msg);
    //send to client
    //sendTaskToClient(msg);
    //free up memory
    cleanup(myTask);
}
/* TODO: create the message
*/
void prepareMessage(struct spy_task_handler *myTask, char* msg)
{
        int size = 100;

        msg = malloc(size);
        memset(msg, '0', size);
        strcpy(msg, "Hello World\n");
}
