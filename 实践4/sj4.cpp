
// A

#include <bits/stdc++.h>
using namespace std;
#define M 100
#define true 1
#define false 0
#define ElemType Tr


typedef struct Tnode
{
    char data;
    struct Tnode *lchild;
    struct Tnode *rchild;
} Tnode, *Tr;

void CreatT(Tr &T)
{
    char ch;
    scanf("%c", &ch);
    if (ch=='#')
    {
        T = NULL;
    }
    else
    {
        //T = (Tnode *)malloc(sizeof(Tnode));
        T = new Tnode;
        T->data = ch;
        CreatT(T->lchild);
        CreatT(T->rchild);
    }
}

typedef struct SqQueue
{
    ElemType *elem;
    int front;
    int rear;
} Qu;

void InitQueue(SqQueue &Q)
{
    Q.elem = new ElemType[M];
    Q.front = Q.rear = 0;
}

int IsEmpty(SqQueue &Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

int enqueue(SqQueue &Q, ElemType &e)
{
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % M;
    return true;
}

Tr dequeue(SqQueue &Q) // 出队
{
    if (IsEmpty(Q))
    {
        return false;
    }
    Q.front = (Q.front + 1) % M;
    return Q.elem[Q.front - 1];
}

void lev(Tr T)
{
    if (T == NULL)
    {
        return;
    }

    Qu queue;
    InitQueue(queue);
    enqueue(queue, T);

    while (!IsEmpty(queue))
    {
        Tr node = dequeue(queue);
        printf("%c", node->data);
        if (node->lchild != NULL)
        {
            enqueue(queue, node->lchild);
        }

        if (node->rchild != NULL)
        {
            enqueue(queue, node->rchild);
        }
    }
}

void Pre(Tr T)
{
    if (T == nullptr)
    {
        return ;
    }
    printf("%c", T->data);
    Pre(T->lchild);
    Pre(T->rchild);
}

void Mid(Tr T)
{
    if (T == nullptr)
    {
        return;
    }
    Mid(T->lchild);
    printf("%c", T->data);
    Mid(T->rchild);
}

void Last(Tr T)
{
    if (T == nullptr)
    {
        return;
    }
    Last(T->lchild);
    Last(T->rchild);
    printf("%c", T->data);
}

int main()
{
    Tr T;
    T = (Tnode *)malloc(sizeof(Tnode));
    T->lchild = NULL;
    T->rchild = NULL;
    int n;
    scanf("%d", &n);
    while(n--)
    {
        getchar();
        CreatT(T);
        lev(T);
        cout << endl;
        Pre(T);
        cout << endl;
        Mid(T);
        cout << endl;
        Last(T);
        cout << endl;
    }
    return 0;
}


// B
/*
#include <bits/stdc++.h>
using namespace std;
#define M 10000

typedef struct huffnode
{
    int w; // 权
    int lchild, rchild, parent;
} HTNode, *HuffT;

typedef char **HuffCode;

void Initht(HuffT &H, int m) // 初始化
{
    H = new HTNode[m + 1];

    for (int i = 1; i <= m; i++)
    {
        H[i].parent = 0;
        H[i].lchild = H[i].rchild = 0;
    }
}

void chose(HTNode *H, int len, int &s1, int &s2) // 选出权值最小的两个结点
{
    int i, mina = M, minb = M;
    for (i = 1; i <= len; i++)
    {
        if (H[i].w < mina && H[i].parent == 0)
        {
            mina = H[i].w;
            s1 = i;
        }
    }
    for (i = 1; i <= len; i++)
    {
        if (H[i].w < minb && H[i].parent == 0 && i != s1)
        {
            minb = H[i].w;
            s2 = i;
        }
    }
}

int vex[100];

int *CreateHuffT(HuffT &H, int n)
{
    int s1, s2, i = 0;
    if (n <= 1)
    {
        return vex;
    }
    int m = 2 * n - 1;

    Initht(H, m);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &H[i].w);
        vex[i] = H[i].w;
    }

    for (i = n + 1; i <= m; i++) // 在原有结点后加结点
    {
        chose(H, i - 1, s1, s2);
        H[s1].parent = H[s2].parent = i;
        H[i].lchild = s1;
        H[i].rchild = s2;
        H[i].w = H[s1].w + H[s2].w;
    }
    return vex;
}

void Huffcode(HuffT HT, HuffCode &HC, int n) // 哈夫曼编码
{
    char *cd;
    int st = 0;
    int c = 0, f = 0, i = 0;
    HC = new char *[n + 1]; // 指针数组
    cd = new char[n];
    cd[n - 1] = '\0';

    for (i = 1; i <= n; ++i)
    {
        st = n - 1;
        c = i;
        f = HT[i].parent;

        while (f)
        {
            st--;
            if (HT[f].lchild == c)
            {
                cd[st] = '0';
            }
            else
            {
                cd[st] = '1';
            }
            c = f;
            f = HT[f].parent;
        }

        HC[i] = new char[n - st];

        char *p = cd + st;
        char *q = *(HC + i);

        while (*p != '\0')
        {
            *q = *p;
            q++;
            p++;
        }

        *q = *p;
    }
    // delete cd;
}

int main()
{
    HuffT HT;
    HuffCode HC;
    int i, n, m;

    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &n);
        int *a;
        a = CreateHuffT(HT, n); // 建立
        Huffcode(HT, HC, n);    // 编码

        for (i = 1; i <= n; i++)
            printf("%d:%s\n", a[i], HC[i]);
    }

    return 0;
}
*/

// C
/*
#include <bits/stdc++.h>
using namespace std;
#define M 100
#define true 1
#define false 0
#define ElemType Tr

typedef struct Tnode
{
    char data;
    struct Tnode *lchild;
    struct Tnode *rchild;
} Tnode, *Tr;

void CreatT(Tr &T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = (Tnode *)malloc(sizeof(Tnode));
        T->data = ch;
        CreatT(T->lchild);
        CreatT(T->rchild);
    }
}

void Width(Tr T, int k, int *wid, int &max)
{
    if(T==NULL)
        return;
    wid[k]++;
    max = max > wid[k] ? max : wid[k];
    Width(T->lchild, k + 1, wid, max);
    Width(T->rchild, k + 1, wid, max);
}

int main()
{
    Tr T;
    T = (Tnode *)malloc(sizeof(Tnode));
    T->lchild = NULL;
    T->rchild = NULL;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        getchar();
        CreatT(T);
        int max = 0;
        int wid[M] = {0};
        Width(T, 1, wid, max);
        cout <<max<< endl;
    }
    return 0;
}
*/
