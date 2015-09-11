#include "taskmgr.h"

void prepareToSendTasking()
{
    struct myTask_handler *myTask;
    pthread_t thread1;

    while(1)
    {
        
        myTask = NULL;
        // Check Queue for tasking
        while(queueEmpty(send_head)==1)
        {
            sleep(5);
	    return;
        }
        
        //pop a tasking off queue
        popEntry(send_head, &myTask);

        if(myTask == NULL)
        {
            printf("PrepareToSendTasking: myTask is NULL.. This is bad\n");
            cleanup(myTask);
            continue;
        }
        printf("PrepareToSendTasking: Preparing to send data\n");
        //create thread 
        pthread_create(&thread1,NULL,(void*) &sendMessage,(void*)myTask);
    }
}
