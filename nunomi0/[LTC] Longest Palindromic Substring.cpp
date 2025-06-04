class Solution {
public:
    string longestPalindrome(string s) {
        string ans=s.substr(0,1);
        for (int i = 0; i<s.length(); i++){
            for (int j = s.length()-1; j>i; j--){

                if (ans.length()>j-i+1) continue;

                bool palindrom = true;
                int start = i;
                int end = j;
                while (start<end){
                    if (s[start]==s[end]){
                        start++;
                        end--;
                    }
                    else {
                        palindrom=false;
                        break;
                    }
                }
                if (palindrom) ans=s.substr(i,j-i+1);
            }
        }    
        return ans;
    }
};
