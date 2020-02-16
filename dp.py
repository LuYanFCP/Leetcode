def dpMakeChange(coinValueList, change, minCoins, coinsUsed):
    """
    @param: coinValueList 有效币值的列表
    @param: change 需要找0的钱
    @param: minCoins 进行找零的最小硬币数
    @param: coinsUsed 用于找零的硬币列表
    """
    for cents in range(change + 1): # cents的遍历范围为 [0, change]
        """
        cents 是 遍历条件
        """
        coinCount = cents
        newCoin = 1
        for j in [c for c in coinValueList if c <= cents]:  # 可选择的硬币数量，这里进行剪枝，处理掉一些不可能的情况
            if minCoins[cents - j] + 1 < coinCount:  # minCoins[cents - j] 是表示把j找个cents, 
                coinCount = minCoins[cents - j] + 1
                newCoin = j
        minCoins[cents] = coinCount
        coinsUsed[cents] = newCoin
    return minCoins[change]

"""
dp 的核心任务的分解->边界条件和转移方程

贪婪算法的问题：
1. 从上至下的搜索（从大到小），导致起缺失了整体的信息

如何解决
1. 从下到上，小到大的搜索， 因此会避免陷入局部最优值
2. 设定：minCoins[i] 表示钱数为i的时候，最小的硬币数的找零（只记录最少用几个硬币，不用记录都用了谁）
    minCoins[i] = min(minCoins[i], minCoins[i - j] + 1)
    这个公式的意思就是从原本的minCoins[i]和再通过另外另一条路，也就是通过找给顾客j元钱，然后的minCoins谁的更小

"""

def dpMakeChange1(coinValueList, change):
    """
    @param: coinValueList为 硬币列表，其他的参数相同
    """
    #1. 创建minCoins 数组 (这里使用100充当最大值)
    minCoins = [100] * (change + 1) # python列表的标号是从0开始的因此创建[0, 1, 2...change]
    # 默认情况下minCoins[0] = 0 边界条件，因为没钱找
    minCoins[0] = 0
    #2. 遍历， 从下到上
    for cent in range(change + 1):  # 还是老问题
        # 3. 现在找minCoins[c]的最优解
        # 首先从硬币列表中筛选能使用的硬币
        allow_count = [c for c in coinValueList if c <= cent]
        # 然后 遍历用转移方程进行筛选
        for j in allow_count:
            minCoins[cent] = min(minCoins[cent], minCoins[cent - j] + 1)
    # 遍历完成之后就找到了最优解
    return minCoins[change]

# dpchange1 是其最简单的版本 
amnt = 63
clist = [1, 5, 10, 21, 25]
print(dpMakeChange1(clist, amnt)) # output: 3, ok

"""
现在另一个问题来了，如果我像记录到底用了那些硬币，应该怎么办, 就在之前的问题上增加一个记录的功能
观察到转移方程：minCoins[i] = min(minCoins[i], minCoins[i - j] + 1)，我们发现当前的节点只需要记录上一跳的位置，就能成功的找到路径。
（搜索的过程类似于与一棵树）
因此使用coinsUsed[i]去记录minCoin[i]的上一跳的节点，这就是刚才你给我发过来的代码
printCoin的函数就是类似如上过程的通过上一跳的节点找路径（需要找的零钱列表）
"""
def dpMakeChange(coinValueList, change, minCoins, coinsUsed):
    """
    @param: coinValueList 有效币值的列表
    @param: change 需要找0的钱
    @param: minCoins 进行找零的最小硬币数
    @param: coinsUsed 解释见上面的注释
    """
    for cents in range(change + 1): # cents的遍历范围为 [0, change]
        """
        cents 是 遍历条件
        """
        coinCount = cents
        newCoin = 1
        for j in [c for c in coinValueList if c <= cents]:  # 可选择的硬币数量，这里进行剪枝，处理掉一些不可能的情况
            if minCoins[cents - j] + 1 < coinCount:  
                coinCount = minCoins[cents - j] + 1  # 主要coinCount一直在变化
                newCoin = j  # newCoin一直在变化
        minCoins[cents] = coinCount
        coinsUsed[cents] = newCoin
    return minCoins[change]

def printCoins(coinsUsed, change):
    """
    @param: coinsUsed 用于找零的硬币列表
    @param: change 零钱
    """
    coin = change
    while coin > 0:
        thisCoin = coinsUsed[coin]
        print(thisCoin)
        coin = coin - thisCoin

amnt = 62
clist = [1, 5, 10, 21, 25]
coinUsed = [0] * 64 
coinCount = [0] * 64
print(dpMakeChange(clist, amnt, coinCount, coinUsed)) 

coins = [3, 4, 12, 1, 5, 2]
coins.sort()
print(coins)