#ifndef __ILRD_OL127_128_PRIORITY_QUEUE_H__
#define __ILRD_OL127_128_PRIORITY_QUEUE_H__

#include <stddef.h> /* size_t */



typedef int (*cmp_priority_func)(void *data1, void *data2, void *params);

typedef int (*is_data_match_ty)(const void *data, void *params);


typedef struct pqueue pqueue_ty;

/*
Description : the PQueueCreate() function create new periority queue.
return value : pointer to the new periority queue
time cpmlexity : O(1)
*/
pqueue_ty *PQueueCreate(cmp_priority_func cmp_priority, void *param);

/*
Description : the PQueueDestroy() function destroy exist periority queue.
Param : pointer to pqueue
return value : void
time cpmlexity : O(1)
*/
void PQueueDestroy(pqueue_ty *pqueue); 

/*
Description : the PQueueEnqueue() function insert new element to exist pqueue , by periority.
Params : pointer to pqueue , pointer to data variable 
return value : 0 if insert succeded , else 1.
time cpmlexity : O(n)
*/
int PQueueEnqueue(pqueue_ty *pqueue, void *data);

/*
Description : the PQueueDequeue() function Removes an element from pqueue.
Param : pointer to pqueue 
return value : void
time cpmlexity : O(1)
*/
void PQueueDequeue(pqueue_ty *pqueue); 

/*
Description : the PQueuePeek() function return the data that hold in the top of pqueue.
Param : pointer to pqueue  
return value : void pointer , point to data variable. can be also NULL
time cpmlexity : O(1)
*/
void *PQueuePeek(const pqueue_ty *pqueue);

/*
Description : the PQueueSize() function return the num elements in pqueue.
Param : pqueue pointer
return value : size_t num 
time cpmlexity : O(1)
*/
size_t PQueueSize(const pqueue_ty *pqueue);

/*
Description : the PQueueIsEmpty() function check if pqueue is empty.
Param :  pqueue pointer
return value : 1 if queue is empty , 0 otherwise
time cpmlexity : O(1)
*/
int PQueueIsEmpty(const pqueue_ty *pqueue);

/*
Description : the PQueueClear() function remove all elements in pqueue.
Param :  pqueue pointer
return value : void
time cpmlexity : O(n)
*/
void PQueueClear(pqueue_ty *pqueue);

/*
Description : the PQueueErase() function remove specifiec element in queue , by match param , 
and return void pointer to param that erased.
Param :  pqueue pointer
return value : void pointer
time cpmlexity : O(n)
*/
void *PQueueErase(pqueue_ty *pqueue, is_data_match_ty is_match, void *param);

#endif /* __ILRD_OL127_128_PRIORITY_QUEUE_H__ */ 







