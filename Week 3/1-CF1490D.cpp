#include <iostream>
using namespace std;

int *perm, *depth;
void recursiveDepth(int lo, int hi, int dpt)
{
    if (lo >= hi)
        return;
    int mx = lo;
    for (int i = lo + 1; i < hi; i++)
        if (perm[i] > perm[mx])
            mx = i;
    depth[mx] = dpt;
    recursiveDepth(lo, mx, dpt + 1);
    recursiveDepth(mx + 1, hi, dpt + 1);
}

int main(void)
{
    int tests, permLen;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> permLen;
        perm = new int[permLen];
        for (int i = 0; i < permLen; i++)
            cin >> perm[i];
        depth = new int[permLen];
        recursiveDepth(0, permLen, 0);
        for (int i = 0; i < permLen; i++)
            cout << depth[i] << ' ';
        cout << endl;
        delete[] perm;
        delete[] depth;
    }
    return 0;
}