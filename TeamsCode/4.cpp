#include <iostream>
using namespace std;

int main(void)
{
    int tests;
    long long n, t;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> n;
        cout << n << ' ' << (n + 1) << ' ';
        long t = n + n + 1;
        cout << t << ' ' << t << endl;
    }
    return 0;
}