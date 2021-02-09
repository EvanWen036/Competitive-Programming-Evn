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
	freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N= 1000;
	/**
	for(int i = 0; i < 3*N; i++){
		string s;
		cin >> s;
		for(char c : s){
			if(c == '-' || c == ':'){
				cout << " ";
			}
			else{
				cout << c;
			}
		}
		cout << '\n';
	}**/
	int ans = 0;
	for(int i  = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		char c;
		cin >> c;
		string s;
		cin >> s;
		int cnt = 0;
		if(s[a-1] == c)cnt++;
		if(s[b-1] == c)cnt++;
		if(cnt == 1)ans++;
	}
	cout << ans << '\n';



}
