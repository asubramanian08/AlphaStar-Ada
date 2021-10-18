#include <iostream>
using namespace std;

int main(void)
{
    //read
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int elements, divTest;
        cin >> elements >> divTest;
        int *remainders = new int[divTest];
        for (int i = 0; i < divTest; i++)
            remainders[i] = 0;
        int ele;
        for (int i = 0; i < elements; i++)
        {
            cin >> ele;
            remainders[ele % divTest]++;
        }

        //groupings
        int count = 0;
        for (int i = 0; i <= divTest / 2; i++)
        {
            int other = (divTest - i) % divTest;
            count += remainders[i] != 0 || remainders[other] != 0;
            if (remainders[i] != remainders[other])
                count += max(remainders[i], remainders[other]) - min(remainders[i], remainders[other]) - 1;
        }
        cout << count << endl;
    }
    return 0;
}