#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    queue<int> stationQueue;
    int n = gas.size();
    
    // Đưa tất cả các trạm xăng vào queue
    for (int i = 0; i < n; ++i) {
        stationQueue.push(i);
    }
    
    // Duyệt qua từng trạm trong hàng đợi
    while (!stationQueue.empty()) {
        int start = stationQueue.front(); // Trạm xăng đầu tiên trong queue
        stationQueue.pop(); // Xóa trạm này khỏi queue
        
        int current_tank = 0;
        bool can_complete = true; // Biến kiểm tra liệu có thể hoàn thành hành trình từ trạm này không
        
        // Kiểm tra từ trạm start qua tất cả các trạm còn lại
        for (int i = 0; i < n; ++i) {
            int current_station = (start + i) % n; // Trạm hiện tại theo vòng tròn
            current_tank += gas[current_station] - cost[current_station]; // Cập nhật lượng xăng
            
            if (current_tank < 0) { // Nếu không đủ xăng để đi tiếp
                can_complete = false;
                break;
            }
        }
        
        // Nếu hoàn thành được hành trình từ trạm này
        if (can_complete) {
            return start; // Trả về trạm bắt đầu
        }
    }
    
    // Nếu không tìm được trạm nào
    return -1;
}

int main() {
    vector<int> gas = {4, 6, 7, 4};
    vector<int> cost = {6, 5, 3, 5};

    int start = canCompleteCircuit(gas, cost);

    if (start != -1) {
        cout << "Start = " << start << endl;
    } else {
        cout << "Không thể thực hiện chuyến đi." << endl;
    }

    return 0;
}
