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
        string s;
        cin >> s;
        bool b1 = false;
        bool b2 = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] - '0' == 1)b1 = true;
            if(s[i] - '0' == 0)b2 = true;
        }
        if(b1 && b2){
            for(int i = 0; i < s.length(); i++){
                cout << 1  << 0;    
            }
        }
        else{
            for(int i = 0; i < s.length(); i++){
                cout << s[i];
            }
        }
        cout << endl;
    }


}

