#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//#ifndef __SEQLIST_H__
//#define __SEQLIST_H__
//#endif

//��̬��˳���-->��С�ǹ̶���-->��֪��Ҫ��������ݣ�
#define N 10
//typedef int SLDataYype;//SLDataType��������//typedef���͵��ض���
//struct SeqList
//{
//	SLDataYype a[N];
//	int size;//�洢���ݵĸ���
//};

//��̬˳���
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;     //�洢���ݵĸ���
	int capacity; //�洢�ռ�Ĵ�С
}SL;

//��ʼ��
void SLInit(SL* psl);

//����
void SLDestory(SL* psl);

//˳���Ĵ�ӡ
void SLPrint(const SL* psl);

//β��
void SLPushBack(SL* psl, SLDataType x);

//ͷ��
void SLPushFront(SL* psl, SLDataType x);

//βɾ
void SLPopBack(SL* psl);

//ͷɾ
void SLPopFront(SL* psl);

// ����,û���ҵ�����-1
int SLFind(SL* psl, SLDataType x);

// ��posλ�ò���x
void SLInsert(SL* psl, size_t pos, SLDataType x);

// ɾ��posλ�õ�ֵ
void SLErase(SL* psl, size_t pos);

//�޸�
void SLModify(SL* psl, size_t pos,SLDataType x);




