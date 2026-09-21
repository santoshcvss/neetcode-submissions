class Solution {
    public:
        int getSum(int a, int b) {
                int ans = 0;
                        int carry = 0;

                                for (int i = 0; i < 32; i++) {
                                            int ai = (a >> i) & 1;
                                                        int bi = (b >> i) & 1;

                                                                    int sum = ai ^ bi ^ carry;
                                                                                ans |= (sum << i);

                                                                                            carry = (ai & bi) | (ai & carry) | (bi & carry);
                                                                                                    }

                                                                                                            return ans;
                                                                                                                }
                                                                                                                };