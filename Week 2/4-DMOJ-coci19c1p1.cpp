#include <iostream>
using namespace std;

long long digitSumDown(long long num)
{
    long long start = (num / 9) * 9;
    long long sum = (num / 9) * 45;
    for (long long i = start + 1; i <= num; i++)
        sum += i % 9;
    return sum;
}

int main(void)
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        long long left, right;
        cin >> left >> right;
        long long ans = digitSumDown(right) - digitSumDown(left - 1);
        cout << ans << endl;
    }
    return 0;
}