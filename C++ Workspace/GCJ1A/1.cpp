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
int cs = 1;
int compare(string a, string b){
	if(a.length() < b.length())return -1;
	if(a.length() > b.length())return 1;
	for(int i = 0; i < a.length(); i++){
		if(a[i] > b[i])return 1;
		if(a[i] < b[i])return -1;
	}
	return 0;
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i ++)cin >> a[i];
	ll ans = 0;
	string cm = "";
	for(int i = 0; i < n;i ++){
		//cout << "hi"<< endl;
		if(compare(to_string(a[i]), cm) == 1){
			//cout << a[i] << " " << cm << '\n';
			cm = to_string(a[i]);
			continue;
		}
		string f = to_string(a[i]);
		string m = cm;
		string append = "";
		int lm = -1;
		for(int j = 0;j < m.size();j ++){
			if(j < f.size() && f[j] < m[j] && lm == -1)lm = 0;
			if(j < f.size() && f[j] > m[j] && lm == -1)lm = 1;
			if(j >= f.size()){
				//adding stuff
				if(lm == 1 || lm == 0){
					append += "0";
					ans++;
				}
				else{
					string dig = m.substr(j,1);
					string val = "0123456789";
					bool br = false;
					if(j == m.size()-1){
						if(dig == "9"){
							bool fixed = false;
							for(int d = j-1; d >= f.size(); d--){
								if(m[d] != '9'){
									fixed=true;
									for(int x = d+1; x < m.size(); x++){
										append[x-f.size()] = '0';
									}
									dig = "";
									append[d-f.size()] = val[val.find(append[d-f.size()]+1)];
									break;
								}
							}
							if(!fixed){
								br = true;
								dig = "00";
							}
						}
						else{
							//cout << dig << " ";
							dig = val[val.find(dig)+1];
							//cout << dig << '\n';
						}
					}
					ans+=dig.length();
					append += dig;
					if(br){
						for(int x = 0; x < append.size(); x++){
							append[x] = '0';
						}
					}
				}
			}
		}
		f += append;
		if(lm == 0 || lm == 1)assert(f.length() == cm.length());
		if(compare(f, cm) <= 0){
			f += "0";
			ans++;
		}
		assert(compare(f,cm) == 1);
		//cout << f << "\n";
		cm = f;
	}
	cout << "Case #" << cs++ << ": " << ans << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//p1
	int t;
	cin >> t;
	while(t--)solve();


}
