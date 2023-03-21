#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"

void SListPrint(SLTNode* phead)
{
	//�����п����ǿյģ����Բ��ܶ���
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;//next�������һ�����ĵ�ַ
	}
	printf("NULL\n");
}

SLTNode* BuySLTNode(SLTDateType x)
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

void SListPushFront(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPushBack(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);
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

void SListPopFront(SLTNode** pphead)
{
	assert(pphead);

	//����ļ��
	/*if (*pphead == NULL)
	{
		return;
	}*/

	//�������
	assert(*pphead != NULL);
	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
	del = NULL;
}

void SListPopBack(SLTNode** pphead)
{
	assert(pphead);

	//����ļ��
/*if (*pphead == NULL)
{
	return;
}*/

//�������
	assert(*pphead != NULL);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//��β
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		prev->next = NULL;
		free(tail);
		tail = NULL;
	}
}

void SListPopBack2(SLTNode** pphead)
{
	assert(pphead);

	//����ļ��
/*if (*pphead == NULL)
{
	return;
}*/

//�������
	assert(*pphead != NULL);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//��β
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListDestory(SLTNode** pphead)
{
	assert(pphead);

	SLTNode* cur = *pphead;
	while (cur != NULL)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	*pphead = NULL;
}

SLTNode* SListFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


//��pos֮ǰ����
void SListInsert(SLTNode** pphead,SLTNode* pos, SLTDateType x)
{
	assert(pphead);
	assert(pos);

	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;

			//������飬pos����������
			assert(prev);
		}

		SLTNode* newnode = BuySLTNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SListInsertAfter(SLTNode* pos, SLTDateType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
			assert(prev);
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}