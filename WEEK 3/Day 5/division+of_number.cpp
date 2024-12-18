class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == dividend) return 1;
        bool sign = true; // positive number ;
        if(divisor>0 && dividend <=0 ) sign = false;
        else if ( divisor <0 && dividend >=0) sign = false;
        long n = abs(dividend);
        long d = abs (divisor);
        long quo = 0;
        while(n>=d){
            int cnt =0;
        while(n>=(d<<(cnt+1))){
            cnt++;

        }
        quo+= 1<<cnt;
        n-=(d <<cnt);
        }
        if(quo <=(1<<31) && !sign){
            return INT_MIN;
        }
        if(quo== (1<<31) && sign){
            return INT_MAX;
        }
        
        return sign ?quo : -quo;



        
    }
};