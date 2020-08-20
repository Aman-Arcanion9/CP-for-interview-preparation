class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        
        unordered_set<int> s;
        for(int i=0;i<A.size();i++){
            int j=i-1;
            int x=0,y=A[i];
            s.insert(y);
            //Reducing range to check the numbers using x!=y, this conditions comes into effect when an A[i] bigger than x and y comes whose all bits are set = 1
            //This means that any number that would come after would only be equal to this bigger number
            //If there is a bigger number of the left side of this number then it was already included in previous cases
            while(j>=0 and x!=y){
                x|=A[j];
                y|=A[j];
                s.insert(y);
                j--;
            }
        }
        return s.size();
    }
};
