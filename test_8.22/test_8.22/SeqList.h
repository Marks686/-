#pragma once
#include<stdio.h>
#include<stdlib.h>

//#ifndef __SEQLIST_H__
//#endif 


//��̬��˳��� -- ��֪��Ҫ�洢�������ݣ�
#define N 10
//typedef int SLDataType;
// struct SeqList
//{
//	SLDataType a[N];//��������
//	int size;//�洢���ݵĸ���
//};


//��̬˳���
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;//��̬���ٵ�����
	int size;    //�洢���ݵĸ���
	int capacity;//�洢�ռ�Ĵ�С
}SL;

//void SqeListInit(SL sl);
void SLInit(SL sl);
void SLDestory(SL sl);