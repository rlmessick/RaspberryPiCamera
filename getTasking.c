#include "taskmgr.h"
enum HRet getTasking(int task)
{
    enum HRet result = success;
    struct myTask_handler *myTask = NULL;
    struct spy_task_handler *job = NULL;

    //move the task into our structure
    job = (struct spy_task_handler*) 
            malloc(sizeof(struct spy_task_handler));
    if (job == NULL)
    {
        printf("getTasking: No Memory for Task\n");
        result = memory;
        goto cleanup;
    }
    //setting default things
    job->job_id = ++jobID;
    job->task_id = task;
    job->filepath = NULL;
    job->file = NULL;
    job->status = created;

    //prepare the things needed for the queue
    myTask = (struct myTask_handler*) 
                malloc(sizeof(struct myTask_handler));
    if(myTask == NULL)
    {
        printf("getTasking: No Memory for Task\n");
        result = memory;
        goto cleanup;
    }
    myTask->list = NULL;
    //Add spy_task_handler structure
    myTask->task = job;
    printEntry(myTask->task);
    addToQueueTail(process_head, myTask);    
goto ret;

cleanup:
    if(job != NULL)
        free(job);
    cleanup(myTask);
ret:
    return result;
}

/*
void cleanup(struct myTask_handler *myTask)
{
    if(myTask == NULL)
        return;
    
    if(myTask->task->filepath != NULL)
        free(myTask->task->filepath);

    if (myTask->task->file != NULL)
        free(myTask->task->file);

    if(myTask->task != NULL)
        free(myTask->task);

    if(myTask != NULL)
        free(myTask);

    printf("Freed all the mallocs!\n");
}
*/
