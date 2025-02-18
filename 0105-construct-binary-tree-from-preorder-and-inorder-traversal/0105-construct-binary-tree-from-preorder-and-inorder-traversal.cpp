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
    int preOrderIndex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, int start, int end){
        if(start>end) return nullptr;

        int data=preorder[preOrderIndex++];
        TreeNode* root=new TreeNode(data);
        int mid=mpp[data];

        root->left=build(preorder,start,mid-1);
        root->right=build(preorder,mid+1,end);

        return root;
    }
};