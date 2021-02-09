#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int getDir(pii P, pii A, pii B){
    B.f -= A.f;
    B.s -= A.s;
    P.f -= A.f;
    P.s -= A.s;
    int cross = B.f * P.s - B.s * P.f;
    if(cross > 0){
         //right
        return 1;
    }
    if(cross < 0){
        //left
        return 2;
    }
    return 0;
}
int orientation(pii p, pii q, pii r){
    int val = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);

    if(val == 0) return 0;
    return (val > 0) ? 1 : 2;
}
bool isInside(vector<pii> &hull, pii point){
    int dir = -1;
    set<int> s;
    for(int i = 0; i < hull.size(); i++){
        int next = (i+1)%hull.size();
        s.insert(getDir(point, hull[i], hull[next]));    
    }
    return s.size() == 1;
}
vector<pii> convexHull(vector<pii> &points, int N){
    vector<pii> hull;
    int l = 0;
    for(int i = 1; i < N; i++){
        if(points[i].f < points[l].f){
            l = i;
        }
    }
    int p = l, q;
    do{
        hull.push_back(points[p]);
        q = (p+1)%N;
        for(int i = 0; i < N; i++){
            
            if(orientation(points[p],points[i],points[q]) == 2){
                q = i;
        }
            
    }
    p = q;
    }while(p != l);
    return hull;

}
bool sortByAtan(pii a, pii b){
    return atan2(a.f,a.s) < atan2(b.f, b.s);
}
int main(){
	freopen("curling.in", "r", stdin);
	freopen("curling.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    vector<pii> A(N);
    vector<pii> B(N);
    int centroidX = 0;
    int centroidY = 0;
    for(int i = 0; i < N;i ++){
        cin >> A[i].f >> A[i].s;
        centroidX += A[i].f/N;
        centroidY += A[i].s/N;
    }
    for(int i = 0; i < N; i++){
        A[i].f -= centroidX;
        A[i].s -= centroidY;
    }
    sort(A.begin(), A.end(), sortByAtan);
    for(int i = 0; i < N; i++){
        A[i].f += centroidX; A[i].s += centroidY;
        //cout << A[i].f << " " << A[i].s << endl;
    }
    int centroidX2 = 0;
    int centroidY2 = 0;
    for(int i = 0; i < N ;i++){
        cin >> B[i].f >> B[i].s;
        centroidX2 += B[i].f/N;
        centroidY2 += B[i].s/N;
    }
    for(int i = 0; i < N; i++){
        B[i].f -= centroidX2; B[i].s -= centroidY2;
    }
    sort(B.begin(),B.end(), sortByAtan);
    for(int i = 0; i < N;i ++){
        B[i].f += centroidX2; B[i].s += centroidY2;
        //cout << B[i].f << " " << B[i].s << endl;
    }
    vector<pii> hullA = convexHull(A, N); 
    vector<pii> hullB = convexHull(B, N);
    int count = 0;
    for(int i = 0; i < N; i++){
        if(isInside(hullA, B[i])){
            //cout << B[i].f << " " << B[i].s << endl;
            count++;
        }
    }
    //cuut << count << " " ;
    int count2 = 0;
    for(int i = 0; i < N; i++){
        if(isInside(hullB, A[i])){
            //cout << A[i].f << " " << A[i].s << endl;
            count2++;

        }
    }
    cout <<count << " " << count2 << endl;

}

