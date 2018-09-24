# ZOJ
My ZOJ solutions

## 1001 A + B Problem (AC)
[ZOJ Problem Set - 1001](http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1001)

练手热身题

## 1002 Fire Net (AC)
[ZOJ Problem Set - 1002](http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1002)

递归回溯 + 剪枝。

递归出口：k = N * N + 1

每次递归使用 `check()` 判断是否要剪枝。

* 注意从二维数组第 k 个元素转换到行号列号的技巧
```
        int r = k / N + 1;
        int c = k % N + 1;
```
* 注意 debug 时使用 `print_map()`
* 注意回溯法的**初始化**
