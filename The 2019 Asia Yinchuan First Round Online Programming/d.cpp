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
#define N 1123456

int main(){	
	int t=gn();
	for(int cas=1;cas<=t;cas++){
		int n,m;
		double ans1,ans2;
		n=gn(); m=gn();
		if(n==1) ans1=1.0; else ans1=0.5;
		ans2=0.5*(m+1.0)/m;
		printf("Case #%d: %lf %lf\n",cas,ans1,ans2);
	}
	return 0;	
}


