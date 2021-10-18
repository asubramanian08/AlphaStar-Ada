#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    //read
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        string a, b;
        cin >> a >> b;

        //set indicies -> increase substring
        int best = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < b.size(); j++)
            {
                int len = 0;
                while ((i + len < a.size() && j + len < b.size()) &&
                       a[i + len] == b[j + len])
                    len++;
                best = max(best, len);
            }

        //print
        cout << (a.size() - best + b.size() - best) << endl;
    }
    return 0;
}