class Solution 
{
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
                return nums1[i];
            if(nums1[i] < nums2[j])
                i++;
            else 
                j++;
        }
        return -1;
    }
};