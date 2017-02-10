#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct Node 
{
	ElemType data;
	struct Node *next;
} Node;

typedef struct Node *CirularLinkList; 

/* 功能: */

/* 初始条件：顺序线性表L已存在，1<=i<=ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(CirularLinkList L,int i,ElemType *e)
{
	int j;
	if(L == L->next)//为空时返回ERROR
		return ERROR;
	CirularLinkList p;
	p = L->next;
	j=1;
	while(p == L || j<i){
		p = p->next;
		++j;
	}
	if(p==L || j>i)//未找到返回ERROR
		return ERROR;
	*e = p->data;
	return OK;
}

/* 初始条件，顺序线性表L已存在，1<=i<=ListLength(L) */
/* 操作结果：在L中的第i位置插入新的数据元素e,L的长度加1 */
Status ListIntert(CirularLinkList *L,int i,ElemType e)
{
	int j;
	if(*L == (*L)->next)
		return ERROR;
	CirularLinkList p,q;
	p = *L;
	j=1;
	while(p == *L || j<i){
		p = p->next;
		++j;
	}
	if(p== *L || j>i)//未找到返回ERROR
		return ERROR;
	q = (CirularLinkList)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	
	return OK;
}

/* 初始条件，顺序线性表L已存在，1<=i<=ListLength(L) */
/* 操作结果：在L中的第i位置插入新的数据元素e,L的长度加1 */
Status ListDelete(CirularLinkList *L, int i, ElemType *e)
{
	int j;
	if(*L == (*L)->next)//为空时返回ERROR
		return ERROR;
	CirularLinkList p,q;
	p = *L;
	j=1;
	while(p == *L || j<i){
		p = p->next;
		++j;
	}
	if(p == *L || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q); /* 让系统回收此结点，释放内存 */
	return OK;
}

/* 随机生成n个元素的值，建立带表头结点的单链线性表L(头插法） */
void CreateListHead(CirularLinkList *L, int n)
{
	CirularLinkList p;
	int i;
	srand(time(0));/* 初始化随机数种子 */
	*L = (CirularLinkList)malloc(sizeof(Node));
	(*L)->next = *L;
	for(i=0;i<n;i++)
	{
		p = (CirularLinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

/* 随机生成n个元素的值，建立带表头结点的单链线性表L(尾插法） */
void CreateListTail(CirularLinkList *L,int n)
{
	CirularLinkList p;
	int i;
	srand(time(0));/* 初始化随机数种子 */
	*L = (CirularLinkList)malloc(sizeof(Node));
	(*L)->next = *L;
	for(i=0;i<n;i++)
	{
		p = (CirularLinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}