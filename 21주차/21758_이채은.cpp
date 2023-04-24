#include <iostream>
#include <algorithm>

using namespace std;

int N, ans, arr[100001], sum[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
	cin >> N;

	for(int i=1; i<=N; i++) {
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
	}

	for(int i=2; i<n; i++){
    ans = max(ans, sum[n] - sum[2] + sum[n] - sum[i] - arr[i]);
  }

	for (int i=n-1; i>1; i--){
		ans = max(ans, sum[n-1] + sum[i-1] - arr[i]);
  }

	for(int i = 2; i <= n - 1; i++){
		ans = max(ans, sum[n-1] - sum[1] + arr[i]);
  }

	cout << ans;
  
}
