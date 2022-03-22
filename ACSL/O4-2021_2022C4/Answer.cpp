#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'absResult' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. FLOAT realPartC
 *  2. FLOAT imagPartC
 */

string absResult(float realPartC, float imagPartC)
{
    string ret;
    float currReal = 0, currImag = 0;
    bool works = true;
    for (int i = 0; i < 5 && works; i++)
    {
        float newReal = currReal * currReal - currImag * currImag + realPartC;
        float newImag = currReal * currImag + currReal * currImag + imagPartC;
        currReal = newReal, currImag = newImag;
        if (currReal * currReal + currImag * currImag > 16)
        {
            ret = "ESCAPES " + to_string(i + 1);
            works = false;
        }
    }
    if (!works)
        return ret;
    ret = to_string(sqrt(currReal * currReal + currImag * currImag));
    int decimal = -1;
    for (int i = 0; i < ret.size() && decimal == -1; i++)
        if (ret[i] == '.')
            decimal = i;
    if (decimal + 4 < ret.length() && ret[decimal + 4] >= '5')
        ret[decimal + 3]++;
    ret.resize(decimal + 4);
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string realPartC_temp;
    getline(cin, realPartC_temp);

    float realPartC = stof(ltrim(rtrim(realPartC_temp)));

    string imagPartC_temp;
    getline(cin, imagPartC_temp);

    float imagPartC = stof(ltrim(rtrim(imagPartC_temp)));

    string result = absResult(realPartC, imagPartC);

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
