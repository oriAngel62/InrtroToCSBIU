/***********
* Ori Angel
* 314617739
* 01
* ass06
***********/

#ifndef _QUEUE_H
#define _QUEUE_H

// The queue, front stores the front node of LL and rear stores the 
// last node of LL 
typedef struct Queue {
	int front, rear;
    void **key;
}Queue;

Queue* createQueue();
//q - the queue, k- the key (element)
void enQueue(Queue* q, void* k);
void deQueue(Queue* q);
// return 1 if empty and zero if not empty
int isQueueEmpty(Queue* q);

#endif
