#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// Cấu trúc để lưu tọa độ ký túc xá
struct Dormitory {
    int x, y;
    
    // Hàm tính khoảng cách bình phương từ gốc O(0,0)
    double distance() const {
        return sqrt(x * x + y * y);
    }
};

// So sánh khoảng cách của hai ký túc xá
struct CompareDistance {
    bool operator()(const Dormitory& d1, const Dormitory& d2) {
        return d1.distance() > d2.distance();
    }
};

vector<Dormitory> findClosestDormitories(vector<Dormitory>& dormitories, int k) {
    priority_queue<Dormitory, vector<Dormitory>, CompareDistance> pq;

    // Đưa các ký túc xá vào hàng đợi
    for (const auto& dorm : dormitories) {
        pq.push(dorm);
        if (pq.size() > k) {
            pq.pop(); // Loại bỏ ký túc xá xa nhất
        }
    }

    // Lưu kết quả vào vector
    vector<Dormitory> closestDormitories;
    while (!pq.empty()) {
        closestDormitories.push_back(pq.top());
        pq.pop();
    }

    return closestDormitories;
}

int main() {
    vector<Dormitory> dormitories = {{1, 0}, {2, 1}, {3, 6}, {-5, 2}, {1, -4}};
    int k = 3;

    vector<Dormitory> closest = findClosestDormitories(dormitories, k);

    // In ra kết quả
    cout << "Ký túc xá gan nhat: \n";
    for (const auto& dorm : closest) {
        cout << "{" << dorm.x << ", " << dorm.y << "} ";
    }
    cout << endl;

    return 0;
}
