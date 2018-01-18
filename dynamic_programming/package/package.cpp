// package.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory.h>
#include <windows.h>

// 背包问题
// 假设山洞里共有a,b,c,d ,e这5件宝物（不是5种宝物），
// 它们的重量分别是2,2,6,5,4，它们的价值分别是6,3,5,4,6，
// 现在给你个承重为10的背包, 怎么装背包，可以才能带走最多的财富。

int weight[5] = { 2, 2, 6, 5, 4 };
int value[5] = { 6, 3, 5, 4, 6 };

#define MAX(a, b) (a > b ? a : b)

// d(n, w) = d(knap(n-1, w), knap(n-1, w-weight[n])+value[n])


int knap_recursive(int n, int w) /*前n个宝物，背包容量w*/
{
	if (w <= 0) return 0;

	if (n == 1)
	{
		if (weight[n - 1] <= w)
			return value[n - 1];
		return 0;
	}

	int r1 = knap_recursive(n - 1, w);
	int r2 = knap_recursive(n - 1, w - weight[n - 1]) + value[n - 1];

	return MAX(r1, r2);
}

int knap[5][10] = { 0 };
unsigned int calculate(int n, int w)
{
	if (w <= 0) return 0;

	if (n == 1)
	{
		if (weight[n - 1] <= w)
			return value[n - 1];
		return 0;
	}

	int r1 = knap[n - 2][w - 1];
	int r2 = 0;
	if (w - weight[n - 1] - 1 >= 0)
		r2 = knap[n - 2][w - weight[n - 1] - 1] + value[n - 1];

	return MAX(r1, r2);
}

unsigned int knap_dp(int n, int w)
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= w; ++j)
		{
			int& value = knap[i-1][j-1];
			value = calculate(i, j);
		}
	return knap[n-1][w-1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int max_value = knap_dp(5, 10);
	printf("max value:%d\n",  max_value);
	return 0;
}
