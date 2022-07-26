#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, x;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        int maxEle = 0, components = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            maxEle = max(maxEle, x);
            components += (maxEle == i + 1);
        }
        cout << components << endl;
    }
    return 0;
}