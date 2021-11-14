#include <iostream>
#include <vector>
using namespace std;

#define NA -1
void DFS(int node, vector<int> *graph, int *component, int setComponent)
{
    if (component[node] != NA)
        return;
    component[node] = setComponent;
    for (int next : graph[node])
        DFS(next, graph, component, setComponent);
}

int main(void)
{
    // read
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> *graph = new vector<int>[nodes];
    for (int i = 0; i < edges; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        n1--, n2--;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    // components
    int *component = new int[nodes];
    for (int i = 0; i < nodes; i++)
        component[i] = NA;
    int numComponents = 0;
    for (int i = 0; i < nodes; i++)
        if (component[i] == NA)
            DFS(i, graph, component, ++numComponents);

    // is_cycle
    bool *is_cycle = new bool[numComponents];
    for (int i = 0; i < numComponents; i++)
        is_cycle[i] = true;
    for (int i = 0; i < nodes; i++)
        if (graph[i].size() != 2)
            is_cycle[component[i] - 1] = false;

    // print and delete
    int cycleCount = 0;
    for (int i = 0; i < numComponents; i++)
        cycleCount += is_cycle[i];
    cout << cycleCount << endl;
    delete[] graph;
    delete[] component;
    delete[] is_cycle;
    return 0;
}