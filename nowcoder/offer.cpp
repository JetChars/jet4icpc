
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
 * title: 树的子结构 ***
 * description: 输入两颗二叉树A，B，判断B是不是A的子结构
 * notice: 
 * 1. empty tree is subtree of any tree, but no in this testcase
 * 2. this issue can be optimize with kmp
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
class Solution1 {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }

    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL) return true;
        if(pRoot1 == NULL) return false;
        return pRoot1->val == pRoot2->val && isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
    }
};


class Solution2 {
/* 改进算法，时间复杂度O（m+n）
 * 1.将root1和root2分别按先序遍历序列化。
 * 2.运用KMP算法匹配序列化结果。
 */
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        if(root2==null)
            return false;// 空树本应是任意树的子结构，但从测试集来看，应视为false
        if(root1==null)
            return false;
        char[] str = Serialize(root1).toCharArray();
        char[] pattern = Serialize(root2).toCharArray();
        int[] next = new int[pattern.length];
        System.out.println(String.valueOf(str));
        System.out.println(String.valueOf(pattern));
        getNext(pattern,next);
        return KMP(str,pattern,next);
         
    }
    private boolean KMP(char[] str, char[] pattern, int[] next) {
        if(str==null||pattern==null)
            return false;
        if(str.length<pattern.length)
            return false;
        int i=0,j=0,len = str.length;
        while(i<len&&j<pattern.length){
            if(j==-1||str[i]==pattern[j]){
                i++;j++;
            }else{
                j = next[j];
            }
        }
        if(j==pattern.length)// 表示最后一个字符也相等，匹配成功
            return true;
        return false;
    }
     
    private void getNext(char[] pattern, int[] next) {
        if(pattern==null||pattern.length==0)
            return;
        int i=0,j=-1;
        next[0] = -1;
        while(i<pattern.length-1){
            if(j==-1||pattern[i]==pattern[j]){
                ++i;++j;               
                if(pattern[i]==pattern[j]){
                    next[i] = next[j];
                }else{
                    next[i] = j;
                }
            }else{
                j = next[j];
            }
        }
    }
    public String Serialize(TreeNode root) {
        if(root==null)
            return "";
        this.buffer = new StringBuffer();
        SerializeF(root);
        int i;
        // 删除序列尾部的$
        for(i = buffer.length()-1;i>=0;i--){
            if(buffer.charAt(i)==','||buffer.charAt(i)=='$'){
                continue;
            }else
                break;
        }
        buffer.delete(i+1,buffer.length());
        return buffer.toString();
    }
};


/*==================================================*\
 * title: 二叉树的镜像 *
 * description: 操作给定的二叉树，将其变换为源二叉树的镜像
 二叉树的镜像定义：  源二叉树       镜像二叉树
                    8            8
                   / \          / \
                  10  6        6   10
                 / \ / \      / \  / \
                11 9 7 5     5 7  9 11
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return;
        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};


/*==================================================*\
 * title: 顺时针打印矩阵 ****
 * description: 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
 例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 * notice: 边界条件要理清楚，使用易识别的变量名
\*==================================================*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> results;
        if(col == 0 || row == 0) return results;

        int left = 0, right = col - 1, top = 0, down = row - 1;
        while(top <= down && left <= right){
            for(int i = left; i <= right; ++i) results.push_back(matrix[top][i]);
            for(int i = top + 1; i <= down; ++i) results.push_back(matrix[i][right]);
            if(top<down)for(int i = right - 1; i >= left; --i) results.push_back(matrix[down][i]);
            if(left<right)for(int i = down - 1; i > top; --i) results.push_back(matrix[i][left]);
            left++, right--, top++, down--;
        }
        return results;
    }
};



/*==================================================*\
 * title: 包含min函数的栈 ***
 * description: 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
 * hint: 每个负值之前存放的是相对当前最小的的差值，可通过减去该值获得当前最小值。
\*==================================================*/
class Solution {
public:
    void push(int value) {
        if(stk.empty()){
            stk.push(0);
            mini = value;
            return;
        }
        stk.push(value - mini);
        if(value < mini) mini = value;
        
    }
    void pop() {
        int x = stk.top();
        if(x < 0) mini -= x;
        stk.pop();
    }
    int top() {
        return stk.top() + mini;
    }
    int min() {
        return mini;
    }

private:
    stack<int> stk;
    int mini;
};



/*==================================================*\
 * title: 栈的压入、弹出序列 ***
 * description: 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
    假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
    序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
\*==================================================*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()) return false;
        stack<int> st;
        for(int i = 0, j = 0, len = pushV.size(); i < len; ){
            st.push(pushV[i++]);
            while(!st.empty() && j < len && st.top() == popV[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};



/*==================================================*\
 * title: 从上往下打印二叉树 **
 * description: 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> res;
        if(root == NULL) return res;

        queue<TreeNode*> qu;
        TreeNode* tmp;
        qu.push(root);
        while(!qu.empty()){
            tmp = qu.front();
            res.push_back(tmp->val);
            qu.pop();
            if(tmp->left != NULL)qu.push(tmp->left);
            if(tmp->right != NULL)qu.push(tmp->right);
        }

        return res;
    }
};



/*==================================================*\
 * title: 二叉搜索树(二叉排序、查找树)的后序遍历序列 **
 * description: 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
    如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
\*==================================================*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len == 0) return false;
        if(len <= 2) return true;

        vector<int> left, right;
        int root = sequence.back(), i = 0, j;
        while(sequence[i] < root) ++i;
        j = i;
        while(j < len - 1)if(sequence[j++] < root) return false;
        left.assign(sequence.begin(), sequence.begin() + i);
        right.assign(sequence.begin() + i, sequence.end() - 1);

        bool l = true, r = true;
        if(!left.empty()) l = VerifySquenceOfBST(left);
        if(!right.empty()) r = VerifySquenceOfBST(right);
        return l && r;

    }
};


calss Solution2 {
public:
    bool judge(vector<int>& a, int l, int r){
        if(l >= r) return true;
        int i = r;
        while(i > l && a[i - 1] > a[r]) --i;
        for(int j = i - 1; j >= l; --j) if(a[j] > a[r]) return false;
        return judge(a, l, i - 1) && (judge(a, i, r - 1));
    }
    bool VerifySquenceOfBST(vector<int> a) {
        if(!a.size()) return false;
        return judge(a, 0, a.size() - 1);
    }
};
}



/*==================================================*\
 * title: 二叉树中和为某一值的路径 ****
 * description: 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
    路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
 * notice: copy code should really carefully
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res, ltmp, rtmp;
        if(root == NULL || root->val > expectNumber || expectNumber <= 0) return res;

        if(root->left != NULL){
            ltmp = FindPath(root->left, expectNumber - root->val);
            if(ltmp.size()){
                for(int i = 0; i < ltmp.size(); ++i){
                    ltmp[i].insert(ltmp[i].begin(), root->val);
                    res.push_back(ltmp[i]);
                }
            }
        }
        if(root->right != NULL){
            rtmp = FindPath(root->right, expectNumber - root->val);
            if(rtmp.size()){
                for(int i = 0; i < rtmp.size(); ++i){
                    rtmp[i].insert(rtmp[i].begin(), root->val);
                    res.push_back(rtmp[i]);
                }
            }
        }    
        
        if(expectNumber == root->val && root->left == NULL && root->right == NULL){
            vector<int> re;
            re.push_back(expectNumber);
            res.push_back(re);
        }

        return res;
    }
};


/*==================================================*\
 * title: 复杂链表的复制 *****
 * description: 输入一个复杂链表（每个节点中有节点值，以及两个指针，
    一个指向下一个节点，另一个特殊指针指向任意一个节点）。
 * solution: A->A->A  ==>  A->B->A->B->A->B
    1. add new nodes B(A->next)
    2. B->random = A->random->next;
    3. split
\*==================================================*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
     
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode *p, *res, *tmp;
        for(p = pHead; p; p = tmp->next){
            tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
        }
        for(p = pHead; p; p = p->next->next)if(p->random) p->next->random = p->random->next;
        for(p = pHead, res = pHead->next; p->next; p = tmp){
            tmp = p->next;
            p->next = tmp->next;
        }

        return res;
    }
};


/*==================================================*\
 * title: 二叉搜索树与双向链表 *****
 * description: 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
                要求不能创建任何新的结点，只能调整树中结点指针的指向。
 * HINT: 递归法求解要考虑最原子的操作才才合理
         还可以考虑使用队列解决该问题
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
class Solution0 {  // now working
public:
    bool isLeaf(TreeNode* node){
        return node->left == NULL && node->right == NULL;
    }

    TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree || isLeaf(pRootOfTree)) return pRootOfTree;
        TreeNode *left = pRootOfTree->left, *right = pRootOfTree->right, *res = pRootOfTree;
        if(left){
            res = left;
            while(left->right) left = left->right;
            if(pRootOfTree->left) res = Convert(pRootOfTree->left);
            left->right = pRootOfTree;
            pRootOfTree->left = left;
        }
        if(right){
            while(right->left) right = right->left;
            if(pRootOfTree->right) Convert(pRootOfTree->right);
            right->left = pRootOfTree;
            pRootOfTree->right = right;
        }
        return res;
    }
};


class Solution {
public:
    TreeNode* Convert(TreeNode* root){
        if(!root) return NULL;
        if(root->left == NULL && root->right == NULL) return root;

        TreeNode *left = NULL, *right, *last;
        if(root->left){
            left = Convert(root->left);
            last = left;
            while(last->right)last = last->right;
            last->right = root;
            root->left = last;
        }
        if(root->right){
            right = Convert(root->right);
            right->left = root;
            root->right = right;
        }
        return left ? left : root;
    }
};


/*==================================================*\
 * title: 字符串的排列
 * description: 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
                例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
                结果请按字母顺序输出。
                输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母
\*==================================================*/
class Solution {
public:
    vector<string> Permutation(string str) {
        
    }
};









