// A

#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define M 900
#define true 1
#define false 0

typedef struct Hstring
{
    char *ch;
    int len;
} Hst;

int Initstr(Hst &s)
{
    s.ch = new char[M];
    s.len = 0;
    return true;
}

void clears(Hst &s)
{
    s.len = 0;
    memset(s.ch, 0, s.len);
}

void scanfs(Hst &s)
{
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '#')
        {
            getchar();
            break;
        }
        else
        {
            s.ch[s.len] = c;
            s.len++;
        }
    }
    for (int i = 0; i < s.len; i++)
    {
        if (s.ch[i] == '\n')
        {
            for (int j = i + 1; j < s.len; j++)
            {
                s.ch[j - 1] = s.ch[j];
            }
            s.len--;
        }
    }
}

void prints(Hst s)
{
    for (int i = 0; i < s.len; i++)
        if (s.ch[i] != '\n')
            printf("%c", s.ch[i]);
    cout << endl;
}

void Insert(Hst &s, Hst s1, int i, int p1)
{
    Hst s2;
    Initstr(s2);
    for (int m = i + p1 - 1; m < s.len; m++)
    {
        s2.ch[s2.len] = s.ch[m];
        s2.len++;
    }
    int p = i - 1;
    for (int k = 0; k < s1.len; k++)
    {
        s.ch[p] = s1.ch[k];
        p++;
    }
    s.len = i + s1.len - 1;
    for (int o = 0; o < s2.len; o++)
    {
        s.ch[s.len] = s2.ch[o];
        s.len++;
    }
    s.ch[s.len] = '\0';
}

int BF(Hst s1, Hst s2, int m, int n)
{
    int i = m - 1, j = 0;
    int l2 = s2.len;
    while (i <= n && j < l2)
    {
        if (s1.ch[i] == s2.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= l2)
        return i - l2 + 1;
    else
        return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        Hst s, s1, s2;
        int m, n, i, x;
        Initstr(s);
        Initstr(s1);
        Initstr(s2);

        scanfs(s);
        scanfs(s1);
        scanfs(s2);
        scanf("%d %d", &m, &n);
        x = m - n + 1;
        x = x / s2.len + 1;
        while (x--)
        {
            i = BF(s, s1, m, n);

            if (i != -1)
            {
                Insert(s, s2, i, s1.len);
            }
            else
                break;
        }
        prints(s);
        clears(s);
        clears(s1);
        clears(s2);
    }
    return 0;
}

// B
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define M 900
#define true 1
#define false 0

typedef struct Hstring
{
    char *ch;
    int len;
} Hst;

int Initstr(Hst &s)
{
    s.ch = new char[M];
    s.len = 0;
    return true;
}

void clears(Hst &s)
{
    s.len = 0;
    memset(s.ch, 0, s.len);
}

void scanfs(Hst &s)
{
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '#')
        {
            getchar();
            break;
        }
        else
        {
            s.ch[s.len] = c;
            s.len++;
        }
    }
}

void prints(Hst s)
{
    for (int i = 0; i < s.len; i++)
        if (s.ch[i] != '\n')
            printf("%c", s.ch[i]);
    cout << endl;
}

void Dels(Hst &s, int m, int n)
{
    if (n < s.len)
    {
        Hst s1;
        Initstr(s1);
        for (int i = n; i < s.len; i++)
        {
            s1.ch[s1.len] = s.ch[i];
            s1.len++;
        }
        s.len = m - 1;
        for (int j = 0; j < s1.len; j++)
        {
            s.ch[s.len] = s1.ch[j];
            s.len++;
        }
    }
    else
    {
        s.len = m - 1;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        Hst s;
        int m, n;
        Initstr(s);
        getchar();

        scanfs(s);

        scanf("%d %d", &m, &n);
        if (m <= 0)
            m = 1;
        if (n > s.len)
            n = s.len;

        if (m <= n)
            Dels(s, m, n);

        prints(s);

        clears(s);
    }
    return 0;
}
*/
// C
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define M 900
#define true 1
#define false 0

typedef struct Hstring
{
    char *ch;
    int len;
} Hst;

int Initstr(Hst &s)
{
    s.ch = new char[M];
    s.len = 0;
    return true;
}

void clears(Hst &s)
{
    s.len = 0;
    memset(s.ch, 0, s.len);
}

void scanfs(Hst &s)
{
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '#')
        {
            getchar();
            break;
        }
        else
        {
            s.ch[s.len] = c;
            s.len++;
        }
    }
    for (int i = 0; i < s.len; i++) // 删除回车
    {
        if (s.ch[i] == '\n')
        {
            for (int j = i + 1; j < s.len; j++)
            {
                s.ch[j - 1] = s.ch[j];
            }
            s.len--;
        }
    }
}

void prints(Hst s)
{
    for (int i = 0; i < s.len; i++)
        if (s.ch[i] != '\n')
            printf("%c", s.ch[i]);
    cout << endl;
}

void links(Hst &s1, Hst s2)
{
    for (int i = 0; i < s2.len;i++)
    {
        s1.ch[s1.len] = s2.ch[i];
        s1.len++;
    }
}

int main()
{
    int t = 0;
    scanf("%d", &t);
    while(t--)
    {
        Hst s1, s2;
        Initstr(s1);
        Initstr(s2);

        scanfs(s1);
        scanfs(s2);

        links(s1, s2);

        prints(s1);

        clears(s1);
        clears(s2);
    }
    return 0;
}*/