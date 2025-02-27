#include <iostream>
#include <cstring>

int kmp(char *string, char *pattern) // 返回pattern在string中出现的第一个位置
{
    // 求pattern的next数组 使用已经计算出来的next数组来计算剩下的
    int *next = new int[strlen(pattern)];
    next[0] = 0;
    for (int i = 1; i < strlen(pattern); i++)
    {
        int j = next[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) // next[i-1]是加最后一个字母之前的最长公共前后缀，从next[i-1]的值的位置开始找，如果相等就加一，如果不相等说明这个位置的值不能加一，那么就从next[j-1]的值开始找，直到找到相等的位置，或者j=0为止
            j = next[j - 1];
        if (pattern[i] == pattern[j])
            next[i] = j + 1;
        else
            next[i] = 0;
    }
    // 使用next数组进行匹配
    int i = 0, j = 0;
    while (i < strlen(string) && j < strlen(pattern))
    {
        if (string[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
                j = next[j - 1];
            else
                i++; // 当j == 0时，直接移动主串指针
        }
    }
    int result = -1;
    if (j == strlen(pattern))
        result = i - j;
    delete[] next; // 清理内存
    return result;
}

int main()
{
    char string[10] = "ababaca";
    char pattern[10] = "aca";
    int result = kmp(string, pattern);
    std::cout << result << std::endl;
    return 0;
}