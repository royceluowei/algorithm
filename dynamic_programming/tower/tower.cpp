// tower.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//�������Ӷ���������ÿһ���ڵ����ѡ�����»����������ߣ�һֱ�ߵ��ײ㣬Ҫ���ҳ�һ��·����ʹ��·���ϵ�����֮�����.
int m[5][5] =
{
	9,	0,	0,	0,	0,
	12, 15,	0,	0,	0,
	10, 6,	8,	0,	0,
	2,	18, 9,	5,	0,
	19, 7,	10, 4,	16
};
#define MAX(a, b) (a > b ? a : b)

// d(i, j):��(i, k)���ײ�����·��
// d(i, j) = MAX(d(i+1, j-1),  d(i+1, j), d(i+1, j+1))	+	m[i][j] 

int tower_recursive(int i, int j)
{
	if (i <= 0 || j <= 0) return 0;
	
	if (i == 5) return m[i - 1][j - 1];

	int r1 = tower_recursive(i + 1, j) + m[i - 1][j - 1];
	int r2 = tower_recursive(i + 1, j + 1) + m[i - 1][j - 1];

	int ret = MAX(r1, r2);
	return ret;
}

int tower[5][5] = { 0 };

int calculate(int i, int j)
{
	if (i <= 0 || j <= 0) return 0;
	if (i == 5) return m[i - 1][j - 1];

	int r1 = tower[i][j - 1] + m[i - 1][j - 1];
	int r2 = tower[i][j] + m[i - 1][j - 1];

	int ret = MAX(r1, r2);
	return ret;
}

int tower_dp()
{
	int max = 0;
	for (int i = 5; i >= 1; --i)
	{
		for (int j = 1; j <= i; ++j)
		{
			tower[i - 1][j - 1] = calculate(i, j);
		}
	}
	return tower[0][0];
}

int _tmain(int argc, _TCHAR* argv[])
{
	//int r = tower_recursive(1, 1);
	int r = tower_dp();
	return 0;
}

