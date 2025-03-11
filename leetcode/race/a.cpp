#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution0
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int number = fruits.size();               // 每放入一个减一，最后数字为未放入的
        vector<int> useBasket(baskets.size(), 0); // 记录basket里面对应位置是否放入水果
        for (int i = 0; i < fruits.size(); i++)
        {
            // 遍历篮子，直到找到第一个可以放入的地方
            for (int j = 0; j < baskets.size(); j++)
            {
                if (useBasket[j] != 0) // 已经被放入其它的了
                    continue;
                if (fruits[i] <= baskets[j]) // 大小足够
                {
                    baskets.erase(baskets.begin() + j);
                    baskets.shrink_to_fit();
                    number--;
                    useBasket[j] = 1;
                    break; // 找到了
                }
            }
        }
        return number;
    }
};

class Solution
{
public:
    vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<long long> ans;
        vector<int> help(k, 0);
        long long sum = 0;
        for (int i = 0; i < nums1.size(); i++) // 对nums1的每一个下标操作
        {
            queue<int> maxk(deque<int>(help.begin(), help.end())); // 创建一个k大小的队列存放最大的k个数
            for (int j = 0; j < nums1.size(); j++)
            {
                if (nums1[j] < nums1[i])
                {
                    if (nums2[j] > maxk.front())
                    {
                        maxk.pop();
                        maxk.push(nums2[j]);
                    }
                }
            }
            sum = 0;
            while (!maxk.empty())
            {
                sum += maxk.front();
                maxk.pop();
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums1 = {4, 2, 1, 5, 3};
    vector<int> nums2 = {10, 20, 30, 40, 50};
    int k = 2;
    Solution sol;
    vector<long long> ans = sol.findMaxSum(nums1, nums2, k);
    cout << "end" << endl;
    return 0;
}