def solution(play_time, adv_time, logs):
    answer = ''
    play_time = str_to_int(play_time)
    adv_time = str_to_int(adv_time)
    
    all_time = [0 for i in range(play_time+1)]
    
    for l in logs:
        start, end = l.split('-')
        start = str_to_int(start)
        end = str_to_int(end)
        all_time[start] += 1
        all_time[end] -= 1
        
    for i in range(1, len(all_time)):
        all_time[i] = all_time[i] + all_time[i-1]
        
    for i in range(1, len(all_time)):
        all_time[i] = all_time[i] + all_time[i-1]
        
    most_view = 0
    max_view = 0
    
    for i in range(adv_time-1, play_time):
        if i>=adv_time:
            if most_view < all_time[i] - all_time[i-adv_time]:
                most_view = all_time[i] - all_time[i-adv_time]
                max_view = i-adv_time+1
        else:
            if most_view < all_time[i]:
                most_view = all_time[i]
                max_view = i-adv_time+1
    
    return int_to_str(max_view)
            
    
    #return answer

def str_to_int(time):
    h, m, s = map(int, time.split(':'))
    return h*3600 + m*60 + s

def int_to_str(time):
    h = time//3600
    h = '0' + str(h) if h<10 else str(h)
    time %= 3600
    
    m = time//60
    m = '0' + str(m) if m<10 else str(m)
    time %= 60
    
    s = time
    s = '0' + str(s) if s<10 else str(s)
    
    return h+':'+m+':'+s
