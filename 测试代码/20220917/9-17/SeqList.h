#pragma once
#include<stdio.h>
#include<stdlib.h>
//#ifndef __SEQLIST_H__
//#define __SEQLIST_H__
//#endif

//��̬��˳���-->��С�ǹ̶���-->��֪��Ҫ��������ݣ�
#define N 10
typedef int SLDataType;//SLDataType��������//typedef���͵��ض���
struct SeqList
{
	SLDataType a[N];
	int size;//�洢���ݵĸ���
};

//��̬˳���
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;     //�洢���ݵĸ���
	int capacity; //�洢�ռ�Ĵ�С
}SL;

//void SeqListInt(SL* sl);

//��ʼ��
void SLInit(SL* psl);

//����
void SLDestory(SL* psl);


