/**
 * @author summer
 * @date 2020/7/15 - 10:06
 */
public class Problem96 {
    public static void main(String[] args) {
        Solution96One solution96One=new Solution96One();
         System.out.println(solution96One.numTrees(3));
    }
}

/**
 * 记忆化递归
 */
class Solution96One {
    int[] memory;

    public int numTrees(int n) {
        memory=new int[n+1];
        return helper(n);

    }
    public int helper(int k){
        int count=0;
        if(k<=1){
            return 1;
        }
        if (memory[k]!=0){
            return memory[k];
        }
        for (int i = 0; i < k; i++) {
            count+= helper(i)*helper(k-i-1);
        }
        return memory[k]=count;
    }
}

/**
 * 动态规划
 */
class Solution96Two {
    public int numTrees(int n) {
        int[] dp=new int[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
}