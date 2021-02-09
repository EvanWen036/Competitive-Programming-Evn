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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string digits = "012345678900000000000000";
	vector<pair<int, string>> answers;
	for(int i = 0;i <= 9;i ++){
		//cout << s << '\n';
		string newV = s;
		int c = 0;
		int amt = 0;
		for(int j  =0; j < s.length(); j++){
			if(s[j] == digits[i])amt++;
		}
		for(int diff = 1; diff <= 9; diff++){

			for(int j = 0; j < s.length(); j++){
				if(i + diff <= 9 && s[j] == digits[i+diff] && amt < k){
					newV[j] = digits[i];
					c += diff;
					amt++;
				}
			}
			
			for(int j = s.length()-1; j >= 0; j--){

				if(i - diff >= 0 && s[j] == digits[i-diff] && amt < k){
					newV[j] = digits[i];
					c += diff;
					amt++;
				}
			}
			
		}
		//cout << c << " " << newV << '\n';
		answers.pb({c, newV});
	}
	sort(answers.begin(), answers.end());
	cout << answers[0].f << '\n';
	cout << answers[0].s << '\n';


}
