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
        if((n/2)%2 == 1){
            cout << "NO" << endl;
        }
        else{
            int even = 2;
            int odd = 1;
            vector<int> b;
            for(int i = 0; i < n/2; i++){
                cout << even << " ";
                even += 2;
            }
            for(int i = 0; i < n/2 - 1; i++){
                cout << odd << " ";
                odd += 2;
            }
            cout << even + n/2 - 3 << "\n";
        }

    }


}

