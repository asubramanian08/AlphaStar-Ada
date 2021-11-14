#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
    // read
    int tests;
    cin >> tests;
    for (int run = 0; run < tests; run++)
    {
        int nodes, opers;
        cin >> nodes >> opers;
        if (nodes == 1)
        {
            cout << 0 << endl;
            continue;
        }
        vector<int> *graph = new vector<int>[nodes];
        for (int i = 1; i < nodes; i++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            n1--, n2--;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }

        // set up: q, size, on
        queue<pair<int, int> > q;
        int *size = new int[nodes];
        for (int i = 0; i < nodes; i++)
        {
            size[i] = graph[i].size();
            if (size[i] == 1)
                q.push(make_pair(i, 1));
        }
        int ans = nodes;

        // simulate remove leaves
        while (!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();
            ans--;
            if (node.second == opers)
                continue;
            for (int conn : graph[node.first])
            {
                size[conn]--;
                if (size[conn] == 1)
                    q.push(make_pair(conn, node.second + 1));
            }
        }

        // print and delete
        cout << ans << endl;
        delete[] graph;
        delete[] size;
    }
    return 0;
}