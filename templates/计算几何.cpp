//计算几何基础: 点/叉积/凸包/线段相交/点在多边形内
const double eps = 1e-9;
int sgn(double x) {
    return x < -eps ? -1 : (x > eps ? 1 : 0);
}

struct Point {
    double x, y;
    Point operator+(Point p) { return {x + p.x, y + p.y}; }
    Point operator-(Point p) { return {x - p.x, y - p.y}; }
    Point operator*(double k) { return {x * k, y * k}; }
    bool operator<(Point p) const { return x < p.x - eps || (fabs(x - p.x) < eps && y < p.y - eps); }
};
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }     //叉积, >0 表示 b 在 a 逆时针方向
double cross(Point a, Point b, Point c) { return cross(b - a, c - a); }

bool on_seg(Point a, Point b, Point p) {           //p 是否在线段 ab 上
    return sgn(cross(a, b, p)) == 0 && sgn(dot(p - a, p - b)) <= 0;
}
bool seg_intersect(Point a, Point b, Point c, Point d) {   //线段 ab 与 cd 是否相交(含端点)
    double d1 = cross(a, b, c), d2 = cross(a, b, d);
    double d3 = cross(c, d, a), d4 = cross(c, d, b);
    if(sgn(d1) * sgn(d2) < 0 && sgn(d3) * sgn(d4) < 0)    return true;
    if(sgn(d1) == 0 && on_seg(a, b, c))    return true;
    if(sgn(d2) == 0 && on_seg(a, b, d))    return true;
    if(sgn(d3) == 0 && on_seg(c, d, a))    return true;
    if(sgn(d4) == 0 && on_seg(c, d, b))    return true;
    return false;
}

//凸包(Andrew): 返回凸包顶点按逆时针排列(不含共线点), O(n log n)
vector<Point> convex_hull(vector<Point> p) {
    sort(p.begin(), p.end());
    vector<Point> hull;
    for(int t = 0; t < 2; t++) {                     //t=0 下凸包, t=1 上凸包
        int base = hull.size();
        for(Point q : p) {
            while((int)hull.size() - base >= 2 &&
                  sgn(cross(hull[hull.size() - 2], hull.back(), q)) <= 0)    hull.pop_back();
            hull.push_back(q);
        }
        hull.pop_back();                             //首尾点重复
        reverse(p.begin(), p.end());
    }
    return hull;
}

double polygon_area(vector<Point>& poly) {           //鞋带公式, 顶点按序(任意多边形)
    double s = 0;
    for(int i = 0; i < (int)poly.size(); i++) {
        Point a = poly[i], b = poly[(i + 1) % poly.size()];
        s += cross(a, b);
    }
    return fabs(s) / 2;
}

//点在多边形内(绕数法): 返回 -1 在边界上, 1 在内部, 0 在外部; 多边形顶点按序
int in_polygon(vector<Point>& poly, Point p) {
    int wn = 0;
    int n = poly.size();
    for(int i = 0; i < n; i++) {
        Point a = poly[i], b = poly[(i + 1) % n];
        if(on_seg(a, b, p))    return -1;
        if(sgn(a.y - p.y) <= 0) {
            if(sgn(b.y - p.y) > 0 && sgn(cross(a, b, p)) > 0)    wn++;
        }
        else {
            if(sgn(b.y - p.y) <= 0 && sgn(cross(a, b, p)) < 0)    wn--;
        }
    }
    return wn != 0;
}
//配套: 点积求夹角 cos = dot/(|a||b|);  三点共线 sgn(cross(a,b,c)) == 0
