#include "queue.h"
#include <stdlib.h>



queue_t*create_Queue(int capacity)
{
    queue_t*qu=(queue_t*)malloc(sizeof(queue_t));

    if(qu != NULL)
    {
        qu->arr=(int*)malloc(capacity*sizeof(int));
        qu->front=0;
        qu->rear=capacity-1;
        qu->size=capacity;
        qu->size=0;
    }
    return qu;
}

// char isfull(queue_t*qu)
// {

// }
