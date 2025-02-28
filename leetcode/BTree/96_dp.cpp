#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp = dpCacu(n);
        return dp[n];
    }
    vector<int> dpCacu(int n)
    {
        if (n == 0)
            return vector<int>();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[i - j] * dp[j - 1]; // 无需关心j 只需要确定剩余结点数是i-1,i-j+j-1=i-1就好  左边的数的数目*右边的数的数目就是结点i作为根节点的BST的数目
            }
        }
        return dp;
    }
};

int main()
{
    return 0;
}