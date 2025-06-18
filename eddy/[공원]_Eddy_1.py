#해당 가능 영역 하나씩 체크하는게 맞는데 가로 세로 외곽선만 체크하고 있다는 사실을 깨달음.
#하나씩 하다보니까. 문제가 생긴듯 


def test():
    mats = [5,3,2]	
    park = [["A", "A", "-1", "B", "B", "B", "B", "-1"], 
        ["A", "A", "-1", "B", "B", "B", "B", "-1"], 
        ["-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"], 
        ["D", "D", "-1", "-1", "-1", "-1", "E", "-1"], 
        ["D", "D", "-1", "-1", "-1", "-1", "-1", "F"], 
        ["D", "D", "-1", "-1", "-1", "-1", "E", "-1"]
        ]
    #초기값 지정
    answer = -1
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
                #돗자리 펴도 될까요?
                if park[i][j] == "-1":
                    found = True
                    #check out of range index
                    #mat 기준 시점 -> 가로
                    if (j+mat-1) <= cols-1:
                        for mat_index in range(mat):
                            #가로로 한칸씩 확인 중, 누군가 이미 돗자리를 차지했다면
                            if park[i][j+mat_index] != "-1":
                                #안쪽 for문을 종료. 
                                found = False
                    else:
                        #out of range
                        found = False
                    

                    #mat 기준시점 -> 세로 
                    if found:
                        #가로 모두 "-1"로 도달한 경우 세로 체크
                        if(i+mat-1) <= rows-1:
                            for mat_index in range(mat):
                                #세로로 한칸씩 확인 중,
                                if park[i+mat_index][j] != "-1":
                                    found = False
                        else:
                            #out of range
                            found = False
                    
                    if (j+mat-1) <= cols-1 and (i+mat-1) <= rows-1:
                        for mat_index in range(mat):
                            #가로로 한칸씩 확인 중, 누군가 이미 돗자리를 차지했다면
                            if park[i+mat_index][j+mat-1] != "-1":
                                #안쪽 for문을 종료. 
                                found = False
                    else:
                        #out of range
                        found = False
                    
                    if (j+mat-1) <= cols-1 and (i+mat-1) <= rows-1:
                        for mat_index in range(mat):
                            #가로로 한칸씩 확인 중, 누군가 이미 돗자리를 차지했다면
                            if park[i+mat-1][j+mat_index] != "-1":
                                #안쪽 for문을 종료. 
                                found = False
                    else:
                        #out of range
                        found = False
                   
                    #mat 기준end -> 세로
                    if found:
                        #여기까지 도달했다면? 다 펼쳤다는 뜻
                        answer = mat
                        #해당 만족 시 가장 큰걸 기준으로 정렬했으니 바로 종료
                        return answer
    

            
answer=test()
print(answer)