#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <climits> // Thêm thư viện này để sử dụng INT_MIN

using namespace std;

// Bài 14: Thống kê tần suất xuất hiện của từng phần tử
void countFrequency(const vector<int>& arr) {
    map<int, int> frequency;
    for (int num : arr) {
        frequency[num]++;
    }
    for (const auto& entry : frequency) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

// Bài 15: Tìm những phần tử có tần suất xuất hiện nhiều nhất
vector<int> mostFrequentElements(const vector<int>& arr) {
    map<int, int> frequency;
    int maxFreq = 0;
    for (int num : arr) {
        frequency[num]++;
        maxFreq = max(maxFreq, frequency[num]);
    }
    vector<int> result;
    for (const auto& entry : frequency) {
        if (entry.second == maxFreq) {
            result.push_back(entry.first);
        }
    }
    return result;
}

// Bài 16: Đếm ký tự và số lần xuất hiện của nó
vector<string> countCharacterFrequency(const string& s) {
    map<char, int> frequency;
    for (char ch : s) {
        frequency[ch]++;
    }
    vector<string> result;
    for (const auto& entry : frequency) {
        result.push_back(string(1, entry.first) + " " + to_string(entry.second));
    }
    return result;
}

// Bài 17: Sửa đổi chuỗi theo quy tắc
string modifyString(const string& s) {
    map<char, int> frequency;
    for (char ch : s) {
        frequency[ch]++;
    }
    vector<pair<char, int>> charFreq(frequency.begin(), frequency.end());
    sort(charFreq.begin(), charFreq.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second; // Sắp xếp theo tần suất
        }
        return a.first < b.first; // Sắp xếp theo thứ tự từ điển
    });
    string result;
    for (const auto& p : charFreq) {
        result += p.first;
    }
    return result;
}

// Bài 18: Tính tổng những số xuất hiện trong cả hai dãy
int sumOfCommon(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> set2(arr2.begin(), arr2.end());
    int sum = 0;
    for (int num : set2) {
        if (set1.count(num)) {
            sum += num;
        }
    }
    return sum;
}

// Bài 19: Kiểm tra xem có tồn tại hai số có tổng bằng sum
bool checkSum(const vector<int>& arr, int sum) {
    unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(sum - num)) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

// Bài 20: Số lớn nhất trong những số có tần số bé nhất
int largestElement(const vector<int>& arr) {
    map<int, int> frequency;
    for (int num : arr) {
        frequency[num]++;
    }
    int minFreq = INT_MAX;
    for (const auto& entry : frequency) {
        minFreq = min(minFreq, entry.second);
    }
    int largest = INT_MIN; // Sử dụng INT_MIN
    for (const auto& entry : frequency) {
        if (entry.second == minFreq) {
            largest = max(largest, entry.first);
        }
    }
    return largest;
}

// Bài 21: Đếm xem tên này là prefix của bao nhiêu tên trong danh bạ
vector<int> countPrefix(const vector<string>& contacts, const vector<string>& names) {
    vector<int> result;
    for (const string& name : names) {
        int count = 0;
        for (const string& contact : contacts) {
            if (contact.find(name) == 0) {
                count++;
            }
        }
        result.push_back(count);
    }
    return result;
}

// Bài 22: Nhập các sản phẩm từ kho B vào kho A
vector<bool> mergeProducts(const vector<string>& A, const vector<string>& B) {
    unordered_set<string> setA(A.begin(), A.end());
    vector<bool> result;
    for (const string& product : B) {
        if (setA.count(product)) {
            result.push_back(false);
        } else {
            result.push_back(true);
            setA.insert(product);
        }
    }
    return result;
}

int main() {
    // Bài 14
    vector<int> arr14 = {4, 7, 2, 8, 4, 8, 3, 2};
    cout << "Bai 14: Thong ke tan suat:\n";
    countFrequency(arr14);

    // Bài 15
    vector<int> arr15 = {4, 7, 2, 8, 4, 8, 3, 2};
    cout << "Bai 15: Phan tu tan suat cao nhat:\n";
    vector<int> mostFrequent = mostFrequentElements(arr15);
    for (int num : mostFrequent) {
        cout << num << " ";
    }
    cout << endl;

    // Bài 16
    string s16 = "aacccd";
    cout << "Bai 16: Tan suat ky tu:\n";
    vector<string> charCount = countCharacterFrequency(s16);
    for (const string& str : charCount) {
        cout << str << " ";
    }
    cout << endl;

    // Bài 17
    string s17 = "codelearn";
    cout << "Bai 17: Chuoi da sua doi:\n" << modifyString(s17) << endl;

    // Bài 18
    vector<int> arr18_1 = {6, 7, 5, 4, 6, 8};
    vector<int> arr18_2 = {2, 5, 7, 5, 3};
    cout << "Bai 18: Tong cac so chung:\n" << sumOfCommon(arr18_1, arr18_2) << endl;

    // Bài 19
    vector<int> arr19 = {2, 4, -1, 9, 8};
    int sum19 = 6;
    cout << "Bai 19: Co ton tai hai so co tong bang " << sum19 << ":\n" << (checkSum(arr19, sum19) ? "true" : "false") << endl;

    // Bài 20
    vector<int> arr20 = {2, 2, 4, 4, 7, 7, 7};
    cout << "Bai 20: So lon nhat trong so co tan suat be nhat:\n" << largestElement(arr20) << endl;

    // Bài 21
    vector<string> contacts21 = {"Codelearn", "Codewar"};
    vector<string> names21 = {"Code", "Codel", "io"};
    cout << "Bai 21: Dem prefix:\n";
    vector<int> prefixCounts = countPrefix(contacts21, names21);
    for (int count : prefixCounts) {
        cout << count << " ";
    }
    cout << endl;

    // Bài 22
    vector<string> A22 = {"Banana", "Banana", "Apple"};
    vector<string> B22 = {"Orange", "Apple", "Banana", "Watermelon"};
    cout << "Bai 22: Ket qua merge products:\n";
    vector<bool> mergeResult = mergeProducts(A22, B22);
    for (bool res : mergeResult) {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
