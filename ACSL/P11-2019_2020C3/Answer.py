def letterRep(letPos, letType):  # True or 1 letType mean NOT
    return ("~" if letType else "") + chr(letPos + ord('A'))


def group4(vd, letter, ans, state):
    works = True
    vl = [0, 0, 0]
    for vl[0] in range(2):
        for vl[1] in range(2):
            for vl[2] in range(2):
                if vl[letter] == state:
                    works &= vd[vl[0]][vl[1]][vl[2]]
    if works == False:
        return
    ans.append(letterRep(letter, state))
    for vl[0] in range(2):
        for vl[1] in range(2):
            for vl[2] in range(2):
                if vl[letter] == state:
                    vd[vl[0]][vl[1]][vl[2]] = False


def group2(vd, ans, letA, letB, letC):
    if letA == 2 and vd[0][letB][letC] and vd[1][letB][letC]:
        ans.append(letterRep(1, letB) + letterRep(2, letC))
        vd[0][letB][letC] = vd[1][letB][letC] = False
    if letB == 2 and vd[letA][0][letC] and vd[letA][1][letC]:
        ans.append(letterRep(0, letA) + letterRep(2, letC))
        vd[letA][0][letC] = vd[letA][1][letC] = False
    if letC == 2 and vd[letA][letB][0] and vd[letA][letB][1]:
        ans.append(letterRep(0, letA) + letterRep(1, letB))
        vd[letA][letB][0] = vd[letA][letB][1] = False


for _ in range(5):
    veitch = int(input(), base=16)
    veitchDiagram = [[[False, False], [False, False]],
                     [[False, False], [False, False]]]
    currPos = 0
    rOrder = [1, 0]
    for i in rOrder:
        for j in rOrder:
            for k in rOrder:
                if veitch & (1 << currPos):
                    veitchDiagram[i][j][k] = True
                currPos += 1
    vd = [[[False, False], [False, False]],
          [[False, False], [False, False]]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                vd[j][i][k if j else 1 - k] = veitchDiagram[i][j][k]
    ans = []
    group4(vd, 1, ans, 0)
    group4(vd, 1, ans, 1)
    group4(vd, 0, ans, 0)
    group4(vd, 2, ans, 0)
    group4(vd, 0, ans, 1)
    group4(vd, 2, ans, 1)
    group2(vd, ans, 0, 0, 2)
    group2(vd, ans, 2, 0, 0)
    group2(vd, ans, 1, 0, 2)
    group2(vd, ans, 0, 1, 2)
    group2(vd, ans, 2, 1, 0)
    group2(vd, ans, 1, 1, 2)
    group2(vd, ans, 0, 2, 1)
    group2(vd, ans, 0, 2, 0)
    group2(vd, ans, 1, 2, 0)
    group2(vd, ans, 1, 2, 1)
    group2(vd, ans, 2, 0, 1)
    group2(vd, ans, 2, 1, 1)
    for B in range(2):
        for A in range(2):
            for C in range(2) if A == 1 else rOrder:
                if(vd[A][B][C]):
                    ans.append(letterRep(0, A) +
                               letterRep(1, B) + letterRep(2, C))
    for i in range(len(ans)):
        if i != 0:
            print(" + ", end='')
        print(ans[i], end='')
    print()
