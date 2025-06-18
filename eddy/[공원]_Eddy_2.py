

def test():
    mats = [5,3,2]	
    park = [["A", "A", "-1", "B", "B", "B", "B", "-1"], 
        ["A", "A", "-1", "B", "B", "B", "B", "-1"], 
        ["-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"], 
        ["D", "D", "-1", "-1", "-1", "-1", "E", "-1"], 
        ["D", "D", "-1", "-1", "-1", "-1", "-1", "F"], 
        ["D", "D", "-1", "-1", "-1", "-1", "E", "-1"]
        ]
    #가장 큰걸 고르기
    mats.sort(reverse=True)
    rows = len(park)
    cols = len(park[0])

    print("cols", cols)
    print("rows", rows)

    #가장 큰것 부터 시작
    for mat in mats:
        for i in range(rows):
            for j in range(cols):
                #아닌건 우선 제외하는 형식으로 변경 1번은 == "-1"로 했었는데, 
                if park[i][j] != "-1":
                    continue
                #해당 영역안에 있는지 확인, 없으면 out of range
                if i + mat > rows or j + mat > cols:
                    continue
                #외곽선만 아니라 가로세로로 찾아보기 
                found = True
                for x in range(i, i + mat):
                    for y in range(j, j + mat):
                        if park[x][y] != "-1":
                            found = False
                            break
                    if not found:
                        break

                if found:
                    return mat

    return -1

    

            
answer=test()
print(answer)