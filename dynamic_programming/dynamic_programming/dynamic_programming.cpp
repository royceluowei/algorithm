// dynamic_programming.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 假设山洞里共有a,b,c,d ,e这5件宝物（不是5种宝物），
// 它们的重量分别是2,2,6,5,4，它们的价值分别是6,3,5,4,6，
// 现在给你个承重为10的背包, 怎么装背包，可以才能带走最多的财富。

int weight[5] = { 2, 2, 6, 5, 4 };
int value[5] = { 6, 3, 5, 4, 6 };

// knap(n, w) = MAX(knap(n-1, total_weight), knap(n-1, total_weight-w[i])+v[i])

int knap_recursive(int n, int w) /*前n个宝物，背包容量w*/
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

