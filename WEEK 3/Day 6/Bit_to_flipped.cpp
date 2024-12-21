class Solution {
public:
    // remeber the functionality of XOR 
    // if 1 ^1 = 0 , 1^0 = 0 , 0^0 = 0 , 0^1 = 1
    // it specify 1 if the bits are not matched 
    //that means the bits that are not matched  a have to be fliped
    int minBitFlips(int start, int goal) {
        int cnt = start ^ goal;
        //__builtin_popcount() inbuilt function to retrurn the set bits in a number
        return __builtin_popcount(cnt);

        
    }
};