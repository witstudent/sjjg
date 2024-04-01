#pragma once
#include<iostream>
#include <malloc.h>

#define MATHLIBRARY_API __declspec(dllexport)

using namespace std;
typedef struct linknode{
	int data;
	struct linknode* next;
}LinkStNode;
void InitStack(LinkStNode*& s) {
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
void DestoryStack(LinkStNode*& s) {
	LinkStNode* p1 = s, * p2 = s->next;
	while (p2!=NULL)
	{
		free(p1);
		p1 = p2;
		p2 = p1->next;
	}
	free(p1);
}
bool StackEmpty(LinkStNode* s) {
	return(s->next==NULL);
}
bool Push(LinkStNode*& s, int e) {           //½øÕ»
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return true;
}
bool Pop(LinkStNode* s, int& e) {            //³öÕ»
	LinkStNode* p;
	if (s->next==NULL)
	{
		return false;
	}
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}
bool GetTop(LinkStNode* s, int& e) {
	if (s->next==NULL)
	{
		return false;
	}
	e = s->next->data;
	return true;
}