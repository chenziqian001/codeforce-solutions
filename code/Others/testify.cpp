#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


long long calculate_R(int n) {
    if (n <= 0) return 0;

    vector<long long> sums;
    sums.reserve(1 << n); // ⭐ 防止reallocate导致 UB
    sums.push_back(0);

    for (int i = 1; i <= n; ++i) {
        size_t current_size = sums.size();
        for (size_t j = 0; j < current_size; ++j) {
            sums.push_back(sums[j] + i);
        }
    }

    long long result = 0;
    for (long long x : sums) result ^= x;
    return result;
}


int main() {
    // 设定最大验证范围。n=16时有 32,768 个和，计算速度很快。
    const int MAX_N = 32; 

    // 优化输入/输出
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    for (int n = 1; n <= MAX_N; ++n) {
        long long R_n = calculate_R(n);
        cout<<"n: "<<n<<" "<<"R_n: "<<R_n<<'\n';
    }
    system("pause");
    return 0;
}