#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;
typedef int TElemType;
//
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*pBiTree,*pBiTNode;
//CreatBiTNode
pBiTNode CreateBiTNode(TElemType e,pBiTNode lchild,pBiTNode rchild)
{
	pBiTNode root=(pBiTNode)malloc(sizeof(BiTNode));
	if(root==NULL)
		return NULL;
	root->data=e;
	root->lchild=lchild;
	root->rchild=rchild;
	return root;
}
//DestroyBiTree
void DestroyBiTree(pBiTree root)
{
	if(root)
	{
		DestroyBiTree(root->lchild);
		DestroyBiTree(root->rchild);
		free(root);
	}
}
//AdBiTree
Status AdBiTree(pBiTNode root,char t,pBiTNode child)
{
	if(root==NULL)
		return ERROR;
	if(t=='l')
	{
		if(root->lchild==NULL)
			root->lchild=child;
		else
		{
			pBiTNode tmp=root->lchild;
			root->lchild=child;
			DestroyBiTree(tmp);
		}
	}
	else
	{
		if(root->rchild==NULL)
			root->rchild=child;
		else
		{

			pBiTNode tmp=root->rchild;
			root->rchild=child;
			DestroyBiTree(tmp);
		}
	}
	return OK;

}
//visit
void visit(TElemType e)
{
	printf("%d ",e);
}
//PreOrderTraverse
Status PreOrderTraverse(pBiTree root,void (*visit)(TElemType))
{
	if(root)
	{
		visit(root->data);
		PreOrderTraverse(root->lchild,visit);
		PreOrderTraverse(root->rchild,visit);
	}
}

//InOrderTraverse
Status InOrderTraverse(pBiTree root,void (*visit)(TElemType))
{
	if(root)
	{
		InOrderTraverse(root->lchild,visit);
		visit(root->data);
		InOrderTraverse(root->rchild,visit);
	}
}
//PostOrderTraverse
Status PostOrderTraverse(pBiTree root,void (*visit)(TElemType))
{
	if(root)
	{
		visit(root->data);
		PostOrderTraverse(root->lchild,visit);
		PostOrderTraverse(root->rchild,visit);
	}
}
int main()
{
	pBiTree root=CreateBiTNode(0,NULL,NULL);
	pBiTNode p3=CreateBiTNode(3,NULL,NULL);
	pBiTNode p4=CreateBiTNode(4,NULL,NULL);
	pBiTNode p5=CreateBiTNode(5,NULL,NULL);
	pBiTNode p6=CreateBiTNode(6,NULL,NULL);
	//pBiTNode p1=CreatBiTNode(1,p3,p4);
	//pBiTNode p2=CreatBiTNode(2,p5,p6);
	//AdBiTree(root,'l',p1);
	//AdBiTree(root,'r',p2);
	return 0;
}
