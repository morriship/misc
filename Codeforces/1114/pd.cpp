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


vector<int> nums;
int in[5001];
int dp[5002][5002];


int main() {
    int n, i, j, k;
    cin >> n;
    rep(i, n) {
        scanf("%d", &in[i]);
    }
    nums.push_back(in[0]);
    xrep(i, 1, n) {
        if (in[i] != in[i-1]) {
            nums.push_back(in[i]);
        }
    }
    xrep(i, 2, nums.size()) {
        rep(j, nums.size() - i) {
            dp[j][j+i] = max(dp[j+1][j+i], dp[j][j+i-1]);
            if (nums[j] == nums[j+i]) {
                dp[j][j+i] = max(dp[j][j+i], dp[j+1][j+i-1] + 1);
            }
        }
    }
    cout << nums.size() - dp[0][nums.size()-1] - 1 << endl;
}
