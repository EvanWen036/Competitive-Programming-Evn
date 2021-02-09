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
        int x;
        cin >> x;
        vector<int> answers;
        int dig = 1;
       
        while(x > 0){
            int digit = x%10;
            if(digit != 0){
                answers.push_back(digit * dig);
            }
            dig *= 10;
            x/=10;
        }
        cout << answers.size() << endl;
        for(int i = 0; i < answers.size(); i++){
            cout << answers[i] << " ";
        }
        cout << endl;
    }


}

