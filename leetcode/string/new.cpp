#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

int main()
{
    // ASCII 艺术大树各阶段图案
    const char *tree[] = {
        "        *        ",
        "       ***       ",
        "      *****      ",
        "     *******     ",
        "    *********    ",
        "   ***********   ",
        "  *************  ",
        " *************** ",
        "      |||||      ",
        "      |||||      "};
    const int treeLines = sizeof(tree) / sizeof(tree[0]);

    // 逐行显示大树的生长过程
    for (int i = 1; i <= treeLines; i++)
    {
// 清屏命令：Unix/Linux 使用 "clear"，Windows 使用 "cls"
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        // 打印当前阶段的大树图案
        for (int j = 0; j < i; j++)
        {
            cout << tree[j] << "\n";
        }
        cout << "\n愿留守儿童像这棵大树般，在关爱中茁壮成长，迎接充满希望的明天！\n";

        // 暂停 500 毫秒
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return 0;
}
