class Solution {
public:
   string removeKdigits(string num, int k) {
      stack<char> st;
      string ret = "";
      int n = num.size();
      
      for(int i = 0; i < n; i++){
      
      //st.top() > num[i] - makes sure that the smallest digit takes the higher order place
      
         while(k && !st.empty() && st.top() > num[i]){
            st.pop();
            k--;
         }
         st.push(num[i]);
      }
      
      // Removes digits from the least significant side
      
      while(k--)st.pop();
      
      //Puts the number bac in reverse order
      
      while(!st.empty()){
         ret += st.top();
         st.pop();
      }
      reverse(ret.begin(), ret.end());
      string ans = "";
      int i = 0;
      
      // Takes care of leading zeros
      
      while(i <ret.size() && ret[i] == '0')i++;
    
      for(; i < ret.size(); i++)ans += ret[i];
      ret = ans;
      
      //Conditional operator returns zero if string is empty i.e. it had only k digits
      return ret.size() == 0? "0" : ret;
   }
};
