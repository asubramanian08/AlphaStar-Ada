#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'printNumbers' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER fibNumber as parameter.
 */

string printNumbers(int fibNumber)
{
    if (fibNumber == 1)
        return "1";
    int curr = 1, prev = 0, temp, pos = 2;
    while (curr < fibNumber)
    {
        temp = prev;
        prev = curr;
        curr += temp;
        pos++;
    }
    int *pascals = new int[pos];
    for (int i = 0; i < pos; i++)
        pascals[i] = 0;
    pascals[0] = 1;
    vector<int> nums;
    for (int i = 2; i < pos; i++)
    {
        for (int j = pos - 1; j > 0; j--)
            pascals[j] += pascals[j - 1];
        nums.push_back(pascals[pos - i - 1]);
    }
    string ans;
    for (int i = nums.size() - 1; i >= 0; i--)
        if (nums[i] != 0)
        {
            ans += to_string(nums[i]);
            ans += ' ';
        }
    ans.pop_back();
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string fibNumber_temp;
    getline(cin, fibNumber_temp);

    int fibNumber = stoi(ltrim(rtrim(fibNumber_temp)));

    string result = printNumbers(fibNumber);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
