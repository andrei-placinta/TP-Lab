/*
6. Nea Vasile se intoarce acasa de la cumparaturi, si realizeaza ca si-a uitat codul de la casa scarii. In
acest moment Nea Vasile are nevoie de ajutorul nostru. Se stie ca pentru codul respective sunt
folosite 4 cifre din cele 10 (0…9), insa el fiind si la o varsta inaintata nu mai tine minte exact care cifre
erau mai exact. Sa se genereze toate combinatiile luate cate 4 a celor pe care si le aminteste nea’
Vasile. (Cifrele nu se pot repeta)
Input: 5 6 1 2 0 3
Output:
0123
0125
...
6523
6532
*/

#include <stdio.h>
#include <stdlib.h>
int x[20],v[20], n, sol = 0;

void afisare()
{
	sol++;
	//printf("Solutia %d:", sol);
	for (int i = 1; i <= 4; i++)
		printf("%d", x[i]);
	printf("\n");
}

int verificare(int k)
{
	for (int i = 1; i < k; i++)
		if (x[i] == x[k])
			return 0;
	return 1;
}

void backrec(int k)
{
	if (k == 5)	// 5 deoarece k incepe de la 1 , si din cauza apelului backrec(k+1)
		afisare();
	else
		for (int i = 1; i <= n; i++)
		{
			x[k] = v[i];	
			if(verificare(k))	//daca cifrele sunt diferite
			backrec(k + 1);	//backtracking recursiv
		}
}

void vector()	// pentru citirea si sortarea cifrelor
{
	int aux,sort=0;
	printf("Cate cifre isi aminteste?\n");
	scanf("%d", &n);
	printf("Ce cifre isi aminteste?\n");
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	while (!sort)
	{
		sort = 1;
		for (int i = 1; i <= n - 1; i++)
			if (v[i] > v[i + 1])
			{
				aux = v[i + 1];
				v[i + 1] = v[i];
				v[i] = aux;
				sort = 0;
			}
	}
}
int main()
{
	vector();
	backrec(1);
	system("pause");
	return 0;
}


