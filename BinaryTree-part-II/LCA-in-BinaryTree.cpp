// problem link: https://www.codingninjas.com/codestudio/problems/920541?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
    unordered_map<int,int>dpth;
    unordered_map<int,int>pth;
    void helper(TreeNode<int> *root,int p,vector<int>&temp,int lvl){
        if(root!=NULL){
            dpth[root->data]=lvl;
            temp.push_back(root->data);
            
            if(root->data ==p){
                
            for(auto x:temp)
                 pth[x]++;
             
               
            }
            
            helper(root->left,p,temp,lvl+1);
            helper(root->right,p,temp,lvl+1);
            temp.pop_back();
            
        }
        
    }
int lowestCommonAncestor(TreeNode<int> *root, int p, int q)
{   
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
       dpth.clear();
       pth.clear();
        
        return data;
}
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
