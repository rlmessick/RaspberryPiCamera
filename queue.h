#include <stdio.h>
#ifndef QUEUE_H
#define QUEUE_H
struct link
{
    struct link *next;
    struct link *prev;
    void * addr;
};

//adds entry to the tail of a head  
void addTail(struct link **head, struct link *entry, void *m_addr);
//adds entry to the head  
void addHead(struct link **head, struct link **entry, void *m_addr);
//initializes an entry
void init(struct link **entry);

//initializes head
void initHead(struct link **head);

//gets the first entry off the list and returns it back to caller
void* pop(struct link **head);

//deletes all entries from the queue
void del(struct link **head);

//verifies if the list is empty
int isEmpty(struct link **head);

//count in list
int count(struct link **head);

#endif
