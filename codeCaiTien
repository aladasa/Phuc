#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;
using ll = long long;

struct Edge {
    int to;
    int weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

const int INF = numeric_limits<int>::max(); // Sử dụng giá trị vô cực từ thư viện <limits>

void dijkstra(const vector<vector<Edge>>& graph, int s, int t) {
    int n = graph.size(); // Số đỉnh trong đồ thị
    vector<ll> dist(n, INF); // Mảng lưu khoảng cách ngắn nhất từ đỉnh s đến các đỉnh khác
    vector<int> pre(n, -1); // Mảng lưu đỉnh trước đó của mỗi đỉnh trên đường đi ngắn nhất
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Hàng đợi ưu tiên

    dist[s] = 0; // Khoảng cách từ s đến chính nó là 0
    pq.push({0, s}); // Thêm đỉnh s vào hàng đợi ưu tiên với khoảng cách là 0

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Nếu khoảng cách hiện tại từ s đến u lớn hơn khoảng cách được lưu trong mảng dist, bỏ qua
        if (d > dist[u]) continue;

        // Duyệt qua các đỉnh kề của đỉnh u
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

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

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    // Khởi tạo danh sách kề của mỗi đỉnh
    vector<vector<Edge>> graph(n);

    // Đọc thông tin về các cạnh
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back(Edge(y, w));
        
    }

    // Gọi hàm Dijkstra để tìm đường đi ngắn nhất từ s đến t
    dijkstra(graph, s, t);

    return 0;
}
