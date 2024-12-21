class Solution {
public:
    int countPrimes(int n) {
        
        //seive of erastothenes methods 
        //marking all positive then picking out 
        vector<bool> prime(n + 1, true);
        prime[0] = false; //beacuse 0 and 1 are never been a prime 
        prime[1] = false;
        //starting from the first prime number
        for(int i = 2; i * i <= n; i++) {
            if(prime[i]) {
                //if 2 if prime that means that the mulitple of 2 cant be 
                //so marking them false /not prime
                //same for all numbers
                for(int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        //the remaining will  be the prime numbers
        
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(prime[i]) count++;
        }
        return count; 
    }
};