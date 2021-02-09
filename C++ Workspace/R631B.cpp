#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, int> pref;
		map<int, int> suff;
		vector<int> A(n);
		
		for(int i = 0; i < n; i++){
			cin >> A[i];
			suff[A[i]]++;
		}
		vector< pair<int, int> > ans;
		//cout << pref.size() << " " << suff.size() << endl;
		for(int i = 0; i < n-1; i++){
			
			suff[A[i]]--;
			if(suff[A[i]] == 0)suff.erase(A[i]);
			pref[A[i]]++;
			//cout << pref.size() << " " << suff.size() << endl;
			int maxL = (*(--pref.end())).first;
			int maxR = (*(--suff.end())).first;
			
			if(maxL == i+1 && pref.size() == i+1 && maxR == (n-i-1) && suff.size() == n-i-1){
				ans.push_back(make_pair(i+1, n-i-1));
			}
		}
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}


}