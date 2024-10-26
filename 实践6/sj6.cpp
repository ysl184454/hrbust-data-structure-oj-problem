// A
/*
#include <bits/stdc++.h>
using namespace std;

void hash1(int *h, int *h1, int r, int s, int t)
{
    for (int i = 0; i < t; i++)
    {
        int a = h1[i];
        int j = a % s;
        while (1)
        {
            if (h[j] == -999)
            {
                h[j] = a;
                break;
            }
            else
                j = (j + 1) % r;
        }
    }
}

int hash2(int *h, int q, int r, int s)
{
    int i = q % s;
    int st = q % s;
    while (1)
    {
        if (h[i] == q)
            return i;
        if (h[i] == -999)
            break;
        i = (i + 1) % r;
        if (i == st)
            break;
    }
    return -1;
}

int main()
{
    int n, r, s, t, q;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d %d", &r, &s, &t);

        int h[r];
        int a[t];

        for (int i = 0; i < r; i++)
        {
            h[i] = -999;
        }

        for (int x = 0; x < t; x++)
            scanf("%d", a + x);

        hash1(h, a, r, s, t);

        for (int i = 0; i < r; i++)
        {
            printf("%d", h[i]);
            if (i != r - 1)
                printf(" ");
        }
        cout << endl;

        scanf("%d", &q);
        int aa[q];
        for (int x = 0; x < q; x++)
            scanf("%d", aa + x);

        for (int i = 0; i < q; i++)
        {
            if (i != 0)
                cout << " ";
            cout << hash2(h, aa[i], r, s);
        }
        cout << endl;
    }
    return 0;
}
*/
// B
/*
#include <bits/stdc++.h>
#define M 300
using namespace std;

void Insertsort(int *a, int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int x = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] <= x)
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = x;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a[M], b, i;
        for (i = 0; i < M; i++)
        {
            scanf("%d", &b);
            if(b!=-1)
                a[i] = b;
            else
                break;
        }
        Insertsort(a, i);
        for (int j = 0; j < i;j++)
        {
            cout << a[j];
            if (j != i - 1)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
*/

// C
/*
#include <bits/stdc++.h>
#define M 300
using namespace std;

void Shellsort(int *a, int n)
{
    int i, j, st = n;
    while (st > 1)
    {
        st = st >> 1;
        for (i = 1; i < n; i+=st)
        {
            int x = a[i];
            for (j = i - 1; j >= 0; j--)
            {
                if (a[j] <= x)
                    a[j + 1] = a[j];
                else
                    break;
            }
            a[j + 1] = x;
        }
    }

}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a[M], b, i;
        for (i = 0; i < M; i++)
        {
            scanf("%d", &b);
            if (b != -1)
                a[i] = b;
            else
                break;
        }
        Shellsort(a, i);
        for (int j = 0; j < i; j++)
        {
            cout << a[j];
            if (j != i - 1)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
*/

// D

#include <bits/stdc++.h>
#define M 300
using namespace std;

void gbing1(int *a, int L, int mid, int R)
{
    int he[R - L + 1];
    int i = 0;
    int p1 = L;
    int p2 = mid + 1;
    while (p1 <= mid && p2 <= R)
    {
        he[i++] = a[p1] <= a[p2] ? a[p1++] : a[p2++];
    }
    while (p1 <= mid)
    {
        he[i++] = a[p1++];
    }
    while (p2 <= R)
    {
        he[i++] = a[p2++];
    }
    for (i = 0; i < R - L + 1; i++)
    {
        a[L + i] = he[i];
    }
}

void mergesort(int *a, int L, int R)
{
    if (L == R)
        return;
    int mid = L + ((R - L) >> 1);
    mergesort(a, L, mid);
    mergesort(a, mid + 1, R);
    gbing1(a, L, mid, R);
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a[M], b, i;
        for (i = 0; i < M; i++)
        {
            scanf(" %d", &b);
            if (b != -1)
                a[i] = b;
            else
                break;
        }
        mergesort(a, 0, i - 1);
        for (int j = i - 1; j >= 0; j--)
        {
            cout << a[j];
            if (j != 0)
                cout << ' ';
        }
        cout << endl;
        memset(a, 0, sizeof(a));
    }
    return 0;
}
