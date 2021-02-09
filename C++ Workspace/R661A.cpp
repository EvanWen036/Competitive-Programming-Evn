#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
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
        vector<int> a(n);
        for(int i = 0; i < n ;i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        bool done = false;
        for(int i = 1; i < n; i++){
            if(a[i] - a[i-1] > 1){
                cout << "No" << endl;
                done = true;
                break;
            }
        }
        if(done)continue;
        cout << "Yes" << endl;
    }


}

