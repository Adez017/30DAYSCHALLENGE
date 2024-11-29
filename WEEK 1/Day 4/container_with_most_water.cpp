class Solution {
public:
    int maxArea(vector<int>& height) {
        //the idea is very simple 
        //we all know the area is width * height 
        // height we have what about width ??
        // lets understand 
        //idx    0,1,2,3,4,5
        //let a [1,2,4,5,6,7,] 
            //   L         R
        //   width = R-L
        //we get the area = min(height[left],heigth[right]) beacuse if we get bigger value it might overflow 
        //
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

            if (height[left] < height[right]) {
                left++; //we want to maximise the water
            } else {
                right--;
            }
        }
        //TC : O(N)
        return maxArea;        
    }
};