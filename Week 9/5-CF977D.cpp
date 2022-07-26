#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll log3(ll x)
{
    ll l = 0;
    while (x % 3 == 0)
    {
        x /= 3;
        l++;
    }
    return l;
}

int main(void)
{
    ll n, x;
    cin >> n;
    pii *arr = new pii[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = pii(-log3(x), x);
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i].second << ' ';
    cout << endl;
    return 0;
}