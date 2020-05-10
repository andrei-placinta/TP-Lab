#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int calcul(int n)
{
	if (n == 1)
	{
		printf("1");
		return 0;
	}
	printf("%d->", n);
	if (n & 1)
		return calcul(3 * n + 1);
	else
		return calcul(n / 2);
	return 0;
}
int main()
{
	int n;
	printf("n=");
	scanf("%d", &n);
	if(n)
	calcul(n);
	printf("\n");
	system("pause");
	return 0;
}