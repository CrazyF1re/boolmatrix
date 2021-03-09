#include <iostream>
using namespace std;
void record(int n, int m,int*N) 
{
    for (int i = 0; i < m + 1; i++)
    {
        unsigned int mask = 1 << (n - 1);//маска
        char v[32];//вектор
        fgets(v, n + 2, stdin);//ввод вектора
        N[i] = 0;
        for (int j = 0; j < n; j++)
        {

            if (v[j] == '1') { N[i-1] = N[i-1] | mask; mask = mask >> 1; }
            else mask = mask >> 1;
        }
    }
}
void sort(int n, int m, int* N)
{
    unsigned int mask = 1 << n;
    int zero = ~(1<<n);
    for (int j = 0; j <= n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            if (mask & N[i])
            {
                N[i] = N[i] & zero;
                break;
            }
        }
        mask = mask >> 1;
        zero = zero >> 1;
    }
}
void prt(int n, int m, int* N) 
{
    for(int i = 0; i < m; i++)
    {
        unsigned int mask = 1 << (n-1);
        for (int j = 0; j < n; j++)
        {
            if (N[i] & mask) printf("1 ");
            else printf("0 ");
            mask = mask >> 1;
        }
        printf("\n");
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int m, n;
    int* N;
    printf_s("Введите количество строк и столбцов матрицы последовательно:");
    scanf_s("%d%d",&m,&n);
    char* w = (char*)malloc(n * sizeof(char));
    N = (int*)malloc(n * sizeof(unsigned int));
    record(n,m,N);
    sort(n, m, N);
    prt(n, m, N);
    
    
    
}