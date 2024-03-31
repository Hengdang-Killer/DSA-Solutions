const int mod = 1e9+7;
const int N = 50;

int dp[N+1][N+1][N+1][1230];
set<int> st;
map<int, int> mp1, mp2;
class Solution {
public:
    int sumOfPowers(vector<int>& arr, int k) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        st.clear();
        mp1.clear();
        mp2.clear();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                st.insert(arr[j] - arr[i]);
            }
        }
        int idx = 0;
        for(int x: st){
            mp1[x] = idx;
            mp2[idx++] = x;
        }
        mp1[1e9] = idx;
        mp2[idx] = 1e9;
        
        
        auto rec = [&](int i, int prv, int cnt, int mn, auto &&rec)->int{
            if(cnt == k){
                if(mn != idx) return mp2[mn];
                return 0;
            }
            if(i == n)
                return 0;
            
            int &ans = dp[i][prv+1][cnt][mn];
            
            if(ans != -1) return dp[i][prv+1][cnt][mn];
            
            ans = rec(i+1, prv, cnt, mn, rec);
            
            if(prv == -1){
                ans += rec(i+1, i, 1, idx, rec);
            }else{
                int pv = arr[prv];
                int cv = arr[i];
                int diff = cv - pv;
                if(diff < mp2[mn]){
                    ans += rec(i+1, i, cnt+1, mp1[diff], rec);
                }else{
                    ans += rec(i+1, i, cnt+1, mn, rec);
                }
            }
            ans %= mod;
            
            return ans;
        };
 
        for(int i = 0; i<=n; i++)
            for(int j = 0; j<=n; j++)
                for(int jk = 0; jk<=k; jk++)
                    for(int ik = 0; ik<=idx+1; ik++)
                        dp[i][j][jk][ik] = -1;

        return rec(0, -1, 0, idx, rec);
    }
};