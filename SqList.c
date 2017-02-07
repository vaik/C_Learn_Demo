#include <stdio.h>
#include <stdlib.h>

//常量定义
#define MAXSIZE 20 //存储空间初分配量
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//数据类型定义
typedef int ElemType; // ElemType类型根据实际情况而定，这里假设为int
typedef struct{
	ElemType data[MAXSIZE]; // 数组存储数据元素，最大值为MAXSIZE
	int length; //线性表当前长度
}SqList;
typedef int Status; //Status 是函数的类型，其值是函数结果的状态代码，如OK等


//线性表操作定义

/*
	获取元素：GetElem
	初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
	操作结果:用e返回L中第i个数据元素的值
*/
Status GetElem(SqList L,int i,ElemType *e){
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i-1];
	return OK;
}

/* 
	初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
	操作结果：在L中第i个位置之前插入新的数据元素e,L的长度加1
 */
 Status ListInsert(SqList *L,int i,ElemType e)
 {
	int k;
	if(L->length==MAXSIZE) //顺序线性表已经满
		return ERROR;
	if(i<1 || i>L->length+1)//当i不在范围内时
		return ERROR;
	if(i<=L->length){
		for(k=L->length-1;k>=i-1;k--)//将要插入位置后数据元素向位移动一位
			L->data[k+1] = L->data[k];
	}
	L->data[i-1]=e;//将新元素插入
	L->length++;
	return OK;
 }

 /* 
	初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
	操作结果：在L中第i个位置删除数据元素e,L的长度减1
 */
 Status ListDelete(SqList *L,int i,ElemType *e){
	int k;
	if(L->length==0)//线性表为空
		return ERROR;
	if(i<1 || i>L->length)//当i不在范围内时
		return ERROR;
	*e=L->data[i-1];
	if(i<=L->length){
		for(k=L->length-1;k>=i;k--)
			L->data[k-1]=L->data[k];
	}
	L->length--;
	return OK;
 }

int main(void){
	SqList L = {{0},0};
	ElemType e;
	ElemType el;
	if(ListInsert(&L,1,1)==ERROR){
		printf("ListInsert error!\n");
	}else{
		if(GetElem(L,1,&e)==ERROR){
			printf("GetElem error!\n");
		}else{
			printf("The first emlement in SqList is %d\n",e);
		}
		if(ListDelete(&L,1,&el)==ERROR){
			printf("ListDelete error!\n");
		}else{
			printf("SqList lenght is %d\n el is %d \n",L.length,el);
		}
	} 

	return 0;
}