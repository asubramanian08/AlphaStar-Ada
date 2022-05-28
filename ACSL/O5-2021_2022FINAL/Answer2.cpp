#include <bits/stdc++.h>

using namespace std;



#define TILES 5
#define MAX_COMB (1 << TILES)

int fibonacci(int cardinalNumber)
{
    switch (cardinalNumber)
    {
    case 0:
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        return 5;
    }
}

int totalFibLength(int bitMask)
{
    int totalLen = 0;
    for (int i = 0; i < TILES; i++)
        if (bitMask & (1 << i))
            totalLen += fibonacci(i);
    return totalLen;
}

char colorSwitch(bool hour, bool min, bool sec)
{
    int h = hour ? (1 << 2) : 0;
    int m = min ? (1 << 1) : 0;
    int s = sec ? (1 << 0) : 0;
    switch (h + m + s)
    {
    case 1:
        return 'b';
    case 2:
        return 'g';
    case 3:
        return 'c';
    case 4:
        return 'r';
    case 5:
        return 'm';
    case 6:
        return 'y';
    case 7:
        return 'w';
    default:
        return 'k';
    }
}

string formColoring(int hourMask, int minMask, int secMask)
{
    string coloring;
    for (int i = 0; i < TILES; i++)
        coloring += colorSwitch(hourMask & (1 << i), minMask & (1 << i), secMask & (1 << i));
    return coloring;
}

/*
 * Complete the 'displayTime' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING time as parameter.
 */

string displayTime(string time)
{
    // prepare data
    int hours = (time[0] - '0') * 10 + (time[1] - '0');
    int mins = (time[3] - '0') * 10 + (time[4] - '0');
    int secs = (time[6] - '0') * 10 + (time[7] - '0');
    vector<string> clocks;
    int hLen = 0, mLen = 0, sLen = 0;

    // test all possible clock setups
    for (int h = 0; h < MAX_COMB; h++, hLen = totalFibLength(h))
        if (hLen == hours)
            for (int m = 0; m < MAX_COMB; m++, mLen = totalFibLength(m))
                if (mLen * 5 == mins)
                    for (int s = 0; s < MAX_COMB; s++, sLen = totalFibLength(s))
                        if (sLen * 5 == secs)
                            clocks.push_back(formColoring(h, m, s));

    // sort and space the clocks
    sort(clocks.begin(), clocks.end());
    string times = clocks[0];
    for (int i = 1; i < clocks.size(); i++)
        times += " " + clocks[i];
    return times;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string time;
    getline(cin, time);

    string result = displayTime(time);

    fout << result << "\n";

    fout.close();

    return 0;
}
