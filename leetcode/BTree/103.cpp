#include <iostream>
#include <vector>
#include <queue>
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
    bool isorder = true; // true从左向右 false从右向左
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>{};
        vector<vector<int>> ans;
        queue<TreeNode *> que; // 辅助进行中序遍历
        que.push(root);

        while (!que.empty())
        {
            vector<int> temp;

            for (int i = que.size(); i > 0; i--)
            {
                root = que.front();
                que.pop();
                temp.push_back(root->val);
                if (root->left)
                    que.push(root->left);
                if (root->right)
                    que.push(root->right);
            }
            if (isorder)
                ans.push_back(temp);
            else
            {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            isorder = !isorder;
        }
        return ans;
    }
};

int main()
{
    return 0;
}