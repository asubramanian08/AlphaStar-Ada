#include <iostream>
#include <vector>
using namespace std;

#define MAX_WIDTH 50
using pii = pair<int, int>;
int width;
bool grid[MAX_WIDTH][MAX_WIDTH];
#define BIG_NUM 1000000000

void floodfill(vector<pii> &canGo, pii pos)
{
    // this node
    if ((pos.first < 0 || pos.first >= width) ||
        (pos.second < 0 || pos.second >= width) ||
        grid[pos.first][pos.second])
        return;
    grid[pos.first][pos.second] = true;
    canGo.push_back(pos);
    // travel
    floodfill(canGo, pii(pos.first + 1, pos.second));
    floodfill(canGo, pii(pos.first, pos.second + 1));
    floodfill(canGo, pii(pos.first - 1, pos.second));
    floodfill(canGo, pii(pos.first, pos.second - 1));
}
int dist(pii p1, pii p2) { return (p1.first - p2.first) * (p1.first - p2.first) +
                                  (p1.second - p2.second) * (p1.second - p2.second); }

int main(void)
{
    // read
    pii loc, goal;
    cin >> width >> loc.first >> loc.second >> goal.first >> goal.second;
    loc.first--, loc.second--, goal.first--, goal.second--;
    for (int i = 0; i < width; i++)
        for (int j = 0; j < width; j++)
        {
            char inCh;
            cin >> inCh;
            grid[i][j] = inCh == '1';
        }

    // flood fill -> get can travel points
    vector<pii> locFlood, goalFlood;
    floodfill(locFlood, loc);
    floodfill(goalFlood, goal);

    // minDist + print
    int minDist = BIG_NUM;
    if (goalFlood.empty())
        minDist = 0;
    for (pii p1 : locFlood)
        for (pii p2 : goalFlood)
            minDist = min(minDist, dist(p1, p2));
    cout << minDist << endl;
    return 0;
}