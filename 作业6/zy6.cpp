// A  最小生成树
/*
#include <bits/stdc++.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define maxVe 30

typedef struct Edge
{
    int v1;
    int v2;
    int w;
} Edge;

typedef struct Graph
{
    int edgeNum;
    int vertexNum;
    char ver[maxVe];
    int vertexs[maxVe][maxVe];
    Edge edge[maxVe];
    int totalWeight;
    int set[maxVe];
    Edge kEdge[maxVe];
} Graph;

void initSet(int *set, int vertexNum)
{
    for (int i = 0; i < vertexNum; i++)
    {
        set[i] = i;
    }
}

int find(int x, int *set)
{
    if (set[x] != x)
        return find(set[x], set);
    else
        return x;
}

void Union(int root1, int root2, int *set)
{
    int x = find(root1, set);
    int y = find(root2, set);
    if (x != y)
    {
        set[x] = y;
    }
}

int Locate(Graph *g, char e)
{
    for (int i = 0; i < g->vertexNum; i++)
    {
        if (g->ver[i] == e)
        {
            return i;
        }
    }
    return -1;
}

void buildGraph(Graph *g)
{
    scanf("%d %d", &g->vertexNum, &g->edgeNum);
    int w, m, n;
    char e1, e2;
    for (int i = 0; i < g->vertexNum; i++)
    {
        scanf(" %c", &g->ver[i]);
    }

    for (int i = 0; i < g->edgeNum; i++)
    {
        scanf(" %c %c %d", &e1, &e2, &w);
        m = Locate(g, e1);
        n = Locate(g, e2);
        g->vertexs[m][n] = w;
        g->vertexs[n][m] = w;
        g->kEdge[i].v1 = m;
        g->kEdge[i].v2 = n;
        g->kEdge[i].w = w;
    }
}

static bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void kruskal(Graph *g)
{
    initSet(g->set, g->vertexNum);
    sort(g->kEdge, g->kEdge + g->edgeNum, cmp);
    int cn = 0;
    int id = 0;
    g->totalWeight = 0;
    while (cn < g->vertexNum - 1 && id < g->edgeNum)
    {
        int v1 = g->kEdge[id].v1;
        int v2 = g->kEdge[id].v2;
        int x = find(v1, g->set);
        int y = find(v2, g->set);

        if (x != y)
        {
            g->edge[cn].v1 = v1;
            g->edge[cn].v2 = v2;
            g->edge[cn].w = g->kEdge[id].w;
            g->totalWeight += g->edge[cn].w;
            cn++;
            Union(v1, v2, g->set);
        }
        id++;
    }
    printf("%d\n", g->totalWeight);
}

int main()
{
    Graph g;
    buildGraph(&g);
    kruskal(&g);
    return 0;
}
*/
// B

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
    for (int i = 0; i < G.vexnum;i++)
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

void BFS(ALGraph G, int v)
{
    int q[1000];
    int l = 0, r = 0, p = 1;
    printf("%c ", G.vertices[v].data);
    visited[v] = 1;
    q[r++] = v;
    ArcNode *t;
    while (l < r)
    {
        t = G.vertices[q[l++]].firstarc;
        while (t)
        {
            int index = t->adjvex;
            if (!visited[index])
            {
                visited[index] = 1;
                p++;
                printf("%c", G.vertices[index].data);
                if (p != G.vexnum)
                    printf(" ");
                q[r++] = index;
            }
            t = t->nextarc;
        }
    }
}

void BFSTraverse(ALGraph G)
{
    int v;
    for (v = 0; v < G.vexnum; ++v)
        visited[v] = 0;
    for (v = 0; v < G.vexnum; ++v)
        if (!visited[v])
            BFS(G, v);
}

void dxcx(ALGraph &G)
{
    int n = G.vexnum;
    int a[n];
    int h = 0;
    for (int i = 0; i < n;i++)
    {
        ArcNode *p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            a[h] = p->adjvex;
            h++;
            p = p->nextarc;
        }

        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            p->adjvex = a[h-1];
            h--;
            p = p->nextarc;
        }
    }
}

int main()
{
    ALGraph G;
    CreateUDG(G);
    dxcx(G);
    BFSTraverse(G);
    printf("\n");
    return 0;
}
*/

// C

#include <malloc.h>
#include <bits/stdc++.h>
using namespace std;
#define MVNum 100    // 最大顶点数
#define MaxInt 66666 // 极大值

typedef struct Graph
{
    char vexs[MVNum];       // 顶点表
    int arcs[MVNum][MVNum]; // 邻接矩阵
    int vexnum, arcnum;     // 图的点数和边数
} AMGraph;

// 定位
int LocateVex(AMGraph *G, char v)
{
    int i;
    for (i = 0; i < G->vexnum; i++)
    {
        if (G->vexs[i] == v)
        {
            return i;
        }
    }
    return -1;
}

// 无向网的建立
AMGraph *CreateUDN()
{
    int i, j, k, w;
    char v1, v2;
    AMGraph *G = (AMGraph *)malloc(sizeof(AMGraph));
    scanf("%d%d", &G->vexnum, &G->arcnum);
    getchar(); // 吸收换行符
    for (i = 0; i < G->vexnum; i++)
    {
        scanf(" %c", &G->vexs[i]);
    }
    getchar(); // 吸收换行符
    for (i = 0; i < G->vexnum; i++)
        for (j = 0; j < G->vexnum; j++)
        {
            if (i == j)
            {
                G->arcs[i][j] = 0;
            }
            else
            {
                G->arcs[i][j] = MaxInt;
            }
        }
    for (k = 0; k < G->arcnum; k++)
    {
        scanf(" %c %c", &v1, &v2);
        scanf(" %d", &w);
        getchar();
        i = LocateVex(G, v1), j = LocateVex(G, v2);
        G->arcs[i][j] = w;
        G->arcs[j][i] = w;
    }
    return G;
}

// 输出邻接矩阵
void print(AMGraph *G)
{
    int i, j;
    printf("  ");
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%c  ", G->vexs[i]);
    }
    printf("\n");
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%c ", G->vexs[i]);
        for (j = 0; j < G->vexnum; j++)
        {
            if (G->arcs[i][j] == MaxInt)
                printf("∞  ");
            else
                printf("%d  ", G->arcs[i][j]);
        }
        printf("\n");
    }
}

// 弗洛伊德算法
void Floyd(AMGraph *G)
{
    int distance[MVNum][MVNum];
    int i, j, k;
    // 初始化距离矩阵
    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            distance[i][j] = G->arcs[i][j];
        }
    }
    // 中间节点迭代
    for (k = 0; k < G->vexnum; k++)
    {
        for (i = 0; i < G->vexnum; i++)
        {
            for (j = 0; j < G->vexnum; j++)
            {

                if (distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // for (int i = 0; i < G->vexnum; i++)
    // {
    //     for (int j = 0; j < G->vexnum; j++)
    //     {
    //         printf("%d ", distance[i][j]);
    //     }
    //     cout << endl;
    // }

    // 输出
    // printf("每对顶点间的最短距离：\n");
    // for (i = 0; i < G->vexnum; i++)
    // {
    //     for (j = 0; j < G->vexnum; j++)
    //     {
    //         if (distance[i][j] == MaxInt)
    //         {
    //             printf("∞  ");
    //         }
    //         else
    //         {
    //             printf("%d  ", distance[i][j]);
    //         }
    //     }
    //     printf("\n");
    // }
    int n = G->vexnum;
    int a[100], k1 = 0, p = 0, p1 = 0;
    for (int u = 0; u < n; u++)
    {
        for (int r = 0; r < n; r++)
        {
            if (k1 < distance[u][r] && u != r)
            {
                k1 = distance[u][r];
            }
        }
        a[u] = k1;
        k1 = 0;
    }
    p = a[0];
    for (int o = 0; o < n; o++)
    {
        if (p > a[o])
        {
            p = a[o];
            p1 = o;
        }
    }
    // for(int j1 = 0; j1 < n;j1++)
    //     printf("%d ", a[j1]);
    printf("%c\n", G->vexs[p1]);
}

int main()
{
    AMGraph *G = CreateUDN();
    Floyd(G);
}

// D
/*
#include <stack>
#include <bits/stdc++.h>
using namespace std;

#define INFIN 32767

typedef struct Graph
{
    char *vex; // 顶点集
    int **arc; // 邻接矩阵
    int numVert, numEdge;
} MGraph;

MGraph *InitGraph(int numVer, int numEdge) // 初始化图
{
    MGraph *G = (MGraph *)malloc(sizeof(MGraph));
    G->vex = (char *)malloc(sizeof(char) * numVer);
    G->arc = (int **)malloc(sizeof(int *) * numVer);
    for (int i = 0; i < numVer; i++)
    {
        G->vex[i] = i;
        G->arc[i] = (int *)malloc(sizeof(int) * numVer);
        for (int j = 0; j < numVer; j++)
        {
            G->arc[i][j] = INFIN;
        }
    }
    G->numVert = numVer;
    G->numEdge = numEdge;

    return G;
}

int *FindInDgree(MGraph *G) // 计算各个顶点的入度，为拓扑排序准备
{
    int *Dgree = (int *)malloc(sizeof(int) * G->numVert);
    for (int i = 0; i < G->numVert; i++)
    {
        Dgree[i] = 0;
    }

    for (int i = 0; i < G->numVert; i++)
    {
        for (int j = 0; j < G->numVert; j++)
        {
            if (G->arc[i][j] != INFIN)
            {
                Dgree[j]++;
            }
        }
    }
    return Dgree;
}

int *Toplogsort(MGraph *G) // 拓扑排序
{
    int index = 0;
    stack<int> S;
    int *TopSort = (int *)malloc(sizeof(int) * G->numVert);
    int *inDgree = FindInDgree(G);
    for (int i = 0; i < G->numVert; i++)
    {
        if (inDgree[i] == 0)
            S.push(i);
    }

    while (S.empty() == 0)
    {
        int vex = S.top();
        TopSort[index++] = vex;
        S.pop();
        for (int i = 0; i < G->numVert; i++)
        {
            if (G->arc[vex][i] != INFIN)
            {
                inDgree[i]--;
                if (inDgree[i] == 0)
                    S.push(i);
            }
        }
    }

    if (index < G->numVert) // 若无拓扑排序序列
    {
        cout << "Impossible";
        exit(0);
    }

    return TopSort;
}

int GetIndex(MGraph *G, int *top, int i)
{
    int j;
    for (j = 0; j < G->numVert; j++)
    {
        if (top[j] == i)
            break;
    }

    return j;
}

void CriticalPath(MGraph *G) // 关键路径中，求最早完成时间
{
    int *TopSort = Toplogsort(G);
    int *early = (int *)malloc(sizeof(int) * G->numVert);
    for (int i = 0; i < G->numVert; i++)
    {
        early[i] = 0;
    }

    // 计算最早发生时间
    for (int i = 0; i < G->numVert; i++)
    {
        int max = 0;
        for (int j = 0; j < G->numVert; j++) //核心
        {
            if (G->arc[j][TopSort[i]] != INFIN)
            {
                int index = GetIndex(G, TopSort, j);
                if (early[index] + G->arc[j][TopSort[i]] > max)
                    max = early[index] + G->arc[j][TopSort[i]];
            }
        }
        early[i] = max;
    }

    int max = 0;
    for (int i = 0; i < G->numVert; i++)
    {
        if (early[i] > max)
            max = early[i];
    }
    cout << max << endl;
}

int Locate(MGraph *G, char m)
{
    for (int i = 0; i < G->numVert; i++)
    {
        if (G->vex[i] == m)
        {
            return i;
        }
    }
    return -1;
}

MGraph *createG()
{
    int N, M;
    cin >> N >> M;
    MGraph *G = InitGraph(N, M);
    for (int j = 0; j < N; j++)
    {
        scanf(" %c", &(G->vex[j]));
    }

    for (int i = 0; i < M; i++)
    {
        char x, y;
        int time, k1, k2;
        scanf(" %c %c %d", &x, &y, &time);
        k1 = Locate(G, x);
        k2 = Locate(G, y);
        G->arc[k1][k2] = time;
    }
    return G;
}

int main()
{
    MGraph *G = createG();

    CriticalPath(G);

    return 0;
}
*/