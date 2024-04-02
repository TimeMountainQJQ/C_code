#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int Sum(int n)
{
	if (n < 5)
	{
		return n ;
	}
	else
	{
		return(Sum(n - 1) + Sum(n - 3));
	}
}


int main()
{
	int n = 0;

	while (scanf("%d", &n)==1)
	{
		if (n == 0)
		{
			break;
		}

		else
		{
			int d = Sum(n);
			printf("%d\n", d);

		}
	}

	return 0;
}