import java.util.*;

public class Main{
    static int N, M, max=0;
    static int[][] map;
    static int[][] map2;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static ArrayList<point> virus = new ArrayList<point>();
    static class point{
        int x, y;
        point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        map = new int[N][M];
        map2 = new int[N][M];
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                map[i][j] = sc.nextInt();
                if(map[i][j]==2) virus.add(new point(i, j));
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j]==0){
                    map[i][j] = 1;
                    wall(i, j, 1);
                    map[i][j] = 0;
                }
            }
        }
        
        System.out.println(max);
        sc.close();
    }
    
    public static void wall(int x, int y, int num){
        if(num == 3){
            spread();
            return;
        }
        
        for(int i=x; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j]==0){
                    map[i][j] = 1;
                    wall(i, j, num+1);
                    map[i][j] = 0;
                }
            }
        }
    }
    
    public static void spread(){
    	copy();
    	
        Queue<point> q2 = new LinkedList<point>();
        for(point tmp:virus){
            q2.add(tmp);
            while(!q2.isEmpty()){
                point p = q2.poll();
                for(int i=0; i<4; i++){
                    int nx = p.x + dx[i];
                    int ny = p.y + dy[i];
                    if(nx>=0 && nx<N && ny>=0 && ny<M && map2[nx][ny]==0){
                        map2[nx][ny] = 2;
                        q2.add(new point(nx, ny));
                    }
                }
            }
        }
        
        int cnt=0;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(map2[i][j]==0) cnt++;
        
        max = (cnt>max)? cnt:max;
    }
    
    public static void copy(){
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                map2[i][j] = map[i][j];
    }
}
