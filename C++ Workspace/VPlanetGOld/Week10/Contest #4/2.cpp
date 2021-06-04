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
string wr[30005];
bool wrk[30005];
map<string, int> m;
set<string> pref;
map<string, vector<int>> op; 
map<string,int> h;
string lp[30005];
bool compare(string x, string y){
	for(int i = 0; i < min(x.length(), y.length());i ++){
		if(h[x.substr(i,1)] == h[y.substr(i,1)])continue;
		if(h.count(x.substr(i,1)) == 0)return false;
		if(h.count(y.substr(i,1)) == 0)return true;
		return h[x.substr(i,1)] < h[y.substr(i,1)];
	}
	return x.size() < y.size();
}
int main(){
	//freopen("first.in", "r", stdin);
	//freopen("first.out","w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//p2
	cin >> N;
	for(int i = 0; i < N;i ++){
		cin >> wr[i];
		m[wr[i]] = i;
		set<string> let;
		string c;
		for(int j = 0;j < wr[i].length();j ++){
			if(let.count(wr[i].substr(j,1)) == 0){
				c += wr[i].substr(j,1);
				let.insert(wr[i].substr(j,1));
			}
		}
		lp[i] = c;
		pref.insert(c);
	}
	for(int i = 0; i < N;i ++){
		//if there is a prefix of c then treat this as the prefix
		//cout << i << endl;
		string c = lp[i];
		cout << c << endl;
		set<string>::iterator it = pref.begin();
		while(it != pref.end()){
			//cout << (*it) << endl;
			if((*it).length() <= c.length() && c.substr(0, (*it).length()) == (*it)){
				c=(*it);
				break;
			}
			it++;
		}
		//cout << "hi" << endl;
		//c = *it;
		cout << c << endl;
		//cout << c << '\n';
		op[c].pb(i);
	}

	for(auto it : pref){
		if(op[it].size() > 0)cout << it << endl;
		h.clear();
		for(int i = 0; i < it.length();i ++){
			h[it.substr(i,1)] = i;
		}
		vector<string> c;
		for(auto it : op[it]){
			c.pb(wr[it]);
		}

		sort(c.begin(), c.end(), compare);
		if(c.size() == 0)continue;
		wrk[m[c[0]]] = true;
	}
	vector<string> ans;
	for(int i = 0; i < N;i ++){
		if(wrk[i])ans.pb(wr[i]);
	}
	cout << ans.size() << '\n';
	for(string s : ans){
		cout << s << '\n';
	}
}
