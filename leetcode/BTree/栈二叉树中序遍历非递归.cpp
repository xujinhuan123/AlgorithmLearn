#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

class Solution
{
public:
    vector<int> ans;
    // 使用栈实现非递归的
    //   使用先序遍历应该得到一组升序数据
    //   注意考虑重复数据
    bool isValidBST(TreeNode *root)
    {
        vector<int> data = midordor(root);
        vector<int> PreData = data;
        sort(data.begin(), data.end());
        for (int i = 0; i < data.size() - 1; i++)
        {
            if (data[i] == data[i + 1])
                return false;
        }
        return data == PreData;
    }
    vector<int> midordor(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *current = root;
        stack<TreeNode *> stack;
        while (current != nullptr || !stack.empty())
        {
            while (current != nullptr)
            {
                stack.push(current);
                current = current->left;
            }

            current = stack.top();
            stack.pop();
            ans.push_back(current->val);

            current = current->right;
        }
        return ans;
    }
};

vector<int> midorder(TreeNode *root)
{
    if (!root)
        return vector<int>{};

    vector<int> ans;
    TreeNode *current = root;
    stack<TreeNode *> stack;
    while (current != nullptr || !stack.empty())
    {
        while (current != nullptr) // 将current指针移动到最左边
        {
            stack.push(current);
            current = current->left;
        }

        current = stack.top(); // 此时current已经指向最左边的叶子结点
        stack.pop();
        ans.push_back(current->val);

        current = current->right; // 第一次到达最左边时切换到子节点为空，执行下一个循环
        // 下一次循环时再次弹出栈顶元素会让current指针指向最左边节点的父节点
        // 此时再执行到这里的时候就会访问最左边的最小子树的右子叶 实现中序遍历
    }
    return ans;
}

int main()
{
    return 0;
}