#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
ll n,m,k;
int step = 0;
void get_step(ll n,ll m,ll k){
    if(k<=m-1) {
        step = 1; 
        return ;
    } else {
        step++;
        k-= m-1;
    }
    for(int i=1;i<n;i++) {
        step++; k--;
        if(!k) return ;
        if(k<=(m-1)*3){
            step+=k;
            return;
        }
        step++;
        k-=(m-1)*3;
    }
    if(k<=m-1){
        step++;
        return ;
    } else {
        step++;
        k-=m-1;
    }
    for(int i=n-1;i>=1;i--){
        step++; k--;
        if(!k) return ;
        if(k<=m-1){
            step++;
            return ;
        }
        step++;
        k-=m-1;
    }
}
void get_ans(ll n,ll m,ll k){
    if(k<=m-1) {
        printf("%d R\n",k);
        return ;
    } else {
        printf("%d R\n",m-1);
        k-= m-1;
    }
    for(int i=1;i<n;i++) {
        k--;
        printf("%d D\n",1);
        if(!k) return ;
        if(k<=(m-1)*3){
            while(k){
                if(i&1){
                    printf("%d L\n",1);
                    k--;
                } else {
                    printf("%d R\n",1);
                    k--;
                }
                if(k){
                    printf("%d U\n",1);
                    k--;
                }
                if(k){
                    printf("%d D\n",1);
                    k--;
                }
            }
            return;
        }
        if(i&1){
            printf("%d LUD\n",m-1);
        } else {
            printf("%d RUD\n",m-1);
        }
        k-=(m-1)*3;
    }
    if(k<=m-1){
        if(n&1){
            printf("%d L\n",k);
        } else {
            printf("%d R\n",k);
        }
        return ;
    } else {
        if(n&1){
            printf("%d L\n",m-1);
        } else {
            printf("%d R\n",m-1);
        }
        k-=m-1;
    }
//    printf("k:%d\n ",k);
    for(int i=n-1;i>=1;i--){
        printf("%d U\n",1);
        k--;
        if(!k) return ;
        if(k<=m-1){
            if(i&1){
                printf("%d L\n",k);
            } else {
                printf("%d R\n",k);
            }
            return ;
        }
        if(i&1){
            printf("%d L\n",m-1);
        } else {
            printf("%d R\n",m-1);
        }
        k-=m-1;
    }
}
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    if(4*n*m-2*n-2*m <k) {
        puts("NO");
        return 0;
    } 
    puts("YES");
    if(m==1){
        if(k<=n-1){
            puts("1");
            printf("%d D\n",k);
        } else {
            puts("2");
            printf("%d D\n",n-1);
            k-=n-1;
            printf("%d U\n",k);
        }
        return 0;
    }
    get_step(n,m,k);
    printf("%d\n",step);
    get_ans(n,m,k);

    return 0;
}