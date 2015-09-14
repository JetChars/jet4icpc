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
        if (!stack2.empty()){
        
        }
        while (!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop;
        }
        stack2.pop()
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

