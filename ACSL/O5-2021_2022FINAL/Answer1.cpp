#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'createWave' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER waveLength
 *  2. STRING numbers
 */

string createWave(int waveLength, string numbers)
{
    // convert numbers in to a vector on ints
    numbers += ' ';
    vector<int> numList;
    int currNum = 0;
    for (char ch : numbers)
        if (ch != ' ')
            currNum = (currNum * 10) + (ch - '0');
        else
        {
            numList.push_back(currNum);
            currNum = 0;
        }

    // create the wave pattern
    int minWaveLen = waveLength * (waveLength + 1) / 2;
    int dupNumbers = (minWaveLen + numList.size() - 1) / numList.size();
    vector<int> waveNums;
    for (int i = 0; i < dupNumbers; i++)
        copy(numList.begin(), numList.end(), back_inserter(waveNums));
    int startIdx = 0, endIdx;
    bool sortAscending = true;
    for (int currLen = waveLength; currLen > 0; currLen--)
    {
        endIdx = startIdx + currLen;
        if (sortAscending)
            sort(waveNums.begin() + startIdx, waveNums.begin() + endIdx, less<int>());
        else
            sort(waveNums.begin() + startIdx, waveNums.begin() + endIdx, greater<int>());
        startIdx = endIdx;
        sortAscending = !sortAscending;
    }
    if (startIdx < waveNums.size())
    {
        if (sortAscending)
            sort(waveNums.begin() + startIdx, waveNums.end(), less<int>());
        else
            sort(waveNums.begin() + startIdx, waveNums.end(), greater<int>());
    }

    // form the wave string
    string wave;
    for (int i = 0; i < waveNums.size(); i++)
    {
        wave.append(to_string(waveNums[i]));
        if (i != waveNums.size() - 1)
            wave.append(" ");
    }
    return wave;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string waveLength_temp;
    getline(cin, waveLength_temp);

    int waveLength = stoi(ltrim(rtrim(waveLength_temp)));

    string numbers;
    getline(cin, numbers);

    string result = createWave(waveLength, numbers);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
