
/*==================================================*\
 * hardness: 
 | 1 star = simple
 | 2 star = can solve within 10 min(think time)
 | 3 star = can solve within 30 min
 | 4 star = can solve within 60 min
 | 5 star = have to ask for help
\*==================================================*/



/*==================================================*\
 * print a linked list in reverse
\*==================================================*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> results;
        stack<int> stack;
        while(head != NULL){
            stack.push(head->val);
            head = head->next;
        }
        while(!stack.empty()){
            results.push_back(stack.top());
            stack.pop();
        }
        return results;
    }
};



/*==================================================*\
 * rebuild binary tree
\*==================================================*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        int len = pre.size();
        if (len == 0) return NULL;

        int val = pre[0], pos = 0;
        TreeNode* results = new TreeNode(val);
        vector<int> pre_l, pre_r, in_l, in_r;

        while (val != in[pos]) pos++;
        for (i = 0; i < pos; i++){
            pre_l.push_back(pre[i+1]);
            in_l.push_back(in[i]);
        }
        for (i = pos+1; i < len; i++){
            pre_r.push_back(pre[i]);
            in_r.push_back(in[i]);
        }

        results->left = reConstructBinaryTree(pre_l, in_l);
        results->right = reConstructBinaryTree(pre_r, in_r);
        return results;
    }
};


/*==================================================*\
 * build queue with 2 stacks
\*==================================================*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()){
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/*==================================================*\
 * title: spin the array
 * description: 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减序列的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
\*==================================================*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() <= 0) return 0;
        min = rotateArray[0];
        for (int i = 1; i < rotateArray.size(); i++) if (rotateArray[i] < min) min = rotateArray[i];
        return min;
    }
};



/*==================================================*\
 * title: 斐波那契数列
 * description: 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项
\*==================================================*/
class Solution {
public:
    int Fibonacci(int n) {
        if (results.size() < 2){
            results.push_back(0);
            results.push_back(1);
        }
        int len = results.size();
        if (len <= n) for (int i = len; i <= n; i++) results.push_back(results[i-2] + results[i-1]);
        return results[n];
    }

private:
    vector<int> results;
};


/*==================================================*\
 * title: 跳台阶
 * description: 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法
\*==================================================*/
class Solution {
public:
    int jumpFloor(int n) {
        if (results.size() < 3){
            results.push_back(0);
            results.push_back(1);
            results.push_back(2);
        }
        int len = results.size();
        if (len <= n) for (int i = len; i <= n; i++) results.push_back(results[i-2] + results[i-1]);
        return results[n];
    }

private:
    vector<int> results;


};


/*==================================================*\
 * title: 变态跳台阶
 * description: 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法
\*==================================================*/
class Solution {
public:
    int jumpFloorII(int n) {
        if (results.size() < 3){
            results.push_back(0);
            results.push_back(1);
            results.push_back(2);
        }
        int len = results.size();
        if (len <= n){
            for (int i = len; i <= n; i++){
                int result = 1;
                for (int j = 1; j < i; j++) result += results[j];
                results.push_back(result);
            }
        }
        return results[n];
    }

private:
    vector<int> results;


};



/*==================================================*\
 * title: 矩形覆盖(同-跳台阶)
 * description: 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
\*==================================================*/
class Solution {
public:
    int rectCover(int n) {
        if (results.size() < 3){
            results.push_back(1);
            results.push_back(1);
            results.push_back(2);
        }
        int len = results.size();
        if (len <= n) for (int i = len; i <= n; i++) results.push_back(results[i-2] + results[i-1]);
        return results[n];
    }

private:
    vector<int> results;


};


/*==================================================*\
 * title: 二进制中1的个数
 * description: 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
\*==================================================*/
class Solution {
public:
     int  NumberOf1(int n) {
        int count = 0;
        while (n != 0){
            count++;
            n &= (n - 1);
        }
        return count;
     }
};


/*==================================================*\
 * title: 数值的整数次方
 * description: 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方
\*==================================================*/
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) return 1;
        if (((base -0.0)>-0.0000001) &&((base-0.0) <0.0000001)) return 0;

        double result = 1;
        bool positive = true;
        if (exponent < 0){
            positive = false;
            exponent = -exponent;
        }
        while (exponent != 0){
            if (exponent & 1 == 1) result *= base;
            base = base * base;
            exponent >>= 1;
        }
        return positive ? result : 1 / result;
    }
};




/*==================================================*\
 * title: 调整数组顺序使奇数位于偶数前面 **
 * note: boundary condition
 * description: 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变
\*==================================================*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size(), pos = 0;
        if (len < 2) return;

        vector<int> even;
        for (int i = 0; i < len; i++){
            if ((array[i] & 1) == 1) array[pos++] = array[i];
            else even.push_back(array[i]);
        }
        for (int i = 0; i < even.size(); i++){
            array[pos++] = even[i];
        }
    }
};




/*==================================================*\
 * title: 链表中倒数第k个结点 **
 * description: 输入一个链表，输出该链表中倒数第k个结点
 * note: check NULL, 0, Invalid
\*==================================================*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL || k == 0) return NULL;

        ListNode *p = pListHead, *q = pListHead;
        for (int i = 1; i < k; i++){
            if (p->next == NULL) return NULL;
            p = p->next;
        }
        while(p->next != NULL){
            p = p->next;
            q = q->next;
        }
        return q;
    }
};



/*==================================================*\
 * title: 反转链表 **
 * description: 输入一个链表，反转链表后，输出链表的所有元素
 * note: head node store val
\*==================================================*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead->next == NULL) return pHead;

        ListNode *qHead = pHead, *tmp = NULL;
        pHead = pHead->next;
        qHead->next = NULL;

        while(pHead->next != NULL){
            tmp = pHead;
            pHead = pHead->next;
            tmp->next = qHead;
            qHead = tmp;
        }

        pHead->next = qHead;
        return pHead;
    }
};



/*==================================================*\
 * title: 合并两个排序的链表 *
 * description: 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则
\*==================================================*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;

        ListNode *head = NULL;
        if(pHead1->val > pHead2->val){
            head = pHead2;
            pHead2 = pHead2->next;
        }else{
            head = pHead1;
            pHead1 = pHead1->next;
        } 

        head->next = Merge(pHead1, pHead2);
        return head;
        
    }
};


/*==================================================*\
 * title: 树的子结构 *
 * description: 输入两颗二叉树A，B，判断B是不是A的子结构
\*==================================================*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {

    }
};









