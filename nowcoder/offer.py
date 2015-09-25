
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
    	if len(pre) < 1: return None
        res = TreeNode(pre[0])
        for i in range(len(pre)):
        	if(tin[i] == pre[0]):
        		res.left = reConstructBinaryTree(pre[1:i+1], tin[0:i])
        		res.right = reConstructBinaryTree(pre[i+1:], tin[i:])
        		break
        return res






















