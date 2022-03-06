// Failed on test case 8
#include <iostream>
#include <algorithm>
using namespace std;

struct assignment
{
    int ID, points, time;
    bool operator<(const assignment &a) const
    {
        bool ret = points * a.time < a.points * time;
        if (points * a.time == a.points * time)
            return ID > a.ID;
        return ret;
    }
};

int main(void)
{
    int HW_ct;
    cin >> HW_ct;
    assignment *assignments = new assignment[HW_ct];
    for (int i = 0; i < HW_ct; i++)
        cin >> assignments[i].ID >> assignments[i].points >> assignments[i].time;
    sort(assignments, assignments + HW_ct);
    for (int i = HW_ct - 1; i >= 0; i--)
        cout << assignments[i].ID << endl;
    return 0;
}