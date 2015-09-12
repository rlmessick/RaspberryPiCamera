#include "taskmgr.h"
/*
    @main
    PURPOSE:
    ARGS:
            1. Gets IP address to send/receive tasking
            2. Port to recieve tasking
            3. Port to send tasking
    To start 3 threads
            1. Server Thread    -> To receive task from a client
            2. Process Thread   -> preforms work
            3. Send to Client   -> Sends data back to client


*/
int main(int argc, char* argv[])
{
    enum HRet result = success;
    int serverPort;
    int outPort;
    char client[10];
    pthread_t thread1, thread2, thread3;

    if(argc != 4)
    {
        printf("usage: ./progam client_ip_address client_port server_port\n");
        return 1;
    }
    strcpy(client, argv[1]);
    outPort = atoi(argv[2]);
    serverPort = atoi(argv[3]);

    setIPAddr(client_ip, client);
    setPort(client_port, outPort);
    setPort(server_port, serverPort);

    printf("Hello world\n Look at me now!!\n I'm getting paper.\n");
    //init the queues and locks
    initialize();
    //needs to be in a thread
    //server thread
    pthread_create(&thread1, NULL, (void*) &initServer, NULL );

    //needs to be in a thread
    //to client thread
    pthread_create(&thread2, NULL, (void*) &prepareToSendTasking, NULL);

    //processThread
    pthread_create(&thread3, NULL, (void*) &processTasking, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
/*    printf("Number of Entries in queue: %d\n", 
            numberEntries(process_head));
    result = getTasking(0x0);
    printf("Number of Entries in queue: %d\n", 
            numberEntries(process_head));
    result += getTasking(0x01);
    printf("Number of Entries in queue: %d\n", 
            numberEntries(process_head));
    result += getTasking(0x02);
    printf("Number of Entries in queue: %d\n", 
            numberEntries(process_head));
    result += getTasking(0x03);
    printf("Number of Entries in queue: %d\n", 
            numberEntries(process_head));
    result += getTasking(0x0);
    printf("Number of Entries in queue: %d\n", 
            numberEntries(process_head));
    result += getTasking(0x03);
    printf("Number of Entries in queue: %d\n", 
            numberEntries(process_head));

    printf("\n\n\nPrint Queue\n");    
    printQueue(process_head);
*/
/*
    printf("\n\n\nDelete Queue\n");
    deleteQueue(process_head);

    printf("\n\n\nProcess Tasking\n");
    processTasking();
    prepareToSendTasking();


    deleteQueue(process_head);
    deleteQueue(send_head);
    printf("Number of Entries in queue: %d\n", 
            numberEntries(process_head));
*/
    if(result == success)
    {
        printf("mission completed for the day\n");
    }
    else
    {
        printf("We have failed to work\n");
    }
    
    //create threads needed to run
        //recieveTasking
        //prepareToSendTasking
        //TEMP:taskingCommand (recieveTasking)

    return 0;
}



