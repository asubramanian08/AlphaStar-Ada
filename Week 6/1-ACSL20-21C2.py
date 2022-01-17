for test in range(5):
    string = input()
    letters = []
    for i in range(26):
        letters.append(0)
    for i in string:
        if i >= 'a' and i <= 'z':
            letters[ord(i) - ord('a')] += 1
        elif i >= 'A' and i <= 'Z':
            letters[ord(i) - ord('A')] += 1
    maxLen = 0
    for i in letters:
        if i > maxLen:
            maxLen = i
    ans = ""
    for i in range(maxLen):
        for j in range(26):
            if i < letters[j]:
                ans += chr(j + ord('a'))
    newAns = ""
    for i in range(len(ans)):
        if i == 0 or ans[i] != ans[i-1]:
            newAns += ans[i]
    print(newAns)
