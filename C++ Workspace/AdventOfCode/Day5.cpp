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
bool seats[2005];
int main(){
	freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ans = 0;
	for(int i = 0; i < 960; i++){
		string s;
		cin >> s;
		int pow = 64;
		int col = 0;
		int row = 0;
		for(int j = 0;j < 7; j++){
			if(s[j] == 'B'){
				row += pow;
			}
			pow /= 2;
		}
		pow = 4;
		for(int j = 7;j < 10;j ++){
			if(s[j] == 'R'){
				col += pow;
			}
			pow /= 2;
		}
		seats[row*8 + col] = true;
	}	
	for(int i = 1; i <= 1500; i++){
		if(seats[i+1] && seats[i-1] && !seats[i]){
			cout << i << '\n';
			return 0;
		}
	}
	//cout << ans << '\n';


}
