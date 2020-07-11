## 题目     

> 面试题51. 数组中的逆序对
> 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:

```
输入: [7,5,6,4]
输出: 5
```
限制：
0 <= 数组长度 <= 50000

### 暴力解法

直接进行无脑扫描

```cpp
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int sum = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] > nums[j])
                    sum++;
            }
        }
        return sum;
    }
};
```

时间复杂度$O(n^2)$，空间复杂度$O(1)$

**超时！**，考虑新的算法。

### 分治法

这个题目有很好的分治法的特征

1. 左右相互独立，可以拆分为两个任务
2. 基本思路是： 计算左半部分的逆序个数+计算右半部分+跨边界的逆序数

定义函数`_reversePairs`用来实现分治法，则solution函数为

```cpp
int _reversePairs(vector<int>& nums, int begin, int end);

int reversePairs(vector<int>& nums) {
    return _reversePairs(nums, 0, nums.size());
}

```

现在看`_reversePairs`函数内部

思路：计算左半部分的逆序个数+计算右半部分+跨边界的逆序数， 使用递归的方式求解

1. 递归的结束条件: begin >= end 为结束条件
2. 找到中间值，递归计算左边的逆序数，递归计算右边的逆序数
3. 跨边界的逆序数计算
4. 加和并返回

**算法核心是处理 跨边界的逆序数的计算**

观察到左右都是无序的，如果是有序的话可以提高计算跨边界的逆序数计算的速度。

因此联想到了归并排序，因为归并排序就是左右有序的。考虑使用归并排序来解决这个问题。

具体思想为：在merge过程中，需要对比左右两个序列的值

```cpp
#include <vector>
#include <iterator>
#include <iostream>
using std::vector;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        temp = new int[nums.size()];
        return _reversePairs(nums, 0, nums.size()-1);
    }

    int _reversePairs(vector<int>& nums, int begin, int end) {

        if (begin < end) {
            int mid = (end - begin)/2 + begin;
            int left_rp = _reversePairs(nums, begin, mid);  // 已排好
            int right_rp = _reversePairs(nums, mid+1, end);
            // 两边执行完毕之后就已经是排好序了
            int i = begin, j = mid+1, k = begin;
            int grap_rp = 0;
            while (i <= mid && j <= end) {
                if (nums[i] <= nums[j]) {
                    temp[k++] = nums[i++];
                    grap_rp += j - mid - 1;
                } else {
                    //  nums[i] > nums[j]
                    temp[k++] = nums[j++];
                }
            }

            //  1 3 5 7 9 <= mid
            //  4 5 6 8 10
            // 
            while (i <= mid) {
                temp[k++] = nums[i++];
                grap_rp += j - mid - 1;   
            }
            while (j <= end) temp[k++] = nums[j++];
            std::copy(temp+begin, temp+end+1, nums.begin()+begin);
            // std::copy(temp+begin, temp+end+1, std::ostream_iterator<int>(std::cout, " "));
            // std::cout << std::endl;
            // std::cout << "left_rp: " << left_rp << " right_rp: " << right_rp << " grap_rp: " << grap_rp << endl;
            return left_rp + right_rp + grap_rp;
        } else {
            return 0;
        } 

    }
private:
    int *temp;
};
```


执行完毕：得到结果为：

执行用时 :

+ 148 ms, 在所有 C++ 提交中击败了92.74%的用户
+ 内存消耗 :47.1 MB, 在所有 C++ 提交中击败了100.00%的用户

### 使用hash去求解

构建一个hashtable去记录数字`x`出现的次数，因此如果求逆序的话就是计算当前数字`v`到末尾`n`的hashtable的值的sum，这样遍历一般数列，因此其时间复杂度为$O(n\*K)$，其中`K`为最大值(因为如果hashtable要容纳所有值的话必须有所有值的索引)。如果K很大的话其计算的复杂度是不可接受的。 因此我们引入离散化，就是将`nums`中的数字从小到大排序，去除重复的然后使用hashmap去索引每一个数字，将其的索引为`1~n`，这样的话时间复杂度会降到 $O(n\*2)$ 与暴力方法相同，也不可接受。

因此为了简化hashtable的值的sum的计算，我们引入树状数组去解决此问题，可以将时间复杂度降低到$O(nlogn)$


### 树状数组(BIT)

其中树状数组具体的定义和使用可见我的另一篇文章[树状数组](https://www.cnblogs.com/luyanfcp/articles/12457039.html)

这个方法的核心是 树状数组 + 离散化

#### 离散化

离散化用于处理，使用树状数组可能引发， 数组hash过长的问题

```c++
vector<int> vec_elem;
std::copy(nums.begin(), nums.end(), std::back_insert_iterator(vec_elem));
sort(vec_elem.begin(), vec_elem.end());
// 删除重复的
vec_elem.erase(unique(vec_elem.begin(), vec_elem.end), vec_elem.end());
// 离散化操作
int count = 1;  // 标记计数
unordered_map<int, int> hashmap;
for (int elem : vec_elem) {
    hashmap[elem] = count++;
}
```

将一些列递增的数列转换位1-n的标号

离散化的操作只适合离线计算不适合在线计算。

#### 树状数组

具体讲解可见我的树状数组总结。

构造树状数组去计算，`x`之前的数比`x`位置的数大数的个数。其中树状数组记录的标号位`x`数字的个数。

```c++
vector<int> t(n + 1);
int ans = 0;
for (int i = 0; i < nums.size(); ++i) {
    add(hashmap[nums[i]], t);
    ans += (i+1) - ask(hashmap[nums[i]], t);  // 正序数+逆序数=i+1
}
return ans;
```


#### 所有的代码

+ 执行用时 :208 ms, 在所有 C++ 提交中击败了66.29%的用户
+ 内存消耗 :61.1 MB, 在所有 C++ 提交中击败了100.00%的用户

```c++
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using std::vector;
using std::sort;
using std::unique;
using std::unordered_map;

class Solution {
public:
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, vector<int>& t) {
        int n = t.size() - 1;
        for (; x <= n; x += lowbit(x)) t[x] += 1;  
    }
    int ask(int x, vector<int>& t) {
        int res = 0;
        for (; x > 0; x -= lowbit(x)) res += t[x];
        return res;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        // 离散化操作
        vector<int> vec_elem;
        std::copy(nums.begin(), nums.end(), std::back_insert_iterator(vec_elem));
        sort(vec_elem.begin(), vec_elem.end());  // 删除重复的
        vec_elem.erase(unique(vec_elem.begin(), vec_elem.end()), vec_elem.end());  
        int count = 1;  // 标记计数
        unordered_map<int, int> hashmap;
        for (int elem : vec_elem) {
            hashmap[elem] = count++;
        }
        vector<int> t(n + 1);
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            add(hashmap[nums[i]], t);
            ans += (i+1) - ask(hashmap[nums[i]], t);
        }
        return ans;
    }
};
```