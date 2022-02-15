#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define NA -1

int followerChain(vector<int> *rgraph, int node, int ban)
{
    int maxLen = 0;
    for (int n : rgraph[node])
        if (n != ban)
            maxLen = max(maxLen, followerChain(rgraph, n, ban));
    return maxLen + 1;
}

int main(void)
{
    // read
    int tests, kids;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> kids;
        int *next = new int[kids];
        vector<int> *rgraph = new vector<int>[kids];
        for (int i = 0; i < kids; i++)
        {
            cin >> next[i];
            rgraph[--next[i]].push_back(i);
        }

        // largest cycle
        pair<int, int> *cycle = new pair<int, int>[kids]; // (cycle start, curr pos)
        fill(cycle, cycle + kids, make_pair(NA, NA));
        int largestCycle = 0;
        for (int i = 0, curr, ct; i < kids; i++)
        {
            for (curr = i, ct = 0; cycle[curr].first == NA; curr = next[curr], ct++)
                cycle[curr] = make_pair(i, ct);
            if (cycle[curr].first == i)
                largestCycle = max(largestCycle, ct - cycle[curr].second);
        }

        // partners (cycle of 2)
        int combineLen = 0;
        for (int i = 0; i < kids; i++)
            if (next[next[i]] == i)
                combineLen += followerChain(rgraph, i, next[i]);

        // print and delete
        cout << "Case #" << (test + 1) << ": " << max(largestCycle, combineLen) << endl;
        delete[] next;
        delete[] rgraph;
        delete[] cycle;
    }
}