#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int N;
vector<pair<int,string>> cows;
vector<pii> oddPref;
vector<pii> evenPref;
map<int,int> ans1;
map<int,int> ans2;
int main(){
	clock_t tStart = clock();
	freopen("fairphoto.in", "r", stdin);
	freopen("fairphoto.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i=0; i < N;i ++){
		int a; string s;
		cin >> a >> s;
		cows.pb({a,s});
	}
	sort(cows.begin(), cows.end());
	evenPref.pb({0,0});
	int amt1=0; int amt2 =0;
	for(int i = 1; i <= N;i ++){
		if(cows[i-1].s == "S")amt1++;
		else{amt2++;}
		if(i % 2 == 1){
			oddPref.pb({amt1,amt2});
		}
		else{
			evenPref.pb({amt1,amt2});
		}
		//cout << amt1 << " " << amt2 << '\n';
	}
	int ans = 0;
	amt1 = 0;
	amt2 = 0;
	set<pii> s1;
	set<pii> s2;
	//s1 has odd indices
	//s2 has even indices
	s2.insert({0,0});
	for(int i = 1; i <= N;i ++){
		if(cows[i-1].s == "S")amt1++;
		else{amt2++;}
		if(i % 2 == 1){
			//query set1
			set<pii>::iterator it = s1.begin();
			bool isprev = false;
			if(ans1.count(amt2-amt1)){
				ans = max(ans,cows[i-1].f - cows[ans1[amt2-amt1]].f);
				continue;
			}
			int mi = i;
			while(it != s1.end() && (*it).f <= amt2-amt1){
				ans = max(ans, cows[i-1].f - cows[(*it).s].f);
				mi = min(mi, (*it).s);
				if((*it).f <= amt2-amt1)isprev=true;
				it++;
			}
			if(!isprev){
				ans1[amt2-amt1] = mi;
				s1.insert({amt2-amt1,i});
			}
		}
		else{
			set<pii>::iterator it = s2.begin();
			bool isprev = false;
			if(ans2.count(amt2-amt1)){
				ans = max(ans,cows[i-1].f - cows[ans2[amt2-amt1]].f);
				continue;
			}
			int mi = i;
			while(it != s2.end() && (*it).f <= amt2-amt1){
				ans = max(ans, cows[i-1].f - cows[(*it).s].f);
				mi = min(mi, (*it).s);
				if((*it).f <= amt2-amt1)isprev=true;
				it++;
			}
			if(!isprev){
				ans2[amt2-amt1]= mi;
				s2.insert({amt2-amt1, i});
			}
		}
	}
	cout << ans << '\n';

}
