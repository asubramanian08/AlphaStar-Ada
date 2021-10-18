#include <iostream>
using namespace std;

using pii = pair<int, int>;

int main(void)
{
    int boardSize;
    pii queen, king, dest;
    cin >> boardSize >>
        queen.first >> queen.second >>
        king.first >> king.second >>
        dest.first >> dest.second;
    bool sameQuadrent = ((king.first < queen.first) == (dest.first < queen.first)) &&
                        ((king.second < queen.second) == (dest.second < queen.second));
    cout << (sameQuadrent ? "YES" : "NO") << endl;
    return 0;
}