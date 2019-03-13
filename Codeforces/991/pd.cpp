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
typedef long long ll;
using namespace std;


int dp[111][4];

char c[2][210];

int main() {
    int ans(0), i, j;
    scanf("%s %s", c[0], c[1]);
    for (i = 1; c[0][i]; i++) {
        if (c[0][i-1] == '0' && c[1][i-1] == '0') {
            if (c[0][i] == '0') {
                c[0][i] = 'X';
                ans++;
            } else if (c[1][i] == '0') {
                c[1][i] = 'X';
                ans++;
            }
        } else if (c[0][i] == '0' && c[1][i] == '0' && (c[0][i-1] == '0' || c[1][i-1] == '0')) {
            c[0][i] = 'X';
            c[1][i] = 'X';
            ans++;
        }
    }
    cout << ans << endl;
}
