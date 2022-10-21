#pragma once
#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data; 
	struct SListNode* next;
}SLTNode;

//����malloc����ָ��
SLTNode* BuySLTNode(SLTDateType x);
//�����ӡ
void SListPrint(SLTNode* phead);   
//��������
void SListDestory(SLTNode* phead);
//�����ͷ������
void SListPushFront(SLTNode** pphead, SLTDateType x);
//β��
void SListPushBack(SLTNode** pphead, SLTDateType x);