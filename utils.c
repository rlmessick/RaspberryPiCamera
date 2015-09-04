#include "utils.h"
#include "queue.h"
#include <stdio.h>
void initialize()
{
    initHead(&send_head);
    initHead(&process_head);
    jobID =0;
}

void printEntry(struct spy_task_handler *task)
{
    printf("JOB_ID: %d \nTASK_ID: %d\n", task->job_id, task->task_id);
    printf("Status:%d\n", task->status);
    printf("File location %s/%s\n",task->filepath,task->file);
}
/*
*   TODO: finsih this function
*/
char* printQueue(struct link *head)
{
    //char msg [10000];
    //int len_msg = 0;
    struct myTask_handler *task_tmp = NULL;
    struct link *tmp = NULL;

  //task_tmp = (struct myTask_handler*)malloc(sizeof(struct myTask_handler));
    //write to a file
    for(tmp = head->next; tmp != head; tmp=tmp->next)
    {
        task_tmp = tmp->addr;
        //printf("printQueue: 0x%x\n", task_tmp->list);
        printEntry(task_tmp->task); 
        task_tmp = NULL;
    }
    //open file and get the size
    return NULL;
}
enum HRet addToQueueTail(struct link *head, struct myTask_handler* entry)
{
    enum HRet result = success;
    //printf("addToQueueTail: 0x%x\n", entry->list);
    init(&(entry->list));
    addTail(&head, entry->list, entry);
    /*
    printf("head %x\n", head);
    printf("addToQueueTail: 0x%x\n", entry->list);
    printf("next 0x%x prev 0x%x\n", entry->list->next, entry->list->prev);
    */
    return result;
}
enum HRet addToQueueHead(struct link *head, struct myTask_handler* entry)
{
    enum HRet result = success;

    init(&(entry->list));
    addHead(&head, &(entry->list), entry);

    return result;
}

enum HRet deleteQueue(struct link *head)
{
    enum HRet result = success;
    struct link *tmp = NULL;
    struct myTask_handler *task_tmp=NULL;

    for(tmp = head->next; tmp != head; tmp = head->next)
    {
        task_tmp = NULL;
        // get the entry
        //task_tmp  = pop(&head);
        popEntry(head, &task_tmp);
        if(task_tmp != NULL)
        {
            //printf("*************Deleting****************\n");
            //printEntry(task_tmp->task);
            cleanup(task_tmp);
        }

    }
    //printf("deleteQueue: Number of Entries in queue: %d\n",
     //          numberEntries(head));
    //initHead(head);
    return result;
}
int queueEmpty(struct link *head)
{
    return isEmpty(&head);
}
void popEntry(struct link *head, struct myTask_handler **entry)
{

    (*entry) = pop(&head);
    //printf("after pop call\n");
    //printEntry((*entry)->task);
}

int numberEntries(struct link* head)
{
    return count(&head);
}
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

    if(myTask->list != NULL)
        free(myTask->list);

    if(myTask != NULL)
        free(myTask);

    printf("Freed all the mallocs!\n");
}

