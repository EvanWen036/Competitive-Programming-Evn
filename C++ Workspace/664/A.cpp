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
        vector<int> a(4);
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        int ones = 0;
        int even = 0;
        int sum = 0;
        int odd = 0;
        for(int i =0; i< 4; i++){
            if(a[i] == 0 && i != 3)ones++;
            if(a[i] % 2 == 1)odd++;
            if(a[i] % 2 == 0)even++;
            sum += a[i];
        }
        if(ones > 0){
            cout << (odd > 1 ? "No\n" : "Yes\n");
        }
        else{
            if(odd <= 1){
                cout << "Yes" << endl;
                continue;
            }
            a[0]--;
            a[1]--;
            a[2]--;
            a[3]++;
            odd = 0;
            for(int i = 0; i < 4; i++){
                if(a[i] % 2 == 1)odd++;
            }
            cout << (odd > 1 ? "No\n" : "Yes\n");
        }


        
    }


}

