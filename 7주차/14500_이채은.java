
import java.io.*;
import java.util.StringTokenizer;

public class Main {
	static int N, M, max = 0;
	static int map[][];
	static boolean visit[][];
	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		N = Integer.parseInt(stk.nextToken());
		M = Integer.parseInt(stk.nextToken());
		map = new int[N][M];
		visit = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			stk = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++)
				map[i][j] = Integer.parseInt(stk.nextToken());
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dfs(i, j, 0, 0);
				exception(i, j);
			}
		}

		System.out.println(max);
	}

	public static void dfs(int x, int y, int cnt, int sum) {
		if (cnt == 4) {
			max = Math.max(max, sum);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visit[nx][ny]) {
				visit[nx][ny] = true;
				dfs(nx, ny, cnt + 1, sum + map[nx][ny]);
				visit[nx][ny] = false;
			}
		}
	}

	private static void exception(int x, int y) {
		int wing = 4;
		int min = 1001;
		int sum = map[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (wing <= 2)
				return;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				wing--;
				continue;
			}
			min = Math.min(min, map[nx][ny]);
			sum = sum + map[nx][ny];
		}
		if (wing == 4) {
			sum = sum - min;
		}
		max = Math.max(max, sum);
	}
}
