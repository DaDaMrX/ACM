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
bool intersection(Segment seg1, Segment seg2)
{
	Vector vec = seg1.b - seg1.a;
	Vector vec1 = seg2.a - seg1.a;
	Vector vec2 = seg2.b - seg1.a;
	bool b1 = (cross(vec1, vec) * cross(vec2, vec) < 0);
	vec = seg2.b - seg2.a;
	vec1 = seg1.a - seg2.a;
	vec2 = seg1.b - seg2.a;
	bool b2 = (cross(vec1, vec) * cross(vec2, vec) < 0);
	return b1 && b2;
}
double distan(Point p1, Point p2)
{
	double dx = p2.x - p1.x, dy = p2.y - p1.y;
	return sqrt(dx * dx + dy * dy);
}
bool online(Point p, Segment seg)
{
	return abs(cross(p - seg.a, seg.b - seg.a)) < eps;
}
bool inrec(Point p, Segment seg)
{
	double xleft, xright, yup, ydown;
	if (seg.a.x < seg.b.x) xleft = seg.a.x, xright = seg.b.x;
	else xleft = seg.b.x, xright = seg.a.x;
	if (seg.a.y < seg.b.y) ydown = seg.a.y, yup = seg.b.y;
	else ydown = seg.b.y, yup = seg.a.y;
	return (p.x >= xleft && p.x <= xright && p.y >= ydown && p.y <= yup);
}
bool onseg(Point p, Segment seg)
{
	return online(p, seg) && inrec(p, seg);
}