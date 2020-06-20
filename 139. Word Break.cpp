class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //length of longest word
        int longestWord = 0;
        //for faster search
        unordered_map<string,int> dict;
        for(string word : wordDict){
            dict[word]=1;
            longestWord = max(longestWord, (int)word.size());
        }
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;

        for(int i=1;i<=s.size();i++)
        {   
            //making sure evrytime the longest word is also checked
            for(int j=i-1;j>=max(i-longestWord, 0);j--)
            {
                //end of previous word
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {   
                        dp[i]=true; // marks end of current word
                        break; //next i
                    }
                }
            }
        }

        return dp[s.size()];
    }
};
