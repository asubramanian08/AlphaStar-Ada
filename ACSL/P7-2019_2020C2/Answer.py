for test in range(5):
    word1, word2 = input().strip().split(' ')
    newWord1 = newWord2 = ""
    for i in range(len(word1)):
        if i == 0 or word1[i] != word1[i-1]:
            newWord1 += word1[i]
    for i in range(len(word2)):
        if i == 0 or word2[i] != word2[i-1]:
            newWord2 += word2[i]
    word1 = newWord1
    word2 = newWord2
    newWord1 = newWord2 = ""
    for i in range(len(word1)):
        if (word1[i] != "A" and word1[i] != "E" and word1[i] != "I" and
                word1[i] != "O" and word1[i] != "U") or i == 0:
            newWord1 += word1[i]
    for i in range(len(word2)):
        if (word2[i] != "A" and word2[i] != "E" and word2[i] != "I" and
                word2[i] != "O" and word2[i] != "U") or i == 0:
            newWord2 += word2[i]
    word1 = newWord1
    word2 = newWord2
    newWord1 = newWord2 = ""
    minLen = min(len(word1), len(word2))
    for i in range(minLen):
        if word1[i] != word2[i]:
            newWord1 += word1[i]
            newWord2 += word2[i]
    word1 = newWord1 + word1[minLen: len(word1)]
    word2 = newWord2 + word2[minLen: len(word2)]
    newWord1 = newWord2 = ""
    minLen = min(len(word1), len(word2))
    for i in range(1, minLen + 1):
        if word1[-i] != word2[-i]:
            newWord1 += word1[-i]
            newWord2 += word2[-i]
    word1 = newWord1[::-1] + word1[0: -minLen]
    word2 = newWord2[::-1] + word2[0: -minLen]
    if len(word1) < len(word2):
        print(word1)
    elif len(word1) > len(word2):
        print(word2)
    elif word1 < word2:
        print(word1)
    else:
        print(word2)
