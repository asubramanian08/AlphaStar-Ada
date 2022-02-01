#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'fibCypher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. CHARACTER key
 *  2. STRING msg
 */

string fibCypher(char key, string msg) {
    int fibPrev = 0, fibCurr = 1, keyDiff = key - 'a';
    string ans;
    for(char let : msg)
    {
        int temp = fibPrev;
        fibPrev = fibCurr;
        fibCurr += temp;
        int offset = (keyDiff + fibCurr) % 26 + 'a';
        int currAns = offset + let;
        if(!ans.empty())
            ans += ' ';
        ans += to_string(currAns);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string key_temp;
    getline(cin, key_temp);

    char key = key_temp[0];

    string msg;
    getline(cin, msg);

    string result = fibCypher(key, msg);

    fout << result << "\n";

    fout.close();

    return 0;
}
