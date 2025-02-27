#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef struct TNode
{
    int Data;
    struct TNode *left;
    struct TNode *right;
} TNode;

// 链式存储
class BinaryTree
{
private:
    TNode *root; // 根结点

public:
    // 构造函数
    BinaryTree()
    {
        root = nullptr;
    }

    // 析构函数
    ~BinaryTree() {}

    // 创建二叉树
    void CreateBiTree(char *POS, char *IOS);

    // 清空树
    void ClearBiTree();

    // 判断是否为空树
    bool IsEmpty()
    {
        return root == nullptr;
    }

    // 求树的高度
    int GetDepth(TNode *t);

    // 给树结点赋值
    void Assign(TNode *e, int value)
    {
        e->Data = value;
    }

    // 求父结点
    TNode *GetParent(TNode *e);

    // 求左孩子
    TNode *LeftChild(TNode *e)
    {
        return e->left;
    }

    // 求右孩子
    TNode *RightChild(TNode *e)
    {
        return e->right;
    }

    // 求树的根
    TNode *GetRoot()
    {
        return root;
    }

    // 结点值
    int GetValue(TNode *e)
    {
        return e->Data;
    }

    // 插入孩子结点
    void InsertChild(TNode *p, int LR, TNode *c);

    // 删除子树
    void DeleteChild(TNode *p, int LR);

    // 前序遍历
    void PreOrder(TNode *t, void (*visit)(TNode *));

    // 中序遍历
    void INOrder(TNode *t, void (*visit)(TNode *));

    // 后序遍历
    void PostOrder(TNode *t, void (*visit)(TNode *));

    // 层序遍历
    void LevelOrder(TNode *t, void (*visit)(TNode *));

    // 访问操作
    friend void visit(TNode *p);
};

// 前序遍历
void BinaryTree::PreOrder(TNode *t, void (*visit)(TNode *))
{
    if (t)
    {
        visit(t);
        PreOrder(t->left, visit);
        PreOrder(t->right, visit);
    }
}

// 利用栈实现非递归前序遍历
void PreOrder2(TNode *t, void (*visit)(TNode *))
{
    stack<TNode *> s;
    TNode *p = t;
    while (p != nullptr || !s.empty())
    {
        if (p != nullptr)
        {
            visit(p);
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}
// 中序遍历
void BinaryTree::INOrder(TNode *t, void (*visit)(TNode *))
{
    if (t)
    {
        INOrder(t->left, visit);
        visit(t);
        INOrder(t->right, visit);
    }
}

// 后序遍历
void BinaryTree::PostOrder(TNode *t, void (*visit)(TNode *))
{
    if (t)
    {
        PostOrder(t->left, visit);
        PostOrder(t->right, visit);
        visit(t);
    }
}

// 层序遍历 利用队列实现 出队访问，左右孩子入队，直到队列为空
void BinaryTree::LevelOrder(TNode *t, void (*visit)(TNode *))
{
    TNode *p = t;
    queue<TNode *> q;
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        visit(p);
        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
}

int main()
{
    return 0;
}
