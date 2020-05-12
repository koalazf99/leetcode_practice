/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//如何利用二叉搜索树的性质
class Solution{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if ((root->val - p->val) * (root->val - q->val) <= 0)
            return root;
        if ((root->val < p->val) && (root->val < q->val)){
            return lowestCommonAncestor(root->right, p, q);
        }
        return lowestCommonAncestor(root->left, p, q);
    }
};

//纯递归求二叉树最近公共祖先
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (!root)
//             return NULL;
//         if (root == p || root == q)
//             return root;
//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);
//         if (!left)
//             return right;
//         if (!right)
//             return left;
//         return root;
//     }
// };