#pragma once
#include<iostream>
#include <malloc.h>

#define MATHLIBRARY_API __declspec(dllexport)

using namespace std;
typedef struct qnode{
	int data;
	struct qnode* next;
}DataNode;
typedef struct {
	DataNode* front;
	DataNode* rear;
}LinkQuNode;
void InitQueue(LinkQuNode*& q) {
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
void DestroyQueue(LinkQuNode*& q) {
	DataNode* p1 = q->front, * p2;
	if (p1!=NULL)
	{
		p2 = p1->next;
		while (p2!=NULL)
		{
			free(p1);
			p1 = p2;
			p2 = p2->next;
		}
	}
	free(p1);
}
bool QueueEmpty(LinkQuNode* q) {
	return(q->rear==NULL);
}
bool enQueue(LinkQuNode*& q, int e) {         //╫Ь╤сап
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)
	{
		q->front = q->rear = p;
	}
	else {
		q->rear->next = p;
		q->rear = p;
	}
	return true;
}
bool deQueue(LinkQuNode *& q, int& e) {            
	DataNode* p;
	if (q->rear=NULL)
	{
		return false;
	}
	p = q->front;
	if (q->front == q->rear)
	{
		q->front = q->rear = NULL;
	}
	else {
		q->front = q->front->next;
		e = p->data;
	}
	free(p);
	return true;
}