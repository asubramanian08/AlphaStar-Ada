#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'findTime' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. CHARACTER c1
 *  2. CHARACTER c2
 *  3. CHARACTER c3
 *  4. CHARACTER c4
 *  5. CHARACTER c5
 */

string findTime(char c1, char c2, char c3, char c4, char c5) {
    string input = {c1, c2, c3, c4, c5};
    int value[] = {1, 1, 2, 3, 5};
    int hours = 0, minutes = 0;
    for (int i = 0; i < 5; i++) {
        if (input[i] == 'R' || input[i] == 'B')
            hours += value[i];
        if (input[i] == 'G' || input[i] == 'B')
            minutes += value[i] * 5;
    }
    string ret;
    ret += '0' + hours / 10;
    ret += '0' + hours % 10;
    ret += ':';
    ret += '0' + minutes / 10;
    ret += '0' + minutes % 10;
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string c1_temp;
    getline(cin, c1_temp);

    char c1 = c1_temp[0];

    string c2_temp;
    getline(cin, c2_temp);

    char c2 = c2_temp[0];

    string c3_temp;
    getline(cin, c3_temp);

    char c3 = c3_temp[0];

    string c4_temp;
    getline(cin, c4_temp);

    char c4 = c4_temp[0];

    string c5_temp;
    getline(cin, c5_temp);

    char c5 = c5_temp[0];

    string result = findTime(c1, c2, c3, c4, c5);

    fout << result << "\n";

    fout.close();

    return 0;
}
