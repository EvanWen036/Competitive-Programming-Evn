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
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    int square = -1;
    pair<int, int> rectangle;
    rectangle.f = -1;
    rectangle.s = -1;
        //map<int, int> mp;
    cout << square << " " << rectangle.f << " " << rectangle.s << endl;
    int q;
    cin >> q;
    for(int i = 0; i < q;i ++){
        int x;
        //cin >> x;
        string c;
        cin >> c;
        cin >> x;
        //cout << c << " " << x << endl;
        if(c == "+"){
            mp[x]++;
            if(square == 0){
                if(mp[x] >= 4){
                    square = x;
                    mp[x] -= 4;
                }
            }
            if(rectangle.f == -1){
                if(mp[x] >= 2){
                    rectangle.f = x;
                    mp[x] -= 2;
                }
            }
            if(rectangle.s == -1){
                if(mp[x] >= 2){
                    mp[x] -= 2;
                    rectangle.s = x;
                }
            }
        }
        else{
            x *= -1;
            if(mp[x] == 0){
                if(square == x){
                    square = -1;
                    mp[x] += 3;
                }
                if(rectangle.f == x){
                    rectangle.f = -1;
                    mp[x] += 1;
                }
                if(rectangle.s == x){
                    rectangle.s = -1;
                    mp[x] ++;
                }
            }
            else{
                mp[x]--;
            }
        }
        if(square != -1 && rectangle.f != -1 && rectangle.s != -1){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }



}

