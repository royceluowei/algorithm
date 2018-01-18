// lis.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//给定一个数组array[N]，求最大的非降子序列的长度
//d(n)=max(d(n-1), d(k)+1), k < n, a[k]<=a[n]
//d(n)=max{1, d(k)+1},k<n, a[k]<=a[n] 

#define MAX(a, b) (a > b ? a : b)

int a[6] = { 5, 3, 4, 8, 6, 7 };

int lis_recursive(int n)
{
	if (n == 1)
		return 1;

	int r1 = 1;
	for (int k = n - 1; k >= 1; --k)
	{
		if (a[k-1] <= a[n-1])
		{
			r1 = lis_recursive(k) + 1;
			break;
		}
	}

	int r2 = lis_recursive(n - 1);
	return MAX(r1, r2);
}

int lis[6] = { 0 };

int calculate(int n)
{
	if (n == 1)
		return 1;

	int r1 = 1;
	for (int k = n - 1; k >= 1; --k)
	{
		if (a[k - 1] <= a[n - 1])
		{
			r1 = lis[k - 1] + 1;
			break;
		}
	}

	int r2 = lis[n - 2];

	return MAX(r1, r2);
}

int lis_dp(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		lis[i - 1] = calculate(i);
		printf("%d ", lis[i - 1]);
	}
	return lis[n-1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int r = lis_dp(6);
	return 0;
}

