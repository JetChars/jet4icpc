
#==================================================#
# title: 二维数组中的查找 *
# des. : 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
#        每一列都按照从上到下递增的顺序排序。
#        请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#==================================================#
# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, array, target):
        # write code here
        i, j, l = len(array) - 1, 0, len(array[0])
        if (l == 0): return False
        while(j < l and i >= 0):
        	if(array[i][j] < target): j += 1
        	elif(array[i][j] > target): i -= 1
        	else: return True
        return False


#==================================================#
# title: 替换空格 *
# des. : 请实现一个函数，将一个字符串中的空格替换成“%20”。
#		 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
#==================================================#
# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        return s.replace(" ", "%20")


#==================================================#
# title: 从尾到头打印链表 *
# des. : 输入一个链表，从尾到头打印链表每个节点的值。
#==================================================#
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
def iter_n(head):
	while head:
		yield head.val
		head = head.next

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, head):
        return list(iter_n(head))[::-1]


#==================================================#
# title: 重建二叉树 *
# des. : 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
#        假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
#		 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
#==================================================#
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        if len(pre) == 0:
            return None
        else:
            res = TreeNode(pre[0])
            for i in range(len(pre)):
                if(tin[i] == pre[0]):
                    res.left = self.reConstructBinaryTree(pre[1:i+1], tin[0:i])
                    res.right = self.reConstructBinaryTree(pre[i+1:], tin[i+1:])
                    break
            return res


# Solution2
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        l = len(pre)
        if l==0:
            return None
        else:
            patitionNum = pre[0]
            i = 0
            while tin[i]!=patitionNum:
                i += 1
            pre_left = pre[1:i+1]
            pre_right = pre[i+1:l]
            tin_left = tin[0:i]
            tin_right = tin[i+1:]
            leftNode = self.reConstructBinaryTree(pre_left,tin_left)
            rightNode = self.reConstructBinaryTree(pre_right,tin_right)
            node = TreeNode(patitionNum)
            node.left = leftNode
            node.right = rightNode
            return node




#==================================================#
# title: 用两个栈实现队列
# des. : 用两个栈来实现一个队列，完成队列的Push和Pop操作。
#		 队列中的元素为int类型
# Note : 不能tab和空格混用
#==================================================#
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, node):
        self.stack1.append(node)

    def pop(self):
        if self.stack2:
            return self.stack2.pop()
        elif self.stack1:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
            return self.stack2.pop()
        else:
            return None



#==================================================#
# title: 两个链表的第一个公共结点 **
# des. : 输入两个链表，找出它们的第一个公共结点。
# Note :
#==================================================#

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def FindFirstCommonNode(self, pHead1, pHead2):
        # write code here
        if pHead1 == None or pHead2 == None:
            return None

        len1, len2 = 0, 0
        p, q = pHead1, pHead2
        while p:
            len1 += 1
            p = p.next
        while q:
            len2 += 1
            q = q.next

        p, q = pHead1, pHead2
        if len1 < len2:
            for i in xrange(len2-len1):
                q = q.next
        elif len1 > len2:
            for i in xrange(len1-len2):
                p = p.next

        while p:
            if p == q:
                return p
            p, q = p.next, q.next

        return None



#==================================================#
# title: 数字在排序数组中出现的次数 *
# des. : 统计一个数字在排序数组中出现的次数。
# Note :
#==================================================#

# -*- coding:utf-8 -*-
class Solution:
    def GetNumberOfK(self, data, k):
        # write code here
        if data == None:
            return 0

        res = 0
        for i in data:
            if i == k:
                res += 1

        return res



#==================================================#
# title: 二叉树的深度 *
# des. : 输入一棵二叉树，求该树的深度。
#        从根结点到叶结点依次经过的结点（含根、叶结点）
#        形成树的一条路径，最长路径的长度为树的深度。
# Note :
#==================================================#
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def TreeDepth(self, pRoot):
        # write code here
        if pRoot == None:
            return 0
        self.left, self.right = self.TreeDepth(pRoot.left), self.TreeDepth(pRoot.right)
        return self.left+1 if self.left > self.right else self.right+1




#==================================================#
# title: 平衡二叉树 ***
# des. : 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
# Note :
#==================================================#
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def getDepth(self, pRoot):
        if pRoot == None:
            return 0
        self.left, self.right = self.getDepth(pRoot.left), self.getDepth(pRoot.right)
        if self.left == -1 or self.right == -1 or abs(self.left - self.right) > 1:
            return -1
        return self.left+1 if self.left > self.right else self.right+1

    def IsBalanced_Solution(self, pRoot):
        # write code here
        if self.getDepth(pRoot) == -1:
            return False
        return True




#==================================================#
# title: 数组中只出现一次的数字 **
# des. : 一个整型数组里除了两个数字之外，
#        其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
# Note :
#==================================================#
# -*- coding:utf-8 -*-
class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        if array == None or len(array) < 2:
            return [0, 0]

        res = []
        array.sort()
        if array[0] != array[1]:
            res.append(array[0])
        for i in xrange(1, len(array)-1):
            if array[i] != array[i-1] and array[i] != array[i+1]:
                res.append(array[i])
        if array[-1] != array[-2]:
            res.append(array[-1])

        return res



#==================================================#
# title: 和为S的连续正数序列 ***
# des. : 小明很喜欢数学,有一天他在做数学作业时,
#        要求计算出9~16的和,他马上就写出了正确答案是100。
#        但是他并不满足于此,
#        他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
#        没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
#        现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
#        输出所有和为S的连续正数序列。
#        序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
# Note :
#==================================================#
# -*- coding:utf-8 -*-
class Solution:
    def FindContinuousSequence(self, tsum):
        # write code here
        if tsum < 3:
            return []

        res = []
        for i in range(tsum-1, 1, -1):
            if not 2*tsum%i and (2*tsum/i-i+1)>0 and not (2*tsum/i-i+1)%2:
                res.append(range((2*tsum/i-i+1)/2, (2*tsum/i-i+1)/2 + i))

        return res




#==================================================#
# title: 和为S的两个数字 **
# des. : 输入一个递增排序的数组和一个数字S，
#        在数组中查找两个数，是的他们的和正好是S，
#        如果有多对数字的和等于S，输出两个数的乘积最小的。
#        对应每个测试案例，输出两个数，小的先输出。
# Note : 第一组答案就是想要的答案
#==================================================#
# -*- coding:utf-8 -*-
class Solution:
    def FindNumbersWithSum(self, a, tsum):
        # write code here
        if a == None:
            return []

        i, j = 0, len(a)-1
        while i < j:
            while a[i]+a[j] > tsum:
                j -= 1
            while a[i]+a[j] < tsum:
                i += 1
            if a[i]+a[j] == tsum and i < j:
                return [a[i], a[j]]
            i += 1

        return []


#==================================================#
# title: 翻转单词顺序列 **
# des. : JOBDU最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
#        同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
#        例如，“student. a am I”。后来才意识到，
#        这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
#        Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
# Note : we should specifiy the white space ' ', not using the default val
#==================================================#
# -*- coding:utf-8 -*-
class Solution:
    def ReverseSentence(self, s):
        # write code here
        return ' '.join(s.split(' ')[::-1])


#==================================================#
# title: 扑克牌顺子
# des. : LL今天心情特别好,因为他去买了一副扑克牌,
#        发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
#        他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,
#        如果抽到的话,他决定去买体育彩票,嘿嘿！！
#        “红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
#        LL不高兴了,他想了想,决定大\小 王可以看成任何数字,
#        并且A看作1,J为11,Q为12,K为13。
#        上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
#        LL决定去买体育彩票啦。
#        现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。
#        为了方便起见,你可以认为大小王是0。
# Note : 1. king == 0, and 4 kings maximum
#        2. return false, if have same cards other than 0
#==================================================#
# -*- coding:utf-8 -*-
class Solution:
    def IsContinuous(self, numbers):
        # write code here
        if len(numbers) != 5:
            return False

        numbers.sort()
        zeros,cnt = 0,0
        for i in numbers:
            if not i:
                zeros += 1
            else:
                break
        for i in range(zeros+1, len(numbers)):
            if numbers[i] == numbers[i-1]:
                return False
            cnt += numbers[i] - numbers[i-1] - 1

        return zeros >= cnt


#==================================================#
# title: 孩子们的游戏(圆圈中最后剩下的数)
# des. : 每年六一儿童节,NowCoder都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
#        HF作为NowCoder的资深元老,自然也准备了一些小游戏。
#        其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。
#        然后,他随机指定一个数m,让编号为0的小朋友开始报数。
#        每次喊到m的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,
#        并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....
#        这样下去....直到剩下最后一个小朋友,可以不用表演,
#        并且拿到NowCoder名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？
# Note : k = m%n, 则第一个淘汰的是k-1, 剩余的是 k,k+1,..,k-3,k-2
#        若将他们重新排序得到新的数列           0,1,...,n-2
#        hence,      f(n,m) = (f(n-1,m)+m)%n
#        and,        f(n+1,m) = (f(n,m)+m)%(n+1)
#==================================================#
# -*- coding:utf-8 -*-
class Solution:
    def LastRemaining_Solution(self, n, m):
        # write code here
        if n <=0 and m <=0:
            return -1
        elif n == 0:
            return 0

        res = 0;
        for i in xrange(n):
            res = (res+m)%(i+1)

        return res


#==================================================#
# title: 不用加减乘除做加法
# des. : 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
# Note : 分别使用^和&来保存 异或位为1的位置 和 同位1的位置
#==================================================#
# 1. stupidest way
# -*- coding:utf-8 -*-
class Solution:
    def Add(self, a, b):
        # write code here
        lst,flag = [],0
        while a!=0 and b!=0:
            x,y = a&1,b&1
            if x^y:
                if flag:
                    lst.append(0)
                    flag = 1
                else:
                    lst.append(1)
                    flag = 0
            else:
                if flag:
                    lst.append(1)
                else:
                    lst.append(0)
                if x&y:
                    flag = 1
                else:
                    flag = 0
            a >>= 1
            b >>= 1

        while a!=0:
            x = a&1
            if x^flag:
                lst.append(1)
                flag = 0
            else:
                lst.append(0)
                if x&flag:
                    flag = 1
                else:
                    flag = 0
            a >>= 1

        while b!=0:
            x = b&1
            if x^flag:
                lst.append(1)
                flag = 0
            elif x&flag:
                lst.append(0)
                flag = 1
            else:
                lst.append(0)
                flag = 0
            b >>= 1

        if flag:
            lst.append(1)

        lst.reverse()
        res = 0
        for i in lst:
            res <<= 1
            res ^= i

        return res

# solution2
# -*- coding:utf-8 -*-
class Solution:
    def Add(self, a, b):
        # write code here
        while b:
            x, y = a^b, a&b
            y <<= 1
            a, b = x, y

        return a




#==================================================#
# title: 把字符串转换成整数
# des. : 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
# Note : 1. can be null
#        2. can be single '-' or '+'
#==================================================#
# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        if len(s) <= 0:
            return 0
        res,neg = 0,False
        if s[0] == '-':
            s = s[1:]
            neg = True
        elif s[0] == '+':
            s = s[1:]
        for i in s:
            if i >= '0' and i <= '9':
                res = res*10 + int(i)
            else:
                return 0
        if neg:
            return -res
        return res




#==================================================#
# title:
# des. :
# Note :
#==================================================#


