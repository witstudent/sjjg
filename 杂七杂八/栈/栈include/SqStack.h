#pragma once
#pragma once
#include<iostream>
#include <malloc.h>

#define MATHLIBRARY_API __declspec(dllexport)

using namespace std;
//typedef int ElemType;
typedef struct {
	//ElemType data[50];
	int data[50];
	int top;
}SqStack;
void InitStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
void DestoryStack(SqStack*& s) {
	free(s);
}
bool StackEmpty(SqStack* s) {
	return(s->top == -1);
}
bool Push(SqStack*& s, int e) {           //½øÕ»
	if (s->top==50-1)
	{
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack* s, int& e) {            //³öÕ»
	if (s->top==-1)
	{
		return false;
	}
	e = s->data[s->top];
	e = s->top--;
	return true;
}
bool GetTop(SqStack* s, int& e) {
	if (s->top == -1)
	{
		return false;
	}
	e = s->data[s->top];
	return true;
}