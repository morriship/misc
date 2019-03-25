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
#define MID 2001
#define pb push_back
typedef long long ll;
using namespace std;


char in[1000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, i, j, k;
    cin >> t;
    rep(i, t) {
        cin >> n;
        cin >> in;
        for (j = 0; in[j] == '<'; j++);
        for (k = n - 1; in[k] == '>' && k >= 0; k--);
        if (j > 0 && k < n - 1) {
            cout << min(j, n - 1 - k) << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
