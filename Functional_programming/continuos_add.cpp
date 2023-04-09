#include <iostream>
using namespace std;

auto incrementer = [](int initial, int addBy)
{ auto increment = initial;
return [increment, addBy]() mutable {
    increment+=addBy;
    return increment;
}; };

int main()
{
    auto myInc = incrementer(5, 6);
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;
    return 0;
}