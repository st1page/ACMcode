#include<cstdio>

using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
ll a,b,c,ans;

#define N 1123456
ll check(ll a,ll b,ll c){
	a&=1; b&=1; c&=1;
	return (a^c)&(b^c);
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		ll x,y; scanf("%lld%lld",&x,&y);
		ans=0;
		for(int i=32;i>=0;i--){
			if(check(x>>i,y>>i,0)==0){
				
			} else if(check(x>>i,y>>i,1)==0){
				ans|=(1ll<<i);
			} 
		}
		if(!ans) ans=1;
		printf("%lld\n",ans);
	}
	
	return 0;
}




