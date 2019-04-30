#include <cstdio>
#include <vector>
#include <cmath>

#define EPS 0.001

using namespace std;

struct point
{
    double x, y;
};

struct segment
{
    point p1, p2;
};

int N;
vector<point> pts;
vector<segment> segs;

bool is_intersect(segment& s1, segment& s2)
{
    double x0 = s1.p1.x, y0 = s1.p1.y;
    double x1 = s1.p2.x, y1 = s1.p2.y;
    double x2 = s2.p1.x, y2 = s2.p1.y;
    double x3 = s2.p2.x, y3 = s2.p2.y;
    double D = ((x1 - x0) * (y2 - y3) + (x3 - x2) * (y1 - y0));
    if (fabs(D) <= EPS)
        return false;
    double s = ((x2 - x0) * (y2 - y3) + (x3 - x2) * (y2 - y0)) / D;
    if (s < 0 - EPS || s > 1 + EPS)
        return false;
    double t = ((x1 - x0) * (y2 - y0) + (x0 - x2) * (y1 - y0)) / D;
    if (t < 0 - EPS || t > 1 + EPS)
        return false;
    return true;
}

bool possible()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 2; j < N; j++)
        {
            if (i == 0 && j == N - 1)
                continue;
            if (is_intersect(segs[i], segs[j]))
                return false;
        }
    }
    return true;
}

int main()
{
    int cs = 1;
    while (scanf("%d", &N) && N)
    {
        if (cs != 1)
            printf("\n");
        printf("Figure %d: ", cs++);

        pts.clear();
        segs.clear();
        for (int i = 0; i < N; i++)
        {
            point p;
            scanf("%lf %lf", &p.x, &p.y);
            pts.push_back(p);
        }

        if (N <= 2)
        {
            printf("Impossible\n");
            continue;
        }

        for (int i = 0; i < N; i++)
        {
            segment s;
            s.p1 = pts[i];
            s.p2 = pts[(i + 1) % N];
            segs.push_back(s);
        }

        if (!possible())
        {
            printf("Impossible\n");
            continue;
        }

        double area = 0;

        for (int i = 0; i < N; i++)
        {
            point p1 = segs[i].p1;
            point p2 = segs[i].p2;
            area += (p1.x - p2.x) * (p1.y + p2.y);
        }

        area /= 2;
        area = fabs(area);
        printf("%.2f\n", area);
    }
    return 0;
}
