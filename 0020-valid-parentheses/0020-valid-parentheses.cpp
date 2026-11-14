class Solution {
public:
    bool opening(char ch){
        return ch=='{' or ch=='(' or ch=='[';}

    bool valid(char open,char close){
        return open=='{' and close=='}' or  open=='[' and close==']' or  open=='(' and close==')';
    }
    bool isValid(string s) {
        stack<char>st;
        for(auto ch:s){
            if(opening(ch)){
                st.push(ch);

            }
            else{
            if(st.empty()) {return false;}
            if(valid(st.top(),ch)){

                st.pop();
            }
            else{
                return false;
            }}
        }
        return st.empty();
    }
};