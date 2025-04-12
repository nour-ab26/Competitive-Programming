#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

// Function to compute factorial modulo MOD
std::vector<long long> computeFactorials(int n) {
    std::vector<long long> fact(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    return fact;
}

// Function to compute the number of valid ways to fill the table
long long countWays(int N, const std::vector<int>& A, const std::vector<int>& B) {
    int x = A.size(); // Size of A
    int y = B.size(); // Size of B
    int total = 2 * N; // Total numbers from 1 to 2*N
    
    // Create a boolean array to mark numbers in A and B
    std::vector<bool> used(total + 1, false);
    for (int num : A) used[num] = true;
    for (int num : B) used[num] = true;

    // Count how many numbers are left to be placed
    int freeCount = 0;
    for (int i = 1; i <= total; ++i) {
        if (!used[i]) freeCount++;
    }

    // The remaining positions in the table
    int remainingPositions = N - x + N - y; // Total positions minus fixed positions

    // If we don't have enough free numbers to fill the remaining positions, return 0
    if (freeCount < remainingPositions) return 0;

    // Compute factorials for combinations
    std::vector<long long> factorials = computeFactorials(freeCount);

    // The number of ways to choose positions for the free numbers
    long long result = factorials[freeCount] * factorials[remainingPositions] % MOD;
    result = result * factorials[freeCount - remainingPositions] % MOD;

    return result;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int N;
    std::cin >> N;

    int X;
    std::cin >> X;
    std::vector<int> A(X);
    for (int i = 0; i < X; ++i) {
        std::cin >> A[i];
    }

    int Y;
    std::cin >> Y;
    std::vector<int> B(Y);
    for (int i = 0; i < Y; ++i) {
        std::cin >> B[i];
    }

    long long result = countWays(N, A, B);
    std::cout << result << std::endl;

    return 0;
}