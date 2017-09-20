class Solution {
public:
    int findComplement(int num) {
        int ans = 1;
        while (ans < num)
            ans = ans * 2 + 1;
        return ans ^ num;
    }
};
