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


char s[100100];
int cnt[100];
ll dp[27];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int i;
    ll n;
    cin >> n >> s;
    rep(i, n) { cnt[s[i] - 'a']++; }
    dp[0] = cnt[0];
    xrep(i, 1, 26) {
        dp[i] = (cnt[i] + 1) * (dp[i-1]) % mod;
        dp[i] = (dp[i] + cnt[i]) % mod;
    }
    cout << dp[25] << endl;
}
