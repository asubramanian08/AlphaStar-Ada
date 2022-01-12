for i in range(5):
    start, delta, rows = map(int, input().split())
    lastLineStart = int(rows * (rows-1) / 2)
    val = (start + delta * lastLineStart) % 9
    total = 0
    for j in range(rows):
        if val == 0:
            val = 9
        total += val
        val = (val + delta) % 9
    print(total)
