#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int v[100];
char s[100];

void Print()
{
	int i = 1;
	do
		printf("%c", s[v[i]]);
	while (i++ < (int)strlen(s));
	printf(" ");
}

int Valid(int k)
{
	for (int i = 1; i < k; i++)
		if (v[i] == v[k])
			return 0;
	return 1;
}
void Back(int k)
{
	if (k == strlen(s) + 1)
		Print();
	else
	{
		int i = 0;
		while (i < (int)strlen(s))
		{
			v[k] = i;
			if (Valid(k))
				Back(k + 1);
			i++;
		}
	}
}
int main()
{
	scanf("%s", &s);
	Back(1);
	printf("\n");
	system("pause");
	return 0;
}