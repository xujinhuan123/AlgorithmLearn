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
        queue<TreeNode *> help; // 使用队列辅助进行层序遍历
        vector<vector<int>> ans;
        if (root)
            help.push(root);

        // bfs   与普通bfs不同的是，这个需要返回每一层的数据，所以多了一个写入的部分
        // 内层的vector数据写入靠一个for循环，循环次数根据每一层的数据数目定
        // 在for循环中处理每一层，使得每一次的size()获取到的都是一层的数据的数目
        while (!help.empty())
        {
            vector<int> temp;
            for (int i = help.size(); i > 0; i--)
            {
                root = help.front();
                help.pop();
                temp.push_back(root->val);
                if (root->left) // 与普通bfs一样 左右孩子有就要入队
                    help.push(root->left);
                if (root->right)
                    help.push(root->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};