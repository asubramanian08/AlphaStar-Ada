for i in range(5):
    N, P, D = input().split()
    P = len(N) - int(P)
    D = int(D)
    if int(N[P]) < 5:
        N = N[:P] + str((int(N[P]) + D) % 10) + N[P+1:]
    else:
        N = N[:P] + str(abs(int(N[P]) - D))[0] + N[P+1:]
    N = N[:P+1] + (len(N) - P - 1) * '0'
    for ch in N:
        print(ch, end='')
    print()
