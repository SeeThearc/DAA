class Solution {
public:
    //blitz
    int orientation(vector<int> &p, vector<int> &q, vector<int> &r) {
        int val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
        if (val == 0) return 0;
        return (val > 0) ? 1 : 2;
    }

    int distSq(vector<int> &p, vector<int> &q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n <= 3) return trees;

        int leftmost = 0;
        for (int i = 1; i < n; i++) {
            if (trees[i][0] < trees[leftmost][0]) {
                leftmost = i;
            }
        }
        
        set<vector<int>> result;
        int p = leftmost;
        
        do {
            int q = (p + 1) % n;

            for (int i = 0; i < n; i++) {
                int o = orientation(trees[p], trees[q], trees[i]);
                if (o == 2) {
                    q = i;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i != p && i != q && orientation(trees[p], trees[q], trees[i]) == 0 &&
                    min(trees[p][0], trees[q][0]) <= trees[i][0] && trees[i][0] <= max(trees[p][0], trees[q][0]) &&
                    min(trees[p][1], trees[q][1]) <= trees[i][1] && trees[i][1] <= max(trees[p][1], trees[q][1])) {
                    result.insert(trees[i]);
                }
            }
            
            result.insert(trees[q]);
            p = q;
            
        } while (p != leftmost);
        
        return vector<vector<int>>(result.begin(), result.end());
    }
};
