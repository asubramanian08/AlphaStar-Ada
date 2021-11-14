#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void DFS(int node, bool *vis, int *letCon)
{
    if (vis[node])
        return;
    vis[node] = true;
    for (int i = 0; i < 26; i++)
        if (letCon[node] & (1 << i))
            DFS(i, vis, letCon);
}

int main(void)
{
    int numPass;
    cin >> numPass;
    int *pass = new int[numPass];
    for (int i = 0; i < numPass; i++)
    {
        string str;
        cin >> str;
        pass[i] = 0;
        for (char ch : str)
            pass[i] |= 1 << (ch - 'a');
    }
    int *letCon = new int[26];
    for (int i = 0; i < 26; i++)
        letCon[i] = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < numPass; j++)
            if (pass[j] & (1 << i))
                letCon[i] |= pass[j];
    bool *vis = new bool[26];
    for (int i = 0; i < 26; i++)
        if (letCon[i] == 0)
            vis[i] = true;
        else
            vis[i] = false;
    int groupCt = 0;
    for (int i = 0; i < 26; i++)
        if (!vis[i])
        {
            groupCt++;
            DFS(i, vis, letCon);
        }
    cout << groupCt << endl;
    return 0;
}