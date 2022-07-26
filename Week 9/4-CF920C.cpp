#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    string str;
    cin >> str;
    str += '0';
    int lastHigh = 0, currHigh = 0;
    bool works = true;
    for (int i = 0; i < n && works; i++)
    {
        works = arr[i] > lastHigh;
        currHigh = max(currHigh, arr[i]);
        if (str[i] == '0')
            lastHigh = currHigh;
    }
    cout << (works ? "YES" : "NO") << endl;
    return 0;
}