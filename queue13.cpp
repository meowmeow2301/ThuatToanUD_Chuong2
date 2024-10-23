#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int sumOfMinAndMaxInSlidingWindow(const vector<int>& arr, int k) {
    int totalSum = 0;
    deque<int> maxDeque; // Hàng đợi cho số lớn nhất
    deque<int> minDeque; // Hàng đợi cho số nhỏ nhất

    for (int i = 0; i < arr.size(); ++i) {
        // Xóa các phần tử nhỏ hơn phần tử hiện tại khỏi maxDeque
        while (!maxDeque.empty() && arr[maxDeque.back()] <= arr[i]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(i);

        // Xóa các phần tử lớn hơn phần tử hiện tại khỏi minDeque
        while (!minDeque.empty() && arr[minDeque.back()] >= arr[i]) {
            minDeque.pop_back();
        }
        minDeque.push_back(i);

        // Xóa phần tử ra ngoài khoảng kích thước k
        if (maxDeque.front() <= i - k) {
            maxDeque.pop_front();
        }
        if (minDeque.front() <= i - k) {
            minDeque.pop_front();
        }

        // Tính tổng khi đã đủ phần tử trong cửa sổ
        if (i >= k - 1) {
            int maxVal = arr[maxDeque.front()]; // Số lớn nhất
            int minVal = arr[minDeque.front()]; // Số nhỏ nhất
            totalSum += minVal + maxVal; // Cộng vào tổng
        }
    }

    return totalSum;
}

int main() {
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    int total = sumOfMinAndMaxInSlidingWindow(arr, k);
    cout << "Tong các so nho nhat và lon nhat là: " << total << endl;

    return 0;
}
