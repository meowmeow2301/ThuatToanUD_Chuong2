#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Cấu trúc lưu tọa độ (i, j) và thời gian cam bị hỏng
struct Cell {
    int x, y, time;
};

// Kiểm tra xem tọa độ có nằm trong ma trận hay không
bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

int rotOrange(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    queue<Cell> q;  // Hàng đợi để lưu các cam bị hỏng
    int freshCount = 0;  // Đếm số lượng cam tươi
    
    // Duyệt qua ma trận, thêm cam hỏng vào hàng đợi và đếm cam tươi
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 2) {
                q.push({i, j, 0});  // Đẩy cam hỏng vào queue với thời gian 0
            } else if (matrix[i][j] == 1) {
                freshCount++;  // Đếm số lượng cam tươi
            }
        }
    }

    // Nếu không có cam tươi nào, trả về 0
    if (freshCount == 0) return 0;

    // Các hướng di chuyển trong ma trận: lên, xuống, trái, phải
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int timeToRot = 0;  // Biến lưu thời gian hỏng
    int rottenOranges = 0;  // Số lượng cam đã bị hỏng

    // Duyệt BFS
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        // Duyệt 4 hướng của ô hiện tại
        for (int k = 0; k < 4; k++) {
            int newX = current.x + dx[k];
            int newY = current.y + dy[k];

            // Nếu tọa độ hợp lệ và là cam tươi, chuyển nó thành cam hỏng
            if (isValid(newX, newY, rows, cols) && matrix[newX][newY] == 1) {
                matrix[newX][newY] = 2;  // Cam tươi bị hỏng
                rottenOranges++;  // Tăng số lượng cam bị hỏng
                q.push({newX, newY, current.time + 1});  // Đẩy vào hàng đợi với thời gian tăng lên
                timeToRot = current.time + 1;  // Cập nhật thời gian hỏng
            }
        }
    }

    // Nếu tất cả cam tươi đã bị hỏng, trả về thời gian, nếu không trả về -1
    return (rottenOranges == freshCount) ? timeToRot : -1;
}

int main() {
    vector<vector<int>> matrix = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}
    };

    int result = rotOrange(matrix);
    cout << "Thoi gian toi thieu de tat ca cam bi hong: " << result << endl;

    return 0;
}
