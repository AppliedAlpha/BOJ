#include <stdio.h>
int main(){
    int s[105][105];

    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            s[i][j]=0;
        }
    }

    int x1,y1,x2,y2;
    for(int i=0;i<4;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int i=x1;i<x2;i++){
            for(int j=y1;j<y2;j++){
                s[i][j]=1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            cnt+=s[i][j];
        }
    }
    printf("%d",cnt);
}