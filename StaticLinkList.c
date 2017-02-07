#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000

typedef int Status;
typedef int ElemType;

/* 线性表的静态表存储结构 */
typedef struct
{
	ElemType data;
	int cur;
} Component,StaticLinkList[MAXSIZE];

/* 将一维数组space中各分量链成一备用链表 */
/* space[0].cur为头指针，“0”表示空指针 */
Status InitList(StaticLinkList space)
{
	int i;
	for(i=0;i<MAXSIZE-1;i++)
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0;
	
	return OK;
}

/* 返回静态单链表的元素长度 */
int ListLength(StaticLinkList space)
{
	int i=0;
	int p = space[MAXSIZE-1].cur;
	while(p){
		p = space[p].cur;
		i++;
	}
	return i;
}

/* 初始条件：静态链表space 已存在 */
/* 操作结果：返回静态链表space的第i个元素e */
Status GetElem(StaticLinkList space,int i, ElemType *e)
{
	int j,k;
	k = MAXSIZE - 1;
	if( i < 1 || i > ListLength(space)+1)
		return ERROR;
	for(j=1;j<=i;j++)
		k=space[k].cur;
	*e = space[k].data;
	return OK;
}

/* 若备用空间链表非空，则返回分配的结点下标，否则返回0 */
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur; //当前数组第一个元素的cur值，就是要返回的第一个备用空间的下标
	if(space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}

/*  将下标为k的空闲结点回收到备用链表 */
void Free_SLL(StaticLinkList space,int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

/* 在L中第i个元素之前插入新的数据元素e */
Status ListInsert(StaticLinkList space,int i,ElemType e)
{
	int j,k,l;
	k = MAXSIZE - 1;
	if( i < 1 || i > ListLength(space)+1)
		return ERROR;
	j = Malloc_SLL(space);
	if(j)
	{
		space[j].data = e;
		for(l=1;l<=i-1;l++)	
			k = space[k].cur;
		space[j].cur = space[k].cur;
		space[k].cur = j;
		return OK;
	}
	return ERROR;
}

/* 删除L中第i个元素e */
Status ListDelete(StaticLinkList space,int i)
{
	int j,k;
	if( i < 1 || i > ListLength(space)+1)
		return ERROR;
	k = MAXSIZE -1;
	for(j=1;j<=i-1;j++)
		k =space[k].cur;
	j = space[k].cur;
	space[k].cur =space[j].cur;
	Free_SLL(space,j);
	return OK;
}

int main(void)
{
	StaticLinkList space;
	ElemType e;
	InitList(space);
	printf("space's length is %d\n",ListLength(space));
	ListInsert(space,1,5);
	printf("space's length is %d\n",ListLength(space));
	printf("space[MAXSIZE-1].cur is %d\n",space[MAXSIZE-1].cur);
	printf("The first elem of space is %d\n",space[space[MAXSIZE-1].cur].data);
	GetElem(space,1,&e);
	printf("The 1 ElemType is %d\n",e);
	ListDelete(space,1);
	printf("space's length is %d\n",ListLength(space));
	return 0;
}