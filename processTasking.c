#include "taskmgr.h"
#include "utils.h"
 void processTasking()
 {
    enum HRet result;
    struct myTask_handler *myTask = NULL;
    char *q1 = NULL, *q2 = NULL;
    while(1)
    {
        myTask = NULL;
        //check queue for tasking
        while( queueEmpty(process_head) ==1)
        {
                sleep(5);
                printf("sleeping\n");
        }

        //pop a task
        popEntry(process_head, &myTask);
        printf("Task\n");
        printEntry(myTask->task);    
        //Read the task value and evaluate
        switch(myTask->task->task_id)
        {
            // camera shot
            case 1:
                printf("ProcessTasking: Camera shot, please wait\n");
                //lock camera
                    //call camera
                //unlock camera
                break;

            //camera stream
            case 2:
                printf("ProcessTasking: Camera stream, its gonna be fun\n");
                //lock camera
                    //call camera
                //unlock camera
                break;

            //delete tasking queue
            case 3:
                printf("ProcessTasking: Delete Option\n");
                //lock queue
                deleteQueue(process_head);
                //unlock queue
                break;

            //print all qu
            case 4:
                printf("ProcessTasking: Print Queues");
                numberEntries(process_head);
                q1 = printQueue(process_head);
                numberEntries(send_head);
                q2 = printQueue(send_head);
                break;
            //default (no option)
            default:
                printf("ProcessTasking: Option unknown\n");
                printEntry(myTask->task);
                cleanup(myTask);
                continue;
        };

        //Place on sending queue
        result = addToQueueTail(send_head, myTask);
        if(result != success)
        {
            printf("ProcessTasking: Failed to add to sending queue");
        }
    }
 }
