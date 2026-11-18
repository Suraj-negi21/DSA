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

    int largestRectangleArea(vector<int>& a){
        int n=a.size();

        auto left=getnextsmallleft(a,n);
        auto right=getnextsmallright(a,n);

        int ans=0;

        for(int i=0;i<n;i++){
            int h=a[i];
            int w=right[i]-left[i]-1;

            ans=max(ans,h*w);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>height(m,0);

        int ans=0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
            }

            ans=max(ans,largestRectangleArea(height));
        }

        return ans;
    }
};