#include <iostream>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll findClosest(int x, int *row, int n)
{
    pii closest(abs(row[0] - x), 0);
    for (int i = 1; i < n; i++)
        closest = min(closest, {abs(row[i] - x), i});
    return closest.second;
}

int main(void)
{
    int tests, n, *top, *bottom;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        top = new int[n];
        bottom = new int[n];
        for (int i = 0; i < n; i++)
            cin >> top[i];
        for (int i = 0; i < n; i++)
            cin >> bottom[i];
        ll leftLinks[] = {0, findClosest(top[0], bottom, n), n - 1};
        ll rightLinks[] = {0, findClosest(top[n - 1], bottom, n), n - 1};
        ll bottomLeftClosest = findClosest(bottom[0], top, n);
        bottomLeftClosest = abs(bottom[0] - top[bottomLeftClosest]);
        ll bottomRightClosest = findClosest(bottom[n - 1], top, n);
        bottomRightClosest = abs(bottom[n - 1] - top[bottomRightClosest]);
        ll ans = 10'000'000'000LL;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                ll cost = abs(top[0] - bottom[leftLinks[i]]) +
                          abs(top[n - 1] - bottom[rightLinks[j]]);
                if (leftLinks[i] != 0 && rightLinks[j] != 0)
                    cost += bottomLeftClosest;
                if (leftLinks[i] != n - 1 && rightLinks[j] != n - 1)
                    cost += bottomRightClosest;
                ans = min(ans, cost);
            }
        cout << ans << endl;
        delete[] top;
        delete[] bottom;
    }
    return 0;
}