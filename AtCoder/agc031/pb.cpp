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
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define si set<int>
#define pb push_back
typedef long long ll;
using namespace std;

vector<int> c;
int cnt[200010];
ll dp[200010];
ll sum[200010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, i, j, k;
    cin >> n;
    c.pb(-1);
    rep(i, n) {
        int x;
        cin >> x;
        if (x != c.back()) {
            c.pb(x);
        }
    }
    n = c.size();
    dp[0] = 1;
    xrep(i, 1, n) {
        dp[i] = (dp[i - 1] + sum[c[i]]) % mod;
        sum[c[i]] += dp[i - 1];
        sum[c[i]] %= mod;
    }
    cout << dp[n - 1] << endl;
}

