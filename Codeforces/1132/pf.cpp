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


char s[510];
int n, cost[510][510];

int solve(int l, int r) {
    if (l > r) { return 0; }
    int &res = cost[l][r];
    if (res != -1) { return res; }
    res = 1 + solve(l + 1, r);
    int i;
    xrep(i, l + 1, r + 1) {
        if (s[i] == s[l]) {
            res = min(res, solve(l + 1, i - 1) + solve(i, r));
        }
    }
    return res;
}

int main() {
    int i, j, k;
    cin >> n >> s;
    memset(cost, -1, sizeof(cost));
    cout << solve(0, n - 1) << endl;
}
