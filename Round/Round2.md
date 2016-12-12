# Round 2
11.21-11.28 Week 13  
## 1. A - Cellular Network (二分)
一维数轴上，给出n个城市和m个信号塔的整数坐标，问要使所有的城市都被覆盖信号，
每个信号塔的信号范围r最小可以是多少。(n, m <= 1e5)
## 2. B - Memory and De-Evolution (贪心)
给出一大一小两个正三角形的整数边长x和y，一次操作可以修改一个三角形的任意条边长，
只要仍然保持一个非退化的三角形（面积不为0），问最少经过多少次操作可以由一个三角形
变为另一个三角形。（y < x <= 1e5）
## 3. C - Igor In the Museum (BFS)
给出一个n\*m的由\*和.构成的矩阵来表示一个博物馆的地图，*代表墙，.表示可以行走的区域，
在每一处\*和.相邻的地方，墙上都挂着一幅画。k此询问，每次给出矩阵中一个点的坐标，问从
这一点开始最多能看多少幅画。(n, m <= 1e3, k <= 1e5)
## 4. D - Hard problem (DP)
## 5. E - Mike and Shortcuts (最短路)
## 6. F - Guest From the Past (水)
1. 如果塑料瓶饮料价格a小于玻璃瓶饮料净价格b-c，则全买a，相等也全买a
2. 否则，优先买b-c，但要注意，当剩余钱数大于b-c但小于b的时候，就不能买b-c了，
为保证每次都能顺利买b-c，先在n当中减去一个c，然后全买b-c，ans = (n-c)/(b-c),
此时剩余的钱数(n-c)%(b-c)+c < b，不够买一瓶b饮料，此时再全部买a，ans += ((n-c)%(b-c)+c)/a  
3. 特判：当b-c<a且n<c时，n-c为负，此时只能买a
## 7. G - Day at the Beach
## 8. H - Money Transfers
## 9. I - Wilbur and Array (贪心)
给出一个长度为n的整数序列，每此操作可以选择其中一个位置，从此位置之后的每个数都加1或减1，
问最少经过多少此操作之后可以把所有的数都变为0。
## 10. J - New Year and Old Property (位运算)
给出个一整数区间[a, b]，问区间内有多少整数，其二进制表示中除前导0外有且仅有一个0。