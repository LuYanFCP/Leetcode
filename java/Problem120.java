import java.util.ArrayList;
import java.util.List;

/**
 * @author summer
 * @date 2020/7/14 - 9:39
 */
public class Problem120 {
    public static void main(String[] args) {
        List<List<Integer>> triangle =new ArrayList<>();
        List<Integer> temp1 = new ArrayList<>();
        temp1.add(2);
        List<Integer> temp2 = new ArrayList<>();
        temp2.add(3);
        temp2.add(4);
        List<Integer> temp3 = new ArrayList<>();
        temp3.add(6);
        temp3.add(5);
        temp3.add(7);
        List<Integer> temp4 = new ArrayList<>();
        temp4.add(4);
        temp4.add(1);
        temp4.add(8);
        temp4.add(3);
        triangle.add(temp1);
        triangle.add(temp2);
        triangle.add(temp3);
        triangle.add(temp4);
        Solution120One solution120One=new Solution120One();
        System.out.println( solution120One.minimumTotal(triangle));

    }
}

/**
 *给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 *
 * 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
 *
 *  
 *
 * 例如，给定三角形：
 *
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/triangle
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution120One {
    /**
     * 递归＋记忆化剪支
     */
    int[][] memory;
    public int minimumTotal(List<List<Integer>> triangle) {
        memory=new int[triangle.size()][triangle.get(triangle.size()-1).size()];
        return dfs(triangle,0,0);
    }
    public  int dfs(List<List<Integer>> triangle,int row,int column){
        if (row==triangle.size()){
            return 0;
        }
        if(memory[row][column]!=0){
            return memory[row][column];
        }
        return memory[row][column] =Math.min(dfs(triangle,row+1,column),dfs(triangle,row+1,column+1))+triangle.get(row).get(column);

    }
}
class Solution120Two {
    /**
     * 从递归到动态规划
     * @param triangle
     * @return
     */
    public int minimumTotal(List<List<Integer>> triangle) {
        int row = triangle.size();
        int column = triangle.get(triangle.size()-1).size();
        int[][] dp=new int[row+1][column+1];
        for (int i = row-1; i >=0 ; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j]=Math.min(dp[i+1][j], dp[i+1][j+1])+triangle.get(i).get(j);
            }

        }
        return dp[0][0];

    }

}
class Solution120Three {
    /**
     * 动态规划二维转一维
     * @param triangle
     * @return
     */
    public int minimumTotal(List<List<Integer>> triangle) {
        int row = triangle.size();
        int column = triangle.get(triangle.size()-1).size();
        int[] dp=new int[column+1];
        for (int i = row-1; i >=0 ; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j]=Math.min(dp[j], dp[j+1])+triangle.get(i).get(j);
            }

        }
        return dp[0];

    }
}