#include <iostream>
using namespace std;

typedef struct point {
    int x, y;
} point;

// Function to calculate orientation
int orientation(point p1, point p2, point p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to check if point T lies on segment AB
bool onSegment(point A, point B, point T) {
    return min(A.x, B.x) <= T.x && T.x <= max(A.x, B.x) &&
           min(A.y, B.y) <= T.y && T.y <= max(A.y, B.y) &&
           orientation(A, B, T) == 0;
}

// Function to determine if point T is inside, outside, or on the boundary of the rectangle
int pointInRectangle(point A, point B, point C, point D, point T) {
    // Check if T is on any of the rectangle edges
    if (onSegment(A, B, T) || onSegment(B, C, T) || onSegment(C, D, T) || onSegment(D, A, T)) {
        return 0;
    }
    
    // Compute orientation for all four edges
    int o1 = orientation(A, B, T);
    int o2 = orientation(B, C, T);
    int o3 = orientation(C, D, T);
    int o4 = orientation(D, A, T);
    
    // If all orientations are the same, point is inside
    if ((o1 == 2 && o2 == 2 && o3 == 2 && o4 == 2) || (o1 == 1 && o2 == 1 && o3 == 1 && o4 == 1)) {
        return 1;
    }
    return -1; // Otherwise, point is outside
}

int main() {
    point A, B, C, D, T;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y >> T.x >> T.y;
    cout << pointInRectangle(A, B, C, D, T) << endl;
    return 0;
}
