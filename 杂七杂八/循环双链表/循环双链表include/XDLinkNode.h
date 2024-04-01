#pragma once
#include<iostream>
#include <malloc.h>

#define MATHLIBRARY_API __declspec(dllexport)

using namespace std;
typedef int ElemType;
typedef struct DNode {
	//ElemType data[50];
	int data;
	struct DNode* prior;
	struct DNode* next;
}DLinkNode;

void InitList(DLinkNode*& L) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = L;
}
void CreateListF(DLinkNode*& L, int a[], int n) {
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = L;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
		{
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
	}
}
void CreateListR(DLinkNode*& L, int a[], int n) {
	DLinkNode* s, * r;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = L;
}
void DestoryList(DLinkNode*& L) {
	DLinkNode* p1 = L, * p2 = L->next;
	while (p2 != NULL)
	{
		free(p1);
		p1 = p2;
		p2 = p1->next;
		if (p2 == L)
		{
			break;
		}
	}
	free(p1);
}
bool ListEmpty(DLinkNode* L) {
	return (L->next == NULL);
}
int ListLength(DLinkNode* L) {
	int length = 0;
	DLinkNode* p = L;
	while (p != NULL)       //      p->next!=NULL      
	{
		length++;
		p = p->next;
		if (p == L)
		{
			break;
		}
	}
	return length;
}
void OutList(DLinkNode* L) {
	DLinkNode* p = L->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
		if (p == L)
		{
			break;
		}
	}
}
int GetList(DLinkNode* L, int n) {
	int i = 0;
	DLinkNode* p = L;
	while (i < n && p != NULL)
	{
		i++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else {
		return p->data;
	}
}
int FindList(DLinkNode* L, int e) {
	int i = 0;
	DLinkNode* p = L;
	while (p != NULL && p->data != e)
	{
		i++;
		p = p->next;
	}
	return i + 1;
}
bool InsertList(DLinkNode* L, int n, int m) {
	int i = 0;
	DLinkNode* p1 = L, * p2;
	while (i < n - 1 && p1 != NULL)
	{
		i++;
		p1 = p1->next;
	}
	if (p1 == NULL) {
		return false;
	}
	else
	{
		p2 = (DLinkNode*)malloc(sizeof(DLinkNode));
		p2->data = m;
		p2->next = p1->next;
		p1->next->prior = p2;
		p2->prior = p1;
		p1->next = p2;
		return true;
	}
}
bool DeleteList(DLinkNode* L, int n) {
	int i = 0;
	DLinkNode* p1 = L, * p2;
	while (i < n - 1 && p1 != NULL)
	{
		i++;
		p1 = p1->next;
	}
	if (p1 == NULL) {
		return false;
	}
	else
	{
		p2 = p1->next;
		if (p2 == NULL) {
			return false;
		}
		p1->next = p2->next;
		p2->next->prior = p1;
		free(p2);
		return true;
	}
}