#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int treeCt, maxHeight;
    cin >> treeCt >> maxHeight;
    using pii = pair<int, int>;
    pii *trees = new pii[treeCt];
    for (int i = 0; i < treeCt; i++)
        cin >> trees[i].first >> trees[i].second;
    sort(trees, trees + treeCt);
    int lastFail = 0, maxDist = 0;
    for (int i = 0; i < treeCt; i++)
        if (trees[i].second > maxHeight)
        {
            maxDist = max(maxDist, trees[i].first - lastFail - 2);
            lastFail = trees[i].first;
        }
    maxDist = max(maxDist, trees[treeCt - 1].first - lastFail - 1);
    cout << maxDist << endl;
    return 0;
}