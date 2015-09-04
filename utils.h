#ifndef UTILS_H
#define UTILS_H

#include <pthread.h>
#include "queue.h"
#include "result.h"

/*enum HRet{
    success,
    memory,
    socket_failed,
    connect_failed,
    send_failed,
    other
};
*/
int jobID;
enum work_status
{
    created,
    process_queue,
    preform_task,
    finished_queue,
    sending
};
struct spy_task_handler{
    int job_id;
    int task_id;
    char *filepath;
    char *file;
    enum work_status status;

};

struct myTask_handler
{
    struct link *list;
    struct spy_task_handler *task;
};
/*Queue Headers*/
struct link *send_head;
struct link *process_head;
/*Locks*/
    //send_head lock
    //process_head lock
    //camera lock

//Prints the currenty entry 
void printEntry(struct spy_task_handler *task);
//initilizes all locks and queue head
void initialize();
/*  @addToQueueTail
*   Adds a entry to the queue
*   ARGS:   IN  head        queue to insert entry to tail
*/
enum HRet addToQueueTail(struct link *head, struct myTask_handler* entry);
/*  @addToQueueHead
*   Adds a entry to the queue
*   ARGS:   IN  head        queue to insert entry to tail
*/
enum HRet addToQueueHead(struct link *head, struct myTask_handler* entry);
/*  @deleteQueue
*   deletes all entries from a queue
    ARGS:   IN  head        queue to loop through and delete
*/
enum HRet deleteQueue(struct link *head);
/*  @queueEmpty
*   Checks to see if the queue is empty
*   ARGS:   IN  head        queue to check
*/
int queueEmpty(struct link *head);
/*  @popEntry
*   Pops the top entry from the queue and returns entry back to the caller
*   ARGS:   IN  head        queue head to get entry from
            OUT entry       assigned an entry from the queue
*/
void popEntry(struct link *head, struct myTask_handler **entry);
/*  @printQueue 
*   ARGS:   IN  head        queue to get loop through
*/
char* printQueue(struct link *head);
/*  @numberEntries
*   ARGS:   IN  head        queue count
*/
int numberEntries(struct link* head);
/*
*   Free the memory held by this structure
*/
void cleanup(struct myTask_handler *myTask);
#endif
