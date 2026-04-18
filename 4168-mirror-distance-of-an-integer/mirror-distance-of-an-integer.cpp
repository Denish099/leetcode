class Solution {
public:
    int reverse(int n){
        int x = 0;
        while(n){
            int y = n % 10;  
            x = 10 * x + y;
            n /= 10;
        }
        return x;
    }

    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};