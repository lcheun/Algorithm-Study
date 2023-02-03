import java.util.*;

public class Main{
    static int N, cnt = 9;
    static long ans = -1;
    static Queue<Long> q = new LinkedList<>();
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        if(N <= 10){
            System.out.println(N); System.exit(0);
        }
        for(long i=0; i<10; i++) q.add(i);
        while(!q.isEmpty()){
            long tmp = q.poll();
            long last = tmp % 10;
            for(int i=0; i<10; i++){
                if(i >= last) break;
                long num = tmp * 10 + i;
                q.add(num); cnt++;
                if(cnt == N) {
                	ans = num; break;
                }
            }
            if(cnt == N) break;
        }
        System.out.println(ans);
    }
}
