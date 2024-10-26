//作业1 A
// #include <bits/stdc++.h>
// using namespace std;
// typedef struct link
// {
//     int data;
//     struct link *next;
// }l1;

// void rlink(link *p)
// {
//     if(p==NULL) return;
//     else
//     {
//        rlink(p->next);
//        cout<<p->data<<" ";
//     }
// }

// link* clink()
// {
//     l1 *h= (link*)malloc(sizeof(link));
//     h->next=NULL;
//     return h;
// }

// int main()
// {
//     int x,j=0; 
//     l1 *q,*head=clink();
//     q=head;
//     while(scanf("%d",&x)!=EOF)
//     {
//         l1 *p1= (link*)malloc(sizeof(link));
//         p1->data=x;
//         p1->next=NULL;
//         head->next=p1;
//         head=head->next;
//         j++;
//         if(getchar()=='\n')break;
//     }
//     printf("%d \n",j);
//     rlink(q->next);
//     printf("\n");
//     return 0;
// }

//B
// #include <bits/stdc++.h>

// using namespace std;

// typedef struct Lnode
// {
//     int data;
//     struct Lnode *next;
// }Lnode,*Linkl;

// void ScanfL(Linkl &L,int n)
// {
//     Linkl p,q;
//     int i=0;
//     L=(Linkl)malloc(sizeof(Lnode));
//     L->next=NULL;
//     q=L;
//     while(i<n)
//     {
//         p=(Linkl)malloc(sizeof(Lnode));
//         scanf("%d",&p->data);
//         q->next=p;
//         q=p;
//         q->next=NULL;
//         ++i;
//     }
// }

// void printL(Linkl &L)
// {
//     Linkl p;
//     p=L->next;
//     cout<<p->data;
//     p=p->next;
//     while(p!=NULL)
//     {
//         cout<<" "<<p->data;
//         p=p->next;
//     }
// }

// void DelList(Linkl &L,int &e)
// {
//     Linkl p,q;
//     p=L;
//     while(p->next!=NULL)
//     {
//         if(p->next->data==e)
//         {
//             q=p->next;
//             p->next=p->next->next;
//             delete q;
//         }
//         p=p->next;
//     }
// }

// int main()
// {
//     Linkl L;
//     int i,j;
//     cin>>i;
//     ScanfL(L,i);
// 	cin>>j;
// 	DelList(L,j);
//     printL(L);
// }

//C
// #include <bits/stdc++.h>
// using namespace std;

// struct List
// {
// 	int data[999];
// 	int len=0;
// };

// void printL(List l)
// {
//     int i=0;
// 	while(i < l.len)
// 	{
// 		cout<<l.data[i]<<" ";
//         i++;
// 	}
// 	cout<<endl;
// }

// List scanfL()
// {
//     List l;
//     while (scanf("%d", &l.data[l.len])!=EOF)
// 	{
// 		l.len++;
// 		if (getchar() == '\n') break; 		
// 	}
//     return l;
// }

// int main()
// {
// 	List l1, l2, l3;
// 	l1=scanfL();
// 	for (int i = 0; i < l1.len; i++)
// 	{
// 		if (l1.data[i] >= 0)
// 		{
// 			l2.data[l2.len] = l1.data[i];
// 			l2.len++;
// 		}
// 		else
// 		{
// 			l3.data[l3.len] = l1.data[i];
// 			l3.len++;
// 		}
// 	}
// 	printL(l2); 
//     printL(l3);
// 	return 0;
// }

/*
#include <stdio.h>
#include <stdlib.h>

#define M 100

// 定义队列结构体
typedef struct 
{
    int *data;
    int front;
    int rear;
} Queue;

// 初始化队列
void initQ(Queue &queue) 
{
    queue.data = new int[M];
    queue.front = 0;
    queue.rear = 0;
}

// // 判断队列是否为空
// int isEmpty(Queue *queue) {
//     return queue.front == queue.rear;
// }

// // 判断队列是否已满
// int isFull(Queue *queue) {
//     return (queue.rear + 1) % MAX_SIZE == queue.front;
// }


// // 出队
// int dequeue(Queue *queue) {
//     if (isEmpty(queue)) {
//         printf("Queue is empty.\n");
//         return -1;
//     }
//     int value = queue.data[queue.front];
//     queue.front = (queue.front + 1) % MAX_SIZE;
//     return value;
// }


// 入队
void enqueue(Queue &queue, int value) 
{
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }
    queue.data[queue.rear] = value;
    queue.rear = (queue.rear + 1) % M;
}

// 输出队列中的数据元素
void printQ(Queue &queue) 
{
    int i;
    for (i = queue.front; i != queue.rear; i = (i + 1) % M) 
        printf("%d ", queue.data[i]);
    printf("\n");
}

int main() 
{
    int n, i, len;
    Queue q;

    // 读取多组输入
    while (scanf("%d", &n) != EOF) 
    {
        initQ(q);

        // 读取输入数据并入队
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &len);
            enqueue(q, len);
        }

        // 输出队列中的数据元素
        printQ(q);
    }

    return 0;
}
*/

//作业2
//A

/*
#include <bits/stdc++.h>
#define M 100
using namespace std;

// 定义队列结构体
typedef struct Queue
{
    int *data;
    int front;
    int rear;
} Qu;

// 初始化队列
void initQ(Qu &qu) 
{
    qu.data = new int[M];
    qu.front = 0;
    qu.rear = 0;
}

// 入队
void enqueue(Qu &qu, int v) 
{
    qu.data[qu.rear] = v;
    qu.rear = (qu.rear + 1) % M;
}

// 输出队列中的数据元素
void printQ(Qu &qu) 
{
    int i;
    for (i = qu.front; i != qu.rear-1; i = (i + 1) % M) 
        printf("%d ", qu.data[i]);
    printf("%d",qu.data[qu.rear-1]);

    printf("\n");
}

int main() 
{
    int n, i, len;
    Qu q;

    while (scanf("%d", &n) != EOF) 
    {
        initQ(q);

        for (i = 0; i < n; i++) 
        {
            scanf("%d", &len);
            enqueue(q, len);
        }
        
        printQ(q);
    }

    return 0;
}
*/

//B
/*
#include <bits/stdc++.h>
using namespace std;

#define M 100

typedef struct SqStack
{
    char *data;
    int top;
} Stack;

void InitStack(Stack &s) 
{
    s.data = new char[M];
    s.top = -1;
}

void Push(Stack &s, char c) 
{
    s.data[++s.top] = c;
}

char Pop(Stack &s) 
{
    return s.data[s.top--];
}

void IsRe(char *s, int &j) 
{
    int length = strlen(s);
    Stack s1;
    InitStack(s1);
    for (int i = 0; i < length; i++) 
    {
        if (s[i] == '&') continue;
        Push(s1, s[i]);
    }
    for (int i = 0; i < length/2+1; i++) 
    {
        if (s[i] == '&') 
        {
            j=1;
            break;
        }
        char c = Pop(s1);
        if (c != s[i]) 
        {
            j=0;
            break;
        }
    }
}

int main() 
{
    char s[M];
    int i;
    while (scanf("%s", s) != EOF) 
    {
        IsRe(s,i);
        if (i) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
*/

//C
/*
#include <bits/stdc++.h>
using namespace std;
#define M 100

typedef struct 
{
    char *data;
    int top;
    int max;
} Stack;

void initStack(Stack &s) 
{
    s.data = (char*)malloc(sizeof(char) * M);
    s.top = 0;
    s.max = M;
}

int isempty(Stack &s) 
{
    if(s.top == 0)return 1;
    else return 0;
}

void push(Stack &s, char c) 
{
    s.data[s.top] = c;
    s.top++;
}

char pop(Stack &s)
{
    s.top--;
    char c = s.data[s.top];
    return c;
}

//操作符优先级
int geto(char op) 
{
    if(op=='+'||op=='-')return 1;
    else if(op=='*'||op=='/')return 2;
    else return 0;
}

//转换为后缀
void conp(char *inf, char *p) 
{
    int Len = strlen(inf);
    Stack S;
    initStack(S);
    int q = 0;

    for (int i = 0; i < Len; i++) 
    {
        char c1 = inf[i];
        if (c1 >= 'a' && c1 <= 'z') 
        {
            p[q] = c1;
            q++;
        } 
        else if (c1 == '(') 
        {
            push(S, c1);
        } 
        else if (c1 == ')') 
        {
            while (!isempty(S) && S.data[S.top-1] != '(') 
            {
                p[q] = pop(S);
                q++;
            }
            if (!isempty(S) && S.data[S.top-1] == '(') 
            {
                pop(S); // 弹出左括号
            }
        } 
        else if (c1 == '+' || c1 == '-' || c1 == '*' || c1 == '/') 
        {
            while (!isempty(S) && geto(S.data[S.top-1]) >= geto(c1)) 
            {
                p[q] = pop(S);
                q++;
            }
            push(S, c1);
        }
    }

    while (!isempty(S)) 
    {
        p[q] = pop(S);
        q++;
    }
    p[q] = '\0';
}

int main() 
{
    char inf[M];
    char p[M];

    scanf("%s", inf);
    conp(inf, p);
    printf("%s", p);

    return 0;
}
*/