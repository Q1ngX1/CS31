#include <iostream>
#include <string>
using namespace std;

void foo(int &)
{
}

void print()
{
    cout << endl;
}

template<typename T>
void print(T value)
{
    cout << value << endl;
}

template<typename T, typename... Args>
void print(T first, Args... rest)
{
    cout << first << " ";
    print(rest...);
}

int main()
{
    int x;
    foo(x);
    cout << x;
    return 0;
}