import java.io.*;
import java.util.*;

public class Main{
    static int N;
    static int[][] map;
    static int[][] dist;
    static boolean[][] visit;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static PriorityQueue<point> pq = new PriorityQueue<point>();
    static class point implements Comparable<point>{
    	int x, y;
    	
    	point(int x, int y){
    		this.x = x;
    		this.y = y;
    	}
    	
    	@Override
    	public int compareTo(point e1) {
    		return dist[this.x][this.y] > dist[e1.x][e1.y] ? 1:-1;
    		
    	}
    	
    }
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder res = new StringBuilder("");
        int cnt = 0;
        while(true){
            N = Integer.parseInt(br.readLine());
            if(N==0) break;
            cnt++;
            map = new int[N][N];
            dist = new int[N][N];
            visit = new boolean[N][N];
            for(int i=0; i<N; i++){
                StringTokenizer stk = new StringTokenizer(br.readLine());
                for(int j=0; j<N; j++)
                    map[i][j] = Integer.parseInt(stk.nextToken());
            }
            
            set();
            rupee(0, 0);
            
            res.append("Problem "+cnt+": "+dist[N-1][N-1]+"\n");
        }
        System.out.println(res);
    }
    
    public static void set(){
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                dist[i][j] = 3000;
        
        dist[0][0] = map[0][0];
    }
    
    public static void rupee(int x, int y){
        visit[x][y] = true;
        if(x==N-1 && y==N-1){
            return;
        }
        
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N && visit[nx][ny]==false){
                dist[nx][ny] = Math.min(dist[nx][ny], dist[x][y]+map[nx][ny]);
                pq.offer(new point(nx, ny));
            }
        }
        
        point next = pq.poll();
        rupee(next.x, next.y);
    }
}
