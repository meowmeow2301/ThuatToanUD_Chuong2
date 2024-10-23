#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxInSlidingWindow(const vector<int>& arr, int k) {
    vector<int> result;
    deque<int> dq; // Hàng đợi để lưu trữ các chỉ số

    for (int i = 0; i < arr.size(); ++i) {
        // Xóa các phần tử nhỏ hơn phần tử hiện tại
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        // Thêm chỉ số hiện tại vào deque
        dq.push_back(i);

        // Xóa phần tử ra ngoài khoảng kích thước k
        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        // Khi chúng ta đã có đủ phần tử trong cửa sổ
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]); // Phần tử lớn nhất
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;

    vector<int> maxValues = maxInSlidingWindow(arr, k);

    // In ra kết quả
    for (int val : maxValues) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
