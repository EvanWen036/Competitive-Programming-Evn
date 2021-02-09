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
        int n, a, b;
        cin >> n >> a >> b;
        string characters[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        string ans = "";
        while(ans.length() < n){
            for(int i = 0; i < b; i++){
                if(ans.length() == n)break;
                ans += characters[i];
            }
        }
        cout << ans << endl;
       
    }


}

