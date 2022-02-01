#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define LETTERS 26

int main(void)
{
    // read
    int numWords;
    cin >> numWords;
    string *wordsTemp = new string[numWords];
    for (int i = 0; i < numWords; i++)
        cin >> wordsTemp[i];
    int *lOrder = new int[numWords];
    for (int i = 0; i < numWords; i++)
    {
        cin >> lOrder[i];
        lOrder[i]--;
    }

    // correctly order words
    string *words = new string[numWords];
    for (int i = 0; i < numWords; i++)
    {
        words[i] = wordsTemp[lOrder[i]];
        for (int j = 0; j < words[i].size(); j++)
            words[i][j] -= 'a';
    }

    // setup directed graph of letters
    vector<int> graph[LETTERS];
    int inorder[LETTERS] = {0};
    for (int i = 1, firstDiff; i < numWords; i++)
    {
        int smallestLen = min(words[i].size(), words[i - 1].size());
        for (firstDiff = 0; firstDiff < smallestLen; firstDiff++)
            if (words[i][firstDiff] != words[i - 1][firstDiff])
                break;
        if (firstDiff != smallestLen)
        {
            graph[words[i - 1][firstDiff]].push_back(words[i][firstDiff]);
            inorder[words[i][firstDiff]]++;
        }
        else if (smallestLen != words[i - 1].size())
            inorder[words[i][firstDiff]]++; // force NE
    }

    // BFS though next letters
    vector<int> order;
    int processing = 0;
    for (int i = 0; i < LETTERS; i++)
        if (inorder[i] == 0)
            order.push_back(i);
    while (processing != order.size())
    {
        for (int next : graph[order[processing]])
            if ((--inorder[next]) == 0)
                order.push_back(next);
        processing++;
    }

    // print and delete
    cout << (order.size() != LETTERS ? "NE" : "DA") << endl;
    if (order.size() == LETTERS)
    {
        char key[LETTERS];
        for (int i = 0; i < LETTERS; i++)
            key[order[i]] = i + 'a';
        for (int i = 0; i < LETTERS; i++)
            cout << key[i];
    }
    delete[] wordsTemp;
    delete[] lOrder;
    delete[] words;
    return 0;
}