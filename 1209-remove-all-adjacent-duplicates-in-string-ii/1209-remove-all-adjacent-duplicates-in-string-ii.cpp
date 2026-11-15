class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(auto ch:s){
            if(st.empty() || st.top().first!=ch){
               
                st.push({ch,1});
            }

            else{
                st.top().second++;
                if(  st.top().second==k){
                    st.pop();
                }
            }

        
        }

        string ans="";
        while(!st.empty()){
            auto [h,cnt]=st.top();
            st.pop();
            while(cnt--){
                ans+=h;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};