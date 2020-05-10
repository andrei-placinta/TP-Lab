#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int i, j, k, n, m, mat[50][50], aux;
	scanf("%d%d", &n, &m);
	//citim matricea
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &mat[i][j]);
	//sortam randurile
	for (k = 0; k < n; k++)
		for (i = 0; i < m; i++)
			for (j = 0; j < m - i - 1; j++)
				if (mat[k][j] > mat[k][j + 1])
				{
					aux = mat[k][j];
					mat[k][j] = mat[k][j + 1];
					mat[k][j + 1] = aux;
				}
	//sortam coloanele
	for (k = 0; k < m; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n - i - 1; j++)
				if (mat[j][k] > mat[j + 1][k])
				{
					aux = mat[j][k];
					mat[j][k] = mat[j + 1][k];
					mat[j + 1][k] = aux;
				}
	//afisam matricea sortata
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
	//intrebarile continua pana la apasarea consecutiva de 3 ori a CTRL+Z + ENTER
	while (scanf("%d", &aux) != EOF)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (mat[i][j] == aux)
				{
					printf("true\n");
					i = n;	//"al 2-lea break"
					break;
				}
				else if (i == n - 1 && j == m - 1) // daca am ajuns la final(ultimul element) si nu s-a gasit
				{
					printf("false\n");
					break;
				}
	}
	printf("\n");
	system("pause");
	return 0;
}

