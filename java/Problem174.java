/**
 * @author summer
 * @date 2020/7/12 - 20:04
 */
public class Problem174 {
    public static void main(String[] args) {
        int[][] dungeon=new int[][]{
                {-2,-3,3},
                {-5,-10,1},
                {10,30,-5}
        };
//        Solution174One solution174One=new Solution174One();
//        System.out.println(solution174One.calculateMinimumHP(dungeon));
        Solution174Two solution174Two=new Solution174Two();
        System.out.println(solution174Two.calculateMinimumHP(dungeon));
    }
}

/**
 * 174. 地下城游戏
 * 一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
 *
 * 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
 *
 * 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
 *
 * 为了尽快到达公主，骑士决定每次只向右或向下移动一步。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/dungeon-game
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution174One {
    /**
     * 成员变量memory,用于存储递归过程返回值，复用结果（剪枝）
     */
    int[][] memory;
    /**
     * 递归搜索方法
     * @param dungeon
     * @return
     */
    public int calculateMinimumHP(int[][] dungeon) {
        memory=new int[dungeon.length][dungeon[0].length];
        return dfs(dungeon, dungeon.length-1, dungeon[0].length-1, 0, 0);
    }

    /**
     *
     * @param dungeon
     * @param row 总行数
     * @param columm 总列数
     * @param currentRow 当前行
     * @param currentColumn 当前列
     * @return 当前点处最小生命值
     */
    public int dfs(int[][] dungeon,int row,int columm,int currentRow,int currentColumn){
        //到达公主位置，递归终点
        if(currentRow==row&&currentColumn==columm){
            return Math.max(1,1-dungeon[row][columm]);
        }
        if (memory[currentRow][currentColumn]>0){
            return memory[currentRow][currentColumn];
        }
        int minBlood=0;
        //到达最后一行，还没到公主位置，只能向右移动
        if(currentRow==row){
            minBlood=Math.max(1,dfs(dungeon,row,columm,currentRow,currentColumn+1)-dungeon[currentRow][currentColumn]);
        }
        //到达最后一列，同上
        else if(currentColumn==columm){
          minBlood=Math.max(1,dfs(dungeon,row,columm,currentRow+1,currentColumn)-dungeon[currentRow][currentColumn]);
        }
        else {
        minBlood=Math.max(
                    Math.min(dfs(dungeon,row,columm,currentRow+1,currentColumn)-dungeon[currentRow][currentColumn],
                            dfs(dungeon,row,columm,currentRow,currentColumn+1)-dungeon[currentRow][currentColumn]),
                    1);
        }
        return  memory[currentRow][currentColumn]=minBlood;

    }
}

/**
 * 从暴力搜索到动态规划
 */
class Solution174Two {
    public int calculateMinimumHP(int[][] dungeon) {
        //由于要求中间过程任何一个位置骑士血量必须大于零，因此考虑从公主位置往骑上位置递推；
        if (dungeon == null || dungeon.length == 0 || dungeon[0].length == 0) {
            return 0;
        }
        int row = dungeon.length;
        int column = dungeon[0].length;
        int[][] dp = new int[row][column];
        //设置公主位置骑士最低血量
        dp[row - 1][column -1] = dungeon[row - 1][column - 1]>0?1:-dungeon[row - 1][column - 1]+1;
        //设置最后一行骑士最低血量
        for (int j = column-2; j >=0; j--) {
            dp[row-1][j]=Math.max(1,dp[row - 1][j+1]-dungeon[row-1][j]);
        }
        //设置最后一列骑士最低血量
        for (int i = row-2; i >=0 ; i--) {
            dp[i][column-1]=Math.max(1,dp[i+1][column -1]-dungeon[i][column-1]);
        }
        //设置中间
        for (int i = row - 2; i >= 0; --i) {
            for (int j = column - 2; j >= 0; --j) {
                dp[i][j]=Math.max(1,Math.min(dp[i][j+1]-dungeon[i][j],dp[i+1][j]-dungeon[i][j]));
            }
        }
        return dp[0][0];
    }
}
