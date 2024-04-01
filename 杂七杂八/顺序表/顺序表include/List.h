#pragma once
#include<iostream>
#include <malloc.h>

#define MATHLIBRARY_API __declspec(dllexport)

using namespace std;
//typedef int ElemType;
typedef struct {
	//ElemType data[50];
	int data[50];
	int length;
}List;

void InitList(List*& L) {
	L = (List*)malloc(sizeof(List));
	L->length = 0;
}
void DestoryList(List*& L) {
	free(L);
}
bool ListEmpty(List* L) {
	return (L->length == 0);
}
int ListLength(List* L) {
	return L->length;
}
void OutList(List* L) {
	for (int i = 0; i < L->length; i++)
	{
		cout << L->data[i] << endl;
	}
}
void GetList(List* L, int n, int& m) {
	m = L->data[n-1];
}
int FindList(List* L, int e) {
	int n = 0;
	for (int i = 0; i < L->length&&L->data[i]!=e; i++)
	{
		if (i == L->length - 1 && L->data[i] != e) {
			return 0;
		}
		n = i;
	}
	return n + 1;
}
void InsertList(List* L,int n,int m) {
	for (int i =L->length ; i >n; i--)
	{
		L->data[i] = L->data[i - 1];
	}
	L->data[n] = m;
	L->length = L->length + 1;
}
void DeleteList(List* L, int n) {
	for (int i = n-1; i < L->length-1; i++)
	{
		L->data[i] = L->data[i + 1];
	}
	L->length = L->length - 1;
}