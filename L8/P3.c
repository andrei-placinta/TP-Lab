#include <stdio.h>
#include <stdlib.h>

int x[20],n,c;                             

void citire(int p, int u)      // p - prim , u-ultim             
{
    int mij;                   //mij - mijloc
    if (p < u)                      
    {
        mij = (p + u) / 2;
        citire(p, mij);
        citire(mij + 1, u);
    }
    else
        scanf("%d", &x[p]);
}

int cautare_binara(int p, int u)           
{
    int mij;
    mij = (p + u) / 2;
    if (c == x[mij])             
        return 1;
    else
        if (p < u)
        {
            if (c < x[mij])             
                cautare_binara(p, mij - 1);    
            else
                cautare_binara(mij + 1, u);
        }
        else
            return 0;
}

int main()
{
    printf("Cate numere sunt in sir?\n");  
    while (n <= 0)
    {
        printf("n=");
        scanf("%d", &n);
    }
    printf("\nDati numerele: ");
    citire(1, n);
    printf("\nCe numar doriti sa cautati?\n"); 
    scanf("%d", &c);
    if (cautare_binara(1, n))
        printf("\nValoarea %d exista in sir\n", c);
    else
        printf("\nValoarea %d nu exista in sir\n", c);
    system("pause");
    return 0;
}

