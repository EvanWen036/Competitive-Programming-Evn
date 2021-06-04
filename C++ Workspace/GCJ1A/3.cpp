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
vector<pair<string,int>> st;
int q;
vector<string> pos;

void go(string curr){
	//cout << curr << " " << p << '\n';
	if(curr.length() == q){
		//cout << curr << '\n';
		for(auto it : st){
			//if works
			int sc = 0;
			for(int i = 0; i < q;i ++){
				if(it.f[i] == curr[i])sc++;
			}
			if(sc != it.s)return;
		}
		pos.pb(curr);
		return;
	}
	curr += "T";
	go(curr);
	curr = curr.substr(0, curr.length()-1);
	curr += "F";
	go(curr);
}
double best = 0;
int bn;
int bd;
void go2(string curr){
	if(curr.length() == q){
		//cout << curr << '\n';
		int num = 0;
		int den = pos.size();
		for(auto it : pos){
			int sc = 0;
			for(int i = 0; i < q;i ++){
				if(it[i] == curr[i])sc++;
			}
			num += sc;
		}
		//cout << num << " " << den << '\n';
		if(1.0*num/den > best){
			bn = num /= __gcd(num, den);
			bd = den /= __gcd(num, den);
			best = 1.0*num/den;
		}
		return;
	}
	curr += "T";
	go2(curr);
	curr = curr.substr(0, curr.length()-1);
	curr += "F";
	go2(curr);
}
int cs = 1;
void solve(){
	int n;
	cin >> n >> q;
	for(int i=0;i < n;i ++){
		string s; int sc;
		cin >> s >> sc;
		st.pb({s,sc});	
	}
	go("");

	go2("");
	cout << "Case #" << cs++ << ": " << bn << "/" << bd << '\n';
	pos.clear();
	st.clear();
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//p3
	int t;
	cin >> t;
	while(t--)solve();


}
