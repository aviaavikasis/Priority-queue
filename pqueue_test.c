#include <assert.h>
#include <stdio.h>
#include "pqueue.h"

#define UNUSED(x) (void)x

void PQueueCreateTest(void);
void PQueueEnqueueTest(void);
void PQueueDequeueTest(void);
void PQueuePeekTest(void);
void PQueueSizeTest(void);
void PQueueIsEmptyTest(void);
void PQueueClearTest(void);
void PQueueEraseTest(void);


/* help functions for find and foreach tests */
int SumList(void* num , void* result);
int MultList(void* num , void* result);
int FindNumInList(const void* num , void* value);
int FindEvenNumbers(const void* num , void* value);
int IncreaseOrderCompare(void *data1 , void *data2 , void *param);


int main(void)
{
	PQueueCreateTest();
	PQueueEnqueueTest();
	PQueueDequeueTest();
	PQueuePeekTest();
	PQueueSizeTest();
	PQueueIsEmptyTest();
	PQueueClearTest();
	PQueueEraseTest();
	printf("\n\n->->->->->->->->-> success!!! <-<-<-<-<-<-<-<-<-<\n\n\n");
	
	return 0;
}

void PQueueCreateTest(void)
{
	cmp_priority_func cmp_priority = &IncreaseOrderCompare;
	pqueue_ty *pqueue = PQueueCreate(cmp_priority , NULL);
	assert(NULL != pqueue);
	PQueueDestroy(pqueue);

}


void PQueueEnqueueTest(void)
{
	cmp_priority_func cmp_priority = &IncreaseOrderCompare;
	int i = 0;
	pqueue_ty *pqueue = PQueueCreate(cmp_priority , NULL);
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	
	for ( ; i < 10 ; ++i)
	{
		PQueueEnqueue(pqueue , (void*)(arr + i));
	}
	assert(*((int*)PQueuePeek(pqueue)) == 10);
	PQueueDestroy(pqueue);
	
}


void PQueueDequeueTest(void)
{
	cmp_priority_func cmp_priority = &IncreaseOrderCompare;
	int i = 0;
	pqueue_ty *pqueue = PQueueCreate(cmp_priority , NULL);
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	
	for ( ; i < 10 ; ++i)
	{
		PQueueEnqueue(pqueue , (void*)(arr + i));
	}

	for (i = 0 ; i < 3 ; ++i)
	{
		PQueueDequeue(pqueue);
	}	
	assert(*((int*)PQueuePeek(pqueue)) == 7);
	
	PQueueDestroy(pqueue);
}


void PQueuePeekTest(void)
{
	cmp_priority_func cmp_priority = &IncreaseOrderCompare;
	int d = 3;
	int c = 4;
	pqueue_ty *pqueue = PQueueCreate(cmp_priority , NULL);
	PQueueEnqueue(pqueue , (void*)&d);
	PQueueEnqueue(pqueue , (void*)&c);
	assert(*((int*)PQueuePeek(pqueue)) == 4);
	PQueueDestroy(pqueue);	
}

void PQueueSizeTest(void)
{
	cmp_priority_func cmp_priority = &IncreaseOrderCompare;
	int i = 0;
	pqueue_ty *pqueue = PQueueCreate(cmp_priority , NULL);
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	assert(PQueueSize(pqueue) == 0);	
	
	for ( ; i < 10 ; ++i)
	{
		PQueueEnqueue(pqueue , (void*)(arr + i));
	}
	assert(PQueueSize(pqueue) == 10);	
	PQueueDestroy(pqueue);
	
}

void PQueueIsEmptyTest(void)
{
	cmp_priority_func cmp_priority = &IncreaseOrderCompare;
	int i = 0;
	pqueue_ty *pqueue = PQueueCreate(cmp_priority , NULL);
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	assert(PQueueIsEmpty(pqueue) == 1);	
	
	for ( ; i < 10 ; ++i)
	{
		PQueueEnqueue(pqueue , (void*)(arr + i));
	}
	assert(PQueueIsEmpty(pqueue) == 0);	
	PQueueDestroy(pqueue);

}


void PQueueClearTest(void)
{
	cmp_priority_func cmp_priority = &IncreaseOrderCompare;
	int i = 0;
	pqueue_ty *pqueue = PQueueCreate(cmp_priority , NULL);
	int arr[10] = {10,9,8,7,6,5,4,3,2,1};
	
	for ( ; i < 10 ; ++i)
	{
		PQueueEnqueue(pqueue , (void*)(arr + i));
	}
	assert(PQueueSize(pqueue) == 10);	
	PQueueClear(pqueue);
	assert(PQueueIsEmpty(pqueue) == 1);	

	PQueueDestroy(pqueue);
}


void PQueueEraseTest(void)
{
	cmp_priority_func cmp_priority = &IncreaseOrderCompare;
	is_data_match_ty is_data_match = &FindNumInList;
	int i = 0;
	int x = 4;
	pqueue_ty *pqueue = PQueueCreate(cmp_priority , NULL);
	int arr[10] = {10,9,8,7,6,5,4,3,2,1};
	
	for ( ; i < 10 ; ++i)
	{
		PQueueEnqueue(pqueue , (void*)(arr + i));
	}

	
	assert(*((int*)PQueueErase(pqueue , is_data_match , (void*)&x)) == 4);	

	PQueueDestroy(pqueue);	

}


int SumList(void* num , void* result)
{
	*((int*)result) += *((int*)num);
	return 0;
}

int MultList(void* num , void* result)
{
	*((int*)result) *= *((int*)num);
	return 0;
}

int FindNumInList(const void* num , void* value)
{
	return (*((int*)num) == *((int*)value)) ? 1 : 0;
}

int FindEvenNumbers(const void* num , void *value)
{
	UNUSED(value);
	return (*((int*)num) % 2 == 0);
}

int IncreaseOrderCompare(void *data1 , void *data2 , void *param)
{
	UNUSED(param);
	return *((int*)data1) - *((int*)data2);
}



