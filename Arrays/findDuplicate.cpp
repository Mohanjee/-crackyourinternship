//brute force 
int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                if(nums[i]== nums[j]){
                    return nums[i];
                }
            }
        }
        return -1;
    }
//T(n) : O(n^2)
//S(n) : O(1)

//Better
 int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n;i++){
            if(nums[i] == nums[i+1]) return nums[i];
        }
        return -1;
    }
//T(n) : O(nlogn)
//S(n) : O(1)

//Optimal 
int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
//T(n) : O(n)
//S(n) : O(1)
