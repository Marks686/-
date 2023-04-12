#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//��������
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;

		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}

			a[end + gap] = tmp;
		}
	}
}


oid Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



void BubbleSort(int* a, int n)
{
	assert(a);

	int end = n;
	while (end > 0)
	{
		/*
		��һ����ǣ�����м�û�з�������
		˵��ǰ���ֵ���Ⱥ����С
		�������������ģ���õ�����£�
		����ʱ�临�ӶȾ�ΪN
		*/
		int flag = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}

		--end;
	}
}

void TestBubbleSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// ����ȡ�з���������ȡһ���м�ֵ

int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else // begin >= mid
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}

}

int PartSort1(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int start = begin;
	/*
	����Ҫ���ұ��ߣ����������ߣ�
	�������һ��������Ҳ�������
	��׼ֵ�ģ��ᵼ��begin == end
	�������������ұ߻�û���ߣ�����
	�����ֵһ�����ڻ�׼ֵ����󽻻�
	�ͻ�����⣬����һ��Ҫ���ұ��ߣ�
	��ʹ���һ���Ҳ���С�ڻ�׼ֵ�ģ�
	����������������ߴ�ʱ��û�ߣ�
	һ���Ȼ�׼ֵС����󽻻��϶�û������
	*/
	while (begin < end)
	{
		// end ��С
		while (begin < end && a[end] >= key)
			--end;

		// begin�Ҵ�
		while (begin < end && a[begin] <= key)
			++begin;

		Swap(&a[begin], &a[end]);
	}
	//���Ľ���һ��Ҫ��֤a[begin] < a[start], ����Ҫ���ұ���
	Swap(&a[begin], &a[start]);
	return begin;
}

int PartSort2(int* a, int begin, int end)
{
	//begin�ǿ�
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
			--end;

		// end��begin����ӣ�end�ͱ�����µĿӡ�
		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
			++begin;

		// end��begin����ӣ�begin�ͱ�����µĿӡ�
		a[end] = a[begin];
	}

	a[begin] = key;

	return begin;
}


/*
ǰ��ָ�뷨
*/
int PartSort3(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int prev = begin;
	int cur = begin + 1;

	while (cur <= end)
	{
		// cur��С����С����ǰ�����������
		if (a[cur] < key && ++prev != cur)
			Swap(&a[cur], &a[prev]);

		++cur;
	}

	Swap(&a[begin], &a[prev]);

	return prev;
}

// []
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int div = PartSort3(a, left, right);
		//[left, div-1]
		//[div+1, right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}
//��ջģ��ݹ飬�ö���Ҳ����ʵ��
void QuickSortR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st, 10);
	//���������
	if (left < right)
	{
		StackPush(&st, right);
		StackPush(&st, left);
	}
	//ջ��Ϊ�գ�˵������û���������
	while (StackEmpty(&st) != 0)
	{
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);
		//���ŵ�������
		int div = PartSort1(a, left, right);
		// [left div-1]
		// �Ѵ���1���������������ջ
		if (left < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, left);
		}

		// [div+1, right]
		if (div + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, div + 1);
		}
	}

}

void TestQuickSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	QuickSortR(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}