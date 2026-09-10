/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        auto dfs = [&](auto&& self,TreeNode* root) -> pair<int, int> {
            if(!root){
                return {0,0};
            }

            auto [leftSum,leftCnt] = self(self,root->left);
            auto [rightSum,rightCnt] = self(self,root->right);

            int sum = leftSum + rightSum + root->val;
            int cnt = leftCnt + rightCnt + 1;

            if(sum / cnt == root->val){
                ans++;
            }

            return {sum,cnt};
        };
        
        dfs(dfs,root);
        return ans;
    }
};