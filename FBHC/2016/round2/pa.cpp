#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define readi(a) scanf("%d", &a)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define min(a,b) ( a < b ? a : b )
#define max(a,b) ( a > b ? a : b )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

char src[100100], dst[100100];
int ltor[100100], rtol[100100];

int main() {
    int t, tt, n, i, j, k;
    cin >> tt;
    xrep(t, 1, tt+1) {
        cin >> n;
        scanf("%s %s", src, dst);
        memset(ltor, 0, sizeof(ltor));
        memset(rtol, 0, sizeof(rtol));
        int now(0), dstc(1);
        if (src[0] != dst[0]) {
            now++;
            ltor[0] = 1;
        }
        xrep(i, 1, n) {
            if (dst[i] != dst[i-1]) { dstc++; }
            if (src[i] != dst[i]) {
                now = dstc;
                ltor[i] = dstc;
            }
            if (src[i] == dst[i]) {
                ltor[i] = ltor[i-1];
            }
        }
        now = 0;
        dstc = 1;

        if (src[n-1] != dst[n-1]) {
            now++;
            rtol[n-1] = 1;
        }
        for (i = n-2; i >= 0; i--) {
            if (dst[i] != dst[i+1]) { dstc++; }
            if (src[i] != dst[i]) {
                now = dstc;
                rtol[i] = dstc;
            }
            if (src[i] == dst[i]) {
                rtol[i] = rtol[i+1];
            }
        }

        int ans(n);
        rep(i, n-1) {
            ans = min(ans, max(ltor[i], rtol[i+1]));
        }
        // rep(i, n) cout << ltor[i] << ' ';
        // cout << endl;
        // rep(i, n) cout << rtol[i] << ' ' ;
        // cout << endl;
        cout << "Case #" << t << ": " << ans << endl;
    }
}
