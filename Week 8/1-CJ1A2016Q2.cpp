#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    int tests, len, num;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> len;
        map<int, int> count;
        for (int i = 1; i < 2 * len; i++)
            for (int j = 0; j < len; j++)
            {
                cin >> num;
                count[num]++;
            }
        cout << "Case #" << test << ':';
        for (pair<int, int> val : count)
            if (val.second % 2 == 1)
                cout << ' ' << val.first;
        cout << endl;
    }
}