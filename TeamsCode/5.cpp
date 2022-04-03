#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    long long tests, x, y, maxX, minX, maxY, minY, junk;
    string str;
    cin >> tests;
    while (tests--)
    {
        x = y = maxX = minX = maxY = minY = 0;
        cin >> junk >> str;
        for (char ch : str)
            if (ch == 'U')
                maxY = max(maxY, ++y);
            else if (ch == 'D')
                minY = min(minY, --y);
            else if (ch == 'R')
                maxX = max(maxX, ++x);
            else
                minX = min(minX, --x);
        cout << ((maxX - minX + 1) * (maxY - minY + 1)) << endl;
    }
    return 0;
}