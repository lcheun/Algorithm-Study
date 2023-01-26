import java.util.*;

public class Main{
    static int N, ans;
    static int[] map;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        map = new int[N];
        nQueen(0);
        System.out.println(ans);
    }
    
    public static void nQueen(int cnt){
		if(cnt == N){
			ans++; return;
		}
        
        for(int i=0; i<N; i++){
            map[cnt] = i;
            if(check(cnt)){
                nQueen(cnt+1);
            }
        }
	}
 
	public static boolean check(int col){
        for(int i=0; i<col; i++){
            if(map[col] == map[i]) return false;
            else if(Math.abs(col - i) == Math.abs(map[col] - map[i])) return false;
        }
        
        return true;
	}
}
