int findfloor(vector<int>&arr, int x){
    //approach 
    //what is floor of a number ?
    //Floor of 'x' is the largest element in the array which is smaller than or equal to 'that number'.
    //idea is simple using the standard binary search we will be serach for that number

	int n = arr.size();
	int low = 0, high = n-1;
	int b =-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]<=x){
			b = arr[mid];
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return b;
}
int findceil(vector<int> &arr, int x){
    //same as above the ciel of the number is smallest element which is greater than or equal to the that number
	int n = arr.size();
	int low =0, high = n-1;
	int a = -1;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]>=x){
			a = arr[mid];
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return a;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int floorVal = findfloor(a, x);
    int ceilVal = findceil(a, x);

    // If floor or ceil is not found, return x itself
   

    return {floorVal, ceilVal};


	
}
