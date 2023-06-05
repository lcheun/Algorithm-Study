#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
 
int M, N, total, result;
int parent[200001];
vector<pair<int, pair<int, int>>> edge;
 
int Find_Parent(int A) {
    if (A == parent[A]) return A;
    else return parent[A] = Find_Parent(parent[A]);
}
 
bool Same_Parent(int A, int B) {
    A = Find_Parent(A);
    B = Find_Parent(B);
  
    if (A == B) return true;
    return false;
}
 
void Union(int A, int B) {
    A = Find_Parent(A);
    B = Find_Parent(B);
    
    Parent[B] = A;    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    while (true) {
        Edge.clear();
        Total = Result = 0;
        for (int i = 0; i < 200001; i++) parent[i] = i;
      
        cin >> M >> N;
        if (M == 0 && N == 0) break;
      
       for (int i = 0; i < N; i++) {
           int a, b, c;
           cin >> a >> b >> c;
           edge.push_back({c, {a, b}});
           total += c;
        }
      
        sort(edge.begin(), edge.end());
        for(int i = 0; i < edge.size(); i++) {
 
           if (!SameParent(edge[i].second.first, edge[i].second.second)) {
               Union(edge[i].second.first, edge[i].second.second);
               result += edge[i].first;
           }
        }

        cout << total - result << '\n';
    }
}
