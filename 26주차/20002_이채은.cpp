#include <iostream>
#include <cmath>

using namespace std;

int sum[301][301];
int N;

int main() {
  cin >> N;
  
  int tmp;
  for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
          cin >> tmp;
          sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + tmp - sum[i - 1][j - 1];
      }
  }
  
  int ans = -1001;
  for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<=min(i, j); k++) {
                else ans = max(ans, sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i-k][j-k]);
            }
        }
   }
  
    cout << ans;
}
