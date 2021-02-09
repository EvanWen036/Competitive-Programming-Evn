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
    int s = 0;
    cin >> N;
    for(int i = 0; i < N;i ++){
        int x;
        cin >> x;
        s += x;
    }
    cout << s << endl;


}

