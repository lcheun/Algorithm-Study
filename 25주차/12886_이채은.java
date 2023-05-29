import java.util.*;

public class Main{
    static int A, B, C;
    static boolean ans;
    static boolean[][] visit = new boolean[1501][1501];
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();
        simul(A, B, C);
        System.out.println(ans? 1:0);
        sc.close();
    }
    
    public static void simul(int x, int y, int z){
        if(ans == true) return;
        if(x==y && y==z){
            ans = true; return;
        }
        if(visit[x][y]) return;
        
        visit[x][y] = true;
        if(x<y)simul(x+x, y-x, z);
        else if(x>y) simul(x-y, y+y, z);
        
        if(y<z) simul(x, y+y, z-y);
        else if(y>z) simul(x, y-z, z+z);
        
        if(x<z) simul(x+x, y, z-x);
        else if(x>z) simul(x-z, y, z+z);
    }
}
