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

void printWrong(int n) {
    if (n < 6) {
        cout << -1 << endl;
        return;
    }
    cout << "1 2" << endl;
    cout << "1 3" << endl;
    cout << "1 4" << endl;
    for (int i = 5; i <= n; i++) {
        cout << "2 " << i << endl;
    }
}

void printCorrect(int n) {
    int i;
    xrep(i, 2, n+1) { cout << 1 << ' ' << i << endl; }
}

int main () {
    int n;
    cin >> n;
    printWrong(n);
    printCorrect(n);
}
