for test in range(5):
    expression = input()
    para = int
    for i in range(len(expression)):
        if expression[i] == '(' or expression[i] == ')':
            para = i
    placements = []
    for i in (range(para+4, len(expression)+1, 2) if para % 2 == 0 else range(0, para-1, 2)):
        placements.append(i)
    for i in placements:
        print(str(i+1), end='')
        if i != placements[len(placements)-1]:
            print(end=', ')
    print()
