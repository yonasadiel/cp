#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

double degToRad(double a){return a*pi/180.0;}
double radToDeg(double a){return a*180.0/pi;}

struct point_i{
	int x,y;
	point_i(){x = 0; y=0;}
	point_i(int _x, int _y){x = _x; y = _y;}
};

struct point{
	double x,y;
	point(){x = y = 0.0;}
	point(double _x, double _y): x(_x), y(_y){}
	bool operator < (point other) const {
		if(fabs(x-other.x)>eps){return x < other.x;}
		return y<other.y;
	}
	bool operator == (point other){return ((fabs(x-other.x)<eps) && (fabs(y-other.y)<eps));}
};
struct vec{
	double x,y;
	vec(double _x, double _y): x(_x), y(_y){}
};

vec toVec(point a, point b){
	return vec(b.x-a.x, b.y-a.y);
}
double dist(point p1, point p2){return hypot(p1.x-p2.x,p1.y-p2.y);}

double perimeter(const vector<point> &P){
	double result = 0.0;
	for(int i=0;i<P.size()-1;i++){
		result+=dist(P[i],P[i+1]);
	}
	return result;
}

double area(const vector<point> &P){
	double result = 0.0, x1,x2,y1,y2;
	for(int i=0;i<P.size()-1;i++){
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result+=(x1*y2 - x2*y1);
	}
	return fabs(result)/2.0;
}

double dot(vec a, vec b){return (a.x*b.x + a.y*b.y);}
double norm_sq(vec v){return (v.x*v.x + v.y*v.y);}

double angle(point a, point o, point b){//return in rad
	vec oa = toVec(o,a), ob = toVec(o,b);
	return acos(dot(oa,ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}



double cross(vec a, vec b){return a.x*b.y - a.y*b.x;}
bool ccw(point p, point q, point r){
	return cross(toVec(p,q), toVec(p,r)) > 0;
}
bool collinear(point p, point q, point r){
	return fabs(cross(toVec(p,q), toVec(p,r))) < eps;	
}

bool isConvex(const vector<point> &P){
	int sz = P.size();
	if(sz <= 3){return false;}
	bool isLeft = ccw(P[0],P[1],P[2]);
	for(int i=1;i<sz-1;i++){
		if(ccw(P[i],P[i+1],P[(i+2)==sz? 1:i+2]) != isLeft){return false;}
	}
	return true;
}

bool inPolygon(point pt, const vector<point> &P){
	if(P.size()==0){return false;}
	double sum = 0.0;
	for(int i=0;i<P.size()-1;i++){
		if(ccw(pt,P[i],P[i+1])){sum+=angle(P[i],pt,P[i+1]);}
		else{sum-=angle(P[i],pt,P[i+1]);}
	}
	return fabs(fabs(sum)-2*pi) <eps;
}

point pivot;
bool angleCmp(point a, point b){
	if(collinear(pivot, a, b)){return dist(pivot,a) < dist(pivot,b);}
	point d1,d2;
	d1.x = a.x - pivot.x, d1.y = a.y - pivot.y;
	d2.x = b.x - pivot.x, d2.y = b.y - pivot.y;
	return (atan2(d1.y,d1.x) - atan2(d2.y,d2.x)) < 0;
}

vector<point> CH(vector<point> P) {
	int i,j, n =P.size();
	if(n<=3){
		if(!(P[0]==P[n-1])){P.pb(P[0]);}
		return P;
	}
	//find index so that P[idx] has lowest Y, if tie..the rightmost X
	int idx = 0;
	for(i=1;i<n;i++){
		if(P[i].y < P[idx].y || (P[i].y==P[idx].y && P[i].x > P[idx].x)){
			idx = i;
		}
	}
	//swap routine
	point temp = P[0]; P[0] = P[idx]; P[idx] = temp;
	//sort
	pivot = P[0];
	sort(++P.begin(),P.end(),angleCmp);

	vector<point> S;
	S.pb(P[n-1]); S.pb(P[0]); S.pb(P[1]);
	i = 2;
	while(i<n){
		j = S.size()-1;
		if(ccw(S[j-1],S[j],P[i])){S.pb(P[i++]);}
		else{S.pop_back();}
	}
	return S;
}

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); }

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
  vector<point> P;
  for (int i = 0; i < (int)Q.size(); i++) {
    double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
    if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
    if (left1 > -eps) P.push_back(Q[i]);       // Q[i] is on the left of ab
    if (left1 * left2 < -eps)        // edge (Q[i], Q[i+1]) crosses line ab
      P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
  }
  if (!P.empty() && !(P.back() == P.front()))
    P.push_back(P.front());        // make P's first point = P's last point
  return P; }

int main() {
    int n;
    vector<point> v, ch;
    scanf("%d", &n);
    for (int i= 0; i < n; i++) {
        double a, b;
        scanf("%lf%lf", &a, &b);
        v.push_back(point(a, b));
    }

    ch = CH(v);
    double ans = 0;
    for (int i = 0; i < ch.size(); i++) {
        int j = (i + 1) % ch.size();
        ans += ch[i].x * ch[j].y;
        ans -= ch[i].y * ch[j].x;
    }
    ans = ans / 2.0;
    printf("%.2lf\n", ans);
    return 0;
}