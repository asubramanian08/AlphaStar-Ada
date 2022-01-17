#include <iostream>
#include <vector>
using namespace std;

int DFS(int node, bool *vis, vector<int> *graph, int *subtree)
{
    if (vis[node])
        return 0;
    vis[node] = true;
    subtree[node] = 1;
    for (int next : graph[node])
        subtree[node] += DFS(next, vis, graph, subtree);
    return subtree[node];
}

int main(void)
{
    // read
    int numNodes;
    cin >> numNodes;
    vector<int> *graph = new vector<int>[numNodes];
    for (int i = 1; i < numNodes; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        n1--, n2--;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    // subtree size
    bool *vis = new bool[numNodes];
    for (int i = 0; i < numNodes; i++)
        vis[i] = false;
    int *subtree = new int[numNodes];
    DFS(0, vis, graph, subtree);

    // count removals: even subtrees
    int ans = 0;
    for (int i = 0; i < numNodes; i++)
        ans += subtree[i] % 2 == 0;

    // print and delete
    cout << (numNodes % 2 ? -1 : ans - 1) << endl;
    delete[] graph;
    delete[] vis;
    delete[] subtree;
    return 0;
}