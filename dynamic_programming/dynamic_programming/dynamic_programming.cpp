// dynamic_programming.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

// ����ɽ���ﹲ��a,b,c,d ,e��5���������5�ֱ����
// ���ǵ������ֱ���2,2,6,5,4�����ǵļ�ֵ�ֱ���6,3,5,4,6��
// ���ڸ��������Ϊ10�ı���, ��ôװ���������Բ��ܴ������ĲƸ���

int weight[5] = { 2, 2, 6, 5, 4 };
int value[5] = { 6, 3, 5, 4, 6 };

// knap(n, w) = MAX(knap(n-1, total_weight), knap(n-1, total_weight-w[i])+v[i])

int knap_recursive(int n, int w) /*ǰn�������������w*/
{
	if (w <= 0) return 0;
	
	if (n == 0)
	{
		if (weight[0] <= w)
			return value[0];
		return 0;
	}

	unsigned int r1 = knap_recursive(n - 1, w);
	unsigned int r2 = knap_recursive(n - 1, w - weight[n]) + value[n];

	if (r2 > r1)
	{
		return r2;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int max_value = knap_recursive(4, 10);
	return 0;
}

