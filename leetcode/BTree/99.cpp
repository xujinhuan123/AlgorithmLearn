#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution // 1 3 2 4 // 3 2 1   3 1 2
{
public:
    TreeNode *p, *q, *pre;
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
    }
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        static vector<int> ans;
        inorder(root->left);

        if (pre != nullptr && pre->val > root->val)
        {
            if (p == nullptr) //******这个十分重要   出现了逆序，那么第一个出现逆序的一定是要被处理的，但是不一定只有一组逆序，可能有多组逆序 同时题目说了只有一次交换 如果不交换第一个肯定无法做到不逆序，所以出现的第一个逆序的数字一定要被交换  多组逆序的出现使得交换不一定发生在第一对，所以应该是第一个逆序的数字和最后一个逆序的数字交换
                p = pre;
            q = root;
        }
        pre = root;
        inorder(root->right);
    }
};

int main()
{
    return 0;
}