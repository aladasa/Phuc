#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 100001;
int n, m, s, t;

//Dùng vector để lưu danh sách kề của mỗi đỉnh 
vector<pair<int, int>> adj[maxn];

void nhap() {
    // Yêu cầu người dùng nhập số đỉnh và số cạnh cho đến khi nhập đúng
    while (true) {
        cout << "Nhap so dinh cua do thi: ";
        cin >> n;
        if (n > 0) {
            break; // Thoát khỏi vòng lặp nếu số đỉnh hợp lệ
        }
        cout << "So dinh khong hop le. Vui long nhap lai." << endl;
    }

    while (true) {
        cout << "Nhap so canh cua do thi: ";
        cin >> m;
        if (m > 0) {
            break; // Thoát khỏi vòng lặp nếu số cạnh hợp lệ
        }
        cout << "So canh khong hop le. Vui long nhap lai." << endl;
    }

    // Yêu cầu người dùng nhập đỉnh nguồn và đỉnh đích cho đến khi nhập đúng
    while (true) {
        cout << "Nhap dinh nguon: ";
        cin >> s;
        if (s > 0 && s <= n) {
            break; // Thoát khỏi vòng lặp nếu đỉnh nguồn hợp lệ
        }
        cout << "Dinh nguon khong hop le. Vui long nhap lai." << endl;
    }

    while (true) {
        cout << "Nhap dinh dich: ";
        cin >> t;
        if (t > 0 && t <= n) {
            break; // Thoát khỏi vòng lặp nếu đỉnh đích hợp lệ
        }
        cout << "Dinh dich khong hop le. Vui long nhap lai." << endl;
    }

    // Yêu cầu người dùng nhập danh sách cạnh cho đến khi nhập đúng
    cout << "Nhap danh sach cac canh va trong so tuong ung:\n";
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        while (true) {
            cout << "Nhap canh " << i + 1 << ": ";
            cin >> x >> y >> w;
            if (x > 0 && x <= n && y > 0 && y <= n && w > 0) {
                break; // Thoát khỏi vòng lặp nếu cạnh hợp lệ
            }
            cout << "Canh khong hop le. Vui long nhap lai." << endl;
        }
        adj[x].push_back({y, w});
    }
}




//Định nghĩa INF là 1 số vô cùng lớn
const int INF = 1e9;

//Dùng để lưu trữ đỉnh trước đó của mỗi đỉnh. 
int pre[maxn];

void dijkstra(int s, int t){
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    vector<int> pre(n + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
    Q.push({0, s});
    vector<bool> visited(n + 1, false); // Mảng kiểm tra xem mỗi đỉnh đã được xét chưa

    while(!Q.empty()){
        pair<int, int> top = Q.top(); Q.pop();
        int u = top.second;
        int kc = top.first;
        
        // Kiểm tra xem đã xét đỉnh u chưa
        if (visited[u]) continue;
        visited[u] = true;

        // Nếu khoảng cách hiện tại tới đỉnh u lớn hơn khoảng cách được lưu trong d[], bỏ qua
        if(kc > d[u]) continue;

        // Duyệt qua các đỉnh kề của đỉnh u
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
                pre[v] = u;
            }
        }
    }

    // Kiểm tra xem có đường đi từ s đến t không
    if (d[t] == INF) {
        cout << "Khong co duong di tu " << s << " den " << t << endl;
        return;
    }

    // In ra khoảng cách ngắn nhất từ s đến t
    cout << "Khoang cach ngan nhat tu " << s << " den " << t << " la: " << d[t] << endl;

    vector<int> path;
    for (int v = t; v != -1; v = pre[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    cout << "Duong di ngan nhat: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
}



int main(){
	cin.tie(nullptr);
	nhap();
	dijkstra(s,t);
}
