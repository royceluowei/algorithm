// lcs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
//给定两个字符串X[A,B,C,B,D,A,B]和Y[B,D,C,A,B,A],求X和Y的最长子串

#define MAX(a, b) (a > b ? a : b)

char* x = "ABCBDAB";
char* y = "BDCABA";

//char* x = "123123123abcabcabc567567";
//char* y = "cdefabcabcabcxyzxyz";

int lcs[100][100] = {0};

int calculate(int i, int j)
{
	if (i <= 0 || j <= 0)
		return 0;

	if (x[i - 1] == y[j - 1])
	{
		if (i == 1 || j == 1)
			return 1;
		else
			return lcs[i - 2][j - 2] + 1;
	}
	else
	{
		return 0;
	}
}

int lcs_dp(int m, int n)
{
	int max = 0;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			lcs[i - 1][j - 1] = calculate(i, j);
			max = MAX(max, lcs[i - 1][j - 1]);
			printf("%d ", lcs[i - 1][j - 1]);
		}
		printf("\n");
	}
	return max;
}

void print_lcs(int r)
{
	for (unsigned int i = 0; i < strlen(x); ++i)
	{
		for (unsigned int j = 0; j < strlen(y); ++j)
		{
			if (r == lcs[i][j])
			{
				char substr[100] = { 0 };
				strncpy(substr, y + j - r + 1, r);
				printf("lcs=%s\n", substr);
				return;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int max = lcs_dp(strlen(x), strlen(y));
	printf("%d\n", max);
	print_lcs(max);
	getchar();
	return 0;
}

