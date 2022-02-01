#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    // read
    int fighters;
    cin >> fighters;
    int *adversary = new int[fighters];
    for (int i = 0; i < fighters; i++)
        cin >> adversary[i];
    int *dwarves = new int[fighters];
    for (int i = 0; i < fighters; i++)
        cin >> dwarves[i];
    int *elves = new int[fighters];
    for (int i = 0; i < fighters; i++)
        cin >> elves[i];

    // entry points: 2 passes
    set<int> *waiting = new set<int>[fighters];
    for (int i = 0; i < fighters; i++)
        waiting[adversary[i] - 1].insert(elves[i]);
    set<int> searching;
    int victories = 0;
    for (int pass = 0, selectedFighter; pass < 2; pass++)
        for (int i = 0; i < fighters; i++)
        {
            searching.merge(waiting[i]);
            waiting[i].clear();
            if (searching.empty())
                continue;
            auto bestPos = searching.lower_bound(dwarves[i]);
            if (bestPos != searching.end())
                selectedFighter = *bestPos, victories += pass;
            else
                selectedFighter = *searching.begin();
            searching.erase(selectedFighter);
            waiting[i].insert(selectedFighter);
        }

    // print and delete
    cout << victories << endl;
    delete[] adversary;
    delete[] dwarves;
    delete[] elves;
    delete[] waiting;
    return 0;
}