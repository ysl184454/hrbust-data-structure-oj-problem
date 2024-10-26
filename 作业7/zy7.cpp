// A
/*
#include <bits/stdc++.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int search(int *a, int n)
{
    int i;
    for (i = n; a[i] != a[0]; i--)
        ;
    return i;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", a + i);
    }
    scanf("%d", a);
    cout << search(a, n + 1);

    return 0;
}
*/
// B
/*
#include <bits/stdc++.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct pxsz
{
    int a;
    int b;
} px;

static bool cmp(px s, px s1)
{
    return s.a < s1.a;
}

int search(int *a, int n, px *ss)
{
    sort(ss + 1, ss + n, cmp);

    int l = 1, r = n, m = l + (r - l) / 2;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (ss[m].a < a[0])
            l = m + 1;
        else if (ss[m].a == a[0])
            return ss[m].b;
        else
            r = m - 1;
    }
    return 0;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    int a[n + 1];
    px ss[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &k);
        a[i] = k;
        ss[i].a = k;
        ss[i].b = i;
    }
    scanf("%d", a);
    cout << search(a, n + 1, ss);

    return 0;
}
*/

// C
/*
#include <bits/stdc++.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct diction
{
    int key;
    int st;
    int end;
} zd;

int search(int *a, int l, int r)
{
    int m = l + (r - l) / 2;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (a[m] < a[0])
            l = m + 1;
        else if (a[m] == a[0])
            return m;
        else
            r = m - 1;
    }
    return 0;
}

int main()
{
    int n, x;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i < n + 1;i++)
    {
        scanf("%d", a + i);
    }
    scanf("%d", a);

    int k = n / 3;
    zd ss[3];
    for (int y = 0; y < 3;y++)
    {
        ss[y].st = 1 + y * k;
        ss[y].end = k * (y + 1);
        ss[y].key = a[k * (y + 1)];
    }
    for (x = 0; x < 3;x++)
    {
        if (ss[x].key >= a[0])break;
    }

    cout << search(a, ss[x].st, ss[x].end);

    return 0;
}
*/

// D
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;

void QuickSort(int *array, int low, int high)
{
    int i = low;
    int j = high;
    if (i >= j)
    {
        return;
    }

    int temp = array[low];
    while (i < j)
    {
        while (array[j] >= temp && i < j)
        {
            j--;
        }
        swap(array[i], array[j]);
        while (array[i] <= temp && i < j)
        {
            i++;
        }
        swap(array[i], array[j]);
    }
    QuickSort(array, low, i - 1);
    QuickSort(array, i + 1, high);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    QuickSort(a, 0, n);
    for (int m = 0; m < n; m++)
    {
        cout << a[m];
        if (m != n - 1)
            cout << " ";
    }

    return 0;
}
*/

// E
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;

void BubbleSort(int *a, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i;j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    BubbleSort(a, n);
    for (int m = 0; m < n; m++)
    {
        cout << a[m];
        if (m != n - 1)
            cout << " ";
    }

    return 0;
}
*/

// F

#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;

void SelectSort(int *a, int n)
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[m])
                m = j;
        }
        swap(a[m], a[i]);
        m = i + 1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    SelectSort(a, n);
    
    for (int m = 0; m < n; m++)
    {
        cout << a[m];
        if (m != n - 1)
            cout << " ";
    }

    return 0;
}
