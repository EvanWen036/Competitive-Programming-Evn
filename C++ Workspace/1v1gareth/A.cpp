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
    string s;
    cin >> s;
    for(int i=  0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
    cout << (s[s.length()-1] != 'a' &&  s[s.length()-1] != 'e' &&  s[s.length()-1] != 'i' &&  s[s.length()-1] != 'o' &&  s[s.length()-1] != 'u' ? "NO": "YES" )<< endl; 


}

