#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool songuyento(int n) {
    if (n < 2) return false;
    if (n % 4 != 3) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm tạo mảng các số Blum nhỏ hơn N
int mangcacsoblum(int b[], int N) {
    int count = 0;
    for (int i = 2; i <= sqrt(N); i++) {
        if (songuyento(i)) {
            for (int j = i; j <= sqrt(N); j++) {
                if (songuyento(j)) {
                    int blum = i * j;
                    if (blum < N) {
                        b[count++] = blum;
                    }
                }
            }
        }
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (b[i] > b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    int uniqueCount = 1;
    for (int i = 1; i < count; i++) {
        if (b[i] != b[uniqueCount - 1]) {
            b[uniqueCount++] = b[i];
        }
    }
    return uniqueCount;
}

// Hàm tìm các cặp số Blum có tổng là số Blum nhỏ hơn N
void timkiem(int b[], int size, int N) {
    cout << "Các cặp số Blum có tổng cũng là số Blum nhỏ hơn " << N << ":\n";
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int sum = b[i] + b[j];
            if (sum < N) {
                bool found = false;
                for (int k = 0; k < size; k++) {
                    if (b[k] == sum) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    cout << "(" << b[i] << ", " << b[j] << ") ";
                }
            }
        }
    }
    cout << endl;
}

// Hàm kiểm tra xem số Blum M có tồn tại trong mảng không
bool kiemtra(int b[], int size, int M) {
    for (int i = 0; i < size; i++) {
        if (b[i] == M) {
            return true;
        }
    }
    return false;
}

int main() {
    int N, M;
    cout << "Nhập số N: ";
    cin >> N;
    cout << "Nhập số Blum: ";
    cin >> M;

    
    int b[1000];
    int size = mangcacsoblum(b, N);

    
    cout << "Các số Blum nhỏ hơn " << N << " là:\n";
    for (int i = 0; i < size; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

   
    timkiem(b, size, N);

   
    if (kiemtra(b, size, M)) {
        cout << "Số Blum " << M << " có tồn tại trong mảng.\n";
    }2
    else {
        cout << "Số Blum " << M << " không tồn tại trong mảng.\n";
    }

    return 0;
}
