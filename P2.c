#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prim(int n)
{
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int  i, j, aux, i_nou, circular = 0, cifre = 0;

    for (i = 2; i <= 10000; i++)                       
    {
        cifre = 0; circular = 0;

        aux = i;     //variabila auxiliara aux pentru ca informatia numarului sa nu se piarda
        while (aux!=0)  //pentru numararea cifrelor lui i
        {                  
            cifre++;
            aux = aux / 10;
        }

        aux = i;   
        if (prim(i)!=0)    //doar daca numarul este prim vom trece la pasul urmator
        {
            for (j = 0; j < cifre; j++) // formam permutarile circulare ale numarului     
            {
                i_nou = aux % 10;        
                aux = aux / 10;
                i_nou = i_nou * pow(10, (double)cifre - 1); 
                i_nou = i_nou + aux;                       
                aux = i_nou;
                if (prim(i_nou)!=0)   //verificam daca noul numar este prim          
                    circular++;                              
            }
            if (circular == cifre)
                printf("%d \n", i);
        }
    }
    system("pause");
    return 0;
}
