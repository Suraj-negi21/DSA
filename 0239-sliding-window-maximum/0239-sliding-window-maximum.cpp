class Queue{
    stack<pair<int,int>>instack,outstack;
    void helper( stack<pair<int,int>>&s,int x){
        if(s.empty()){
            s.push({x,x});
        }
        else{
            s.push({x,max(x,s.top().second)});
        }
    }
public:
void push(int x){
    helper(instack,x);
}

void pop(){
    if(outstack.empty()){
        while(!instack.empty()){
            helper(outstack,instack.top().first);
            instack.pop();
        }
    }
    outstack.pop();
}

int getmax(){
    if(instack.empty() && outstack.empty()) return -1;
    if(instack.empty()){
        return outstack.top().second;
    }
    else if(outstack.empty()){
        return instack.top().second;
    }
    else{
        return max(instack.top().second,outstack.top().second);
    }
}

};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        Queue q;
        auto n=nums.size();
        for(int i=0;i<k;i++){
            q.push(nums[i]);
        }
        ans.push_back(q.getmax());
        for(int i=k;i<n;i++){
            q.push(nums[i]);
            q.pop();
             ans.push_back(q.getmax());
        }
        return ans;
    }
};