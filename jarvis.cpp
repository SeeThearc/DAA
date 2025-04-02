#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

int crossProduct(Point p, Point q, Point r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

vector<Point> convexHull(vector<Point> &points) {
    int n = points.size();
    if (n < 3) return {};
    
    vector<Point> hull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    
    int p = l, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (crossProduct(points[p], points[q], points[i]) < 0)
                q = i;
        }
        p = q;
    } while (p != l);
    
    return hull;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    
    vector<Point> hull = convexHull(points);
    for (auto p : hull)
        cout << p.x << " " << p.y << endl;
    return 0;
}