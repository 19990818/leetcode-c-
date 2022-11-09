#include <vector>
#include <math.h>
using namespace std;

//首先这个问题用递归会超时
// 然后采用动态规划，分为上下左右，实际上上下左右逻辑
// 十分相似，所以可放在一起减少代码量，因为实际上结果取中间最小值
// 然后我们实际上只有0特殊，所以可将grid就作为每个点的最大加号
// 选上下左右最小值，需先初始化为最大值
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n,vector<int>(n,INT_MAX));
        for(vector<int> t:mines){
            grid[t[0]][t[1]]=0;
        }
        for(int i=0;i<n;i++){
            int left=0,right=0,up=0,down=0;
            for(int j=0,k=n-1;j<n&&k>=0;j++,k--){
                left=grid[i][j]==0?0:left+1;
                right=grid[i][k]==0?0:right+1;
                up=grid[j][i]==0?0:up+1;
                down=grid[k][i]==0?0:down+1;
                grid[i][j]=min(grid[i][j],left);
                grid[i][k]=min(grid[i][k],right);
                grid[j][i]=min(grid[j][i],up);
                grid[k][i]=min(grid[k][i],down);
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res=max(res,grid[i][j]);
            }
        }
        return res;
    }   
};