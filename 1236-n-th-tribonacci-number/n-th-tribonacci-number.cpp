class Solution {
private:
    void f(int a, int b, int c, int& ans, int i, int n)
    {
        if(i == n) 
        {
            ans = a + b + c;
            return;
        }
        f(b, c, (a + b + c), ans, i+1, n);
    }
public:
    int tribonacci(int n) {
        int ans = 0;
        if(n >= 3) f(0, 1, 1, ans, 3, n);
        else if(n > 0 && n < 3) ans = 1;
        
        return ans; 
    }
};