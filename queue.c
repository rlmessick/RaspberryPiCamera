#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
void addTail(struct link **head, struct link *entry, void *m_addr)
{
    entry->addr = m_addr;

    if((*head)->next == (*head))
    {
        //printf("addTail: Option 1\n");
        entry->next = entry->prev =(*head);
        (*head)->next = (*head)->prev = entry;
    }
    else
    {
        //printf("addTail: Option2\n");
        entry->next = (*head);
        entry->prev = (*head)->prev;
        
        (*head)->prev->next = entry;
        (*head)->prev = entry;
    }
}
void addHead(struct link **head, struct link **entry, void *m_addr)
{
    (*entry)->addr = m_addr;

    (*entry)->next = (*head)->next;
    (*entry)->prev = (*head);
    
    (*head)->next->prev = *entry;
    (*head)->next = *entry;
}
void initHead(struct link **head)
{
    //printf("initHead\n");
    (*head) = (struct link*) malloc(sizeof(struct link));
    (*head)->next = (*head)->prev = (*head);
}
void init(struct link **entry)
{
    (*entry) = (struct link *) malloc(sizeof(struct link));
    (*entry)->next = (*entry)->prev = NULL;
}
void* pop(struct link **head)
{
    struct link *node = NULL;
    void* entry = NULL;

    if( isEmpty(head) == 1)
    {
        printf("queue.c:pop(): List emptied!!!\n");
        goto exit;
    }
    //Get the first entry
    node = (*head)->next;
    entry = node->addr;
    //pop it off
    (*head)->next = node->next;
    //(*head)->prev = *entry->prev;
    printf("queue.c:pop(): Got and entry!!!\n");
exit:
    return entry;
}
void del(struct link **head)
{
    printf("queue.c::");
    return;
}
int isEmpty(struct link **head)
{
    if((*head)->next == (*head))
    {
        //printf("isEmpty: List is empty\n");
        return 1;
    }
    //printf("isEmpty: We have at least an entry\n");
    return 0;
}

int count(struct link **head)
{
    int count = 0;
    struct link *tmp = NULL;
    for(tmp = (*head)->next; tmp != (*head); tmp= tmp->next)
    {
        count++;
    }
    return count;
}
