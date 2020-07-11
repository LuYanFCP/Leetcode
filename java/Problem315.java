import java.util.ArrayList;
import java.util.List;

/**
 * @author summer
 * @date 2020/7/11 - 11:40
 */
public class Problem315 {
    public static void main(String[] args) {
        Solution solution=new Solution();
        List<Integer> list= solution.countSmaller(new int[]{5,2,6,1});
        list.forEach(i -> System.out.print(i));
    }
}

/**给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 归并+索引数组
 */
class Solution {
    int[] indexNums;
    int[] countNums;
    int[] helperNums;
    public List<Integer> countSmaller(int[] nums) {
       int length=nums.length;
       indexNums=new int[length];
       helperNums=new int[length];
       countNums=new int[length];
       List<Integer> list=new ArrayList<>();
        for (int i = 0; i < length; i++) {
            indexNums[i]=i;
        }
        sort(nums,0,length-1);
        for (int i = 0; i < length; i++) {
            list.add(countNums[i]);
        }
        return list;
    }
    public void sort(int[] nums,int left,int right){
        if(left>=right){
            return;
        }
        //避免相加结果超int范围
        int mid=(right-left)/2+left;
        sort(nums,left,mid);
        sort(nums,mid+1,right);
        merge(nums,left,right);
    }
    //按从大到小的顺序归并
    public void merge(int[] nums,int left,int right){
        for (int i = left; i <=right ; i++) {
            helperNums[i]=indexNums[i];
        }
        //避免相加结果超int范围
        int mid=(right-left)/2+left;
        int leftFlag=left,rightFlag=mid+1,helperFlag=left;
        while (leftFlag<=mid&&rightFlag<=right) {
            //左边比右边大，出列，计数
            if (nums[indexNums[leftFlag]] > nums[indexNums[rightFlag]]) {
                //右侧当前下标到最后都比当前左侧出列元素小
                countNums[indexNums[leftFlag]] += right - rightFlag + 1;
                helperNums[helperFlag++] = indexNums[leftFlag++];
            } else {
                //右边比左边大出列，不计数
                helperNums[helperFlag++] = indexNums[rightFlag++];
            }
        }


        //左侧出列，当前右侧已经全部出列，并且都比当前元素大，不计数
        while (leftFlag<=mid){
            helperNums[helperFlag++]=indexNums[leftFlag++];
        }
            //右侧出列，当前左侧已全部出列，出列过程中已统计这一部分，不计数
        while (rightFlag<=right){
            helperNums[helperFlag++]=indexNums[rightFlag++];
        }
        for (int i = left; i <=right ; i++) {
            indexNums[i]=helperNums[i];
        }

    }

}
