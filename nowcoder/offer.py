
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
        l = len(array[0])
        if (l == 0): return False
        i = len(array) - 1
        j = 0
        while(j < l and i >= 0):
        	if(array[i][j] < target): j += 1
        	elif(array[i][j] > target): i -= 1
        	else: return True
        return False