#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxn = 1100;
const double esp = 1e-10;
struct point {
    double x, y;
}poi[maxn];
struct line1 {
    point head, tail;
}line[maxn];
double tmin(double a, double b) {
    return a < b ? a : b;
}
double tmax(double a, double b) {
    return a > b ? a : b;
}
//判断是否相交
bool inter(const line1& m, const line1& n) {
    point a = m.head;
    point b = m.tail;
    point c = n.head;
    point d = n.tail;
    if (tmin(a.x, b.x) > tmax(c.x, d.x) ||
        tmin(a.y, b.y) > tmax(c.y, d.y) ||
        tmin(c.x, d.x) > tmax(a.x, b.x) ||
        tmin(c.y, d.y) > tmax(a.y, b.y))
        return 0;
    double h, i, j, k;
    h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
    j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
    return h * i <= esp && j * k <= esp;
}
int main() {
    int n;
    int cas = 1;
    //cin >> n;
    while ((scanf("%d", &n)) != EOF) {
        if (n == 0)
            break;
        if (cas != 1)
            puts("");
        for (int i = 0; i < n; i++) {
            cin >> poi[i].x >> poi[i].y;
        }
        if (n < 3) {
            printf("Figure %d: Impossible\n", cas++);
            continue;
        }
        for (int i = 0; i < n; i++) {
            point u, v;
            if ((i == (n - 1))) {
                u.x = poi[i].x;
                u.y = poi[i].y;
                v.x = poi[0].x;
                v.y = poi[0].y;
            }
            else {
                u.x = poi[i].x;
                u.y = poi[i].y;
                v.x = poi[i + 1].x;
                v.y = poi[i + 1].y;
            }
            line[i].head = u;
            line[i].tail = v;
        }
        bool flag = false;
        bool tmp = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j++) {
                if (i == 0 && (j == (n - 1)))
                    continue;
                tmp = inter(line[i], line[j]);
                if (tmp) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag) {
            printf("Figure %d: Impossible\n", cas++);
        }
        else {//求多边形面积
            double area = 0;
            double x1, x2, y1, y2, x0, y0;
            x0 = x1 = poi[0].x;
            y0 = y1 = poi[0].y;
            for (int i = 1; i <= n; i++)
            {
                if (i < n) {
                    x2 = poi[i].x;
                    y2 = poi[i].y;
                }
                else
                {
                    x2 = x0;
                    y2 = y0;
                }
                area += (y1 + y2) * (x2 - x1) * 0.5;
                x1 = x2;
                y1 = y2;
            }
            if (area < 0)
                area *= -1;
            printf("Figure %d: %.2f\n", cas++, area);
        }
    }
    return 0;
}

