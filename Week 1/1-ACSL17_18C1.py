from sys import stdin


def play(card, points):
    if card == 9:
        pass
    elif card == 4:
        points -= 10
    elif card == 0:
        if points + 11 > 99:
            points += 1
        else:
            points += 11
    else:
        points += card
    return points


for i in range(5):
    input = list(map(int, stdin.readline().strip().split(", ")))
    points = input[0]
    cards = input[1:4]
    deck = input[4:11]
    cards.extend([deck[0], deck[2], deck[4], deck[6]])
    dealer = [deck[1], deck[3], deck[5]]
    for j in range(4):
        # player
        points = play(cards[j], points)
        if points > 99:
            print(str(points) + ", dealer")
            break
        # dealer
        points = play(dealer[j], points)
        if points > 99:
            print(str(points) + ", player")
            break
