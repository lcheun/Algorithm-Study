# 땅 높이가 최대 256
for i in range(257)
    use_block = 0
    take_block = 0
  
    for x in range(N):
        for y in range(M):
            # 블럭이 현재 높이보다 높으면 블록 하나 뽑기
            if block[x][y] > i:
                take_block += block[x][y] - i
            # 블럭이 현재 높이보다 낮으면 블록 써서 높이 높여주기
            else:
                use_block += i - block[x][y]
    
    if use_block > take_block + B:
        continue

    count = take_block * 2 + use_block

    if count <= ans:
        ans = count
        glevel = i
