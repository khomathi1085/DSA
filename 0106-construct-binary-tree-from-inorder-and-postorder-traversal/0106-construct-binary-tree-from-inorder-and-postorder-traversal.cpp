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
    unordered_map<int,int> mpp;
    int postOrderIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        postOrderIndex=postorder.size()-1;
        return build(postorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& postorder,int start,int end){
        if(start>end) return nullptr;

        int data=postorder[postOrderIndex--];
        TreeNode* root=new TreeNode(data);
        int mid=mpp[data];

        root->right=build(postorder,mid+1,end);
        root->left=build(postorder,start,mid-1);

        return root;
    }
};