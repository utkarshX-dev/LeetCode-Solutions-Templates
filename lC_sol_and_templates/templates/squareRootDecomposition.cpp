class NumArray {
public:
    vector<int> nums, blocks;
    int blockSize;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        blockSize = ceil(sqrt(nums.size()));
        blocks.resize(blockSize, 0);

        // built block array
        for (int i = 0; i < nums.size(); i++) {
            blocks[i / blockSize] += nums[i];
        }
    }

    void update(int idx, int val) {
        int block = idx / blockSize;
        blocks[block] += (val - nums[idx]);
        nums[idx] = val;
    }

    int sumRange(int l, int r) {
        int startBlock = l / blockSize;
        int endBlock = r / blockSize;
        if (startBlock == endBlock) { // single block
            int sum = 0;
            for (int i = l; i <= r; i++) { // T.C : O(root n)
                sum += nums[i];
            }
            return sum;
        } else { // multiple blocks
            // left block T.c: O(root n)
            int sum = 0;
            int endofStartBlock = ((startBlock + 1) * blockSize) - 1;
            for (int i = l; i <= endofStartBlock; i++) {
                sum += nums[i];
            }
            // middle blocks in constant time T.C: O(root n)
            for (int i = startBlock + 1; i <= endBlock - 1; i++) {
                sum += blocks[i];
            }
            // right blocks O(root n)
            int startofEndBlock = (endBlock)*blockSize;
            for (int i = startofEndBlock; i <= r; i++) {
                sum += nums[i];
            }
            return sum;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */