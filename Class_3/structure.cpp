#include <bits/stdc++.h>

//Use of structure
using namespace std;

struct Point {
    int x;
    int y;
    int z;
    Point &operator+(const Point &pp) {
        this->x += pp.x;
        this->y += pp.y;
        this->z += pp.z;
        return *this;
    }
};

//Custom sorting function
// bool custom(int &a, int &b) {
//     if (a % 10 <= b % 10)
//         return true;
//     else
//         return false;
// }
bool cust(Point *p1, Point *p2) {
    if (p1->x == p2->x) {
        if (p1->y == p2->y) {  //dono poiint ka x equal h
            return p1->z < p2->z;
        }
        return p1->y < p2->y;
    }
    return p1->x < p2->x;
}
int main() {
    // Point p;
    // p.x = 10;
    // p.y = 20;
    // p.z = 30;
    // Point *pp = new Point;
    // pp->x = 10;  //(*pp).x;
    // pp->y = 30;
    // pp->z = 40;
    Point *p[5];
    for (int i = 0; i < 5; i++) {
        p[i] = new Point;
        cin >> p[i]->x >> p[i]->y >> p[i]->z;
    }
    sort(p, p + 5, cust);
    cout << " ";
    for (int i = 0; i < 5; i++) {
        cout << p[i]->x << " " << p[i]->y << " " << p[i]->z << endl;
    }

    // Point p1 = {1, 2, 3};
    // Point p2 = {4, 5, 6};

    // //Operator overloading
    // Point p3 = p1 + p2;
    // cout << p3.x << " " << p3.y << " " << p3.z << endl;
}