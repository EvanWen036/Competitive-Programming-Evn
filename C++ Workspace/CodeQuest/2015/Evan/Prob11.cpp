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
map<char, int> grp;
int main(){
	ofstream cout("Prob11.out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	grp['b']=1;
	grp['f']=1;
	grp['p']=1;
	grp['v']=1;
	grp['c']=2;
	grp['g']=2;
	grp['j']=2;
	grp['k']=2;
	grp['q']=2;
	grp['s']=2;
	grp['x']=2;
	grp['z']=2;
	grp['d']=3;
	grp['t']=3;
	grp['l']=4;
	grp['m']=5;
	grp['n']=5;
	grp['r']=6;
	while(t--){
		int n;
		cin >> n;
		cout << "OUTPUT\n";
		map<string, int> v;
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			for(int j = 0;j < s.length();j++){
				s[j] = tolower(s[j]);
			}
			string a = "";
			for(int j = 0;j  < s.length();j ++){
				if(s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' && s[j] != 'h' && s[j] != 'w'){
					a += s.substr(j,1);
				} 
				else if(j == 0){
					a+=s.substr(j,1);
				}
			}
			//cout << a << '\n';
			string f;
			for(int j = 0; j < a.length(); j++){
				if(j == 0 || grp[a[j-1]] != grp[a[j]]){
					f += a.substr(j,1);
				}
			}
			int dig = 0;
			//cout <<f << '\n';
			f[0]=toupper(f[0]);
			string se = f.substr(0,1);
			for(int j = 1;j < f.length();j ++){
				if(dig == 3)break;
				se += to_string(grp[f[j]]);
				dig++;
			}
			while(dig < 3){
				se += "0";
				dig++;
			}
			v[se]++;
		}
		for(auto it : v){
			cout << it.f << " " << it.s << '\n';
		}
	}	


}
