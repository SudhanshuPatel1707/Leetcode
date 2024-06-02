class Solution {
private: 
int absOf(int n) 
    {
    if(n < 0) return n*-1;
    return n;
}
public:
    int scoreOfString(string s) {
        int score= 0;
        for(int i = 1; i < s.length(); i++)
         {
            int n = absOf(s[i] - s[i-1]);
            
            score += n;
        }
        
        return score;
    }
};