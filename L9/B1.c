#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	int i, j, aux, n;
	char s[100];
	scanf("%s", &s);
	n = strlen(s);
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (s[j] > s[j + 1])
			{
				s[j + 1] = s[j + 1] + s[j];
				s[j] = s[j + 1] - s[j];
				s[j + 1] = s[j + 1] - s[j];
			}
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
		{
			for (aux = i; aux <= j; aux++)
				printf("%c", s[aux]);
			printf(" ");
		}
	printf("\n");
	system("pause");
	return 0;
}