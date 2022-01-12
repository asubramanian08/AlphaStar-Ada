sentence = input()
letterCount = []
for i in range(26):
    letterCount.append(0)
uppercase = 0
for i in sentence:
    if i >= 'a' and i <= 'z':
        letterCount[ord(i) - ord('a')] += 1
    if i >= 'A' and i <= 'Z':
        letterCount[ord(i) - ord('A')] += 1
        uppercase += 1
# Stat 1
ans = 0
for i in letterCount:
    if i > 0:
        ans += 1
print(ans)
# Stat 2
ans = letterCount[0] + letterCount[4] + \
    letterCount[8] + letterCount[14] + letterCount[20]
print(ans)
# Stat 3
print(uppercase)
# Stat 4
ans = 0
for i in letterCount:
    if ans < i:
        ans = i
print(ans)
# Stat 5
words = sentence.split(' ')
words.sort()
ans = ''
for i in words:
    start = 0
    while start < len(i) and not ((i[start] >= 'a' and i[start] <= 'z') or (i[start] >= 'A' and i[start] <= 'Z')):
        start += 1
    end = len(i) - 1
    while end >= 0 and not ((i[end] >= 'a' and i[end] <= 'z') or (i[end] >= 'A' and i[end] <= 'Z')):
        end -= 1
    if end < start:
        continue
    word = i[start:end+1]
    if len(ans) < len(word):
        ans = word
print(ans)
