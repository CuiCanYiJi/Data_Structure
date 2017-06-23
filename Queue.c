#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

typedef struct Node
{
	ElemType data;
	struct Node * next;
}Node,*pNode;
typedef struct Queue
{
	pNode head;
	pNode tail;
	int length;
}Queue,*pQueue;

//InitQueue
void InitQueue(pQueue Q)
{
	Q->head=Q->tail=NULL;
	Q->length=0;
}
//DestroyQueue
void DestroyQueue(pQueue Q)
{
	if(Q->head)
	{
		pNode p=Q->head;
		pNode pnext;
		while(p)
		{
			pnext=p->next;
			free(p);
			p=pnext;
		}
	}
}
//ClearQueue
void ClearQueue(pQueue Q)
{
	DestroyQueue(Q);
	InitQueue(Q);
}
//isEmpty
Status isEmpty(pQueue Q)
{
	if(Q->length==0)
		return TRUE;
	else
		return FALSE;
}
//EnQueue
Status EnQueue(pQueue Q,ElemType e)
{
	pNode pNew=(pNode)malloc(sizeof(Node));
	if(pNew==NULL)
		exit(-2);
	pNew->data=e;
	pNew->next=NULL;

	if(isEmpty(Q))
		Q->head=Q->tail=pNew;
	else
	{
		Q->tail->next=pNew;
		Q->tail=pNew;
	}
	++Q->length;
	return OK;
}
//DeQueue
Status DeQueue(pQueue Q,ElemType *e)
{
	if(isEmpty(Q))
		return ERROR;
	pNode p=Q->head;
	*e=p->data;
	if(Q->length==1)
	{
		free(p);
		Q->head=Q->tail=NULL;
	}
	else
	{
		Q->head=p->next;
		free(p);
	}
	--Q->length;
}
int main()
{
	Queue Q;
	InitQueue(&Q);
	int i=1;
	for(;i<11;i++)
		EnQueue(&Q,i);
	ElemType e;
	i=1;
	for(;i<11;i++)
	{
		DeQueue(&Q,&e);
		printf("%d ",e);
	}
	printf("\n");
	DestroyQueue(&Q);
	return 0;
}
