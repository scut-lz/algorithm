#include<bits/stdc++.h>
using namespace std;

const int maxn =8003;
int val[maxn * 4],num[maxn],n,last;
void pushdown(int rt){

    if(val[rt] != -1){
        val[rt<<1] = val[rt<<1|1] = val[rt];
    }

    val[rt] = -1;
}

void update(int ql,int qr,int c,int l,int r,int rt){

    if(ql <= l && qr >= r)
        val[rt] = c;
        return;

    pushdown(rt);
    int m = (l + r) >> 1;

    if(ql <= m)
        update(ql,qr,c,l,m,rt<<1);
    if(qr > m)
        update(ql,qr,c,m + 1,r,rt <<1|1);
}


void query(int l,int r,int rt){

    if(l == r){
        if(val[rt] != -1 && val[rt] != last){
            num[val[rt]]++;
        }

        last = val[rt];
        return;
    }

    pushdown(rt);
    int m = (l+r)>>1;
    query(l,m,rt<<1);
    query(m + 1, r, rt << 1|1);
}



int main(){
    while(scanf("%d",&n) == 1) {
        memset(val,-1,sizeof(val));
        memset(num,0,sizeof(num));
        int a,b,c;
        for(int i = 0; i < n; i++)
            scanf("%d%d%d",&a,&b,&c);
            if(a<b)
                update(a+1,b,c,1,8000,1);

        last = -1;
        query(1,8000,1);
        for(int i = 0; i <= 8000;i++)
            if(num[i]) printf("%d %d\n",i,num[i]);

        printf("\n");
    }

    return 0;
}
