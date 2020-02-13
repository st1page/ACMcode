#include<cstdio>
#include<iostream>

using namespace std;
typedef long long ll;
ll n,g,b;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&g,&b);
        ll mid = (n+1)/2;
        ll x = (mid/g)*(g+b)+mid%g;
        if(mid%g == 0) x-=b;
        if(x > n) cout<<x<<"\n";
        else cout<<n<<"\n";
    }
    return 0;
}