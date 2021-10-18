#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    // read
    int nodes;
    cin >> nodes;
    bool *respect = new bool[nodes];
    vector<int> *children = new vector<int>[nodes];
    for (int i = 0; i < nodes; i++)
    {
        int parent, resp;
        cin >> parent >> resp;
        if (parent != -1)
            children[parent - 1].push_back(i);
        respect[i] = resp;
    }

    // root
    bool *is_root = new bool[nodes];
    for (int i = 0; i < nodes; i++)
        is_root[i] = true;
    for (int i = 0; i < nodes; i++)
        for (int child : children[i])
            is_root[child] = false;

    // check remove
    vector<int> remove;
    for (int i = 0; i < nodes; i++)
    {
        bool toRemove = respect[i] && !is_root[i];
        for (int child : children[i])
            if (!respect[child])
                toRemove = false;
        if (toRemove)
            remove.push_back(i);
    }

    // print and delete
    for (int node : remove)
        cout << (node + 1) << ' ';
    if (remove.empty())
        cout << -1 << endl;
    delete[] respect;
    delete[] children;
    delete[] is_root;
    return 0;
}