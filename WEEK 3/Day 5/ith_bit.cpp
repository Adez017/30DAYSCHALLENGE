class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        // Your code here
        //take an example and do it you will understand 
        return (n & (1 << k));
    }
};