#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define NA -1

int BFS(int *connect, int currConnect, int src, vector<int> *friends)
{
    int added = 0;
    queue<int> q;
    q.push(src);
    connect[src] = currConnect;
    added++;
    while (!q.empty())
    {
        for (int next : friends[q.front()])
            if (connect[next] == NA)
            {
                connect[next] = currConnect;
                added++;
                q.push(next);
            }
        q.pop();
    }
    return added;
}

int main(void)
{
    // read
    int users, groups;
    cin >> users >> groups;
    vector<int> *friends = new vector<int>[users];
    for (int i = 0; i < groups; i++)
    {
        int groupSz, mainFriend, groupee;
        cin >> groupSz;
        if (groupSz == 0)
            continue;
        cin >> mainFriend;
        for (int j = 1; j < groupSz; j++)
        {
            cin >> groupee;
            friends[groupee - 1].push_back(mainFriend - 1);
            friends[mainFriend - 1].push_back(groupee - 1);
        }
    }

    // connected size
    int *connect = new int[users];
    for (int i = 0; i < users; i++)
        connect[i] = NA;
    vector<int> connectSize;
    for (int i = 0; i < users; i++)
        if (connect[i] == NA)
            connectSize.push_back(BFS(connect, connectSize.size(), i, friends));

    // print and delete
    for (int i = 0; i < users; i++)
        cout << connectSize[connect[i]] << ' ';
    delete[] friends;
    delete[] connect;
    return 0;
}