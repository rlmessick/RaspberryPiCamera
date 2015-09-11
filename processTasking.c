#include "taskmgr.h"
#include "utils.h"
#include <time.h>

 void processTasking()
 {
    enum HRet result;
    struct myTask_handler *myTask = NULL;
    char *q1 = NULL, *q2 = NULL, *filename= NULL, *filepath = NULL;
    int tmp_filenameSize, tmp_filepathSize;
    time_t t;
    struct tm c_time;
    char cmd[1000];
    while(1)
    {
        memset(cmd, 0, 1000);
        myTask = NULL;
        filename = NULL;
        filepath = NULL;
        tmp_filenameSize = 0;
        tmp_filepathSize = 0;

        t = time(NULL);
        c_time = *localtime(&t);

        //check queue for tasking
        while( queueEmpty(process_head) ==1)
        {
                sleep(5);
<<<<<<< HEAD
                printf("sleeping\n");
		return;
=======
                printf("processTasking:sleeping\n");
                return;
>>>>>>> d7234ad2671565a37b0b847d62538561e82bf623
        }

        //pop a task
        popEntry(process_head, &myTask);
        printf("*************Task***************************\n");
        printEntry(myTask->task);    
        //Read the task value and evaluate
        switch(myTask->task->task_id)
        {
            // camera shot
            case 1:
                tmp_filepathSize = snprintf(NULL, 0, "/tmp/");

                filepath = malloc(tmp_filepathSize+1);
                memset(filepath, 0, tmp_filepathSize+1);
                snprintf(filepath, tmp_filepathSize+1, "/tmp/");

                tmp_filenameSize = snprintf(NULL, 0,
                    "%d_%d_%d_%d:%d:%d_%d.jpg", 
                    c_time.tm_year+1900, c_time.tm_mon+1, c_time.tm_mday,
                    c_time.tm_hour, c_time.tm_min, c_time.tm_sec,
                    myTask->task->job_id);            

                filename = (char*) malloc(tmp_filenameSize+1);
                memset(filename, 0, tmp_filenameSize+1);
                snprintf(filename, tmp_filenameSize+1,
                    "%d_%d_%d_%d:%d:%d_%d.jpg",
                    c_time.tm_year+1900, c_time.tm_mon+1, c_time.tm_mday,
                    c_time.tm_hour, c_time.tm_min, c_time.tm_sec,
                    myTask->task->job_id);
                printf("ProcessTasking: Camera shot, please wait\n");
                //lock camera
                    //call camera
                //unlock camera
                myTask->task->file = filename;
                myTask->task->filepath = filepath;

                printEntry(myTask->task);
                break;

            //camera stream
            case 2:
                tmp_filepathSize = snprintf(NULL, 0, "/tmp/");

                filepath = malloc(tmp_filepathSize+1);
                memset(filepath, 0, tmp_filepathSize+1);
                snprintf(filepath, tmp_filepathSize+1, "/tmp/");

                tmp_filenameSize = snprintf(NULL, 0,
                    "%d_%d_%d_%d:%d:%d_%d.jpg", 
                    c_time.tm_year+1900, c_time.tm_mon+1, c_time.tm_mday,
                    c_time.tm_hour, c_time.tm_min, c_time.tm_sec,
                    myTask->task->job_id);    

                filename = (char*) malloc(tmp_filenameSize+1);
                memset(filename, 0, tmp_filenameSize+1);

                snprintf(filename, tmp_filenameSize+1,
                    "%d_%d_%d_%d:%d:%d_%d.jpg",
                    c_time.tm_year+1900, c_time.tm_mon+1, c_time.tm_mday,
                    c_time.tm_hour, c_time.tm_min, c_time.tm_sec,
                    myTask->task->job_id);

                printf("ProcessTasking: Camera stream, its gonna be fun\n");
                //lock camera
                    //call camera
                //unlock camera
                myTask->task->file = filename;
                myTask->task->filepath = filepath;
                break;

            //delete tasking queue
            case 3:
                printf("ProcessTasking: Delete Option\n");
                //lock queue
                deleteQueue(process_head);
                //unlock queue
                break;

            //print all queue
            case 4:
                tmp_filepathSize = snprintf(NULL, 0, "/tmp/");

                filepath = malloc(tmp_filepathSize+1);
                memset(filepath, 0, tmp_filepathSize+1);
                snprintf(filepath, tmp_filepathSize+1, "/tmp/");

                tmp_filenameSize = snprintf(NULL, 0,
                    "%d_%d_%d_%d:%d:%d_%d.txt", 
                    c_time.tm_year+1900, c_time.tm_mon+1, c_time.tm_mday,
                    c_time.tm_hour, c_time.tm_min, c_time.tm_sec,
                    myTask->task->job_id);    

                filename = (char*) malloc(tmp_filenameSize+1);
                memset(filename, 0, tmp_filenameSize+1);
                snprintf(filename, tmp_filenameSize+1,
                    "%d_%d_%d_%d:%d:%d_%d.txt",
                    c_time.tm_year+1900, c_time.tm_mon+1, c_time.tm_mday,
                    c_time.tm_hour, c_time.tm_min, c_time.tm_sec,
                    myTask->task->job_id);
                printf("ProcessTasking: Print Queues");
                numberEntries(process_head);
                q1 = printQueue(process_head);
                numberEntries(send_head);
                q2 = printQueue(send_head);

                myTask->task->file = filename;
                myTask->task->filepath = filepath;
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
