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
map<string, int> cnt[8];
int main(){
	freopen("bgm.in", "r", stdin);
	freopen("bgm.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i< N;i ++){
		string s; int k;
		cin >> s >> k;
		k %= 7;
		k += 7;
		k %= 7;
		cnt[k][s]++;
	}
	ll ans = 0;
	for(int b = 0; b < 7; b++){
		for(int e = 0; e < 7; e++){
			for(int s = 0; s < 7; s++){
				for(int i = 0;i < 7; i++){
					for(int g = 0; g < 7; g++){
						for(int o = 0; o < 7; o++){
							for(int m = 0;m < 7; m++){
								if((b + e + s + s + i + e) * (g + o + e + s) * (m + o  + o) % 7 == 0){
									ans += 1LL * cnt[b]["B"] * cnt[e]["E"]*cnt[s]["S"]*cnt[i]["I"]*cnt[g]["G"]*cnt[o]["O"]*cnt[m]["M"];
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';


}
