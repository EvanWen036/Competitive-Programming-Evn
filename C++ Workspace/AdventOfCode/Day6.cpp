#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream File("input.in");
	int ans = 0;
	while(!File.eof()){
		string s;
		map<char, int> cnt;
		int amt = 0;
		while(getline(File, s) && !s.empty()){
			amt++;
			for(char c : s){
				cnt[c]++;
			}
		}
		map<char, int>::iterator it = cnt.begin();
		while(it != cnt.end()){
			if(it -> second == amt){
				ans++;
			}
			it++;
		}
	}
	cout << ans << '\n';

}
