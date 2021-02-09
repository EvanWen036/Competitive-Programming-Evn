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
    int n;
    cin >> n;
    vector<int> p(n+1);
    if(n ==1){
        cout << "! " << 1 << "\n";
        cout.flush();
        return 0;
    }
    cout << "? " <<  1 << " " << 2 << "\n";
    cout.flush();
    int ans1;
    cin >> ans1;
    cout << "? " << 2 << " " << 1 << "\n";
    cout.flush();
    int ans2;
    cin >> ans2;
    int larger = 0;
    if(ans1 > ans2){
        //then 1 is smaller
        p[1] = ans1;
        larger = 2;
    }
    else{
        //p[1] = ans2;
        larger = 1;
    }
    for(int i =2; i <= n; i++){
        if(i == larger)continue;
        cout << "? " << larger << " " << i << "\n";
        cout.flush();
        cin >> ans1;
        cout << "? " <<i << " " << larger << "\n";
        cout.flush();
        cin >> ans2;
        if(ans1 > ans2){
            //larger is smaller
            p[larger] = ans1;
            larger = i;
        }
        else{
            p[i] = ans2;
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        if(p[i] == 0)p[i] = n;
        cout << p[i] << " ";
    }
    cout.flush();
}
