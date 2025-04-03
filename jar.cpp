#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    
    bool operator<(const Point &p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
};

int orientation(const Point &p, const Point &q, const Point &r) {
    long long val = (long long)(q.y - p.y) * (r.x - q.x) - 
                    (long long)(q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

vector<Point> outerTrees(vector<Point>& trees) {
    int n = trees.size();
    if (n <= 3) return trees;

    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (trees[i].x < trees[leftmost].x || 
            (trees[i].x == trees[leftmost].x && trees[i].y < trees[leftmost].y)) {
            leftmost = i;
        }
    }

    set<Point> result;
    int p = leftmost;

    do {
        int q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(trees[p], trees[q], trees[i]) == 2) {
                q = i;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i != p && i != q && orientation(trees[p], trees[i], trees[q]) == 0) {
                bool isBetween = true;
                if ((trees[i].x < min(trees[p].x, trees[q].x)) || 
                    (trees[i].x > max(trees[p].x, trees[q].x))) {
                    isBetween = false;
                }
                if ((trees[i].y < min(trees[p].y, trees[q].y)) || 
                    (trees[i].y > max(trees[p].y, trees[q].y))) {
                    isBetween = false;
                }

                if (isBetween) {
                    result.insert(trees[i]);
                }
            }
        }

        result.insert(trees[q]);
        p = q;
    } while (p != leftmost);

    return vector<Point>(result.begin(), result.end());
}

int main() {
    int n;
    cin >> n;
    vector<Point> trees(n);
    for (int i = 0; i < n; i++)
        cin >> trees[i].x >> trees[i].y;

    vector<Point> hull = outerTrees(trees);

    for (auto p : hull)
        cout << p.x << " " << p.y << endl;

    return 0;
}
