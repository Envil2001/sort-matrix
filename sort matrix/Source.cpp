#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;
const int n = 3, m = 3;

int main() {
	setlocale(LC_ALL, "ru");
	int** Arr;
	Arr = new int* [n]; // объявляем указатель на динамический массив типа int и размера n.
	int k = 0, sum = 0;
	for (int i = 0; i < n; i++) { //инициализация массива
		for (int j = 0; j < m; j++) {
			Arr[i] = new int[m];
		}
	}
	for (int i = 0; i < n; i++) { //Ввод элементов
		for (int j = 0; j < m; j++) {
			cout << "Введите [" << i << "][" << j << "] элемент: ";
			cin >> Arr[i][j];
		}
	}
	cout << endl;
	cout << "Ваш массив: " << endl;
	for (int i = 0; i < n; i++) { //Вывод элементов
		for (int j = 0; j < m; j++) {
			cout << setw(5) << Arr[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < n - 1; i++) {//запускаем цикл по массиву
		for (int k = 0; k < n - 1; k++) {
			if (Arr[k][0] > Arr[k + 1][0]) {//проверяем текущий первый элемент со следующим. если текущий больше - нужно поменять местами
				for (int j = 0; j < m; j++) {//запускаешь сортировку
					int b = Arr[k][j];//временной переменной присваиваешь текущий
					Arr[k][j] = Arr[k + 1][j];//текущему присваеваем следующий
					Arr[k + 1][j] = b;//следующему присваеваем значение предыдущего которое хранится во временной переменной
				}
			}
		}
	}
	cout << endl;
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < n; i++) { //Вывод элементов
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