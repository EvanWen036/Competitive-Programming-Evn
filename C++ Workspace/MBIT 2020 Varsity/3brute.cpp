#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define RFOR(i, n) for(int i = n - 1; i >= 0; i--)
#define f first
#define s second
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<int> A(N), fixed(N + 1, 0);
    vector<vector<int> > rotate(N + 1, vector<int>(N + 1, 0));
    deque<int> B(N);
    FOR(i, 0, N) {
        cin >> A[i];
        fixed[A[i]] = i + 1;
    }
    FOR(i, 0, N) cin >> B[i];
    FOR(i, 0, N) {
        FOR(j, 0, N) rotate[i + 1][B[j]] = j + 1;
        int temp = B[0]; B.pop_front();
        B.pb(temp);
    }
    ll ret = 1000000000;
    FOR(i, 0, N) {
        ll total = 0;
        FOR(j, 0, N) total += abs(fixed[j + 1] - rotate[i + 1][j + 1]);
        ret = min(ret, total);
    }
    cout << ret;
    return 0;
}