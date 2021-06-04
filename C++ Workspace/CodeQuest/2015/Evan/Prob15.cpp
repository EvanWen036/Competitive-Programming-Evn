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
int dp[55][55];
int main(){
	ofstream cout("Prob15.out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string genome;
		cin >> genome;
		int n;
		cin >> n;
		vector<string> list;
		int bestAns = -1;
		for(int i = 0; i <= n;i ++){
			string line;
			getline(cin, line);
			int pos = line.find("=");
			string name = line.substr(0, pos);
			string ge = line.substr(pos+1);
			assert(ge.length() <= 54 && genome.length() <= 54);
			memset(dp, 0, sizeof(dp));
			for(int i = 1; i <= genome.length(); i++){
				for(int j = 1;j <= ge.length();j ++){
					dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + (genome[i-1] == ge[j-1]?1:0)});
				}
			}
			if(dp[genome.length()][ge.length()] > bestAns){
				bestAns = dp[genome.length()][ge.length()];
				list.clear();
				list.pb(name);
			}
			else if(dp[genome.length()][ge.length()] == bestAns){
				list.pb(name);
			}
			//cout << name << " " << ge << '\n';
			
		}
		sort(list.begin(), list.end());
		for(int i = 0; i < list.size(); i++){
			cout << list[i];
			if(i != list.size()-1){
				cout << ", ";
			}
		}
		cout << '\n';
	}


}
