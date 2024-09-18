class Solution 
{
private:
    bool compare(int &firstNum, int &secondNum) 
    {
        return to_string(firstNum) + to_string(secondNum) > to_string(secondNum) + to_string(firstNum);
    }
    vector<int> merge(vector<int>& leftHalf, vector<int>& rightHalf) 
    {
        vector<int> sortedNums;
        int leftIndex = 0, rightIndex = 0;
        while (leftIndex < leftHalf.size() && rightIndex < rightHalf.size()) 
        {
            if (compare(leftHalf[leftIndex], rightHalf[rightIndex]))
                sortedNums.push_back(leftHalf[leftIndex++]);
            else 
                sortedNums.push_back(rightHalf[rightIndex++]);
        }
        while (leftIndex < leftHalf.size())
            sortedNums.push_back(leftHalf[leftIndex++]);
        while (rightIndex < rightHalf.size())
            sortedNums.push_back(rightHalf[rightIndex++]);
        return sortedNums;
    }
    vector<int> mergeSort(vector<int>& nums, int left, int right) 
    {
        if (left >= right) 
            return {nums[left]};
        int mid = left + (right - left) / 2;
        vector<int> leftHalf = mergeSort(nums, left, mid);
        vector<int> rightHalf = mergeSort(nums, mid + 1, right);
        return merge(leftHalf, rightHalf);
    }
public:
    string largestNumber(vector<int>& nums) {
        nums = mergeSort(nums, 0, nums.size() - 1);
        string largestNum = "";
        for (int &num : nums) 
            largestNum += to_string(num);
        return largestNum[0] == '0' ? "0" : largestNum;
    }
};