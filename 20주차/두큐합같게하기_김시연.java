import java.util.*;

public class Solution {
    public int solution(int[] queue1, int[] queue2) {
        Deque<Integer> deq1 = new ArrayDeque<>();
        Queue<Integer> deq2 = new ArrayDeque<>();
        int cnt = 0;

        //모든 값을 queue에 넣어주고, 두 queue의 평균값을 구함
        long s1=0, s2=0, sum;
        for (int tmp : queue1) {deq1.add(tmp); s1+=tmp;}
        for (int tmp : queue2) {deq2.add(tmp); s2+=tmp;}
        sum = s1+s2;
        if (sum%2 == 1) return -1;
        else sum /=2;

        //큐의 값이 상대 큐로 이동했다가 다시 원상복귀까지 대충 queue길이*4 만큼 걸림
        //또한 모든값이 한 큐로 이동한 경우도 다른 방도가 없다는 증거이므로 while문 탈출 조건
        while(cnt<=queue1.length*4 && deq1.size() < queue1.length*2 && deq1.size() != 0) {
            if (s1 == sum) return cnt;

            //그리디하게, 목표값보다 크면 빼고, 작으면 더해주는 식으로 진행
            else if (s1 > sum) {
                s1-=deq1.peek();
                s2+=deq1.peek();
                deq2.add(deq1.remove());
                cnt++;
            }
            else if (s1 < sum && s1 > 0){
                s2-=deq2.peek();
                s1+=deq2.peek();
                deq1.add(deq2.remove());
                cnt++;
            }
        }
        return -1;
    }
}