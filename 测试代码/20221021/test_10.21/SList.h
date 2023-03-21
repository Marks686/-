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
//βɾ
void SListPopBack(SLTNode** pphead);
//ͷɾ
void SListPopFront(SLTNode** pphead);
//����Ĳ���
SLTNode* SListFind(SLTNode* phead,SLTDateType x);
//ĳ��λ��ȥ����  ---- ��pos֮ǰ����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//��pos֮�����
void SListInsertAfter(SLTNode* pos, SLTDateType x);
//ĳ��λ��ȥɾ��---- ɾ��pos
void SListErase(SLTNode** pphead, SLTNode* pos);
