for test in range(5):
    num_arr = input()
    ans = 0
    length = len(num_arr)
    for i in range(length):
        num = ord(num_arr[i]) - ord('0')
        if test == 0:
            ans += 1
        elif test == 1:
            ans += num
        elif (test == 2) and (i % 2 == 0):
            ans += num
        elif (test == 3) and (num == 4):
            ans += 1
        elif (test == 4) and (i == int(length / 2) - 1 + length % 2):
            ans = num
    print(ans)
