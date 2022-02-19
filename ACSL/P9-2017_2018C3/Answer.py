# vars
TESTS = 5
MOVES = 6
GRID_SIZE = 4
# read
grid = input().split(", ")
for i in range(GRID_SIZE):
    grid[i] = (GRID_SIZE - len(grid[i])) * '0' + grid[i]
# simulate
currGrid = []
for i in range(GRID_SIZE):
    currGrid.append([])
    for j in range(GRID_SIZE):
        currGrid[i].append(0)
for _ in range(TESTS):
    for i in range(GRID_SIZE):
        for j in range(GRID_SIZE):
            currGrid[i][j] = ord(grid[i][j]) - ord('0')
    posY, posX = map(int, input().split(", "))
    posY -= 1
    posX -= 1
    for _ in range(MOVES):
        currGrid[posY][posX] = (currGrid[posY][posX] + 1) % GRID_SIZE
        if currGrid[posY][posX] == 0:
            posY += 1  # 0 + 1, down
        elif currGrid[posY][posX] == 1:
            posX += 1  # 0 + 1, right
        elif currGrid[posY][posX] == 2:
            posX += 3  # 4 - 1, left
        else:  # currGrid[posY][posX] == 3
            posY += 3  # 4 - 1, up
        posY %= GRID_SIZE
        posX %= GRID_SIZE
    print(str(posY + 1) + ", " + str(posX + 1))
