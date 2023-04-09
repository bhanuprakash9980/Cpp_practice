#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    auto render = [](auto collection)
    {
        for (const auto &val : collection)
        {
            cout << val << endl;
        }
    };

    vector<int> intCollection{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> outCollection;
    transform(intCollection.begin(), intCollection.end(), back_inserter(outCollection), [](const int &value)
              { return value * 3; });
    cout << "Transform" << endl;
    render(outCollection);

    vector<int> filterCollection;
    copy_if(outCollection.begin(), outCollection.end(), back_inserter(filterCollection), [](const int &value)
            { return value % 2 != 0; });
    cout << "copy_if" << endl;
    render(filterCollection);

    int results = accumulate(filterCollection.begin(), filterCollection.end(), 0, [](int total, int current)
                             { return total + current; });
    cout << "accumulate" << endl;
    cout << "results = " << results << endl;
    return 0;
}