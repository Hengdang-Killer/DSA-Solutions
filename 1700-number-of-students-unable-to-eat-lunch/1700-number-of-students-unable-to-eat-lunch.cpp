class Solution 
{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = students.size(), circular = 0, square = 0;
        for(int &itr : students)
        {
            if(itr == 0)
                circular++;
            else
                square++;
        }
        for(int &itr : sandwiches)
        {
            if(itr == 0)
            {
                if(circular == 0)
                    break;
                circular--;
            }
            if(itr == 1)
            {
                if(square == 0)
                    break;
                square--;
            }
            ans--;
        }
        return ans;
    }
};