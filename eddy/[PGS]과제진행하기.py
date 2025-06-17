#틀려서 다시 풀 예정 ㅠㅠㅠ
def solution(plans):
    plans.sort(key=lambda x:x[1])
    stack = []
    answer = []
    name_answer = []
    
    for index in range(len(plans)):
        if(index == len(plans)-1):
            answer.append(plans[index])
            break
    
        now = plans[index][1]
        next = plans[index+1][1]
        play_time = int(plans[index][2])
        nowH = now.split(":")[0]
        nowM = now.split(":")[1]
        nextH = next.split(":")[0]
        nextM = next.split(":")[1]
        restH = int(nextH) - int(nowH)
        restM = int(nextM) - int(nowM)
        totalM = restH * 60 + restM
        spendM = play_time-totalM
        if(spendM >0):
            plans[index][2] = str(play_time-totalM)
            stack.append(plans[index])
        else:
            answer.append(plans[index])
            if stack:
                while(spendM <0):
                    item = stack.pop()
                    itemPlayTime = int(item[2])
                    itemRestPlayTime =  itemPlayTime + spendM
                    #남은 시간업데이트
                    spendM = spendM+itemPlayTime
                    #뺏음에도 불구하고, 여전히 남아있다면 다시 스택에 넣을게요.
                    if(itemRestPlayTime > 0):
                        item[2] = str(itemRestPlayTime)
                        stack.append(item)
                        continue
    while stack:
        item = stack.pop()
        answer.append(item)

    for item in answer:
        name_answer.append(item[0])
    return name_answer