/*
 ID: evan.h.1
 TASK: dualpal
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
string baseConv(int x, int newBase){
   int currPower = 1;
   while(currPower * newBase < x){
       currPower *= newBase;
   }
   string ans = "";
   while(currPower > 0){
       ans += to_string(x / currPower);
       int dig = x/currPower;
       x -= dig * currPower;
       currPower /= newBase;
   }
   return ans;
}
bool isPalindrome(string s){
    int len = s.length();
    for(int i = 0; i < len/2; i++){
        if(s[i] != s[s.length()-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    int palindromesFound = 0;
    int curr = s+1;
    while(palindromesFound < n){
        int bases = 0;
        for(int i = 2; i <= 10; i++){
            string newVal = baseConv(curr, i);
            if(isPalindrome(newVal)){
                bases++;
            }
        }
        if(bases >= 2){
            palindromesFound++;
            cout << curr << endl;
        }
        curr++;
    }


}

