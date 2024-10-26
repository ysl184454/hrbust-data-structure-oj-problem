// A
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define M 100
#define true 1
#define false 0

typedef struct
{
    int i, j, data;
}three;

typedef struct array
{
    three *arr;
    int m, n;
} Arr;

void Initarr(Arr &ar,int m1,int n1)
{
    ar.arr = new three[M];
    ar.m = m1;
    ar.n = n1;
    int o = 0;
    for (int a = 1; a <= ar.m; a++)
    {
        for (int b = 1; b <= ar.n; b++)
        {
            ar.arr[o].i = a;
            ar.arr[o].j = b;
            ar.arr[o].data = 0;
            o++;
        }
    }
}

void scanfa(Arr &ar,int k)
{
    while(k--)
    {
        int n1, n2, n3;
        scanf("%d %d %d", &n1, &n2, &n3);
        n1--;
        n2--;
        ar.arr[ar.n * n1 + n2].i = n1;
        ar.arr[ar.n * n1 + n2].j = n2;
        ar.arr[ar.n * n1 + n2].data = n3;
    }
}

void printarr(Arr A)
{
    int q = 0;
    for (int i = 0; i < A.m;i++)
    {
        for (int j = 0; j < A.n;j++)
        {
            cout << A.arr[q].data ;
            if (j != A.n - 1)
                cout << " ";
            q++;
        }
        cout << endl;
    }
}


void jzzh(Arr A, Arr &B)
{
    int q = 0;
    int b = 0;
    B.m = A.n;
    B.n = A.m;
    for (int a = 1; a <= A.n;a++)
    {
        for (; b < A.m * A.n;b+=A.n)
        {
                B.arr[q].i = A.arr[b].j;
                B.arr[q].j = A.arr[b].i;
                B.arr[q].data = A.arr[b].data;
                q++;
        }
        b = b - A.m * A.n + 1;
    }
}

int main()
{
    Arr A, B;
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    Initarr(A, m, n);
    Initarr(B, n, m);
    scanfa(A, k);
    //printarr(A);
    jzzh(A, B);
    printarr(B);
    return 0;
}
*/

// B

#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define M 100
#define true 1
#define false 0

typedef struct
{
    int i, j, data;
} three;

typedef struct array
{
    three *arr;
    int m, n;
} Arr;

void Initarr(Arr &ar, int m1, int n1)
{
    ar.arr = new three[M];
    ar.m = m1;
    ar.n = n1;
    int o = 0;
    for (int a = 1; a <= ar.m; a++)
    {
        for (int b = 1; b <= ar.n; b++)
        {
            ar.arr[o].i = a;
            ar.arr[o].j = b;
            ar.arr[o].data = 0;
            o++;
        }
    }
}

void scanfa(Arr &ar, int k)
{
    while (k--)
    {
        int n1, n2, n3;
        scanf("%d %d %d", &n1, &n2, &n3);
        n1--;
        n2--;
        ar.arr[ar.n * n1 + n2].i = n1;
        ar.arr[ar.n * n1 + n2].j = n2;
        ar.arr[ar.n * n1 + n2].data = n3;
    }
}

void printarr(Arr A)
{
    int q = 0;
    for (int i = 0; i < A.m; i++)
    {
        for (int j = 0; j < A.n; j++)
        {
            cout << A.arr[q].data ;
            if (j != A.n - 1)
                cout << " ";
            q++;
        }
        cout << endl;
    }
}

void plus1(Arr &A, Arr B)
{
    for (int i = 0; i < A.m * A.n; i++)
    {
        A.arr[i].data += B.arr[i].data;
    }
}

int main()
{
    Arr A, B;
    int m, n, k1, k2;
    scanf("%d %d", &m, &n);
    scanf("%d %d", &k1, &k2);
    Initarr(A, m, n);
    Initarr(B, m, n);
    scanfa(A, k1);
    scanfa(B, k2);

    plus1(A, B);

    printarr(A);

    return 0;
}
