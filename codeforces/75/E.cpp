#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100007
#define MOD 1000000007
#define MODL 1000000007LL
#define EPS 1e-12
#define sz(x) ((int)(x).size())
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update> 
 

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

// Trace dinâmico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

// Debugador de recursão
int recNum = 0;
void prTabs() { for (int ii = 0; ii < recNum; ++ii) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}


#define PI (4*atan(1LL))

bool eq(double d1, double d2) { return fabs(d1 - d2) < EPS;}
bool dif(double d1, double d2) { return !eq(d1, d2);}
bool men(double d1, double d2) { return d1 + EPS < d2;}
bool mai(double d1, double d2) { return d1 > d2 + EPS;}

struct pt {double x, y;
    bool operator < (pt o) {
        return eq(x, o.x) ? y < o.y : x < o.x;}
    bool operator == (pt o) {
        return eq(x, o.x) && eq(y, o.y);
    }
    pt operator + (pt o) { //Soma de pontos
        return  {x + o.x, y + o.y};
    }
    pt operator - (pt o) { //Diferença de pontos
        return {x - o.x, y - o.y};
    }
    pt operator * (double o) { // Escalar ponto
        return {x * o, y * o};
    }
    pt operator / (double o) { // Escalar ponto
        return {x / o, y / o};
    }
    double operator * (pt o) { // Produto escalar |this|*|o|*cos(this->o)
        return x * o.x + y * o.y;
    }
    double operator ^ (pt o) { // Produto cruzado |this|*|o|*sin(this->o)
        return x * o.y - y * o.x;
    }
    double operator ~ () { // Comprimento do vetor
        return hypot(x, y);
    }
    double operator | (pt o) { //Distância entre 2 pontos Pre: (pt: -, ~) 
        return ~((*this)-o);
    }
    double operator - () { // Comprimento de vetor ao quadrado
        return x * x + y * y;
    }
    pt rotate(double an) { //Rotaciona ponto ao redor da origem em ângulo an (em radianos)
        return {x*cos(an)-y*sin(an), x*sin(an)+y*cos(an)};
    }
    pt rotateAround(pt p, double an) { //Rotaciona ao redor do ponto p em ângulo an(radianos)
    return (((*this)-p).rotate(an))+p;
    }
    double an() { // Ângulo do vetor em relação ao eixo x
        return atan2(y, x);
    }
    pt rot90() { return {-y, x}; }
    pt rot90cw() { return {y, -x}; }
    pt unit() { return (*this)/(~(*this)); }
};

//Para printar ponto com cout/trace
ostream &operator<<(ostream &out, const pt &p) { return out << "{" << p.x << ", " << p.y << "}"; }

// Distância entre ponto p e linha com pointos a e b. Pre: (pt: -, ^, |) 
double distToLn(pt p, pt a, pt b) {
    return fabs(((a-p)^(b-p))/(a|b)); 
}

// Distância entre ponto p e segmento entre pointos a e b. Pre: (pt: -, +, *, *(double), -(), |)
double distToSeg(pt p, pt a, pt b) {
    double u = ((p-a)*(b-a)) / (-(b-a));
    return p|(a + ((b-a) * max(0.0, min(1.0, u))));
}

// Retorna ângulo aob em radianos Pre: (pt: -, an()) 
// an(a, b, c)*180.0/pi para obter o resultado em graus
double an(pt a, pt o, pt b) {
    return (b-o).an() - (a-o).an();
}

//Retorna se o ponto p está a esquerda da linha que passa de q para r Pre: (pt: -, ^)
bool isLeft( pt p, pt q, pt r ) {
    return mai((r-q)^(p-q), 0.0);
}

//Retorna se os pontos p, q e r são colineares Pre: (pt: -, ^)
bool col(pt p, pt q, pt r) {
    return eq((r-q)^(p-q), 0.0);
}

// Retorna intersecção de linhas ln(a, b) e ln(c, d)
pt linesIntersection(pt a, pt b, pt c, pt d) {
    double s = (b-a)^(d-c);
    if (fabs(s) < EPS) {//parallel or equal lines
        return {1e18, 1e18};
    }
    double s1 = (c-a)^(d-a);
    return a + ((b-a)*(s1/s));
}

bool segIntersection(pt a, pt b, pt c, pt d, pt &r) {
    double s = (b-a)^(d-c);
    if (fabs(s) < EPS) {//parallel or equal lines
        return false;
    }
    double s1 = (c-a)^(d-a);
    r = a + ((b-a)*(s1/s));
    if (distToSeg(r, a, b) > EPS || distToSeg(r, c, d) > EPS || (a|r) < EPS) return false;
    return true;
}


pt s, e;
vector<pt> poly;
vector<pt> inter;
double total, dinterior;

double a, b, c, d;
int main(){
    int n, m, k;
    sc("%lf %lf %lf %lf", &a, &b, &c, &d);
    s = {a, b}; e = {c, d};
	sc("%d", &n);
    for(int i = 0; i < n; i++) {
        sc("%lf %lf", &a, &b);
        poly.pb({a, b});
    }
    //falta testar caso em que segmento é tangente ao polígono
    d = 0;
    poly.pb(poly[0]);
    for(int i = 0; i < n; i++) {
        pt tmp;
        if (segIntersection(poly[i], poly[i+1], s, e, tmp)) {
            inter.pb({tmp});
            if (sz(inter) == 1) {
                d += (tmp|poly[i+1]);
            } else {
                d += (tmp|poly[i]);
            }
        } else if (sz(inter) == 1) {
            d += (poly[i]|poly[i+1]);
        }
        total += (poly[i]|poly[i+1]);
    }
    d = min(total - d, d);

    if (sz(inter) < 2) {
        pr("%.12lf\n", s|e);
    } else {
        if ((s|inter[0]) > (s|inter[1])) swap(inter[0], inter[1]);
        pr("%.12lf\n", min((s|inter[0]) + d + (e|inter[1]), (s|inter[0]) + 2.0*(inter[0]|inter[1]) + (e|inter[1])));
    }
    
 	return 0;
}