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
Vector operator-(Vector A, Vector B)
{
	return Vector(A.x - B.x, A.y - B.y);
}
double dot(Vector A, Vector B)
{
	return A.x * B.x + A.y * B.y;
}
double cross(Vector A, Vector B)
{
	return A.x * B.y - B.x * A.y;
}
int sgn(double x)
{
	if (abs(x) < eps) return 0;
	if (x < 0) return -1;
	return 1;
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
double norm(Vector A)
{
	return sqrt(A.x * A.x + A.y * A.y);
}
double dist(Point p1, Point p2)
{
	return norm(p2 - p1);
}
double dist(Point p, Segment seg)
{
	return abs(cross(seg.b - seg.a, p - seg.a)) / norm(seg.b - seg.a);
}

int n;
Point p[4 * N], convex[4 * N];
Point refer;

bool cmp1(Point p1, Point p2)
{
	if (abs(p1.y - p2.y) > eps) return p1.y < p2.y;
	return p1.x < p2.x;
}
bool cmp2(Point p1, Point p2)
{
	double c = cross(p1 - refer, p2 - refer);
	if (abs(c) > eps) return c > 0;
	return norm(p1 - refer) < norm(p2 - refer);
}
int graham(int n)
{
	sort(p + 1, p + 1 + n, cmp1);
	refer = p[1];
	sort(p + 2, p + 1 + n, cmp2);
	int m = 0;
	convex[m++] = p[1];
	convex[m++] = p[2];
	for (int i = 3; i <= n; i++)
	{
		while (cross(p[i] - convex[m - 1], convex[m - 1] - convex[m -2]) > 0)
			m--;
		convex[m++] = p[i];
	}
	return m;
}