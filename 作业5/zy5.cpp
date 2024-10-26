// A-right
/*
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <malloc.h>
using namespace std;
typedef struct node
{
    char val;
    struct node *left;
    struct node *right;
} node;
#define ALLOC_(name, xx)                       \
    node *name = (node *)malloc(sizeof(node)); \
    name->val = xx;                            \
    name->left = name->right = NULL;

void buildTree(node *&t)
{
    char a, b, c;
    cin >> a;
    if (a == '#')
        return;
    map<char, node *> mp;
    ALLOC_(root, a);
    mp[root->val] = root;
    while (cin >> a)
    {
        if (a == '#')
            break;
        cin >> b >> c;
        auto parent = mp.find(a);
        if (b != '0')
        {
            auto left = mp.find(b);
            if (left == mp.end())
            {
                ALLOC_(p, b);
                mp[p->val] = p;
                left = mp.find(p->val);
            }
            parent->second->left = left->second;
        }
        if (c != '0')
        {
            auto right = mp.find(c);
            if (right == mp.end())
            {
                ALLOC_(p, c);
                mp[p->val] = p;
                right = mp.find(p->val);
            }
            parent->second->right = right->second;
        }
    }
    t = root;
    return;
}

void Swap(node *&T1, node *&T2) // 交换两个二叉树结点指针的指向
{
    node *t = T1;
    T1 = T2;
    T2 = t;
}
void NodeSwap(node *&T) // 交换二叉树每个结点的左孩子和右孩子
{
    if (T != NULL)
    {
        if (T->left != NULL && T->right != NULL)
        {
            Swap(T->left, T->right);
        }
        else if (T->left != NULL && T->right == NULL)
        {
            // 将T的左子树变为右子树
            T->right = T->left;
            T->left = NULL;
        }
        else if (T->left == NULL && T->right != NULL)
        {
            // 将T的右子树变为左子树
            T->left = T->right;
            T->right = NULL;
        }
        else // 如果T的左孩子和右孩子都为空
        {
            ;
        }
        NodeSwap(T->left);
        NodeSwap(T->right);
    }
    else
    {
        ;
    }
}

void FloorPrint_QUEUE(node *&Tree) // 层序遍历
{
    queue<node *> q;
    if (Tree != NULL)
    {
        q.push(Tree);
    }

    while (q.empty() == false) // 队列不为空判断
    {
        cout << q.front()->val << " ";

        if (q.front()->left != NULL) // 如果有左孩子，leftChild入队列
        {
            q.push(q.front()->left);
            cout << q.front()->left->val << " ";
        }
        else
        {
            cout << "0"
                 << " ";
        }
        if (q.front()->right != NULL) // 如果有右孩子，rightChild入队列
        {
            q.push(q.front()->right);
            cout << q.front()->right->val << endl;
        }
        else
        {
            cout << "0" << endl;
        }
        q.pop();
    }
}

int main()
{
    node *T;
    buildTree(T);
    NodeSwap(T);
    FloorPrint_QUEUE(T);
    return 0;
}
*/

//B

/*
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <malloc.h>
using namespace std;
typedef struct node
{
    char val;
    struct node *left;
    struct node *right;
} node;
#define ALLOC_(name, xx)                       \
    node *name = (node *)malloc(sizeof(node)); \
    name->val = xx;                            \
    name->left = name->right = NULL;

void buildTree(node *&t)
{
    char a, b, c;
    cin >> a;
    if (a == '#')
        return;
    map<char, node *> mp;
    ALLOC_(root, a);
    mp[root->val] = root;
    while (cin >> a)
    {
        if (a == '#')
            break;
        cin >> b >> c;
        auto parent = mp.find(a);
        if (b != '0')
        {
            auto left = mp.find(b);
            if (left == mp.end())
            {
                ALLOC_(p, b);
                mp[p->val] = p;
                left = mp.find(p->val);
            }
            parent->second->left = left->second;
        }
        if (c != '0')
        {
            auto right = mp.find(c);
            if (right == mp.end())
            {
                ALLOC_(p, c);
                mp[p->val] = p;
                right = mp.find(p->val);
            }
            parent->second->right = right->second;
        }
    }
    t = root;
    return;
}

int GetH(node *T)
{
    if (!T)
        return 0;
    else
    {
        int l = GetH(T->left);
        int r = GetH(T->right);
        return (l > r ? l : r) + 1;
    }
}

int main()
{
    node *T;
    buildTree(T);
    cout << GetH(T) << endl;

    return 0;
}
*/


// C
/*
#include <bits/stdc++.h>
using namespace std;

typedef struct Tnode
{
    char data;
    struct Tnode *left;
    struct Tnode *right;
} Tnode, *Tr;

void CreatN(Tr &t, char x)
{ // t处生成一新节点，内容为x
    t = new Tnode;
    t->data = x;
    t->left = NULL;
    t->right = NULL;
}

void CreateL(Tr &t)
{
    queue<Tr> q;
    char x;
    cin >> x;
    if (x == '#')
        return;
    if (x != ' ')
    {
        CreatN(t, x);
        q.push(t);
    }
    while (!q.empty())
    {
        Tr s = q.front();
        cin >> x;
        if (x == '#')
            break;
        if (x != ' ')
        {
            CreatN(s->left, x);
            q.push(s->left);
        }
        cin >> x;
        if (x == '#')
            break;
        if (x != ' ')
        {
            CreatN(s->right, x);
            q.push(s->right);
        }
        q.pop();
    }
}

int il = 0;
int lefts(Tr T)
{
    if (T == NULL || T->data == '0')
        return 0;
    if ((T->left == NULL || T->left->data == '0') && (T->right == NULL || T->right->data == '0'))
        return 1;
    int leftN = lefts(T->left);
    int rightN = lefts(T->right);
    int leafN = leftN + rightN;
    return leafN;
}

int main()
{
    Tnode *T;
    T->left = NULL;
    T->right = NULL;

    CreateL(T);
    printf("%d\n", lefts(T));

    return 0;
}
*/