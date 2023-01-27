import java.util.Scanner;

public class Main{
	private static int table[][];
	private static int N, K;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        table = new int[N+1][K+1];
        
        set();

        System.out.println(table[N][K]);
        sc.close();
    }
    
    public static void set() {
    	for(int i=0; i<N+1; i++) {
    		table[i][1] = 1;
    	}
    	for(int i=0; i<K+1; i++)
    		table[0][i] = 1;
    	for(int i=1; i<N+1; i++) {
    		for(int j=2; j<K+1; j++) {
    			table[i][j] = (table[i][j-1]+table[i-1][j]) % 1000000000;
    		}
    	}
    }
}
