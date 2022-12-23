package study.week4;

import java.io.*;
import java.util.*;

public class No2644_촌수계산 {
    static int n,m;
    static  ArrayList<Integer> [] arr = new ArrayList[n+1];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        m = Integer.parseInt(br.readLine());

        arr = new ArrayList[n+1];

        for(int i=0;i<=n;i++) {
            arr[i] = new ArrayList<>();
        }

        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            arr[x].add(y);
            arr[y].add(x);
        }

        System.out.println(bfs(a,b));
    }

    static int bfs(int a, int b) {
        Queue<Integer> q = new LinkedList<>();
        q.add(a);
        int[] visited = new int[n+1];
        Arrays.fill(visited, -1);
        visited[a] = 0;

        while(!q.isEmpty()) {
            int now = q.poll();
            if(now == b) {
                return visited[b];
            }

            for(int next:arr[now]) {
                if(visited[next]==-1) {
                    visited[next] = visited[now]+1;
                    q.add(next);
                }
            }
        }

        return visited[b];
    }
}
