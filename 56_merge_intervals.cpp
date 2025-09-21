class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int>> st;
        st.push(intervals[0]);
        for (int i=1;i<intervals.size();i++){
            vector<int> top=st.top();
            if (top[1]>=intervals[i][0]){
                st.pop();
                top[1]=max(intervals[i][1],top[1]);
                st.push(top);
            }
            else{
                st.push(intervals[i]);
            }

        }
        vector<vector<int>> merged;
        while (!st.empty()) {
            merged.push_back(st.top());
            st.pop();
        }
        reverse(merged.begin(), merged.end());
        return merged;
    }
};