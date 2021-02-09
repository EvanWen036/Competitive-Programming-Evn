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
        vector<int> p(n);
        int onePos = 0;
        for(int i = 0; i < n;i ++){
            cin >> p[i];
            if(p[i] == 1)onePos = i;
        }
        bool yes = true;
        for(int i = 0; i < n-1; i++){
            if(p[i] < p[i+1] && p[i+1] - p[i] != 1){
                yes = false;
                break;
            }
        }
        cout << (yes ? "Yes":"No") << endl;
    }


}

