#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> help;
        vector<vector<int>> ans;
        if (root)
            help.push(root);

        // bfs
        while (!help.empty())
        {
            vector<int> temp;
            for (int i = help.size(); i > 0; i--)
            {
                root = help.front();
                help.pop();
                temp.push_back(root->val);
                if (root->left)
                    help.push(root->left);
                if (root->right)
                    help.push(root->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};