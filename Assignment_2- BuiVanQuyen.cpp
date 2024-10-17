#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố dạng 4k + 3
bool isBlumPrime(int num) {
    if (num < 2) return false;
    if (num % 4 != 3) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tạo mảng các số Blum nhỏ hơn N
int generateBlumNumbers(int blumNumbers[], int N) {
    int count = 0;
    for (int i = 2; i <= sqrt(N); i++) {
        if (isBlumPrime(i)) {
            for (int j = i; j <= sqrt(N); j++) {
                if (isBlumPrime(j)) {
                    int blum = i * j;
                    if (blum < N) {
                        blumNumbers[count++] = blum;
                    }
                }
            }
        }
    }
    // Sắp xếp mảng theo thứ tự tăng dần và loại bỏ trùng lặp
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (blumNumbers[i] > blumNumbers[j]) {
                int temp = blumNumbers[i];
                blumNumbers[i] = blumNumbers[j];
                blumNumbers[j] = temp;
            }
        }
    }
    int uniqueCount = 1;
    for (int i = 1; i < count; i++) {
        if (blumNumbers[i] != blumNumbers[uniqueCount - 1]) {
            blumNumbers[uniqueCount++] = blumNumbers[i];
        }
    }
    return uniqueCount;
}

// Hàm tìm các cặp số Blum có tổng là số Blum nhỏ hơn N
void findBlumPairs(int blumNumbers[], int size, int N) {
    cout << "Các cặp số Blum có tổng cũng là số Blum nhỏ hơn " << N << ":\n";
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int sum = blumNumbers[i] + blumNumbers[j];
            if (sum < N) {
                bool found = false;
                for (int k = 0; k < size; k++) {
                    if (blumNumbers[k] == sum) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    cout << "(" << blumNumbers[i] << ", " << blumNumbers[j] << ") ";
                }
            }
        }
    }
    cout << endl;
}

// Hàm kiểm tra xem số Blum M có tồn tại trong mảng không
bool checkBlumExists(int blumNumbers[], int size, int M) {
    for (int i = 0; i < size; i++) {
        if (blumNumbers[i] == M) {
            return true;
        }
    }
    return false;
}

int main() {
    int N, M;
    cout << "Nhập số N: ";
    cin >> N;
    cout << "Nhập số Blum M để kiểm tra: ";
    cin >> M;

    // Mảng tĩnh để lưu số Blum, giả sử tối đa 1000 số
    int blumNumbers[1000];
    int size = generateBlumNumbers(blumNumbers, N);

    // In các số Blum
    cout << "Các số Blum nhỏ hơn " << N << " là:\n";
    for (int i = 0; i < size; i++) {
        cout << blumNumbers[i] << " ";
    }
    cout << endl;

    // Tìm và in các cặp số Blum có tổng cũng là số Blum
    findBlumPairs(blumNumbers, size, N);

    // Kiểm tra số Blum M có trong mảng không
    if (checkBlumExists(blumNumbers, size, M)) {
        cout << "Số Blum " << M << " có tồn tại trong mảng.\n";
    }
    else {
        cout << "Số Blum " << M << " không tồn tại trong mảng.\n";
    }

    return 0;
}
