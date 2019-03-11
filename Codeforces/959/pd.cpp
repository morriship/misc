#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

ll prime[120055], plen;
ll used[120055];
ll limit(120000);
ll in[120005];
ll out[120005];

void buildPrime() {
    prime[0] = 2;
    prime[1] = 3;
    ll i, j, ii;
    for (plen = 2, i = 5, ii = 2; plen < limit; i += ii, ii ^= 6) {
        for (j = 0; prime[j] * prime[j] < i; j++) { if (i % prime[j] == 0) { break; } }
        if (i % prime[j] != 0) { prime[plen++] = i; }
    }
}

int check(int n) {
    for (int i = 0; prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            if (used[i] != 0) { return 0; }
            while (n % prime[i] == 0) { n /= prime[i]; }
        }
    }
    return 1;
}

void distruct(int n) {
    for (int i = 0; prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            used[i] = 1;
            while (n % prime[i] == 0) { n /= prime[i]; }
        }
    }
}

int main () {
    buildPrime();
    memset(used, 0, sizeof(used));

    ll i, j, n;
    cin >> n;
    rep(i, n) { scanf("%lld", &in[i]); }
    rep(i, n) {
        if (check(in[i])) {
            distruct(in[i]);
            out[i] = in[i];
        } else {
            break;
        }
    }
    for (j = in[i] + 1; !check(j) ; j++) {}
    distruct(j);
    out[i++] = j;
    for (j = 0; i < n; j++) {
        if (!used[j]) {
            out[i] = prime[j];    
            i++;
        }
    }
    rep(i, n) {
        cout << out[i] << ' ' ; 
    }
    cout << endl;
}
