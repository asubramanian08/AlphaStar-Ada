#include <iostream>
using namespace std;

#define MAX_SIDE 505
#define MAX_LOG 32

int main(void)
{
    int rows, cols, queries, threat;
    cin >> rows >> cols >> queries;
    int bitPS[MAX_SIDE][MAX_SIDE][MAX_LOG] = {0};
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= cols; j++)
        {
            cin >> threat;
            for (int bit = 0; bit < MAX_LOG; bit++)
                if (threat & (1 << bit))
                    bitPS[i][j][bit] = 1;
                else
                    bitPS[i][j][bit] = 0;
        }
    for (int bit = 0; bit < MAX_LOG; bit++)
        for (int i = 1; i < MAX_SIDE; i++)
            for (int j = 1; j < MAX_SIDE; j++)
                bitPS[i][j][bit] += bitPS[i][j - 1][bit] + bitPS[i - 1][j][bit] - bitPS[i - 1][j - 1][bit];
    int x1, y1, x2, y2, ans;
    for (int i = 0; i < queries; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, ans = 0;
        for (int bit = 0; bit < MAX_LOG; bit++)
            if (bitPS[x2][y2][bit] - bitPS[x1][y2][bit] - bitPS[x2][y1][bit] + bitPS[x1][y1][bit])
                ans += 1 << bit;
        cout << ans << endl;
    }
}