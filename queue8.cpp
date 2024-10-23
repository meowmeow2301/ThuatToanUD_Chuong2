#include <iostream>
#include <queue>
using namespace std;

int findFirstElementAfterNMoves(int N) {
    queue<int> q;
    
    // Khởi tạo queue với các phần tử 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    // Thực hiện N lượt chơi
    for (int i = 0; i < N; i++) {
        int front = q.front();  // Lấy phần tử đầu queue
        q.pop();  // Xóa phần tử đầu
        q.push(front);  // Đưa phần tử đó xuống cuối queue
        q.push(front);  // Đưa thêm một lần nữa xuống cuối queue
    }

    // Phần tử đầu tiên của queue sau N lượt chơi
    return q.front();
}

int main() {
    int N;
    cout << "Nhap so luot choi N: ";
    cin >> N;

    int result = findFirstElementAfterNMoves(N);
    cout << "Phan tu dau tien cua queue sau " << N << " luot choi la: " << result << endl;

    return 0;
}
