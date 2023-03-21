#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);
	//1����
	//2���ǿ�
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPopBack(SLTNode** pphead)
{
	assert(pphead);

	//����ļ��
	if (*pphead == NULL)
	{
		return;
	}

	//�����ļ��
	//assert(*pphead != NULL);

	//1.һ���ڵ�
	//2.����ڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//��β
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL);
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(pphead);

	//����ļ��
	if (*pphead == NULL)
	{
		return;
	}

	//�����ļ��
	//assert(*pphead != NULL);

	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;

	free(del);
	del = NULL;
}


void SListDestory(SLTNode** pphead)
{
	assert(pphead);

	SLTNode* cur = *pphead;
	//while(cur != NULL)
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;

}


SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SListInsetrt(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);

	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next; 
	}

	SLTNode* newnode = BuySLTNode(x);
	prev->next = pos;
	newnode->next = pos;
}