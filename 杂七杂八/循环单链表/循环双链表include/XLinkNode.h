#pragma once
#include<iostream>
#include <malloc.h>

#define MATHLIBRARY_API __declspec(dllexport)

using namespace std;
typedef int ElemType;
typedef struct LNode {
	//ElemType data[50];
	int data;
	struct LNode* next;
}LinkNode;

void InitList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = L;
}
void DestoryList(LinkNode*& L) {
	LinkNode* p1 = L, * p2 = L->next;
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
bool ListEmpty(LinkNode* L) {
	return (L->next == L);
}
int ListLength(LinkNode* L) {
	int length = 0;
	LinkNode* p = L;
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
void OutList(LinkNode* L) {
	LinkNode* p = L->next;
	int size = 0;
	while (p != NULL)
	{
		cout << p->data << endl;
		size++;
		p = p->next;
		if (p == L)
		{
			break;
		}
	}
}
int GetList(LinkNode* L, int n) {
	int i = 0;
	LinkNode* p = L;
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
int FindList(LinkNode* L, int e) {
	int i = 0;
	LinkNode* p = L;
	while (p != NULL && p->data != e)
	{
		i++;
		p = p->next;
	}
	return i + 1;
}
bool InsertList(LinkNode* L, int n, int m) {
	int i = 0;
	LinkNode* p1 = L, * p2;
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
		p2 = (LinkNode*)malloc(sizeof(LinkNode));
		p2->data = m;
		p2->next = p1->next;
		p1->next = p2;
		return true;
	}
}
bool DeleteList(LinkNode* L, int n) {
	int i = 0;
	LinkNode* p1 = L, * p2;
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
		free(p2);
		return true;
	}
}
void CreateListR(LinkNode*& L, int a[], int n) {
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = L;
}
void CreateListF(LinkNode*& L, int a[], int n) {
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}