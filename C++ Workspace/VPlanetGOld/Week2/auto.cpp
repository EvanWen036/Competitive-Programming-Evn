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

int main(){
	freopen("auto.in", "r", stdin);
	freopen("auto.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<pair<string, int>> words;
	for(int i = 0; i < N;i ++){
		string s;
		cin >> s;
		words.pb({s,i});
	}	
	sort(words.begin(), words.end());
	for(int i = 0; i < K;i ++){
		int k; string s;
		cin >> k >> s;
		vector<pair<string,int>>::iterator it = lower_bound(begin(words),end(words), make_pair(s,0));
		bool bad = false;
		for(int i = 1; i <= k; i++){
			string current = (*it).f;
			if(s.length() <= current.length() && current.substr(0, s.length()) == s){
				if(i == k){
					cout << (*it).s+1<< '\n';
				}
				it++;
			}
			else{
				cout << -1 << '\n';
				break;
			}
		}
	}


}
