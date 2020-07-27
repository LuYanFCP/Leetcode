/**
 * @author summer
 * @date 2020/7/27 - 14:17
 */
public class Problem392 {
    public static void main(String[] args) {

    }
}

/**
 * 双指针
 */
class Solution392  {
    public boolean isSubsequence(String s, String t) {
        if (s.length() > t.length()) {
            return false;
        }
        int sIndex=0,tIndex=0;
        while (sIndex<s.length()&&tIndex<t.length()){
            if(s.charAt(sIndex)==t.charAt(tIndex)){
                sIndex++;
                tIndex++;
            }else {
                tIndex++;
            }
        }
        return s.length()==sIndex;
    }

}