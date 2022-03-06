// Failed on test case 6
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define DIST 4

int main(void)
{
    int platforms, mapLen;
    cin >> platforms >> mapLen;
    using pii = pair<int, int>;
    pii *plats = new pii[platforms];
    for (int i = 0; i < platforms; i++)
    {
        cin >> plats[i].first >> plats[i].second;
        plats[i].second += plats[i].first - 1;
    }
    vector<pii> plat;
    int start = plats[0].first, end = start;
    for (int i = 0; i < platforms; i++)
        if (plats[i].first <= end)
            end = max(end, plats[i].second);
        else
        {
            plat.push_back(pii(start, end));
            start = plats[i].first;
            end = plats[i].second;
        }
    plat.push_back(pii(start, end));
    int pos = plat[0].first;
    bool works = true;
    for (int i = 0, next; i < plat.size() - 1 && works; i = next)
    {
        next = i + 1;
        while (next < plat.size() && pos + DIST > plat[next].second)
            next++;
        works = next < plat.size() && plat[i].second + DIST >= plat[next].first;
        pos = max(pos + DIST, plat[next].first);
    }
    cout << works << endl;
    return 0;
}