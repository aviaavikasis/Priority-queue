#include <stddef.h> /* size_t */
#include <assert.h> /* assert */
#include <stdlib.h> /* malloc */
#include "pqueue.h" 
#include "srtlist.h" /* sorted list functions */

struct pqueue
{
	srtlist_ty *srtlist;
};

pqueue_ty *PQueueCreate(cmp_priority_func cmp_priority, void *param)
{
	pqueue_ty *pqueue = (pqueue_ty*)malloc(sizeof(pqueue_ty));
	if(NULL == pqueue)
	{
		return NULL;
	}
	
	pqueue->srtlist = SrtlistCreate(cmp_priority , param);
	
	if(NULL == pqueue->srtlist)
	{
		free(pqueue);
		return NULL;
	}
	
	return pqueue;
}


void PQueueDestroy(pqueue_ty *pqueue)
{
	assert(NULL != pqueue);
	SrtlistDestroy(pqueue->srtlist);
	free(pqueue);
} 


int PQueueEnqueue(pqueue_ty *pqueue, void *data)
{
	assert(NULL != pqueue);
	return (SrtlistIterIsEqual(SrtlistInsert(pqueue->srtlist, data),
									        SrtlistEnd(pqueue->srtlist)));
}


void PQueueDequeue(pqueue_ty *pqueue)
{
	assert(NULL != pqueue);
	SrtlistRemove(SrtlistPrev(SrtlistEnd(pqueue->srtlist)));
} 


void *PQueuePeek(const pqueue_ty *pqueue)
{
	assert(NULL != pqueue);
	return SrtlistGetData(SrtlistPrev(SrtlistEnd(pqueue->srtlist)));
}

size_t PQueueSize(const pqueue_ty *pqueue)
{
	assert(NULL != pqueue);
	return SrtlistSize(pqueue->srtlist);
}

int PQueueIsEmpty(const pqueue_ty *pqueue)
{
	assert(NULL != pqueue);
	return SrtlistIsEmpty(pqueue->srtlist);
}

void PQueueClear(pqueue_ty *pqueue)
{
	assert(NULL != pqueue);
	while(0 == SrtlistIsEmpty(pqueue->srtlist))
	{
		SrtlistRemove(SrtlistBegin(pqueue->srtlist));
	}
}


void *PQueueErase(pqueue_ty *pqueue, is_data_match_ty is_match, void *param)
{
	void *ret_value = NULL;
	assert(NULL != pqueue);
	ret_value = SrtlistGetData(SrtlistFindIf(SrtlistBegin(pqueue->srtlist),
								SrtlistEnd(pqueue->srtlist),is_match, param));
	
	SrtlistRemove(SrtlistFindIf(SrtlistBegin(pqueue->srtlist),
					SrtlistEnd(pqueue->srtlist),is_match, param));
					
	return ret_value;
}


























