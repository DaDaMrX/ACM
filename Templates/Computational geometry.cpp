/********************************************************************************
计算几何

点，向量定义
点-点=向量
向量+向量=向量
数乘向量*
向量点乘dot()
向量模norm()
向量叉乘cross()
三点叉乘cross()
取符号sign()
判两点相等==
两点距离dist()
********************************************************************************/
typedef struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
} Vector;

Vector operator-(Point A, Point B)    
{
    return Vector(A.x - B.x, A.y - B.y);
}

Vector operator+(Vector A, Vector B)
{
    return Vector(A.x + B.x, A.y + B.y);
}

Vector operator*(double k, Vector A)
{
    return Vector(k * A.x, k * A.y);
}

double dot(Vector A, Vector B)
{
    return A.x * B.x + A.y * B.y;
}
double norm(Vector A)
{
    return sqrt(dot(A, A));
}

double cross(Vector A, Vector B)
{
    return A.x * B.y - B.x * A.y;
}

double cross(Point A ,Point B, Point C)
{
    return cross(B - A, C - A);
}

int sign(double x)
{
    if(abs(x) < eps) return 0;
    return x > 0 ? 1 : -1;
}
bool operator==(Point A, Point B)
{
    return sign(A.x - B.x) == 0 && sign(A.y - B.y) == 0;
}

/********************************************************************************
凸包Graham O(nlogn)
判断点在凸包内 O(logn)
********************************************************************************/
int n, m;
Point p[N], c[N];
Point referPoint;
bool cmp1(Point p1, Point p2)
{
	if (sign(p1.y - p2.y) != 0) return p1.y < p2.y;
	return p1.x < p2.x;
}
bool cmp2(Point p1, Point p2)
{
	Vector A = p1 - referPoint, B = p2 - referPoint;
	int sgn = sign(cross(A, B));
	if (sgn != 0) return sgn > 0;
	return norm(A) < norm(B);
}
void graham()
{
	sort(p + 1, p + n + 1, cmp1);
	referPoint = p[1];
	sort(p + 2, p + n + 1, cmp2);
	m = 0;
	c[++m] = p[1];
	c[++m] = p[2];
	for (int i = 3; i <= n; i++)
	{
		while (cross(p[i] - c[m], c[m] - c[m - 1]) > 0)
			m--;
		c[++m] = p[i];
	}
}

bool in_convex(Point P)
{
	if (sign(cross(P, c[1], c[2])) > 0) return false;
	if (sign(cross(P, c[1], c[m])) < 0) return false;

	int low = 2, high = m;
	while (high - low > 1)
	{
		int mid = low + high >> 1;
		int sgn = sign(cross(P, c[1], c[mid]));
		if (sgn == 0) 
			return sign(dist(P, c[1]) - dist(c[mid], c[1])) <= 0 ? true : false;
		if (sgn < 0) low = mid;
		else high = mid;
	}

	return sign(cross(P, c[low], c[high])) <= 0 ? true : false;
}


/********************************************************************************
Other
********************************************************************************/

struct Point
{
	double x, y;
	Point() {};
	Point(double x, double y) : x(x), y(y) {};
};
typedef Point Vector;
struct Segment
{
	Point a, b;
	Segment() {};
	Segment(Point a, Point b) :a(a), b(b) {};
};
Vector operator+(Vector A, Vector B)
{
	return Vector(A.x + B.x, A.y + B.y);
}


//线段相交，特殊情况判断
//叉积乘积小于0，边界情况不算相交，叉积乘积小于等于0，边界情况算相交
int sgn(double x)
{
	if (abs(x) < eps) return 0;
	return x > 0 : 1 : -1;
}
bool intersection(Segment seg1, Segment seg2)
{
	return
		min(seg1.a.x, seg1.b.x) <= max(seg2.a.x, seg2.b.x) &&
		min(seg2.a.x, seg2.b.x) <= max(seg1.a.x, seg1.b.x) &&
		min(seg1.a.y, seg1.b.x) <= max(seg2.a.y, seg2.b.y) &&
		min(seg2.a.y, seg2.b.y) <= max(seg1.a.y, seg1.a.y) &&
		sgn(cross(seg1.b - seg1.a, seg2.a - seg1.a)) * sgn(cross(seg1.b - seg1.a, seg2.b - seg1.a)) <= 0 &&
		sgn(cross(seg2.b - seg2.a, seg1.a - seg2.a)) * sgn(cross(seg2.b - seg2.a, seg1.b - seg2.a)) <= 0;
}

double dist(Point p, Segment seg)
{
	return abs(cross(seg.b - seg.a, p - seg.a)) / norm(seg.b - seg.a);
}
