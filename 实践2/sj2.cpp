// A
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define M 100
#define true 1
#define false 0

typedef struct Stack
{
    char data[M];
    int top;
} St;

typedef struct Queue
{
    char *data;
    int front;
    int rear;
} Qu;

void initStack(St *s)
{
    s->top = 0;
}

void push(St &s, char c)
{
    s.data[s.top] = c;
    s.top++;
}

char pop(St &s)
{
    s.top--;
    char c = s.data[s.top];
    return c;
}

void InitQueue(Qu &Q)
{
    Q.data = new char[M];
    Q.front = Q.rear = 0;
}

void InsertQueue(Qu &Q, char e)
{
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % M;
}

void EraseQueue(Qu &Q, char &e)//出队
{
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % M;
}

int geto(char c)
{
    if(c=='P')return 3;
    else if(c=='S')return 2;
    else if(c=='H')return 1;
    else return 0;
}

void Train(char *t,int n)
{
    St s1,s2,s3;
    Qu q;
    initStack(&s1);
    initStack(&s2);
    initStack(&s3);
    InitQueue(q);
    int o=strlen(t);
    int j=0;
    for(int i=0;i<n;i++)
    {
        for(;j<o;j++)
        {
            char c=t[j];
            if(c=='#'){j++;break;}
            else if(geto(c)==3)push(s1,c);
            else if(geto(c)==2)push(s2,c);
            else if(geto(c)==1)push(s3,c);
            else continue;
        }
        while(s1.top!=0)InsertQueue(q,pop(s1));
        while(s2.top!=0)InsertQueue(q,pop(s2));
        while(s3.top!=0)InsertQueue(q,pop(s3));
        for(int m=0;m<(q.rear-q.front+M)%M;m=(m+1)%M)
        {
            printf("%c",q.data[m]);
        }
        cout<<endl;
        q.front = q.rear = 0;
    }
}

int main()
{
    int n;

    while(scanf("%d", &n)!=EOF)
    {
        char train[M];
        scanf("%s", train);
        Train(train,n);
    }

    return 0;
}
*/

// B
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define M 100
#define true 1
#define false 0

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
        // if (s[i] == '&') continue;
        Push(s1, s[i]);
    }
    for (int i = 0; i < (length + 1) / 2; i++)
    {
        if (s[i] == '&')
        {
            j = 1;
            break;
        }
        char c = Pop(s1);
        if (c != s[i])
        {
            j = 0;
            break;
        }
    }
}

void Issame(char *s, int &j)
{
    int length = strlen(s);
    Stack s1;
    InitStack(s1);
    for (int i = 0; i < length; i++)
    {
        // if (s[i] == '&')continue;
        Push(s1, s[i]);
    }
    for (int i = (length - 3) / 2; i >= 0; i--)
    {
        char c = Pop(s1);

        if (c != s[i])
        {
            j = 0;
            break;
        }
        else if (i == 0 && c == s[i])
        {
            j = 2;
            break;
        }
    }
}

int Isright(char *a)
{
    int x = 0;
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '&')
        {
            x = i;
            break;
        }
    }
    if (x != len - x - 1)
        return 0;
    else
        return 1;
}

int main()
{
    int n, j = 0;
    char str[M];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        gets(str);
        int x = Isright(str);

        IsRe(str, j);
        if (j == 0)
            Issame(str, j);
        if (j == 1 && x)
            cout << "1" << endl;
        else if (j == 2 && x)
            cout << "2" << endl;
        else
            cout << "0" << endl;
        j = 0;
    }

    return 0;
}
*/
// C

#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define M 100
#define true 1
#define false 0

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

void kh(char *s1, int n)
{
    int i=0;
    int o=strlen(s1);
    Stack S;
    InitStack(S);
    while(n--)
    {
        for(;i<o;i++)
        {
        if(s1[i]=='('||s1[i]=='['||s1[i]=='{')Push(S,s1[i]);
        else if(s1[i]==')'&&S.data[S.top]=='(')Pop(S);
        else if(s1[i]==')'&&S.data[S.top]!='(')Push(S,s1[i]);
        else if(s1[i]==']'&&S.data[S.top]=='[')Pop(S);
        else if(s1[i]==']'&&S.data[S.top]!='[')Push(S,s1[i]);
        else if(s1[i]=='}'&&S.data[S.top]=='{')Pop(S);
        else if(s1[i]=='}'&&S.data[S.top]!='{')Push(S,s1[i]);
        else if(s1[i]=='#'){i++;break;}
        else continue;
        }
        if(S.top==-1)printf("YES\n");
        else printf("NO\n");
        S.top=-1;
    }
}

int main()
{
    int n;
    char s1[M];
    scanf("%d", &n);
    getchar();
    gets(s1);
    kh(s1, n);

    return 0;
}