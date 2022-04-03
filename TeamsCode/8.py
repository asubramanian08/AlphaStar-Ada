import math
rows, cols = input().split(' ')
rows = int(rows) + 1
cols = int(cols) + 1
grid = []
for i in range(rows):
    grid.append(input().strip().split())
ans = 0
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == "A":
            for k in range(rows):
                for l in range(cols):
                    if grid[k][l] == "B":
                        g = math.gcd(k - i, l - j)
                        rDiff = int((k - i) / g)
                        cDiff = int((l - j) / g)
                        rCurr = i
                        cCurr = j
                        works = True
                        for m in range(g):
                            if grid[rCurr][cCurr] == "C":
                                works = False
                            rCurr += rDiff
                            cCurr += cDiff
                        if works:
                            ans += 1
print(ans)
