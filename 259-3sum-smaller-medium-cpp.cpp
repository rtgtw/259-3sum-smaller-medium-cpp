/*

259. 3Sum Smaller

Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.



Example 1:

Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]


Solution: we are going to use the two pointer method for this problem

We can use a count variable rather than storing the triplets in an array

For loop can stop 2 positions from the end of the array since we are looking
for triplets

We call searchPairs within the for loop to find all triplets that are less than the target

searchPair uses the two pointer method


*/

#include <iostream>
#include <vector>
#include <algorithm>



class Solution {

private:
	//searchPair is going to return the count
	//Search pair needs:
	// the array, target value, the index(in order to determine the first element) and the count
	int searchPair(std::vector<int>& arr, int target, int i);

public:
	int searchTriplets(std::vector<int>& arr, int target);
};

//Passing count by reference to continually keep track of count
int Solution::searchPair(std::vector<int>& arr, int targetSum, int i) {

	//Once inside of the searchPair method we can start searching for a match
	//The goal is to find a pair of triplets that are less than the target and 
	//increment the count and return the count
	// 
	// At First this was in searchTriplets but this will be used inside of searchPairs
	//We are going to be using a left and right pointer with the two pointer method
	//Left and right need to be initialized here in order to enter the while loop
	int count = 0;
	int left = i + 1;
	int right = arr.size() - 1;


	//Continue through the while loop until left and right cross 
	while (left < right) {

		if (arr[left] + arr[right] < targetSum) {

			count += right - left;
			left++;
		}
		else {
			right--;
		}

	}

	return count;
}



int Solution::searchTriplets(std::vector<int>& arr, int target) {

	//First thing that we need to do is sort the array
	std::sort(arr.begin(), arr.end());


	//variables
	//We need a count to keep count of all the triplets that are less than the target
	//It can be initialized to 0
	int count = 0;

	

	//We are going to create a for loop to iterate through each element within the array
	//We have to avoid duplicates, we can say, while the prev is = current, skip 
	//We can stop at .size -2 since we are looking for triplets
	for (int i = 0; i < arr.size() - 2; i++) {

		count += searchPair(arr, target - arr[i], i);
	}


	return count;
}



int main() {

	Solution solution;

	std::vector<int> array1 = { -1, 0, 2, 3 };

	std::vector<int> array2 = { -1, 4, 2, 1, 3 };

	std::vector<int> array3 = { 2,0,0,2,-2 };

	std::vector<int> array4 = { 3,2,-2,6,2,-2,6,-2,-4,2,3,0,4,4,1 };

	int target = 3;

	std::cout << solution.searchTriplets(array4,target);




	//Time complexity: O(n^2)
	//Space complexity: O(n)
	//Time spent 2.5h

	return 0;
}