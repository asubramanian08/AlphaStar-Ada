#include <iostream>
using namespace std;

int *depth, *dCt, n, x;

int main(void)
{
    cin >> n;
    depth = new int[n];
    dCt = new int[n];
    for (int i = 0; i < n; i++)
        dCt[i] = 0;
    depth[0] = 0;
    dCt[0] = 1;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        depth[i] = depth[x - 1] + 1;
        dCt[depth[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += dCt[i] % 2;
    cout << ans << endl;
    return 0;
}