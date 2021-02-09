#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e4, MAX_P = 70;

bool composite[MAX_N + 1];
vector<int> primes = { 2,   3,   5,   7,   11,  13,  17,  19,  23,  29,
                       31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
                       73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                       127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                       179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
                       233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                       283, 293, 307, 311, 313, 317, 331, 337, 347, 349
                    };

double mem[MAX_N + 1][MAX_P];
bool visited[MAX_N + 1][MAX_P];
int backtrack[MAX_N + 1][MAX_P];

double dp(int n, int pos = 0) {
    if (pos == primes.size() || primes[pos] > n) return 0;
    if (visited[n][pos]) return mem[n][pos];

    double ans = dp(n, pos + 1);
    backtrack[n][pos] = 0;
    for (int p_pow = primes[pos], expo = 1; p_pow <= n; p_pow *= primes[pos], expo++) {
        double potential = expo * log(primes[pos]) + dp(n - p_pow, pos + 1);
        if (ans < potential) {
            ans = potential;
            backtrack[n][pos] = p_pow;
        }
    }
    visited[n][pos] = true;
    return mem[n][pos] = ans;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        scanf("%d", &m);
        dp(m);
        cout << mem[m][0] << '\n';
        vector<int> lens;
        for (int pos = 0; pos < primes.size(); m -= backtrack[m][pos++]) {
            if (backtrack[m][pos]) lens.push_back(backtrack[m][pos]);
        }
        while (m--) lens.push_back(1);
        sort(lens.begin(), lens.end());
        for (int i = 0, j = 1; i < lens.size(); j += lens[i++]) {
            for (int k = 1; k < lens[i]; k++) printf("%d ", j + k);
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}