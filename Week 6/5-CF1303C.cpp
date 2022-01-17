#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define NA -1
#define LETTERS 26

int main(void)
{
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        string str;
        cin >> str;
        int(*side)[2] = new int[LETTERS][2];
        for (int i = 0; i < LETTERS; i++)
            side[i][0] = side[i][1] = NA;
        bool works = true;
        for (int i = 1; i < str.size() && works; i++)
        {
            int prevPos = str[i - 1] - 'a';
            int currPos = str[i] - 'a';
            bool type = side[prevPos][0] != NA;
            if (side[currPos][0] != NA || side[currPos][1] != NA || side[prevPos][type] != NA)
            {
                works = (side[currPos][0] == prevPos) ||
                        (side[currPos][1] == prevPos);
                continue;
            }
            side[prevPos][type] = currPos;
            side[currPos][!type] = prevPos;
        }
        cout << (works ? "YES" : "NO") << endl;
        if (!works)
        {
            delete[] side;
            continue;
        }
        bool *added = new bool[LETTERS];
        fill(added, added + LETTERS, false);
        auto leftMost = [side](int let)
        {
            while (side[let][0] != NA)
                let = side[let][0];
            return let;
        };
        string ansStr;
        for (int i = 0; i < LETTERS; i++)
            if (!added[i])
                for (int left = leftMost(i); left != NA; left = side[left][1])
                {
                    ansStr += left + 'a';
                    added[left] = true;
                }
        cout << ansStr << endl;
        delete[] side;
        delete[] added;
    }
    return 0;
}