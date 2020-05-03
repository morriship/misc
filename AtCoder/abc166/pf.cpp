#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) ((a)<<(b))
#define Rshift(a,b) ((a)>>(b))
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define sz(a) int(a.size())
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

string in[100100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll i;
    vector<char> ans;
    rep(i, n) {
        cin >> in[i];
    }
    rep(i, n) {
        if (in[i][0] == 'A' && in[i][1] == 'B') {
            if (a == 0 && b == 0) {
                cout << "No" << endl;
                return 0;
            }
            if (a == 1 && b == 1 && c == 0) {
                if (i != n-1) {
                    if (in[i+1][0] == 'A' && in[i+1][1] == 'C') {
                        ans.pb('A');
                        a++, b--;
                        continue;
                    }
                    if (in[i+1][0] == 'B' && in[i+1][1] == 'C') {
                        ans.pb('B');
                        b++, a--;
                        continue;
                    }
                }
            }

            if (a > 1) {
                ans.pb('B');
                a--;
                b++;
            } else if (b > 1) {
                ans.pb('A');
                a++;
                b--;
            } else if (a == 0) {
                ans.pb('A');
                a++;
                b--;
            } else {
                ans.pb('B');
                a--;
                b++;
            }
        }
        if (in[i][0] == 'A' && in[i][1] == 'C') {
            if (a == 0 && c == 0) {
                cout << "No" << endl;
                return 0;
            }
            if (a == 1 && c == 1 && b == 0) {
                if (i != n-1) {
                    if (in[i+1][0] == 'A' && in[i+1][1] == 'B') {
                        ans.pb('A');
                        a++, c--;
                        continue;
                    }
                    if (in[i+1][0] == 'B' && in[i+1][1] == 'C') {
                        ans.pb('C');
                        c++, a--;
                        continue;
                    }
                }
            }


            if (a > 1) {
                ans.pb('C');
                a--;
                c++;
            } else if (c > 1) {
                ans.pb('A');
                a++;
                c--;
            } else if (a == 0) {
                ans.pb('A');
                a++;
                c--;
            } else {
                ans.pb('C');
                a--;
                c++;
            }

        }
        if (in[i][0] == 'B' && in[i][1] == 'C') {
            if (b == 0 && c == 0) {
                cout << "No" << endl;
                return 0;
            }
            if (b == 1 && c == 1 && a == 0) {
                if (i != n-1) {
                    if (in[i+1][0] == 'A' && in[i+1][1] == 'B') {
                        ans.pb('B');
                        b++, c--;
                        continue;
                    }
                    if (in[i+1][0] == 'A' && in[i+1][1] == 'C') {
                        ans.pb('C');
                        c++, b--;
                        continue;
                    }
                }
            }
            if (b > 1) {
                ans.pb('C');
                b--;
                c++;
            } else if (c > 1) {
                ans.pb('B');
                b++;
                c--;
            } else if (b == 0) {
                ans.pb('B');
                b++;
                c--;
            } else {
                ans.pb('C');
                b--;
                c++;
            }
        }
    }
    cout << "Yes" << endl;
    rep(i, sz(ans)) {
        cout << ans[i] << endl;
    }
}
