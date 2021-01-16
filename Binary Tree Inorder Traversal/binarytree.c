#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


/**S
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    struct TreeNode *cur = root, *pre;
    int *ret = NULL;
    while(cur)
    {
        if(cur->left == NULL)
        {
            ret = (int *)realloc(ret, sizeof(int) * (*returnSize + 1));
            (*returnSize)[ret] = cur->val;
            (*returnSize)++;
            cur = cur->right;
        }
        else
        {
            pre = cur->left;
            while(pre->right != cur && pre->right != NULL)
                pre = pre->right;

            if(pre->right)
            {
                ret = (int *)realloc(ret, sizeof(int) * (*returnSize + 1));
                (*returnSize)[ret] = cur->val;
                (*returnSize)++;
                pre->right = NULL;
                cur = cur->right;
            }
            else
            {
                pre->right = cur;
                cur = cur->left;
            }
        }
    }
    return ret;
}