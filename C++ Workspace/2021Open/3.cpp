#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define x first
#define y second
typedef long long ll;
typedef pair<long double, long double> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int N;
bool intersect(array<long double, 4> l1, array<long double, 4> l2){
	pii p1 = {l1[0], l1[1]};
	pii q1 = {l1[2], l1[3]};
	pii p2 = {l2[0], l2[1]};
	pii q2 = {l2[2], l2[3]};
	
	//both vertical lines
	if((p1.f == q1.f) && (p2.f == q2.f)){
		if(p1.f == p2.f){
			if(min(p1.s, q1.s) < max(p2.s, q2.s))return true;
			if(min(p2.s, q2.s) < max(p1.s, q1.s))return true;
		}
		return false;
	}
	//p1q1 is vertical
	if(p1.f == q1.f){
		if(p1.f <= min(p2.f, q2.f) || p1.f >= max(p2.f, q2.f))return false;
		assert(p2.f != q2.f);
		long double s2 = (1.0*p2.s-q2.s)/(p2.f-q2.f);
		long double yint = 1.0*p2.s - p2.f * s2;
		long double ip = 1.0*p1.f * s2 + yint;
	
		if(ip > min(p1.s,q1.s) && ip < max(p1.s, q1.s))return true;
		else{return false;}
	}
	if(p2.f == q2.f){
		if(p2.f <= min(p1.f, q1.f) || p2.f >= max(p1.f, q1.f))return false;
		assert(p1.f != q1.f);
		long double s2 = (1.0*p1.s - q1.s)/(p1.f - q1.f);
		long double yint = p1.s - 1.0*p1.f * s2;
		long double ip = 1.0*p2.f * s2 + yint;
		if(ip > min(p2.s,q2.s) && ip < max(p2.s, q2.s))return true;
		else{return false;}
	}
	//no vertical lines
	assert(p1.f != q1.f && p2.f != q2.f);
	long double s1 = (1.0*p1.s - q1.s)/(p1.f - q1.f);
	long double s2 = (1.0*p2.s - q2.s)/(p2.f - q2.f);
	long double yin1 = p1.s - p1.f*s1;
	long double yin2 = p2.s - p2.f*s2;
	if(abs(s1-s2) <= 0.0000001){
		if(abs(yin1-yin2) > 0.0000001)return false;
		if(max(p1.f, q1.f) > min(p2.f, q2.f))return true;
		if(max(p2.f, q2.f) > min(p1.f, q1.f))return true;
		return false;
	}
	long double xp = (1.0*yin1 - yin2)/(1.0*s2-s1);
	if(xp > min(p2.f, q2.f) && xp < max(p2.f,q2.f) && xp > min(p1.f, q1.f) && xp < max(p1.f, q1.f))return true;
	return false;
}
main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//p3
	cin >> N;
	pii pts[N];
	for(int i = 0; i < N;i ++){
		cin >> pts[i].f >> pts[i].s;
	}
	int ans = 0;
	int cntp = 0;
	sort(pts, pts + N);
	do{
		vector<array<long double, 4>> lines;
		assert(lines.size() == 0);
		for(int i = 0; i < 3;i ++){
			int next = (i+1)%3;
			lines.pb({pts[i].f, pts[i].s, pts[next].f, pts[next].s});
		}
		bool good = true;
		for(int i = 3; i < N;i ++){
			int cnt = 0;
			for(int j = 0;j < i; j++){
				//try to draw a line from i to j
				array<long double, 4> curr = {pts[i].f, pts[i].s, pts[j].f, pts[j].s};
				bool wrk = true;
				for(auto it : lines){
					if(intersect(it, curr)){

						wrk = false;
					}
				}
				if(wrk){
					cnt++;
					lines.pb(curr);
				}

			}
			if(cnt != 3){
				good = false;
			}
		}
		//if(!good)continue;
			if(good){
			ans++;
			ans %= 1000000007;
		}
	}
	while(next_permutation(pts, pts + N));
	cout << ans << '\n';
	assert(ans >= 0);
}
