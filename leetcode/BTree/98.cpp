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
    // 效率很差 需要学习 =====================================
    // 使用队列实现中序遍历？  XX 使用栈实现非递归的
    //  使用先序遍历应该得到一组升序数据
    //  对于有重复数据的应该怎么办？
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

int main()
{
    return 0;
}