#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // 打印心形图案
    for (float y = 1.5; y > -1.5; y -= 0.1)
    {
        for (float x = -1.5; x < 1.5; x += 0.05)
        {
            float a = x * x + y * y - 1;
            if (pow(a, 3) - x * x * pow(y, 3) <= 0.0)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    // 输出祝福语
    cout << "\n亲爱的留守儿童们，愿你们充满勇气与希望，追逐梦想，迎接美好未来！" << endl;
    return 0;
}
