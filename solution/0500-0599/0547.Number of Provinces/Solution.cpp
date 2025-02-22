class Solution {
public:
    vector<int> p;

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j && isConnected[i][j] == 1) p[find(i)] = find(j);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i == find(i)) ++cnt;
        }
        return cnt;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};