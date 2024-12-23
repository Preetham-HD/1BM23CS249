/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root==NULL){
        return false;
    }
    if(root->left==NULL&&root->right==NULL){
        if(root->val==targetSum){
            return true;
        }
        else return false;
    }
    bool LeftS=hasPathSum(root->left,targetSum-root->val);
    bool RightS=hasPathSum(root->right,targetSum-root->val);
    return LeftS||RightS;
}
