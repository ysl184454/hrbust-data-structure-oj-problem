//A
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define MAX 100
#define true 1
#define false 0

typedef struct Sqlist
{
    int *elem;
    int length;
}list1;

int Initlist(list1 &L)
{
    L.elem = new int[MAX];
    L.length = 0;//设定线性表长度为0
    return true;
}

int Deletelist(list1 &L, int i)
{
    if(i<0 || i>L.length)
    {
        //cout << "wrong erase position!" << endl;
        return false;
    }
    if(L.length == 0)
    {
        //cout << "list1 has no length" << endl;
        return false;
    }
    //将位于删除位置之后的元素依次向前挪动一位
    for (int p = i + 1; p < L.length; ++p)
    {
        L.elem[p - 1] = L.elem[p];
    }
    //线性表长度-1
    L.length --;
    return true;
}

void remL(list1 &L, int n) 
{
    int i, j = 0;
    for (i = 0; i < n - 1; i++) 
    {
        if (L.elem[i] != L.elem[i + 1]) 
        {
            L.elem[j] = L.elem[i];
            j++;
        }
    }
    L.elem[j++] = L.elem[n - 1];
    
    for (i = n-1; i >= j; i--) Deletelist(L,i);
}

int main() 
{
    list1 L1;
    Initlist(L1);
    int m, i, j;
    scanf("%d", &m);
    for (i = 0; i < m; i++) 
    {
        int n;
        scanf("%d", &n);
        L1.length=n;

        for (j = 0; j < n; j++) scanf("%d", L1.elem+j);

        remL(L1, n);
        
        for (j = 0; j < L1.length-1; j++) printf("%d ", L1.elem[j]);
        printf("%d",L1.elem[L1.length-1]);
        printf("\n");
    }
    return 0;
}
*/

//B
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;

typedef struct Lnode
{
    int data;//结点的数据域
    Lnode *next;//结点的指针域
}Lnode,*LinkList;

int InitList(LinkList &L)
{
    L = new Lnode; //开辟一个头结点
    L->next = NULL;  //空表
    return true;
}

void scanfL(LinkList &L,int n)
{
    LinkList p,last;
    int temp;
    L=(LinkList)malloc(sizeof(Lnode));
    L->next=NULL;
    last=L;
    while(n--)
    {
        scanf("%d",&temp);
        p=(LinkList)malloc(sizeof(Lnode));
        p->data=temp;
        last->next=p;
        last=p;
        last->next=NULL;
    }
}

void printL(LinkList l)
{
    Lnode *p = l->next;
	while(p->next)
	{
		cout<<p->data<<" ";
        p=p->next;
	}
    cout<<p->data<<endl;
}

LinkList mergeL(LinkList La, LinkList Lb)
{
    Lnode *pa = La->next;
    Lnode *pb = Lb->next;
    LinkList Lc = La;
    Lnode *pc = Lc;
    while(pa && pb)
    {
        if(pa->data < pb->data)
        {
            pc->next = pa;
            pc = pc->next;
            pa = pa->next;
        }
        else if(pa->data > pb->data)
        {
            pc->next = pb;
            pc = pc->next;
            pb = pb->next;
        }
        else if(pa->data == pb->data)
        {
            pc->next = pa;
            pc = pc->next;

            LinkList q = new Lnode;//再次插入pb
            q->data = pb->data;
            q->next = pc->next;
            pc->next = q;

            pa = pa->next;
            pb = pb->next;
        }
    }
    pc->next = (pa ? pa : pb);
    free(Lb);
    return Lc;
}

int main()
{
    int m,n1,n2;
    LinkList L1,L2;
    InitList(L1);
    InitList(L2);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&n1);
        scanfL(L1,n1);
        scanf("%d",&n2);
        scanfL(L2,n2);
        printL(mergeL(L1,L2));
    }
    return 0;
}
*/

//C

#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define MAX 100
#define true 1
#define false 0

typedef struct Sqlist
{
    int *elem;
    int length;
}list1;

int Initlist(list1 &L)
{
    L.elem = new int[MAX];
    L.length = 0;//设定线性表长度为0
    return true;
}

void CLearL(list1 &L)
{
    L.length = 0;
}

int Deletelist(list1 &L, int &i)
{
    //异常判断
    if(i<0 || i>L.length)
    {
        //cout << "wrong erase position!" << endl;
        return false;
    }
    if(L.length == 0)
    {
        //cout << "list1 has no length" << endl;
        return false;
    }
    //将位于删除位置之后的元素依次向前挪动一位
    for (int p = i + 1; p < L.length; ++p)
    {
        L.elem[p - 1] = L.elem[p];
    }
    //线性表长度-1
    L.length -= 1;
    return true;
}

void unionL(list1 L1,list1 L2,list1 &L3)//求L2,L3交集
{
    int i=0,j=0;
    while ( i < L1.length && j < L2.length ) 
    {
       if (L1.elem[i] == L2.elem[j])
       {
           L3.elem[L3.length]=L1.elem[i];
           L3.length++;
           i++;
           j++;
       } 
       else if (L1.elem[i] < L2.elem[j]) i++;
       else j++;
    }
}

void delun(list1 &L1,list1 L2)//删除相同元素
{
    int i=0,j=0;
    while ( i < L1.length && j < L2.length ) 
    {
       if (L1.elem[i] == L2.elem[j]) 
       {
           Deletelist(L1,i);
           j++;
       } 
       else if (L1.elem[i] < L2.elem[j]) i++;
       else j++;
    }
}

void scanfL(list1 &l,int n)
{
    while (n--)
	{
        scanf("%d", &l.elem[l.length]);
		l.length++;		
	}
}

void printL(list1 l)
{
    int i=0;
	while(i < l.length-1)
	{
		cout<<l.elem[i]<<" ";
        i++;
	}
    cout<<l.elem[l.length-1]<<endl;
}


int main()
{
    int m,n1,n2,n3;
    list1 L1,L2,L3,L4;

    Initlist(L1);//初始化
    Initlist(L2);
    Initlist(L3);
    Initlist(L4);

    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n1);//输入
        scanfL(L1,n1);
        scanf("%d",&n2);
        scanfL(L2,n2);
        scanf("%d",&n3);
        scanfL(L3,n3);

        unionL(L2,L3,L4);//求相同元素
        delun(L1,L4);//删除相同元素

        printL(L1);

        CLearL(L1);//清空,防止影响下一组数据
        CLearL(L2);
        CLearL(L3);
        CLearL(L4);
    }
    return 0;
}


