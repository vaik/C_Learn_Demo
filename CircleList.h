#ifndef _CIRCLE_H_
#define _CIRCLE_H_

//采用数据封装的方式，防止主函数修改其中的属性值(有点点像面向对象中的私有属性)
typedef void CircleList;
typedef struct CircleListNode
{
	CircleListNode *next;
}CircleListNode;

CircleList* CircleList_Create();

void CircleList_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list,CircleListNode* node,int pos);

CircleListNode* CircleList_Get(CircleList* list,int pos);

CircleListNode* CircleList_Delete(CircleList* list,int pos);

CircleListNode* CircleList_DeleteNode(CircleList* list,CircleListNode* node);

CircleListNode* CircleList_Reset(CircleList* list);

CircleListNode* CircleList_Current(CircleList* list);

CircleListNode* CircleList_Next(CircleList* list);

#endif
