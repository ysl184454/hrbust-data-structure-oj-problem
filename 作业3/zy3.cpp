//A
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define M 100
#define true 1
#define false 0

typedef struct Hstring
{
    char *ch;
    int len;
}Hst;

int Initstr(Hst &s)
{
    s.ch = new char[M];
    s.len = 0;
    return true;
}

void Insert(Hst &s,Hst s1,int i)
{
    int j = i - 1;
    int p = 0;
    while (p < s1.len)
    {
        for (int o = s.len; o >= j;o--)
        {
            s.ch[o + 1] = s.ch[o];
        }
        s.len++;
        s.ch[j] = s1.ch[p];
        p++;
        j++;
    }
}

void scanfs(Hst &s)
{
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='\n')break;
        else 
        {
            s.ch[s.len]=c;
            s.len++;
        }
    }
}

void prints(Hst s)
{
    for(int i=0;i<s.len;i++)printf("%c",s.ch[i]);
}

int main()
{
    Hst s,s1;
    int n;
    Initstr(s);
    Initstr(s1);

    scanfs(s);
    scanfs(s1);
    scanf("%d",&n);
    Insert(s, s1, n);
    prints(s);


    return 0;
}
*/

//B
/*
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
#define M 100
#define true 1
#define false 0

typedef struct Hstring
{
    char *ch;
    int len;
}Hst;

int Initstr(Hst &s)
{
    s.ch = new char[M];
    s.len = 0;//设定线性表长度为0
    return true;
}

void qvzc(Hst s,Hst &s1,int m,int n)
{
    for(int i=0;i<n;i++)
    {
        s1.ch[s1.len]=s.ch[m-1+i];
        s1.len++;
    }
}

void scanfs(Hst &s)
{
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='\n')break;
        else 
        {
            s.ch[s.len]=c;
            s.len++;
        }
    }
}

void prints(Hst s)
{
    for(int i=0;i<s.len;i++)printf("%c",s.ch[i]);
}

int main()
{
    Hst s,s1;
    int m,n;
    Initstr(s);
    Initstr(s1);
    scanfs(s);
    scanf("%d",&m);
    scanf("%d",&n);

    qvzc(s,s1,m,n);
    prints(s1);

    return 0;
}
*/

//C
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
}Hst;

int Initstr(Hst &s)
{
    s.ch = new char[M];
    s.len = 0;
    return true;
}

void getnext(Hst sub,int* next,int lensub)
{
	next[0] = -1;
	next[1] = 0;
	int i = 2;
	int k = 0;
	while (i < lensub)
	{
		if (k==-1||sub.ch[i - 1] == sub.ch[k])//当k==-1不符合条件next[i]置0
		{
			next[i] = k + 1;
			i++;
			k++;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMP(Hst str, Hst sub)
{
	int i = 0;
	int j = 0;
	int lenstr = str.len;//主串长
	int lensub = sub.len;//子串长
	int* next = new int[lensub];
	getnext(sub,next,lensub);
	while (i < lenstr && j < lensub)
	{
		if (j==-1||str.ch[i] == sub.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= lensub)
	{
		return i - j + 1;
	}
	return -1;
}

void prints(Hst s)
{
    for(int i=0;i<s.len;i++)printf("%c",s.ch[i]);
    cout<<endl;
}

int BF(Hst s1, Hst s2)
{
    int i = 0, j = 0;
    int l1 = s1.len;
    int l2 = s2.len;
    while (i < l1 && j < l2)
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
    Hst s1,s2;
    int q;
    Initstr(s1);
    Initstr(s2);
    char a[M],b[M];
    while (scanf("%s %s",a,b) != EOF)
    {
        
        s1.ch=a;
        s1.len=strlen(a);
        
        s2.ch=b;
        s2.len=strlen(b); 

       q=KMP(s1,s2);
       if(q==-1)q++;
	   printf("%d\n",q);
       Initstr(s1);
       Initstr(s2);
    }
    
	return 0;
}
*/

//D

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
}Hst;

int Initstr(Hst &s)
{
    s.ch = new char[M];
    s.len = 0;//设定线性表长度为0
    return true;
}

int compare(Hst s1,Hst s2)
{
    int i=0,p;
    while(i<s1.len&&i<s2.len)
    {
        if(s1.ch[i]!=s2.ch[i])
        {
            p=s1.ch[i]-s2.ch[i];
            return p;
        }
        else 
        {
            i++;
        }
    }
    return 0;
}

void scanfs(Hst &s)
{
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='\n')break;
        else 
        {
            s.ch[s.len]=c;
            s.len++;
        }
    }
}

int main()
{
    Hst s,s1;
    Initstr(s);
    Initstr(s1);
    scanfs(s);
    scanfs(s1);

    cout<<compare(s,s1);

    return 0;
}
