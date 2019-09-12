#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 212345
struct data1{
	int val;
	int id;
	data1(){
	}
	data1(int x,int y){
		val=x; id = y;
	}
	friend bool operator <(data1 x,data1 y){
		return x.val < y.val;
	}
};
struct data2{
	int val;
	int id;
	data2(){
	}
	data2(int x,int y){
		val=x; id = y;
	}
	friend bool operator <(data2 x,data2 y){
		return x.val > y.val;
	}
};
int del1[N];
int del2[N];
int del3[N];
priority_queue<data2> q1;
priority_queue<data1> q2,q3;
void init(){
	memset(del1,0,sizeof(del1));
	memset(del2,0,sizeof(del2));
	memset(del3,0,sizeof(del3));
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
}
int n; 
int v[N];
int main(){
	int T=gn();
	while(T--){
		init();
		n=gn();
		for(int i=0;i<n;i++){
			int a=gn(), b=gn();
			q2.push(data1(a+b,i));
			q3.push(data1(a,i));
			v[i]=a; v[i+n]=b;
		}
		ll ans=0;
		for(int i=0;i<2*n;i++){
			int d1=0,d2=0;
			while(!q1.empty()&&del1[q1.top().id]) q1.pop();
			while(!q2.empty()&&del2[q2.top().id]) q2.pop();
			while(!q3.empty()&&del3[q3.top().id]) q3.pop();
			if(!q1.empty()&&!q2.empty()){
				d1 = q2.top().val - q1.top().val;
			}
			if(!q3.empty()) {
				d2 = q3.top().val;
			}
//			printf("%d - %d\n",d1,d2);
			if(d1>d2&&!q1.empty()&&!q2.empty()){
				int chos = q2.top().id;
				del3[chos] = del2[chos] = 1;
				del3[chos+n] = 1;
				del1[chos+n] = 0;
				q1.push(data2(v[chos+n],chos+n));
				int back = q1.top().id;
				del1[back] = 1;
				del3[back] = 0;
				q3.push(data1(v[back],back));
				if(back<n) {
					del2[back] = 0;
					q2.push(data1(v[back]+v[back+n], back));
					del3[back+n] = 1;
				} else {
					del1[back-n] = 0;
					q1.push(data2(v[back-n], back-n));
				}
				ans+=d1;
			} else if(!q3.empty()){
				int chos = q3.top().id;
				del1[chos] = 0;
				q1.push(data2(v[chos],chos));
				del3[chos] = 1;
				if(chos<n){
					del2[chos] = 1;
					del3[chos+n] = 0;
					q3.push(data1(v[chos+n],chos+n));
				} else{
					del1[chos-n] = 1;
				}
				ans+=d2;
			}
			if(i!=2*n-1) printf("%lld ",ans );
			else printf("%lld\n",ans);
		}
	}
	return 0;
}




