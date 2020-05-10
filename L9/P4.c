#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mat[4][4], isOk;
static int dx[] = { -1, 0, 1,  0 };
static int dy[] = { 0, 1, 0, -1 };

void Print(int startX, int startY) 
{
	int i, j;
	for (i = 0; i < 4; i++) 
	{
		for (j = 0; j < 4; j++)
			if (i == startX && j == startY)
				printf("S ");
			else
				printf("%u ", mat[i][j]);
		printf("\n");
	}
}
void Clear(int startX, int startY) 
{
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (mat[i][j] != 1 || (i == startX && j == startY))
				mat[i][j] = 0;
}

int valid(int i, int j) {
	if (i < 0 || j < 0) return 0;
	if (i > 3 || j > 3) return 0;
	if (mat[i][j]) return 0;
	return 1;
}
void Flood(int i, int j)
{
	int k;
	if (i == 0 || j == 0 || i == 3 || j == 3) isOk = 0;
	for (k = 0; k < 4; k++) 
	{
		if (valid(i + dx[k], j + dy[k])) 
		{
			mat[i + dx[k]][j + dy[k]] = mat[i][j] + 1;
			Flood(i + dx[k], j + dy[k]);
		}
	}

}

int main()
{
	int contorPereti = 0, startX, startY;
	while (contorPereti < 10)
	{
		srand((unsigned)time(0));
		do 
		{
			startX = rand() % 4;
			startY = rand() % 4;
		} while (mat[startX][startY]);
		mat[startX][startY] = 1;
		contorPereti++;
	}

	do 
	{
		isOk = 1;
		srand((unsigned)time(0));
		do
		{
			startX = rand() % 4;
			startY = rand() % 4;
		} while (mat[startX][startY]);
		mat[startX][startY] = 1;
		Flood(startX, startY);
		if (isOk)
			Clear(startX, startY);
	} while (isOk);

	Print(startX, startY);
	system("pause");
	return 0;
}
