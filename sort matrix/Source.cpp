#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;
const int n = 3, m = 3;

int main() {
	setlocale(LC_ALL, "ru");
	int** Arr;
	Arr = new int* [n]; // ��������� ��������� �� ������������ ������ ���� int � ������� n.
	int k = 0, sum = 0;
	for (int i = 0; i < n; i++) { //������������� �������
		for (int j = 0; j < m; j++) {
			Arr[i] = new int[m];
		}
	}
	for (int i = 0; i < n; i++) { //���� ���������
		for (int j = 0; j < m; j++) {
			cout << "������� [" << i << "][" << j << "] �������: ";
			cin >> Arr[i][j];
		}
	}
	cout << endl;
	cout << "��� ������: " << endl;
	for (int i = 0; i < n; i++) { //����� ���������
		for (int j = 0; j < m; j++) {
			cout << setw(5) << Arr[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < n - 1; i++) {//��������� ���� �� �������
		for (int k = 0; k < n - 1; k++) {
			if (Arr[k][0] > Arr[k + 1][0]) {//��������� ������� ������ ������� �� ���������. ���� ������� ������ - ����� �������� �������
				for (int j = 0; j < m; j++) {//���������� ����������
					int b = Arr[k][j];//��������� ���������� ������������ �������
					Arr[k][j] = Arr[k + 1][j];//�������� ����������� ���������
					Arr[k + 1][j] = b;//���������� ����������� �������� ����������� ������� �������� �� ��������� ����������
				}
			}
		}
	}
	cout << endl;
	cout << "��������������� ������: " << endl;
	for (int i = 0; i < n; i++) { //����� ���������
		for (int j = 0; j < m; j++) {
			cout << setw(5) << Arr[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		delete[] Arr[i];
	}
	delete[]Arr;
	return 0;
}