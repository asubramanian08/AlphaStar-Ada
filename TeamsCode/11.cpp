#include <iostream>
using namespace std;

int main(void)
{
    int tests;
    cin >> tests;
    while (tests--)
    {
        long long N, A, B, C = 0, log;
        cin >> N >> A >> B;
        if (A > B)
            swap(A, B);
        if (A == B)
        {
            cout << 0 << endl;
            continue;
        }
        bool same = true;
        for (log = 0; N & (1 << log); log++)
            ;
        for (int bit = log - 1; bit >= 0; bit--, same &= ((A & (1 << bit)) == (B & (1 << bit))))
            C += ((same ? A : B) & (1 << bit)) ^ (1 << bit);
        cout << min(max(A ^ C ^ N, B ^ C ^ N), A ^ B ^ N) << endl;
    }
    return 0;
}