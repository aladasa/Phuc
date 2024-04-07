#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, m, s, t;
const int maxn = 100001;
const ll INF = numeric_limits<ll>::max(); // Sử dụng giá trị vô cực phù hợp với kiểu dữ liệu long long

struct Edge {
    int to;
    ll weight;
    Edge(int _to, ll _weight) : to(_to), weight(_weight) {}
};

// Dùng vector để lưu danh sách kề của mỗi đỉnh 
vector<Edge> adj[maxn];

void nhap(){
    cin >> n >> m >> s >> t; 
    for(int i = 0; i < m; i++){
        int x, y; ll w; 
        cin >> x >> y >> w;
        adj[x].push_back(Edge(y, w));
        // Nếu đồ thị là vô hướng, bỏ comment dòng dưới
        // adj[y].push_back(Edge(x, w));
    }
}

void dijkstra(int s, int t){
    vector<ll> dist(n + 1, INF); // Mảng lưu khoảng cách ngắn nhất từ đỉnh s đến các đỉnh khác
    vector<int> pre(n + 1, -1); // Mảng lưu đỉnh trước đó của mỗi đỉnh trên đường đi ngắn nhất
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // Hàng đợi ưu tiên

    dist[s] = 0; // Khoảng cách từ s đến chính nó là 0
    pq.push({0, s}); // Thêm đỉnh s vào hàng đợi ưu tiên với khoảng cách là 0

    while (!pq.empty()) {
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        // Nếu khoảng cách hiện tại từ s đến u lớn hơn khoảng cách được lưu trong mảng dist, bỏ qua
        if (d > dist[u]) continue;

        // Duyệt qua các đỉnh kề của đỉnh u
        for (const Edge& edge : adj[u]) {
            int v = edge.to;
            ll w = edge.weight;

            // Nếu có cách đi từ s đến v tốt hơn, cập nhật khoảng cách và đỉnh trước đó
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Kiểm tra xem có đường đi từ s đến t không
    if (dist[t] == INF) {
        cout << "Khong co duong di tu " << s << " den " << t << endl;
        return;
    }

    // In ra khoảng cách ngắn nhất từ s đến t
    cout << "Khoang cach ngan nhat tu " << s << " den " << t << " la: " << dist[t] << endl;

    // Tái tạo đường đi ngắn nhất từ s đến t
    vector<int> path;
    for (int v = t; v != -1; v = pre[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    // In ra đường đi ngắn nhất
    cout << "Duong di ngan nhat: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    nhap();
    dijkstra(s, t);
    return 0;
}
