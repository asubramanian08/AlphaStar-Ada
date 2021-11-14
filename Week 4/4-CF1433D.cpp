#include <iostream>
using namespace std;

int main(void)
{
    int tests;
    cin >> tests;
    while (tests--)
    {
        int districts;
        cin >> districts;
        int *gangs = new int[districts];
        int diffGang = 0;
        for (int i = 0; i < districts; i++)
        {
            cin >> gangs[i];
            if (gangs[i] != gangs[0])
                diffGang = i;
        }
        if (diffGang == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 1; i < districts; i++)
            if (gangs[i] != gangs[0])
                cout << "1 " << (i + 1) << endl;
            else
                cout << (diffGang + 1) << ' ' << (i + 1) << endl;
    }
    return 0;
}