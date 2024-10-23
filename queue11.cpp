#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<long long> findProductOfThreeLargest(const vector<int>& A) {
    vector<long long> result;
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        set<int> largest; // Sử dụng set để giữ ba số lớn nhất

        for (int j = 0; j <= i; ++j) {
            largest.insert(A[j]);
            // Giữ lại chỉ ba phần tử lớn nhất
            if (largest.size() > 3) {
                largest.erase(largest.begin()); // Xóa phần tử nhỏ nhất
            }
        }

        // Tính tích của ba số lớn nhất nếu có đủ ba số
        if (largest.size() == 3) {
            auto it = largest.rbegin(); // Bắt đầu từ phần tử lớn nhất
            long long product = 1;
            for (int k = 0; k < 3; ++k) {
                product *= *it; // Nhân tích
                ++it;
            }
            result.push_back(product);
        } else {
            result.push_back(0); // Nếu không có đủ ba số, trả 0
        }
    }

    return result;
}

int main() {
    vector<int> A = {3, 1, 2, 5, 4};

    vector<long long> products = findProductOfThreeLargest(A);

    // In ra kết quả
    for (long long prod : products) {
        cout << prod << " ";
    }
    cout << endl;

    return 0;
}
