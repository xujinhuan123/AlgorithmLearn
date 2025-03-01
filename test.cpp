#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(42);
    cout << "Top of stack: " << s.top() << endl;
    s.pop();
    cout << "Stack is empty: " << boolalpha << s.empty() << endl;
    return 0;
}