#include <iostream>
#include <cstring>

using namespace std;

char* addStrings(const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = max(len1, len2);

    char* result = new char[maxLen + 2]; // +1 for carry, +1 for '\0'
    result[maxLen + 1] = '\0';

    int carry = 0;
    int i = len1 - 1, j = len2 - 1, k = maxLen;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[k] = (sum % 10) + '0';

        i--;
        j--;
        k--;
    }
    // 处理可能存在的前导0
    if (result[0] == '0' && maxLen > 0) {
        char* newResult = new char[maxLen+1];
        strcpy(newResult,&result[1]);
        delete[] result;
        return newResult;
    }

    return result;
}

int main() {
    const char* num1 = "123456";
    const char* num2 = "1234567";

    char* sum = addStrings(num1, num2);
    cout << "Sum: " << sum << endl;

    delete[] sum; // 释放内存

    const char* num3 = "999";
    const char* num4 = "1";

    char* sum2 = addStrings(num3, num4);
    cout << "Sum2: " << sum2 << endl;

    delete[] sum2;

    return 0;
}