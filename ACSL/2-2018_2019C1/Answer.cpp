#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    for (int test = 0; test < 5; test++)
    {
        string str;
        cin >> str;
        int ans = 0;
        for (int i = 0; i < str.length(); i++)
            if (test == 0)
                ans++;
            else if (test == 1)
                ans += str[i] - '0';
            else if (test == 2 && i % 2 == 0)
                ans += str[i] - '0';
            else if (test == 3)
                ans += str[i] - '0' == 4;
            else if (test == 4 && i == str.length() / 2 - 1 + str.length() % 2)
                ans = str[i] - '0';
        cout << ans << endl;
    }
    return 0;
}