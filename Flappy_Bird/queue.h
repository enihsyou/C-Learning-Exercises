/*
 * C Program to Implement Queue Data Structure using Linked List
 */

#ifndef SDL_DEMO_QUEUE_H
#define SDL_DEMO_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include "util.h"


struct PipeQueueNode {
    Pipe info;
    struct PipeQueueNode *ptr;
} *_node_front, *_node_rear, *_temp_node, *_front1;
struct PipeQueueNode * frontElement();
void pipeEnqueue(Pipe data);
void pipeDeque();
SDL_bool isQueueEmpty();
void display();
void createPipeQueue();
void queuesize();
void clearQueue();
int queueElementCount = 0;

/* Create an empty queue */
void createPipeQueue() {
    _node_front = _node_rear = NULL;
}

/* Returns queue size */
void queuesize() {
    printf("\n Queue size : %d", queueElementCount);
}

/* Enqueing the queue */
void pipeEnqueue(Pipe data) {
    if (_node_rear == NULL) {
        _node_rear = (struct PipeQueueNode *) malloc(1 * sizeof(struct PipeQueueNode));
        _node_rear->ptr = NULL;
        _node_rear->info = data;
        _node_front = _node_rear;
    } else {
        _temp_node = (struct PipeQueueNode *) malloc(1 * sizeof(struct PipeQueueNode));
        _node_rear->ptr = _temp_node;
        _temp_node->info = data;
        _temp_node->ptr = NULL;

        _node_rear = _temp_node;
    }
    queueElementCount++;
}

/* Displaying the queue elements */
void display() {
    _front1 = _node_front;

    if ((_front1 == NULL) && (_node_rear == NULL)) {
        printf("Queue is empty");
        return;
    }
    while (_front1 != _node_rear) {
        printf("%d ", _front1->info);
        _front1 = _front1->ptr;
    }
    if (_front1 == _node_rear)
        printf("%d", _front1->info);
}

/* Dequeing the queue */
void pipeDeque() {
    _front1 = _node_front;

    if (_front1 == NULL) {
//        printf("\n Error: Trying to display elements from empty queue");
        return;
    } else if (_front1->ptr != NULL) {
        _front1 = _front1->ptr;
//        printf("\n Dequed value : %d", _node_front->info);
        free(_node_front);
        _node_front = _front1;
    } else {
//        printf("\n Dequed value : %d", _node_front->info);
        free(_node_front);
        _node_front = NULL;
        _node_rear = NULL;
    }
    queueElementCount--;
}

/* Returns the front element of queue */
struct PipeQueueNode * frontElement() {
    if ((_node_front != NULL) && (_node_rear != NULL))
        return _node_front;
    else
//        printf("!!!");
        return NULL;
}

/* Display if queue is empty or not */
SDL_bool isQueueEmpty() {
    if ((_node_front == NULL) && (_node_rear == NULL))
        return SDL_TRUE;
    else
        return SDL_FALSE;
}

void clearQueue() {
    while (!isQueueEmpty()) pipeDeque();
}

#endif //SDL_DEMO_QUEUE_H
