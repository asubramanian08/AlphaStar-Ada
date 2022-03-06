#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_ASSIGNMENTS 1005
#define MAX_TIME 2005

struct assignment
{
    int ID, points, len, due;
    bool operator<(const assignment &a) const { return ID < a.ID; }
};

int main(void)
{
    int assignmentCt, time;
    cin >> assignmentCt >> time;
    assignment *assignments = new assignment[assignmentCt];
    for (int i = 0; i < assignmentCt; i++)
        cin >> assignments[i].ID >> assignments[i].points >>
            assignments[i].len >> assignments[i].due;
    sort(assignments, assignments + assignmentCt);
    int bestScore[MAX_ASSIGNMENTS][MAX_TIME] = {0};
    for (int i = 0; i < assignmentCt; i++)
        for (int j = 0; j <= time; j++)
        {
            bestScore[i + 1][j] = max(bestScore[i + 1][j], bestScore[i][j]);
            if (j + assignments[i].len <= assignments[i].due)
                bestScore[i + 1][j + assignments[i].len] =
                    max(bestScore[i + 1][j + assignments[i].len],
                        bestScore[i][j] + assignments[i].points);
        }
    int ans = 0;
    for (int i = 0; i <= time; i++)
        ans = max(ans, bestScore[assignmentCt][i]);
    cout << ans << endl;
    return 0;
}