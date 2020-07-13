import java.util.*;

/**
 * @author summer
 * @date 2020/7/13 - 13:52
 */
public class Problem350 {
    public static void main(String[] args) {
        Solution350 solution350=new Solution350();
        solution350.intersect(new int[]{1,2,2,1},new int[]{2,2});
    }
}
class Solution350 {
    public int[] intersect(int[] nums1, int[] nums2) {//计数排序原理
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums1.length; i++) {//存桶里
             map.put(nums1[i], map.getOrDefault(nums1[i],0) + 1);
            }
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums2.length; i++) {//从桶里取出来
            if (map.getOrDefault(nums2[i],0) > 0) {
                map.put(nums2[i], map.get(nums2[i]) - 1);
                list.add(nums2[i]);//如果包含放在List里
            }
        }
        int[] help =new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            help[i]=list.get(i);
        }
        return   help;


    }
}
