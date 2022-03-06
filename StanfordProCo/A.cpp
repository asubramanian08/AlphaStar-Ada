#include <iostream>
#include <algorithm>
using namespace std;

struct assignment
{
    int ID, points, time;
    bool operator<(const assignment &a) const
    {
        double e1 = (double)points / time;
        double e2 = (double)a.points / a.time;
        return e1 == e2 ? ID < a.ID : e1 > e2;
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
    for (int i = 0; i < HW_ct; i++)
        cout << assignments[i].ID << endl;
    return 0;
}