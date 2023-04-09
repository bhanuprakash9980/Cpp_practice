#include <iostream>
using namespace std;

auto addCurry = [](auto a)
{
    return [a](auto b)
    {
        return [a, b](auto c)
        {
            return a + b + c;
        };
    };
};

int main()
{
    auto added1 = addCurry(1);
    auto added2 = added1(10);
    auto addResuts = added2(100);
    cout << "resuts: " << addResuts << endl;
    auto allAtOnce = addCurry(990000)(9900)(99);
    cout << "All resuts: " << allAtOnce << endl;
    return 0;
}