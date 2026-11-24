/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int MAX(TreeNode*root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else{
            if(root->right==NULL and root->left==NULL)return NULL;
            if(root->right!=NULL and root->left==NULL)return root->right;
            if(root->right==NULL and root->left!=NULL)return root->left;
            int mx=MAX(root->left);
            root->val=mx;
            root->left=deleteNode(root->left,mx);
           
        }
         return root;
    }
};