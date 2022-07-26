#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

vector<pii> *graph;
int largestPath(int v, int p)
{
    int path = 0;
    for (pii next : graph[v])
        if (next.first != p)
            path = max(path, largestPath(next.first, v) + next.second);
    return path;
}

int main(void)
{
    int n, u, v, c;
    cin >> n;
    graph = new vector<pii>[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    cout << largestPath(0, -1) << endl;
    return 0;
}