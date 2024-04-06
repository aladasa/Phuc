#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 100001;
//n : số đỉnh
//m : số cạnh
//s : đỉnh gốc
//t : đỉnh đích
int n, m, s, t;

//Dùng vector để lưu danh sách kề của mỗi đỉnh 
vector<pair<int, int>> adj[maxn];

void nhap(){
	cin >> n >> m >> s >> t; 
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		//adj[y].push_back({x, w});
	}
}
//Định nghĩa INF là 1 số vô cùng lớn
const int INF = 1e9;

//Dùng để lưu trữ đỉnh trước đó của mỗi đỉnh. 
int pre[maxn];

void dijkstra(int s, int t){
	//Mang luu khoang cach duong di
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	//Hàng đợi ưu tiên
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
	//{khoang cach, dinh}
	Q.push({0, s});
	while(!Q.empty()){
		//Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u]) continue;
		//Relaxtion : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S (d[v] = min(d[v],d[u] + leng(u,v))) 
		//cập nhật khoảng cách với các đỉnh kề với u
		for(auto it : adj[u]){
			int v = it.first; //đỉnh
			int w = it.second; //trọng số
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
				pre[v] = u;   //đỉnh u là đỉnh trước của v
			}
		}
	}
	//In ra khoảng cách từ đỉnh s đến t
	cout << d[t] << endl;
	vector<int> path;
	//vòng lặp để tái tạo đường đi ngắn nhất từ đỉnh t về đỉnh s
	while (true)
	{
		path.push_back(t);
		if (t == s) break;
		t = pre[t];
	}
	// đảo ngược lại từ đỉnh t về đỉnh s thành từ đỉnh s về đỉnh t
	reverse(begin(path), end(path));
	for(int x : path){
		cout << x << ' ';
	}
	

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	nhap();
	dijkstra(s,t);
}
