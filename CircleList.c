#include <stdio.h>
#include <malloc.h>
#include "CircleList.h"

typedef struct //定义结点
{
	CircleListNode header;
	CircleListNode* slider; //游标
	int len;
}TCircleList;

struct value //定义数据结构体类型
{
	CircleListNode header;//指针域
	int v;//数据域
};

//创建
CircleList * CircleList_Create()
{
	TCircleList* list = (TCircleList*)malloc(sizeof(TCircleList));
	if(NULL != list)
	{
		list->slider = NULL;
		list->header.next = NULL;
		list->len = 0;
	}
	return list;
}

//销毁
void CircleList_Destroy(CircleList* list)
{
	free(list);
}

//清空
void CircleList_Clear(CircleList* list)
{
	TCircleList* slist = (TCircleList*)list;
	if(NULL != slist)
	{
		slist->len = 0;
		slist->header.next = NULL;
		slist->slider = NULL;
	}
}

//获得长度
int CircleList_Length(CircleList* list)
{
	TCircleList* slist =(TCircleList*)list;
	int len = -1;
	if(NULL != slist)
	{
		len = sList->len;
	}
	return len;
}

//插入
int CircleList_Insert(CircleList* list,CircleListNode* node,int pos)
{
	TCircleList* slist = (TCircleList*)list;
	int i = 0;
	int ret =0;
	slist->len;
	if((NULL != slist) && (pos>=0) && (NULL != node))
	{
		CircleListNode *current = (CircleLisstNode*)slist;
		for(i=0;i<pos && current->next != NULL;i++)
		{
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
		if(slist->len == 0)
		{
			slist->slider = node;
		}
		++(slist->len);
		if(current == (CircleListNode*) slist)
		{
			CircleLisstNode* last = CircleList_Get(slist,slist->len -1);
			last->next = current->next;
		}
		ret = 1;
	}
	return ret;
}

//获得结点
CircleListNode* CircleList_Get(CircleList* list int pos)
{
	TCircleList* slist = (TCircleList*) list;
	CircleLisstNode* resNode = NULL;
	int i = 0;
	if((NULL != slist) && (pos >= 0))
	{
		CircleListNode* current = (CircleLisstNode*)slist;
		for(i=0; i < pos; i++)
		{
			//i=0时，current为头结点,current->next为真正的第一个结点
			current = current->next;
		}
		resNode = current->next;
	}
	return resNode;
}

//删除
CircleListNode* CircleList_Delete(CircleList* list,int pos)
{
	TCircleList* slist = (TCircleList*) list;
	int i = 0;
	CircleListNode* resNode = NULL;
	CircleListNode* first = slist->header.next;
	CircleListNode* last = (CircleLisstNode*)CircleListNode*)CircleList_Get(list,slist->len-1);
	if((NULL != slist) && (pos >=0) && (pos < slist->len))
	{
		CircleListNode* current = (CircleLisstNode*)slist;
		for(i=0;i<pos;i++)
		{
			//i=0时,current头结点,current->next为真正的第一个结点
			current = current->next;
		}
		resnode = current->next;
		if(first == resnode)
		{
			slist->header.next = first->next;
			last->next = first->next;
		}
		
		if(slist->slider == resnode)
		{
			sList->slider = resnode->next;
		}
		
		if(slist->len == 0)
		{
			slist->header.next = NULL;
			slist->slider = NULL;
		}
	}
	slist->len--;
	return resnode;
}

//根据结点来删除
CircleListNode* CircleList_DeteteNode(CircleList* list,CircleListNode* node)
{
	TCircleList* slist = (TCircleList*)list;
	CircleListNode* resnode = NULL;
	int i=0;
	if(NULL != slist)
	{
		CircleListNode* current =(CircleListNode*)slist;
		for(i=0;i<slist->len;i++)
		{
			if(node == current->next)
			{
				resnode = current->next;
				break;
			}
			current = current->next;
		}
		if(NULL!=resnode)
		{
			CircleList_Delete(slist,i);
		}
	}
	return resnode;
}

//将游标重置回第一个元素
CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList* slist = (TCircleList*) list;
	CircleListNode* ret = NULL;
	if(slist != NULL)
	{
		slist->slider = slist->header.next;
		ret = slist->slider;
	}
	return ret;
}

//获得当前游标下的结点
CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList* slist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	slist->len;
	slist->header;
	slist->slider;
	if(slist != NULL)
	{
		ret = slist
	}
	return ret;
}

//将游标移到下一个结点并获得当前移动前的结点
CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList* slist = (TCircleList*) list;
	CircleListNode* ret = NULL;
	if((slist != NULL) && (slist->slider != NULL))
	{
		ret = slist->slider;
		slist->slider = ret->next;
	}
	return ret;
	
}