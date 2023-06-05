import java.util.*;

public class Main{
    static ArrayList<Integer>[] list;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        list = new ArrayList[N+1];
        list[1] = new ArrayList<>(Arrays.asList(2, 3, 5, 7));
        for(int i=2; i<=N; i++) list[i] = new ArrayList<Integer>();
        setup(N);
        for(int num:list[N]) System.out.println(num);
        sc.close();
    }
    
    public static void setup(int N){
        for(int i=2; i<=N; i++){
        	for(int tmp:list[i-1]) {
        		for(int j=1; j<10; j++) {
        			if(j%2==0) continue;
        			int num = tmp*10 + j;
        			if(!isPrime(num)) list[i].add(num);
        		}
        	}
        }
    }
    
    public static boolean isPrime(int num) {
    	for(int i=2; i*i<=num; i++)
    		if(num % i == 0) return true;
    	return false;
    }
}
