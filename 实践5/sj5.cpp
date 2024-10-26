//A
/*
#include <bits/stdc++.h>
using namespace std;
#define MVNum 10
#define MAXQSIZE 100`

bool visited[MVNum];
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    int info;
} ArcNode;

typedef struct VNode
{
    char data;
    ArcNode *firstarc;
} VNode, AdjList[MVNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

int LocateVex(ALGraph &G, char a)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == a)
        {
            return i;
        }
    }
    return -1;
}

void CreateUDG(ALGraph &G)
{
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; ++i)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = nullptr;
    }
    for (int j = 0; j < G.arcnum; ++j)
    {
        char a, b;
        cin >> a >> b;
        int i = LocateVex(G, a);
        int j1 = LocateVex(G, b);

        ArcNode *p = new ArcNode;
        p->adjvex = j1;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;

        ArcNode *q = new ArcNode;
        q->adjvex = i;
        q->nextarc = G.vertices[j1].firstarc;
        G.vertices[j1].firstarc = q;
    }
}

void print(ALGraph G)
{

    for (int i = 0; i < G.vexnum;i++)
    {
        printf("%c:", G.vertices[i].data);
        ArcNode *p = G.vertices[i].firstarc;
        while(p)
        {
           printf("%d", p->adjvex);
           if(p->nextarc)
               printf(" ");
           p = p->nextarc;
        }
        printf("\n");
    }
    
}

int main()
{
    int m;
    scanf("%d", &m);
    getchar();
    while (m--)
    {
        ALGraph G;
        CreateUDG(G);
        print(G);
    }
    return 0;
}
*/

//B
/*
#include <bits/stdc++.h>
#include <stdio.h>
#include <malloc.h>
using namespace std;

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINIT 0 

typedef struct
{
    VertexType vexs[MAXVEX];      // 顶点集
    EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵
    int numVertexes, numEdges;    // 顶点数和边数
} MGraph;

void CreateM(MGraph *G)
{
    int i, j, k, l = 0;
    char ch;
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    getchar();
    for (i = 0; i < G->numVertexes; i++)
    {
        scanf("%c", &ch);
        if (ch != ' ')
        {
            G->vexs[l] = ch;
            l++;
        }
        else
            i--;
    }

    // 邻接矩阵初始化

    for (i = 0; i < G->numVertexes; i++)
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINIT;

    // 输入边
    char c;

    for (k = 0; k < G->numVertexes; k++)
    {
        int i, j;
        scanf(" %c", &c);
        for (int i1 = 0; i1 < G->numVertexes; i1++)
        {
            if (G->vexs[i1] == c)
            {
                i = i1;
                break;
            }
        }
        for (int o = 0; o < G->numVertexes;o++)
        {
            scanf(" %d", &j);
            if (j != -1)
                G->arc[i][j] = 1;
                else
                    break;
        }
    }
}

int main()
{
    int m;
    scanf("%d", &m);
    getchar();

    while(m--)
    {
        MGraph G;

        CreateM(&G);

        for (int j = 0; j < G.numVertexes; j++)
        {
            for (int p = 0; p < G.numVertexes; p++)
            {
                printf("%d", G.arc[j][p]);
                if (p != G.numVertexes - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    
    return 0;
}
*/

//C

#include <bits/stdc++.h>
#include <stdio.h>
#include <malloc.h>
using namespace std;

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100

typedef struct
{
    VertexType vexs[MAXVEX];     
    EdgeType arc[MAXVEX][MAXVEX]; 
    int numVer, numEdges;    
} MGraph;


void CreateM(MGraph *G)
{
    int i, j, l = 0;
    char ch;
    scanf("%d%d", &G->numVer, &G->numEdges);
    getchar();
    for (i = 0; i < G->numVer; i++)
    {
        scanf("%c", &ch);
        if (ch != ' ')
        {
            G->vexs[l] = ch;
            l++;
        }
        else
            i--;
    }

    for (i = 0; i < G->numVer; i++)
        for (j = 0; j < G->numVer; j++)
        {
            scanf("%d", &G->arc[i][j]);
        }
    
}

int visited[MAXVEX];

void DFS(MGraph G, int i, int &x)
{
    int j;
    visited[i] = 1;

    if(x!=0)
        cout << " ";
    cout << G.vexs[i];
    
    for (j = 0; j < G.numVer; j++)
    {
        if (G.arc[i][j] == 1 && !visited[j])
        {
            x++;
            DFS(G, j, x);
        }
    }
}

int main()
{
    int m;
    scanf("%d", &m);
    while(m--)
    {
        MGraph G;

        CreateM(&G);

        for (int i = 0; i < G.numVer;i++)
        {
            int x = 0;
            DFS(G, i, x);
            printf("\n");
            memset(visited, 0, sizeof(visited));
        }
    }
    
    return 0;
}
