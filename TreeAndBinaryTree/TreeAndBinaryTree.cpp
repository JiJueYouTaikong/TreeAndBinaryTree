#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

typedef struct
{
    int top;
    struct BiTNode* data[MAXSIZE];
}SqStack;

typedef struct
{
    int front;
    int rear;
    int tag;
    struct BiTNode* data[MAXSIZE];
}SqQueue;

bool InitSqStack(SqStack& s);
BiTNode* Pop(SqStack& s);
void Push(SqStack& s, BiTNode *p);
BiTNode* GetTheTop(SqStack& s);
bool EmptyStack(SqStack& s);

bool InitSqQueue(SqQueue& Q);
bool EnSqQueue(SqQueue& Q, BiTNode* p);
BiTNode* DeSqQueue(SqQueue& Q);
bool EmptyQueue(SqQueue& q);


bool CreateBiTree(BiTree& T);//先序序列创建二叉树，输入x代表节点数据为空
bool CreateIntBiTree(BiTree& T);//先序序列创建二叉树，输入x代表节点数据为空
void visit(BiTree& T);//输出节点数据
void PreOrder(BiTree& T);//先序遍历
void InOrder(BiTree& T);//中序遍历
void PostOrder(BiTree& T);//后序遍历
void LevelOrder(BiTree& T);//层序遍历
void LevelOrderReverse(BiTree& T);//层序遍历
void Print(BiTree& T);



void PreOrder_NonRecursive(BiTree& T);//非递归先序
void InOrder_NonRecursive(BiTree& T);//非递归中序
void PostOrder_NonRecursive(BiTree& T);//非递归后序


int GetTheDepth(BiTree& T);//求树的最大高度
bool isComplete(BiTree& T);//判断是否为完全二叉树
int GetTheNumOfNode(BiTree& T);//求非空节点数
int GetTheNumOfLeaf(BiTree& T);//求叶子节点数
int GetTheNumOfN2(BiTree& T);//求n2节点数
int GetTheNumOfN1(BiTree& T);//求n1节点数
int GetTheDepthByRecursive(BiTree& T);//求树的最大高度

void  FindTheMinNode(BiTNode *T,int &min);//找最小节点
bool MinNode(BiTNode* T);//辅助函数：设置最小节点
int GetTheSum(BiTree& T);//求节点值之和
int GetTheNumOfX(BiTree& T, int x);//求值为X的节点个数

void Swap(BiTree& T);//交换左右子树
bool isSimilar(BiTree& T1, BiTree& T2);//判断两树是否相似
int GetTheLevelOfX(BiTree& T, int x, int h);//求值为x的节点所在层数
int main()
{
    
    BiTree T1, T2;
    CreateBiTree(T1);
    Print(T1);
    CreateBiTree(T2);
    Print(T2);
    

    
    //求树高
    printf("\nT1树树高为%d\n", GetTheDepth(T1));
    printf("T2树树高为%d\n\n", GetTheDepth(T2));
    

    
    //判断是否为完全二叉树
    if (isComplete(T1))
    {
        printf("T1是完全二叉树\n");
    }
    else
            printf("T1不是完全二叉树\n");

    if (isComplete(T2))
    {
        printf("T2是完全二叉树\n");
    }
    else
        printf("T2不是完全二叉树\n");
    printf("\n");

    //求非空节点数
    printf("T1树的非空节点数为%d\n", GetTheNumOfNode(T1));
    printf("T2树的非空节点数为%d\n\n", GetTheNumOfNode(T2));

    //求叶子节点数
    printf("T1树的叶子节点数为%d\n", GetTheNumOfLeaf(T1));
    printf("T2树的叶子节点数为%d\n\n", GetTheNumOfLeaf(T2));

    //求n1节点数
    printf("T1树的n1节点数为%d\n", GetTheNumOfN1(T1));
    printf("T2树的n1节点数为%d\n\n", GetTheNumOfN1(T2));

    //求n2节点数
    printf("T1树的n2节点数为%d\n", GetTheNumOfN2(T1));
    printf("T2树的n2节点数为%d\n\n", GetTheNumOfN2(T2));

    //求最小节点
    MinNode(T1);
    MinNode(T2);
    printf("\n");

    //求节点值之和
    printf("T1树的节点值之和为%d\n", GetTheSum(T1));
    printf("T2树的节点值之和为%d\n", GetTheSum(T2));
    printf("\n");

    //求值为x的结点总数
    printf("T1树的值为1的节点个数为%d\n", GetTheNumOfX(T1,1));
    printf("T2树的值为1的节点个数为%d\n", GetTheNumOfX(T2,1));
    printf("\n");

    //递归求树高
    printf("T1树高度为%d\n", GetTheDepthByRecursive(T1));
    printf("T2树高度为%d\n", GetTheDepthByRecursive(T2));
    printf("\n");

    //交换左右子树
    Swap(T1);
    Swap(T2);
    printf("T1交换左右子树\n");
    printf("T2交换左右子树\n");
    printf("\n");
    Print(T1);
    printf("\n");
    Print(T2);
    printf("\n");

    //判断两树是否相似
    if (isSimilar(T1, T2))
        cout << "T1与T2相似" << endl;
    else
        cout << "T1与T2不相似" << endl;
    cout<<""<< endl;

    //求值为x的节点所在的层数
    printf("T1树值为1的节点所在层数为%d\n", GetTheLevelOfX(T1,1,1));
    printf("T2树值为1的节点所在层数为%d\n", GetTheLevelOfX(T2,1,1));
    printf("\n");
    
}

bool InitSqStack(SqStack& s)
{
    s.top = 0;
    return true;
}
bool InitSqQueue(SqQueue& Q)
{
    Q.rear = 0;
    Q.front = 0;
    Q.tag = 0;
    return true;
}

bool EnSqQueue(SqQueue& Q,BiTNode *p)
{
    if (Q.front == Q.rear && Q.tag == 1)
    {
        //队满 无法入队
        printf("[队满 无法入队]\n");
        return false;
    }
    else
    {
        Q.data[Q.rear] = p;
        Q.rear = (Q.rear + 1) % 100;
        Q.tag = 1;
        //printf("[%c进队,队列长度为%d]\n", p->data, (Q.rear - Q.front + 100) % 100);
    }
    return true;

}
BiTNode* DeSqQueue(SqQueue& Q)
{
    BiTNode* p = NULL;
    if (Q.front == Q.rear && Q.tag == 0)
    {
        //队空 无法出队
        printf("[队空 无法出队]\n");
        return NULL;
    }
    else
    {
        
        p = Q.data[Q.front];
        Q.front = (Q.front + 1) % 100;
        Q.tag = 0;
        //printf("[%c出队,队列长度为%d]\n", p->data, (Q.rear - Q.front + 100) % 100);
    }
    return p;

}

BiTNode* Pop(SqStack& s)
{
    s.top--;
   // printf("%c出栈,栈长度为%d\n", s.data[s.top]->data, s.top);
    return s.data[s.top];

}
void Push(SqStack& s,BiTNode *p)
{
    s.data[s.top] = p;
    s.top++;
    //printf("%c入栈,栈长度为%d\n", p->data, s.top);

}
BiTNode* GetTheTop(SqStack& s)
{
    return s.data[s.top - 1];
}

bool EmptyStack(SqStack& s)
{
    if (s.top == 0)
        return true;
    else
        return false;
}
bool EmptyQueue(SqQueue& q)
{
    if (q.front==q.rear&&q.tag==0)
        return true;
    else
        return false;
}

bool CreateBiTree(BiTree& T)
{
    /*
     错误点
        scanf中“ %c”里面要加个空格吸收缓冲区回车符
    */
    int ch;
    printf("请输入数据:");
    scanf_s("%d", &ch);

    if(ch==0)
    {
        T = NULL;   
    }
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return true;
}

void visit(BiTree& T)
{
    printf("%d ", T->data);
}
void Print(BiTree& T)
{
    printf("先序遍历序列为：");
    PreOrder(T);
    printf("\n");
    printf("中序遍历序列为：");
    InOrder(T);
    printf("\n");
    printf("后序遍历序列为：");
    PostOrder(T);
    printf("\n");
    printf("层序遍历序列为：");
    LevelOrder(T);
    printf("\n");
    /*
   各种遍历序列
    printf("左右互换层序遍历序列为：");
    LevelOrderReverse(T);
    printf("\n");
    printf("先序遍历序列(非递归)为：");
    PreOrder_NonRecursive(T);
    printf("\n");
    printf("中序遍历序列(非递归)为：");
    InOrder_NonRecursive(T);
    printf("\n");
    printf("后序遍历序列(非递归)为：");
    PostOrder_NonRecursive(T);
    printf("\n");*/
}

void PreOrder(BiTree& T)
{
    
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void InOrder(BiTree& T)
{
    
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
void PostOrder(BiTree& T)
{
    
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
void LevelOrder(BiTree& T)//层序遍历
{
    SqQueue q;
    InitSqQueue(q);
    BiTree p;
    EnSqQueue(q,T);
    while (EmptyQueue(q) == false)
    {
        p=DeSqQueue(q);
        visit(p);
        if (p->lchild != NULL)
        {
            EnSqQueue(q, p->lchild);
        }
        if (p->rchild != NULL)
        {
            EnSqQueue(q, p->rchild);
        }
    }
}
void LevelOrderReverse(BiTree& T)//层序遍历
{
    SqQueue q;
    SqStack s;
    InitSqStack(s);
    InitSqQueue(q);
    BiTree p;
    EnSqQueue(q, T);
    while (EmptyQueue(q) == false)
    {
        p = DeSqQueue(q);
        Push(s, p);
        if (p->lchild != NULL)
        {
            EnSqQueue(q, p->lchild);
        }
        if (p->rchild != NULL)
        {
            EnSqQueue(q, p->rchild);
        }
    }
    while (EmptyStack(s) == false)
    {
        p=Pop(s);
        visit(p);
    }
}

void PreOrder_NonRecursive(BiTree& T)
{
    SqStack s;
    InitSqStack(s);
    BiTNode* p;
    p = T; //p 是遍历循环指针 
    while (p!=NULL || !EmptyStack(s))
    {
        if (p!=NULL)
        {
            visit(p);
            Push(s,p);
            p = p->lchild;
        }
        else
        {
            p=Pop(s);
            p = p->rchild;
        }

    }
}
void InOrder_NonRecursive(BiTree& T)
{
    SqStack s;
    InitSqStack(s);
    BiTNode* p;
    p = T; //p 是遍历循环指针 
    while (p != NULL || !EmptyStack(s))
    {
        if (p != NULL)
        {
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            p = Pop(s);
            visit(p);
            p = p->rchild;
        }

    }
}
void PostOrder_NonRecursive(BiTree& T)
{
    SqStack s;
    InitSqStack(s);
    BiTNode* p;
    BiTNode* q = NULL;
    p = T; //p 是遍历循环指针 
    while (p!=NULL || !EmptyStack(s))
    {
        if (p!=NULL)
        {
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            p=GetTheTop(s);
            if (p->rchild!=NULL && p->rchild !=q)
            {
                p = p->rchild;
            }
            else
            {
                p=Pop(s);
                visit(p);
                q = p;
                p = NULL;
            }
        }

    }
}

int GetTheDepth(BiTree& T)//求树的最大高度
{
    int ld, rd = 0;
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        ld=GetTheDepth(T->lchild);
        rd = GetTheDepth(T->rchild);
        if (ld > rd)
        {
            return ld + 1;
        }
        else
            return rd + 1;
    }
}
bool isComplete(BiTree& T)//判断是否为完全二叉树
{
    SqQueue q;
    BiTree p = NULL;
    InitSqQueue(q);
    if (T == NULL)
    {
        return true;
    }
    
        EnSqQueue(q, T);
        while (EmptyQueue(q) == false)
        {
            p=DeSqQueue(q);
            if (p != NULL)
            { /*
                此处将下面的p->写成了T->导致严重逻辑错误              
              */
                //printf("%c非空，转入调用左右子树入队\n", p->data);
                    EnSqQueue(q, p->lchild);          
                    EnSqQueue(q, p->rchild);
            }
            else if(p==NULL)
            {
                while (EmptyQueue(q) == false)
                {
                    p = DeSqQueue(q);
                    if (p != NULL)
                    {
                        return false;
                    }
                }
            }
        
        }   
        return true;
}
int GetTheDepthByRecursive(BiTree& T)//求树的最大高度
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        
        return GetTheDepthByRecursive(T->lchild) > GetTheDepthByRecursive(T->rchild) 
            ? GetTheDepthByRecursive(T->lchild) + 1 : GetTheDepthByRecursive(T->rchild) + 1;
    }
        
}

int GetTheNumOfNode(BiTree& T)//求非空节点数
{
    int ln = 0, rn = 0;
    if (T == NULL)
        return 0;

    ln=GetTheNumOfNode(T->lchild);
    rn=GetTheNumOfNode(T->rchild);
    return  ln + rn+1;
}//求所有节点数
int GetTheNumOfLeaf(BiTree& T)//求叶子节点数
{
    int ln, rn;
    if (T == NULL)
        return 0;
    else if (T->lchild == NULL && T->rchild == NULL)
    {
        return 1;
    }
    else
    {
        ln=GetTheNumOfLeaf(T->lchild);
        rn = GetTheNumOfLeaf(T->rchild);
        return ln + rn;
    }
}//求n0节点数
int GetTheNumOfN2(BiTree& T)//求n2节点数
{
    int ln, rn;
    if(T==NULL)
    {
        return 0;
    }
    else if (T->lchild != NULL && T->rchild != NULL)
    {
        ln = GetTheNumOfN2(T->lchild);
        rn = GetTheNumOfN2(T->rchild);
        return ln + rn + 1;
    }
    else
    {
        ln = GetTheNumOfN2(T->lchild);
        rn = GetTheNumOfN2(T->rchild);
        return ln + rn ;
    }
}
int GetTheNumOfN1(BiTree& T)//求n1节点数
{
    int ln,rn;
    if (T==NULL)
    {
        return 0;
    }
    else if (T->rchild == NULL && T->lchild == NULL)
    {
        return 0;
    }
    else if (T->rchild == NULL || T->lchild == NULL)
    {
        ln = GetTheNumOfN1(T -> lchild);
        rn = GetTheNumOfN1(T -> rchild);
        return 1 + ln + rn;
    }
    else
    {
        ln = GetTheNumOfN1(T->lchild);
        rn = GetTheNumOfN1(T->rchild);
        return ln + rn;
    }
}


void  FindTheMinNode(BiTNode* T,int &min)//找最小节点
{
    //错误点1：必须加上T!=NULL的判断 否则递归将会永远不结束
    if (T != NULL)
    {
        if (T->data < min)
        {
            min = T->data;
        }
        FindTheMinNode(T->lchild, min);
        FindTheMinNode(T->rchild, min);

    }
    

        
}
bool MinNode(BiTNode* T)//辅助函数：设置最小节点
{
    if (T == NULL)
    {
        return false;
    }
    else
    {
        int min = T->data;
        FindTheMinNode(T, min);
        printf("Min = %d\n", min);
        return true;
    }
}
int GetTheSum(BiTree& T)//求节点值之和
{
    int ln, rn;
    if(T == NULL)
    {
        return 0;
    }
    else if (T->lchild == NULL && T->rchild == NULL)
    {
        return T->data;
    }
    else
    {
        ln = GetTheSum(T->lchild);
        rn = GetTheSum(T->rchild);
        return T->data + ln + rn;
    }
}
int GetTheNumOfX(BiTree& T,int x)//求值为X的节点个数
{
    if (T == NULL)
    {
        return 0;
    }
    else if (T->data == x)
    {
        return 1 + GetTheNumOfX(T->lchild, x) + GetTheNumOfX(T->rchild, x);
    }
    else
    {
        return GetTheNumOfX(T->lchild, x) + GetTheNumOfX(T->rchild, x);
    }
}

void Swap(BiTree& T)//交换左右子树
{
    BiTNode* temp;
    if (T != NULL)
    {
        Swap(T->lchild);
        Swap(T->rchild);
        temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}
bool isSimilar(BiTree& T1, BiTree& T2)//判断两树是否相似
{
    bool t1, t2;
    if (T1 == NULL && T2 == NULL)
    {
        //cout << "两树相似"<<endl;
        return true;
    }
    else if (T1 == NULL || T2 == NULL)
    {
        //cout << "两树不相似" << endl;
        return false;
    }
    else
    {
        t1 = isSimilar(T1->lchild, T2->lchild);
        t2 = isSimilar(T1->rchild, T2->rchild);
        return t1 && t2;
    }
}
int GetTheLevelOfX(BiTree& T, int x, int h)//求值为x的节点所在层数
{
    //注意：函数调用时，传入的实参h必须为1 代表T所在的根节点所在的层数
    int hx;
    if (T == NULL)
        return 0;
    else if (T->data == x)
        return h;
    else
    {
        hx = GetTheLevelOfX(T->lchild, x, h + 1);
        if (hx == 0)//左子树没找到
        {
            return GetTheLevelOfX(T->rchild, x, h + 1);
        }
        else
            return hx;
    }    
    
}


