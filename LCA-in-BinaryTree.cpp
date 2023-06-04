/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int,int>dpth;
    map<int,int>pth;
    void helper(TreeNode*root,TreeNode* p,vector<int>&temp,int lvl){
        if(root!=NULL){
            dpth[root->val]=lvl;
            temp.push_back(root->val);
            
            if(root->val ==p->val){
                
            for(auto x:temp)
                 pth[x]++;
             
             }
            
            helper(root->left,p,temp,lvl+1);
            helper(root->right,p,temp,lvl+1);
            temp.pop_back();
            
        }
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>temp;
        helper(root,p,temp,0);
        helper(root,q,temp,0);
        int maxi=0;
        int data;
        for(auto x:pth){
          
            if(x.second==2 && dpth[x.first]>=maxi){
                maxi=dpth[x.first];
                data=x.first;
            }
        }
        TreeNode* ans=new TreeNode(data);
        
        return ans;
    } 
};
/*
        1
       / \
      2   3
     / \   \
    4   5   6
       / \
      7   8

   LCA is lowest node in the tree that has both x and y as descendants or successors
   LCA(7,8)=5  common ancestors are 5, 2, 1 lowest node is 5

*/
