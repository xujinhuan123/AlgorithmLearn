#include <iostream>
#include <vector>
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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n)
            return gener(1, n);
        else
            return vector<TreeNode *>{};
    }
    vector<TreeNode *> gener(int left, int right)
    {
        vector<TreeNode *> res;
        if (left > right)
        {
            res.push_back(nullptr);
            return res;
        }
        for (int i = left; i <= right; i++)
        {
            vector<TreeNode *> lefts = gener(left, i - 1);
            vector<TreeNode *> rights = gener(i + 1, right);
            for (auto left : lefts)
                for (auto right : rights)
                    res.push_back(new TreeNode(i, left, right));
        }
        return res;
    }
};
int main()
{
    return 0;
}