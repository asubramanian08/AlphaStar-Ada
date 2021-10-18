#include <iostream>
using namespace std;

int main(void)
{
    int tests, len, num;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> len;
        int *minIndex = new int[len];
        for (int i = 0; i < len; i++)
        {
            cin >> num;
            minIndex[num / 2] = i;
        }
        for (int i = 1; i < len; i++)
            minIndex[i] = min(minIndex[i - 1], minIndex[i]);
        int best = len;
        for (int i = 0; i < len; i++)
        {
            cin >> num;
            best = min(best, i + minIndex[num / 2 - 1]);
        }
        cout << best << endl;
    }
    return 0;
}