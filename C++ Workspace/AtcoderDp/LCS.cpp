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
string a;
string b;
int ans[3005][3005];
pii pa[3005][3005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	for(int i = 1; i <= a.length(); i++){
		for(int j = 1;j <= b.length();j ++){
			if(a[i-1] == b[j-1]){
				ans[i][j] = ans[i-1][j-1] + 1;
				pa[i][j] = {i-1,j-1};
			}
			else{
				if(ans[i-1][j] > ans[i][j-1]){
					ans[i][j] = ans[i-1][j];
					pa[i][j] = {i-1,j};
				}
				else{
					ans[i][j] = ans[i][j-1];
					pa[i][j] = {i,j-1};
				}
			}
		}
	}
	string answer = "";
	int p1 = a.length();
	int p2 = b.length();
	while(p1 != 0 && p2 != 0){
		if(a[p1-1] == b[p2-1]){
			answer += a[p1-1];
		}
		int og = p1;
		int og2 = p2;
		p1 = pa[og][og2].f;
		p2 = pa[og][og2].s;
	}
	reverse(answer.begin(), answer.end());
	cout << answer << '\n';	


}
