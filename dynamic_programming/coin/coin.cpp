// coin.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

//������ 1 Ԫ��3 Ԫ��5 Ԫ��Ӳ�����ɣ����ޣ���������Ҫ�ճ� 11 Ԫ���������ϲ���ʹӲ�ҵ��������٣�
//d(v) = min(d(v-1), d(v-3), d(v-5))+1

#define MIN(a, b) (a < b ? a : b)
#define total_yuan 11

int coin_recursive(int v)
{
	if (v <= 0) return 255;
	if (v == 1 || v == 3 || v == 5) return 1;
	
	int r1 = coin_recursive(v - 1) + 1;
	int r2 = coin_recursive(v - 3) + 1;
	int r3 = coin_recursive(v - 5) + 1;
	
	int ret = MIN(r1, r2);
	ret = MIN(ret, r3);
	return ret;
}

int coin[total_yuan] = { 255 };

int calculate(int v)
{
	if (v <= 0) return 255;
	if (v == 1 || v == 3 || v == 5) return 1;

	int r1 = (v >= 2 ? coin[v - 2] + 1 : 255);
	int r2 = (v >= 4 ? coin[v - 4] + 1 : 255);
	int r3 = (v >= 6 ? coin[v - 6] + 1 : 255);

	int ret = MIN(r1, r2);
	ret = MIN(ret, r3);
	return ret;
}

int coin_dp(int v)
{
	for (int i = 0; i < v; ++i)
	{
		coin[i] = calculate(i + 1);
		printf("%d ", coin[i]);
	}
	printf("\n");
	return coin[total_yuan-1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int t = GetTickCount();
	int r = coin_dp(total_yuan);
	printf("result = %d, ticks = %d\n",r, GetTickCount() - t);
	getchar();
	return 0;
}

