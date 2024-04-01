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
	q->front = q->rear = 0;
}
void DestroyQueue(SqQueue*& q) {
	free(q);
}
bool QueueEmpty(SqQueue* q) {
	return(q->front == q->rear);
}
bool enQueue(SqQueue*& q, int e) {         //╫Ь╤сап
	if ((q->rear+1)% 50==q->front)
	{
		return false;
	}
	q->rear = (q->rear + 1) % 50;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, int& e) {
	if (q->front == q->rear)
	{
		return false;
	}
	q->front = (q->front + 1) % 50;
	e = q->data[q->front];
	return true;
}