// A
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;

int search(int *a, int n)
{
    int l = 1, r = n, m, x = 0;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        x++;
        if (a[m] == a[0])
            return x;
        else if (a[m] < a[0])
            l = m + 1;
        else
            r = m - 1;

    }
    return 0;
}

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        int a[n + 1];
        scanf("%d", a);
        for (int i = 1; i < n + 1; i++)
        {
            scanf("%d", a + i);
        }
        cout << search(a, n) << endl;
    }

    return 0;
}
*/

// B

#include <bits/stdc++.h>
using namespace std;

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *Linkl;

void ScanfL(Linkl &L, int n)
{
    Linkl p, q;
    int i = 0;
    L = (Linkl)malloc(sizeof(Lnode));
    L->next = NULL;
    q = L;
    while (i < n)
    {
        p = (Linkl)malloc(sizeof(Lnode));
        scanf("%d", &p->data);
        q->next = p;
        q = p;
        q->next = NULL;
        ++i;
    }
}

void printL(Linkl &L)
{
    Linkl p;
    p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void DelList(Linkl &L, int &e)
{
    Linkl p, q;
    p = L;
    int x = 0;
    while (p->next)
    {
        if (p->next->data == e)
        {
            q = p->next;
            p->next = p->next->next;
            delete q;
            x++;
        }
        if (x == 0)
            p = p->next;
        x = 0;
    }
}

int main()
{
    Linkl L;
    int i, j;
    cin >> i;
    ScanfL(L, i);
    cin >> j;
    DelList(L, j);
    printL(L);
}

// C
/*
#include <bits/stdc++.h>
#include <stdio.h>
#include <malloc.h>
using namespace std;

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100

typedef struct
{
    VertexType vexs[MAXVEX];      // 顶点集
    EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵
    int numVer, numEdges;         // 顶点数和边数
} MGraph;

void CreateM(MGraph *G,int n)
{
    int i, j;
    G->numVer = n;
    scanf(" %d", &G->numEdges);
    for (i = 0; i < G->numVer; i++)
    {
        scanf(" %c", &G->vexs[i]);
    }

    for (i = 0; i < G->numVer; i++)
        for (j = 0; j < G->numVer; j++)
        {
            G->arc[i][j] = 0;
        }

    char c1, c2;

    for (int k = 0; k < G->numEdges; k++)
    {
        int i, j;
        scanf(" %c %c", &c1, &c2);
        for (int i1 = 0; i1 < G->numVer; i1++)
        {
            if (G->vexs[i1] == c1)
            {
                i = i1;
                break;
            }
        }
        for (int j1 = 0; j1 < G->numVer; j1++)
        {
            if (G->vexs[j1] == c2)
            {
                j = j1;
                break;
            }
        }
        G->arc[i][j] = 1;
        G->arc[j][i] = G->arc[i][j];
    }


}

int visited[MAXVEX];

// 深度优先搜索

void DFS(MGraph G, int i)
{
    int j;
    visited[i] = 1; // 访问过

    cout << G.vexs[i];

    for (j = 0; j < G.numVer; j++)
    {
        if (G.arc[i][j] == 1 && !visited[j])
        {
            DFS(G, j);
        }
    }
}

int main()
{
    MGraph G;
    int n;

    while (scanf("%d", &n) != EOF)
    {
        CreateM(&G,n);

        DFS(G, 0);

        printf("\n");
        for (int j = 0; j <= G.numVer; j++)
        {
            visited[j] = 0;
        }
    }

    return 0;
}
*/