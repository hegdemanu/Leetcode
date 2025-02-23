class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false; // Perfect numbers are greater than 1

        int sum = 1; // Start with 1 (a divisor of all numbers)
        for (int i = 2; i * i <= num; i++) { // Iterate up to the square root
            if (num % i == 0) {
                sum += i; // Add the divisor
                if (i != num / i) { // Add the complementary divisor
                    sum += num / i;
                }
            }
        }
        return sum == num; // Check if sum equals the number
    }
};
