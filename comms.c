#include "comms.h"

void initServer( )
{
    int *client_sock;
    int socket_desc, c, tmp;
    struct sockaddr_in server, client;
    pthread_t thread_id;

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        goto exit;
    }
    memset(&server, 0, sizeof(struct sockaddr_in));
    puts("Socket created");
                                 
        //Prepare the sockaddr_in structure
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons( server_port );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        goto exit;
    }
    puts("bind done");

    //Listen
    listen(socket_desc , 3);
                                                
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    while( (tmp = accept(socket_desc, (struct sockaddr *)&client, 
                (socklen_t*)&c)) )
    {
        puts("Connection accepted");
        client_sock = (int*) malloc(sizeof(int));
        *client_sock = tmp;

        pthread_create( &thread_id , NULL ,  (void *) &recieveTask , 
                (void*) client_sock);

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( thread_id , NULL);
        puts("Handler assigned");
    }

    if (client_sock < 0)
    {
        perror("accept failed");
        goto exit;
    }
exit:
    return;
}

void recieveTask(void* c_sock)
{
    //Get the socket descriptor
    int *sock = (int*) c_sock;
    int read_size, task;
    char *message , client_message[2000];
    /*              
    //Send some messages to the client
    message = "Greetings! I am your connection handler\n";
    write(sock , message , strlen(message));
                                   
    message = "Now type something and i shall repeat what you type \n";
    write(sock , message , strlen(message));
      */                                          
    //Receive a message from client
    read_size = recv(*sock , client_message , 2000 , 0);
    
    //end of string marker
    //should only be a integer for now
    client_message[read_size] = '\0';

    if(read_size > 0)
    {
        task = atoi(client_message);
        //Send the message back to client
        // write(sock , client_message , strlen(client_message));

        printf("recieveTask: Task option from client: %d", task);

        //clear the message buffer
        memset(client_message, 0, 2000);

        //send to getTasking
        getTasking(task);
    }
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }
    if(c_sock!= NULL)
    {
        free(c_sock);
    }
}

//client
enum HRet sendTaskToClient(char* message)
{
    int sock;
    struct sockaddr_in server;
    //char server_reply[2000];
    enum HRet result = success;

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
        result = socket_failed;
        goto exit;
    }
    puts("Socket created");
                                                   
    server.sin_addr.s_addr = inet_addr(client_ip);
    server.sin_family = AF_INET;
    server.sin_port = htons( client_port );
                                                                    
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        result = connect_failed;
        goto closeSocket;
    }

    puts("Connected\n");
    /*TODO: send in chunks (SEND_CHUNKS)*/
    //Send some data
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        result = send_failed;
        goto closeSocket;
    }
    /*
    //Receive a reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    
        puts("Server reply :");
        puts(server_reply);
    */
closeSocket:
    close(sock);
exit:
    return result;
}
void setIPAddr(char *ip, char *m_ip)
{
    memset(ip, '\n', 10);
    strncpy(ip, m_ip, 10);
}
void setPort( int port, int m_port)
{
    port = m_port;
}
