#include<iostream>
using namespace std;
void sapxep(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cout << "RED" << " ";
		}
		else if(a[i]==1) {
			cout << "WHITE" << " ";
		}
		else if (a[i] == 2) {
			cout << "BLUE" << " ";
		}
	}
}
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sapxep(a, n);
	return 0;
}
