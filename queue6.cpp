#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Hàm tìm phần tử âm đầu tiên trong các cửa sổ k phần tử
vector<int> firstNegative(vector<int>& arr, int k) {
    vector<int> result;
    queue<int> negatives;  // Hàng đợi chứa các chỉ số của phần tử âm

    // Xử lý các cửa sổ đầu tiên
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            negatives.push(i);  // Lưu chỉ số phần tử âm
        }
    }

    // Thêm phần tử âm đầu tiên của cửa sổ đầu tiên vào kết quả
    if (!negatives.empty()) {
        result.push_back(arr[negatives.front()]);
    } else {
        result.push_back(0);
    }

    // Duyệt qua các cửa sổ còn lại
    for (int i = k; i < arr.size(); i++) {
        // Loại bỏ các phần tử âm không còn trong cửa sổ
        if (!negatives.empty() && negatives.front() <= i - k) {
            negatives.pop();
        }

        // Thêm chỉ số của phần tử âm mới nếu có
        if (arr[i] < 0) {
            negatives.push(i);
        }

        // Thêm phần tử âm đầu tiên trong cửa sổ hiện tại vào kết quả
        if (!negatives.empty()) {
            result.push_back(arr[negatives.front()]);
        } else {
            result.push_back(0);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    
    vector<int> result = firstNegative(arr, k);
    
    cout << "Cac phan tu am dau tien trong moi cua so kich thuoc " << k << " la: ";
    for (int x : result) {
        cout << x << " ";
    }
    
    return 0;
}
