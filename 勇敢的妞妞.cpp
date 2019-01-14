#include <iostream>
#include <memory.h>
using namespace std;

int main(){
    int n, k;
    while(cin>>n>>k){
        // equip[i][j]表示第i件装备的第j属性的值
        int equip[n][5];
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++) cin>>equip[i][j];
        }
        // 若可挑选装备数>=5，则挑选出具有最大属性的5个装备即可
        if(k>=5){
            int max[5]={0};
            for(int i=0;i<n;i++){
                for(int j=0;j<5;j++)
                    if(equip[i][j]>max[j]) max[j]=equip[i][j];
            }
            int s=0;
            for(int j=0;j<5;j++) s+=max[j];
            cout << s << endl;
            return 0;
        }
        // 若可挑选装备数<5，用状压dp
        // dp[i][j][s]表示前i件装备中挑j件达到状态s时的最大战斗力
        // 状态s表示挑选了哪几个属性，如10100表示选用1和3属性
        int dp[n][5][1<<5];
        memset(dp, 0, sizeof(dp));
        // partSum[i][s]表示第i件装备在状态s下到达的战斗力
        int partSum[n][1<<5];
        memset(partSum, 0, sizeof(partSum));
        for(int i=0;i<n;i++){        
            for(int s=0;s<(1<<5);s++)
                for(int j=0;j<5;j++)
                    if(s&(1<<j)) partSum[i][s]+=equip[i][j];
        }
        // 设置边界：第0件装备；状态s为0和挑0件装备已经在初始化中设置(dp[i][0][s]=dp[i][j][0]=0)
        for(int s=0;s<(1<<5);s++) dp[0][1][s]=partSum[0][s];
        for(int i=1;i<n;i++){
            for(int j=1;j<5;j++)
                for(int s1=1;s1<(1<<5);s1++){
                    dp[i][j][s1]=dp[i-1][j][s1]; 
                    for(int s0=1;s0<=s1;s0++) 
                        // s0表示在第i件装备的状态（选用哪几个属性）
                        // (s0&s1)==s0保证了第i件装备选用的属性在想要选用的属性范围中
                        if((s0&s1)==s0 && (dp[i-1][j-1][s1-s0]+partSum[i][s0])>dp[i][j][s1])
                            dp[i][j][s1] = dp[i-1][j-1][s1-s0]+partSum[i][s0];
                }
        }
        cout << dp[n-1][k][(1<<5)-1] << endl;
    }
    return 0;
}