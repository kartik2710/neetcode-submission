class DSU {
public:
    vector<int> parent;

    void init(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        parent[rx] = ry;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> conn;

        DSU dsu;
        dsu.init(n);

        // Build all edges with Manhattan distance
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                conn.push_back({dist, i, j});
            }
        }

       
        sort(conn.begin(), conn.end());

        int ans = 0, edgesUsed = 0;

     
        for (auto& x : conn) {
            if (dsu.unite(x[1], x[2])) {
                ans += x[0];
                edgesUsed++;
                if (edgesUsed == n - 1) break; // MST complete
            }
        }

        return ans;
    }
};
