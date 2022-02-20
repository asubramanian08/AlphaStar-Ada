def addFig(grid, posR, posC, figR, figC, rows, cols, currFig):
    for r in figR:
        if r + posR >= rows:
            return posR, posC
    for c in figC:
        if c + posC >= cols:
            return posR, posC
    for i in range(len(figR)):
        if grid[posR + figR[i]][posC + figC[i]]:
            return posR, posC
    posR += figR[len(figR) - 1]
    posC += figC[len(figC) - 1] + 1
    print(chr(currFig + ord('A')), end='')
    return posR, posC


for _ in range(5):
    inArr = list(map(int, input().split(' ')))
    rows, cols, pos, blockCt = inArr[:4]
    blocks = inArr[4:]
    grid = []
    for i in range(rows):
        grid.append([])
        for j in range(cols):
            grid[i].append(False)
    for block in blocks:
        grid[int((block - 1) / cols)][(block - 1) % cols] = True
    figR = [[0, 0, 0], [0, 1, 1], [0, 0, 1, 2]]
    figC = [[0, 1, 2], [0, 0, 1], [0, 1, 1, 1]]
    currFig = 0
    pos -= 1
    posR = int(pos / cols)
    posC = pos % cols
    while posC < cols:
        posR, posC = addFig(
            grid, posR, posC, figR[currFig], figC[currFig], rows, cols, currFig)
        currFig = (currFig + 1) % 3
    print()
