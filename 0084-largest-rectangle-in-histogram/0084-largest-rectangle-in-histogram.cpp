class Solution {
public:

    vector<int> getnextsmallleft(vector<int>& a,int n){
        stack<int>st;
        vector<int>ans(n,-1);

        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }

            if(!st.empty()){
                ans[i]=st.top();
            }

            st.push(i);
        }
        return ans;
    }

    vector<int> getnextsmallright(vector<int>& a,int n){
        stack<int>st;
        vector<int>ans(n,n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }

            if(!st.empty()){
                ans[i]=st.top();
            }

            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        auto getleft=getnextsmallleft(heights,n);
        auto getright=getnextsmallright(heights,n);

        int ans=0;

        for(int i=0;i<n;i++){
            int h=heights[i];
            int w=getright[i]-getleft[i]-1;

            ans=max(ans,h*w);
        }

        return ans;
    }
};