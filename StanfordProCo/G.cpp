// Failed on test case 3
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_ASSIGNMENTS 1005
#define MAX_TIME 1005

struct assignment
{
    int ID, points, time, due;
    bool operator<(const assignment &a) const { return ID < a.ID; }
};

int main(void)
{
    int assignmentCt, time;
    cin >> assignmentCt >> time;
    assignment *assignments = new assignment[assignmentCt];
    for (int i = 0; i < assignmentCt; i++)
        cin >> assignments[i].ID >> assignments[i].points >>
            assignments[i].time >> assignments[i].due;
    sort(assignments, assignments + assignmentCt);
    int bestScore[MAX_ASSIGNMENTS][MAX_TIME] = {0};
    for (int i = 0; i < assignmentCt; i++)
        for (int j = 0; j <= time; j++)
        {
            if (j + assignments[i].time <= assignments[i].due)
                bestScore[i + 1][j + assignments[i].time] =
                    max(bestScore[i + 1][j + assignments[i].time],
                        bestScore[i][j] + assignments[i].points);
            bestScore[i + 1][j] = max(bestScore[i + 1][j], bestScore[i][j]);
            bestScore[i][j + 1] = max(bestScore[i][j + 1], bestScore[i][j]);
        }
    cout << bestScore[assignmentCt - 1][time] << endl;
    return 0;
}