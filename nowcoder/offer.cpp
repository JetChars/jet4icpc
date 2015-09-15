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
