#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

/* 线性表的单链表存储结构 */
typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;

typedef struct Node *LinkList;  /* 定义LinkList */

/* 初始条件：顺序线性表L已存在，1<=i<=ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while(p && j<i){
		p=p->next;
		++j;
	}
	if(!p || j>i)
		return ERROR;
	*e = p->data;
	return OK;
}

/* 初始条件，顺序线性表L已存在，1<=i<=ListLength(L) */
/* 操作结果：在L中的第i位置插入新的数据元素e,L的长度加1 */
Status ListIntert(LinkList *L,int i,ElemType e)
{
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)
		return ERROR;
	s = (LinkList) malloc(sizeof(Node)); /* 生成新结点（c标准函数） */
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	return OK;
	
}

/* 初始条件，顺序线性表L已存在，1<=i<=ListLength(L) */
/* 操作结果：在L中的第i位置插入新的数据元素e,L的长度加1 */
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p,q;
	p = *L;
	j=1;
	while ( p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q); /* 让系统回收此结点，释放内存 */
	return OK;
}

/* 随机生成n个元素的值，建立带表头结点的单链线性表L(头插法） */
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));/* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

/* 随机生成n个元素的值，建立带表头结点的单链线性表L(尾插法） */
void CreateListTail(LinkList *L,int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->next = p;
		r=p;
	}
	r->next = NULL;
}

/* 初始条件，顺序线性表L已存在，操作结果：将L重置为空表 */
Status ClearList(LinkList *L)
{
	LinkList p,q;
	p=(*L)->next;
	while(p){
		q=p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

int main(void){
	LinkList L,p;
	ElemType e;
	int i=10;
	CreateListHead(&L,10);
	p = L->next;
	while(p){
		printf("The %d ElemType is %d\n",i,p->data);
		p = p->next;
		--i;
	}
	ListIntert(&L,10,3);
	GetElem(L,11,&e);
	printf("The 11 ElemType is %d\n",e);
	ClearList(&L);
	if(L->next==NULL){
		printf("The LinkList is empty\n");
	}
	CreateListTail(&L,10);
	p=L->next;
	i=1;
	while(p){
		printf("The %d ElemType is %d\n",i,p->data);
		p = p->next;
		++i;
	}
	return 0;
}