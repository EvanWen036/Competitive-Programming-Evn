#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int count = 0;
        for(int i = 1; i < n-1; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                count++;
            }
        }
        cout << "Case #" << i <<": " << count << endl;

        
    }


}

