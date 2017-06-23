#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10
#define INCREMENT_SIZE 5

typedef int Status;
typedef int Elemtype;

//structure for memory
typedef struct
{
	Elemtype *elem;//base pointer
	int length;
	int size;
}SqList,*pSqList;
typedef  SqList Stack;
typedef  pSqList pStack;
// Initalize
Status InitList(SqList *L)
{
	L->elem=(Elemtype *)malloc(INIT_SIZE*sizeof(Elemtype));
	if(L->elem==NULL)
		return ERROR;
	L->length=0;
	L->size=INIT_SIZE;
	return OK;
}

//destroy a SqList
Status DestroyList(SqList *L)
{
	free(L->elem);
	L->length=0;
	L->size=0;
	return OK;
}
//Clear a SqList
Status ClearList(SqList* L)
{
	L->length=0;
	return OK;
}
//IsEmpty
Status isEmpty(const SqList *L)
{
	if(L->length==0)
		return TRUE;
	else
		return FALSE;
}
//getLength
Status getLength(const SqList *L)
{
	return L->length;
}
//Access a element by index
Status GetElem(const SqList *L,int i,Elemtype *e)
{//index start from 1
	if(i<1||i>L->length)
		return ERROR;
	*e=L->elem[i-1];
	return OK;
}
//Compare two elements
Status compare(Elemtype e1,Elemtype e2)
{
	if(e1==e2)
		return 0;
	else if(e1<e2)
		return -1;
	else
		return 1;
}
//Search for element
Status FindElem(const SqList *L,Elemtype e,Status (*compare)(Elemtype,Elemtype))
{
	int i;
	for(i=0;i<L->length;i++)
	{
		if(compare(L->elem[i],e)==0)
			return i+1;
	}
	if(i>=L->length)
		return ERROR;
}
//PreElem
Status PreElem(const SqList *L,Elemtype cur_e,Elemtype *pre_e)
{
	int s;
	s=FindElem(L,cur_e,compare);
	if(s==0||s==1)
		return ERROR;
	else
	{
		*pre_e=L->elem[s-2];
		return OK;
	}
}
//NextElem
Status NextElem(const SqList *L,Elemtype cur_e,Elemtype *next_e)
{
	int s;
	s=FindElem(L,cur_e,compare);
	if(s==0||s==L->length)
		return ERROR;
	else
	{
		*next_e=L->elem[s+1];
		return OK;
	}
}
//InsertElem
Status InsertElem(SqList *L,int i,Elemtype e)
{
	Elemtype *new;
	if(i<1||i>L->length+1)
		return ERROR;
	if(L->length>=L->size)
	{
		new=(Elemtype*)realloc(L->elem,(L->size+INCREMENT_SIZE)*sizeof(Elemtype));
		if(new==NULL)
			return ERROR;
		L->elem=new;
		L->size+=INCREMENT_SIZE;
	}
	Elemtype *p=&(L->elem[i-1]);
	Elemtype *q=&(L->elem[L->length-1]);
	for(;q>=p;q--)
		*(q+1)=*q;
	*p=e;
	++L->length;
	return OK;
}
//DeleteElem
Status DeleteElem(SqList *L,int i,Elemtype *e)
{
	if(i<1||i>L->length)
		return ERROR;
	Elemtype *p=&L->elem[i-1];
	*e=*p;
	for(;p<&L->elem[L->length];p++)
		*p=*(p+1);
	--L->length;
	return OK;
}
//visit
void visit(Elemtype e)
{
	printf("%d ",e);
}
//TraverseList
Status TraverseList(const SqList *L,void (* visit)(Elemtype))
{
	int i=0;
	for(;i<L->length;i++)
		visit(L->elem[i]);
	return OK;
}
void Error(char *mesg)
{
	printf("%s has failed!\n",mesg);
	exit(1);
}
//InitStack
void InitStack(pStack S)
{
	InitList(S);
}
//Destroy
void DestroyStack(pStack S)
{
	DestroyList(S);
}
//GetTop
Status GetTop(pStack S,Elemtype *e)
{
	if(isEmpty(S))
		return ERROR;
	*e=S->elem[S->length-1];
	return OK;
}
//Pop
Status Pop(pStack S,Elemtype *e)
{
	if(isEmpty(S))
		return ERROR;
	DeleteElem(S,S->length,e);
	return OK;
}
//Push
Status Push(pStack S,Elemtype e)
{
	InsertElem(S,S->length+1,e);
}
int main()
{	Stack S;
	InitStack(&S);
	int i=1;
	for(;i<11;i++)
		Push(&S,i);
	Elemtype e;
	GetTop(&S,&e);
	printf("The TopElem of the Stack is %d\n",e);
	i=1;
	for(;i<11;i++)
	{
		Pop(&S,&e);
		printf("%d ",e);
	}
	printf("\n");
	DestroyStack(&S);
	return 0;
}

