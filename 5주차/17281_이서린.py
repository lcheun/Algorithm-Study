import sys
from itertools import permutations
end = int(sys.stdin.readline())
inning = [list(map(int, sys.stdin.readline().split())) for _ in range(end)]

max_score = 0

def game(line_ups):
    hitter_idx = 0
    score = 0
    for each_inning in inning:
        outcount = 0
        b1, b2, b3 = 0, 0, 0
        while outcount < 3:
            if each_inning[line_ups[hitter_idx]] == 0:
                outcount += 1
            elif each_inning[line_ups[hitter_idx]] == 1:
                score += b3
                b1, b2, b3 = 1, b1, b2
            elif each_inning[line_ups[hitter_idx]] == 2:
                score += (b2 + b3)
                b1, b2, b3 = 0, 1, b1
            elif each_inning[line_ups[hitter_idx]] == 3:
                score += (b2 + b3 + b1)
                b1, b2, b3 = 0, 0, 1
            elif each_inning[line_ups[hitter_idx]] == 4:
                score += (1 + b1 + b2 + b3)
                b1, b2, b3 = 0, 0, 0
        
            hitter_idx = (hitter_idx + 1) % 9
        return score

for line_ups in permutations(range(1,9), 8):
    line_ups = list(line_ups[:3]) + [0] + list(line_ups[3:])
    max_score = max(max_score, game(line_ups))

print(max_score)