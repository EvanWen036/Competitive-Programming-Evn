#include <bits/stdc++.h>
#define ll long long;
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while(q--){
		
		int n;
		cin >> n;
		vector<int> S(4*n);
		//cout << "Hi";
		for(int i = 0; i < 4 * n; i++){
			int s;
			cin >> s;
			S[i] = s;
		}
		
		sort(S.begin(), S.end());
		vector<int>::iterator end = S.end();
		end--;
		vector<int>::iterator start = S.begin();
		int area = -1;
		bool done = false;
		while(start < end){
			int currArea = 0;
			int L1 = *end;
			end--;
			if(L1 != *end){
				done = true;
				cout << "NO" << "\n";
				break;
			}
			end--;
			int l2 = *start;
			start++;
			if(l2 != *start){
				done = true;
				cout << "NO" << "\n";
				break;
			}
			start++;
			currArea = L1*l2;
			if(currArea != area && area != -1){
				cout << "NO" << "\n";
				done = true;
				break;
			}
			area = currArea;
			
		}
		if(done)continue;
		cout << "YES" << "\n";
		
	}


}