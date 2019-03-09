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

char s[500100], t[500100];
int ne[500100];
char out[500100];

int main() {
    scanf("%s %s", s, t); 
    int n, i, j;
    for (n = 0; t[n]; n++);
    ne[n-1] = n;
    for (i = n - 2; i >= 0; i--) {
        j = ne[i + 1];
        while (j < n) {
            if (t[i] == t[j - 1]) {
                break;
            }
            j = ne[j];
        }
        if (t[i] == t[j-1]) {
            ne[i] = j - 1;
        }
        else {
            ne[i] = j;
        }
    }
    int re = ne[0];
    // rep(i, n) {
    //     cout << ne[i] << ' ';
    // }
    // cout << endl;

    int c0 = 0;
    int c1 = 0;
    for (i = 0 ; s[i]; i++) {
        if (s[i] == '1') c1++;
        if (s[i] == '0') c0++;
    }
    int m = i;
    for (int i = 0; i < m; i++) {
        out[i] = t[i % re];
    }
    out[m] = 0;
    for (int i = 0; i < m; i++) {
        if (c0 <= 0) {
            out[i] = '1';
        } else if (c1 <= 0) {
            out[i] = '0';
        } else {
            if (out[i] == '0') {
                c0--;
            }
            if (out[i] == '1') {
                c1--;
            }
        }
    }
    cout << out << endl;
}
