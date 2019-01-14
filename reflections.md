### #CODEUP1106 通信系统
<code><pre>
判断一个无向图是否是一棵树（树的定义：各个顶点连通且没有环路的图）需要满足两个条件：
1、没有环：题目中“每个端点均不会重复收到消息”已经限定了不会出现环路。
2、各个顶点都连通：只需要计算连通块数，并判断连通分支数是否等于1？
树有一个性质：边数=点数-1；如果不满足此条件，也就不是一棵树。
</code></pre>

### #LeetCode 952. Largest Component Size by Common Factor
<code><pre>
1、一开始为了质数打表，TLE。之后改成对输入数组中每个数单独做factor decomposition。
2、并查集 + 计算每个union的大小。
</code></pre>

### #LeetCode 926. Flip String to Monotone Increasing
<code><pre>
TypeError: 'str' object does not support item assignment
</code></pre>

### #PAT1032 Is It a Binary Search Tree
<code><pre>
1、先序/后序/层序序列都可以唯一地确定一棵BST；
2、按原BST的先序序列插入得到的BST与原BST相同；按非BST的先序序列pre0插入得到的BST的先序序列pre1与pre0不同；
3、不同的插入顺序可能生成相同的BST，也可能生成不同的BST。
注：vector.size() 和 int 比较，显示type不匹配，改成(int)vector.size()
</code></pre>

### #LeetCode 235. Lowest Common Ancestor of a Binary Search Tree
<code><pre>
1、def lowestCommonAncestor(self, root, p, q）
2、记p,q的LCA为ans，则构成一棵以ans为根的子树，且p,q分别位于此子树的左右子树，下图表示出了p,q,ans的3种可能结构。此子树外的任何节点值要么大于both p&q，要么小于both p&q。因此要找的LCA(ans)即为binary search过程中遇到第一个 >=p && <= q 的节点。
<img src="LCA.jpg" width = "250" height = "100" div align=center />
</code></pre>

### #LeetCode 168. Excel Sheet Column Title
<code><pre>
1)0-based indexing is better than 1-based indexing when 
it comes to // and %.
2)Convert 1-based indexing to 0-based indexing by subtracting 1 from the numbers.
</code></pre>

### #LeetCode 966. Vowel Spellchecker
<code><pre>
字符串的匹配可以考虑用正则表达式。这题的正则表达式解法打败了100%的Python用户，很快。
</code></pre>

### #Completeness of binary tree
<code><pre>
LeetCode 222. Count Complete Tree Nodes
1、一般树求结点数的方法如DFS、BFS都要求时间复杂度O(n)；对于完全二叉树(complete binary tree)，利用其特殊性质可实现O((logn)^2)的时间复杂度;
2、高度为h的满二叉树(perfect binary tree)，结点数为2^h-1。
</code></pre>
<code><pre>
LeetCode 958. Check Completeness of a Binary Tree
层序遍历(BFS)二叉树：将空指针也进入队列
</code></pre>

### #KickStart-H C. Let Me Count The Ways
<code><pre>
1、[快速幂取模算法详解](https://blog.csdn.net/ltyqljhwcm/article/details/53043646)
2、[容斥原理总结（组合数学）](https://blog.csdn.net/riba2534/article/details/79241913)
3、[Modular arithmetic/modular inverse](https://blog.csdn.net/u013569304/article/details/51407239)
</code></pre>
## Python
<code><pre>
1、In python list can't be used as key of a dictionary, use tuple instead.
2、移位操作:<< / >> A right shift by n bits is defined as division by pow(2,n). A left shift by n bits is defined as multiplication with pow(2,n); 移位操作实际上是调用pow(2,n)函数，再进行乘除。
3、str(n)[::-1]实现字符串翻转
</code></pre>

### #LeetCode 937. Reorder Log Files
<code><pre>
关于Python3的sort/sorted排序：
1、sort只能对list排序，sorted可对任何iterable对象排序。
2、利用key进行custom sorting：
The value of the key parameter should be a function that takes a single argument and returns a key to use for sorting purposes. 
The return value is to be compared, and the value could be a tuple:
s = sorted(s, key = lambda x: (x[1], x[2])) 先按x[1]进行排序，x[1]相等的情况下按x[2]进行排序。
</code></pre>

### [#hoj 2662 Pieces Assignment 经典状压dp](https://www.cnblogs.com/a-clown/p/6145462.html)
### [#nowcoder girl 2017 勇敢的妞妞 状压dp](https://www.nowcoder.com/questionTerminal/aaad2e0e1dc74d5da4587ad7f6e0de8d)
