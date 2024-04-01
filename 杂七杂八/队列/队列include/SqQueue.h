#pragma once
#include<iostream>
#include <malloc.h>

#define MATHLIBRARY_API __declspec(dllexport)

using namespace std;
typedef struct {
	int data[50];
	int front, rear;
}SqQueue;
void InitQueue(SqQueue*& q) {
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}
void DestroyQueue(SqQueue*& q) {
	free(q);
}
bool QueueEmpty(SqQueue* q) {
	return(q->front == q->rear);
}
bool enQueue(SqQueue*& q, int e) {         //╫Ь╤сап
	if (q->rear==49)
	{
		return false;
	}
	q->rear++;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, int& e) {
	if (q->front==q->rear)
	{
		return false;
	}
	q->front++;
	e = q->data[q->front];
	return true;
}