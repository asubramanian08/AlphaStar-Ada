#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define TOTAL_LET 26

int main(void)
{
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        int wordLen, repeat;
        cin >> wordLen >> repeat;
        string word;
        cin >> word;
        int toChoose = repeat / 2 + repeat % 2;
        int(*letterCt)[TOTAL_LET] = new int[toChoose][TOTAL_LET];
        for (int i = 0; i < toChoose; i++)
            fill(letterCt[i], letterCt[i] + TOTAL_LET, 0);
        for (int i = 0; i < wordLen; i++)
        {
            int pos = i % repeat;
            if (pos > toChoose - 1)
                pos = repeat - pos - 1;
            letterCt[pos][word[i] - 'a']++;
        }
        int cost = 0, numLet, maxLet;
        for (int i = 0; i < toChoose; i++)
        {
            numLet = maxLet = 0;
            for (int j = 0; j < TOTAL_LET; j++)
            {
                numLet += letterCt[i][j];
                maxLet = max(maxLet, letterCt[i][j]);
            }
            cost += numLet - maxLet;
        }
        cout << cost << endl;
        delete[] letterCt;
    }
    return 0;
}