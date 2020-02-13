#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
#define N 112345
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
ll n,m;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        cin>>n>>m;
        ll k=n-m;
        ll ans = n*(n+1)/2;
        if(m+1>=k) {
            ans -= k;
        } else {
            ll x = k/(m+1);
            ll re = k%(m+1);
            ll a = m+1-re;
            ll b = re;
            ans -= a*x*(x+1)/2 + b*(x+1)*(x+2)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}