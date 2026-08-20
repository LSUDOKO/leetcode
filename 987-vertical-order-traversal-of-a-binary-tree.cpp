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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>ans;
        if (root==NULL){
            return ans;
        }
        q.push({root,{0,0}});
        unordered_map<int,vector<pair<int,int>>>mp;
        int start=INT_MAX;
        int end=INT_MIN;
        while(!q.empty()){
            auto [curr,pos]=q.front();
            q.pop();
            int dist=pos.first;
            int row=pos.second;

            mp[dist].push_back({row,curr->val});
            start=min(dist,start);
            end=max(dist,end);
            if (curr->left)q.push({curr->left,{dist-1,row+1}});
            if (curr->right)q.push({curr->right,{dist+1,row+1}});
        }
        for (int i=start;i<=end;i++){
            sort(mp[i].begin(),mp[i].end());
            vector<int>temp;
            for (auto p:mp[i]){
                temp.push_back(p.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};