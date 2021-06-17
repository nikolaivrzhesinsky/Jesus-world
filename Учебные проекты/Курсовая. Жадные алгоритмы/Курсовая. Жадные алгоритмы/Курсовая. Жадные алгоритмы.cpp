#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void max_number() {
	int zifra;
	vector<int>set_massiv_of_numbers;
	cout << "Заполните массив случайными цифрами (-1 это выход из заполнения)\n";//кнопка остановки -1
	int i = 0;//счетчик для вектора
	while (true) {
		cin >> zifra;
		if (zifra == -1) {
			break;
		}

		if ((zifra >= 0) && (zifra < 10)) {
			set_massiv_of_numbers.push_back(zifra);
			i++;
		}
	}
	system("cls");
	cout << "Исходный массив: ";
	for (auto const& element : set_massiv_of_numbers)
		cout << element << ' ';
	sort(set_massiv_of_numbers.begin(), set_massiv_of_numbers.end());  // сортировка
	cout << "\n";
	cout << "Наибольшее возможное число: ";
	for (i = set_massiv_of_numbers.size() - 1; i >= 0; i--) {

		cout << set_massiv_of_numbers.at(i);
	}
}
void bag_pack() {
	class Item {
	private:
		int weight;
		int value;
	public:
		Item()
		{
			weight = value = 0;
		}
		/*Item(int weight, int value) {
			this->weight = weight;
			this->value = value;
		}*/
		void set_Item(int weight, int value) {
			this->weight = weight;
			this->value = value;
		}
		int get_weight() {
			return weight;
		}
		int get_value() {
			return value;
		}
		string get_info() {
			return " Item: weight=" + to_string(weight) + " value=" + to_string(value);
		}
		double value_per_weight() {
			return((double)value / weight);
		}

	};
	const int Lenght = 3;
	Item array[Lenght];
	int weight, value;
	cout << "Введите данные каждого предмета (вес, ценность)\n";
	for (int i = 0; i < Lenght; i++) {
		cin >> weight >> value;
		array[i].set_Item(weight, value);
	}
	
	system("cls");
	cout << "Отсортировано по удельной полезности \n";
	for (int i = 0; i < Lenght; i++) {
		for (int j = 0; j < (Lenght - 1); j++) {
			if (array[j].value_per_weight() < array[j + 1].value_per_weight()) {
				std::swap(array[j], array[j + 1]);

			}
		}
	}
	for (int i = 0; i < Lenght; i++) {
		cout << i + 1 << array[i].get_info() << endl;
	}
	cout << "Введтье вместимость рюкзака: ";
	int Size_of_bag;
	cin >> Size_of_bag;
	int sum_weight = 0;
	double sum_value = 0;
	int current_Item=0;
	while (current_Item < Lenght && sum_weight < Size_of_bag) {
		if (sum_weight + array[current_Item].get_weight() < Size_of_bag) {
			sum_value += array[current_Item].get_value();
			sum_weight += array[current_Item].get_weight();
		}
		else {
			sum_value += (((Size_of_bag - sum_weight) / (double)array[current_Item].get_weight()) * array[current_Item].get_value());
			sum_weight = Size_of_bag;
		}
		current_Item++;
	}
	cout << "Наибольшее значение, которое мы можем собрать-" << sum_value << endl;
}
void algoritm_Deyckstr() {
	int n, temp, start, temp_index, index;
	cout << "Количество вершин в графе > ";
	cin >> n;
	int** GR;
	GR = new int* [n];//создание двумерного массива для весов ребер нашего графа
	for (int i = 0; i < n; i++) {
		GR[i] = new int[n];     // инициализация 
	}
	for (int i = 0; i < n; i++)
	{
		GR[i][i] = 0;
		for (int j = i + 1; j < n; j++) {
			cout << "GR[" << i + 1 << "][" << j + 1 << "] > ";
			cin >> temp;
			GR[i][j] = temp;
			GR[j][i] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << GR[i][j] << " ";
		}
		cout << endl;
	}
	start = 0;
	int* route = new int[n];
	bool* visit = new bool[n];
	for (int i = 0; i < n; i++)
	{
		route[i] = INT_MAX; 
		visit[i] = false;
	}
	route[start] = 0;
	for (int count = 0; count < n; count++) {
		int min = INT_MAX;
		for (int i = 0; i < n; i++)
			if (!visit[i] && route[i] <= min)//находим минимальную дистанцию до еще не пройденого этапа (локальный оптимум)
			{
				min = route[i]; 
				index = i;
			}
		temp_index = index;
		visit[temp_index] = true;//посетил новую точку с минимальной дистанцией от прошлой
		for (int i = 0; i < n; i++) {
			if (!visit[i] && GR[temp_index][i] && route[temp_index] != INT_MAX &&
				route[temp_index] + GR[temp_index][i] < route[i]) {
				route[i] = route[temp_index] + GR[temp_index][i];
			}
		}
	}
	cout << "Кратчайшие растояния из начальной точки до конечной\n";
	for (int i = 0; i < n; i++) {
		if (route[i] != INT_MAX)
			cout << start+1 << " > " << i + 1 << " = " << route[i] << endl;
		else cout << start + 1 << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
	}






}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	char tap_continue;
	cout << "              Министерство образования и Науки Российской Федерации\n";
	cout << "                      федеральное государственное бюджетное\n";
	cout << "                  образовательное учреждение высшего образования\n";
	cout << "           «Российский экономический университет имени  Г.В. Плеханова» \n";
	cout << "\n\n           Институт математики, информационных систем и цифровой экономики \n";
	cout << "\n\n  Базовая кафедра цифровой экономики института развития информационного общества \n";
	cout << "\n\n\n\n\n                         КУРСОВАЯ РАБОТА\n";
	cout << "\n\n\n      по дисциплине «Структуры и алгоритмы компьютерной обработки данных»\n";
	cout << "\n\n\n                        на тему «Жадные алгоритмы\n";
	cout << "\n\n\n                                                     Выполнил\n";
	cout << "                                                     Студент группы 4112\n";
	cout << "                                                     Очной формы обучения\n";
	cout << "                                                        ИМИСиЦЭ\n";
	cout << "                                                     Зотин Николай\n";
	cout << "                                                     Научный руководитель:\n";
	cout << "                                                     к.э.н., доцент Комлева Н.В..\n";
	cout << "\n\n\n\n\n\n                           Москва 2021\n";
	cout << "\n\n                            Нажмите любой символ  чтобы продолжить.\n";
	cin >> tap_continue;
	system("cls");
	cout << "\n Надеюсь, что стерлось";
	int exit = 1;
	int operation;
	while (exit == 1) {
		cout << "\n\n\n           Меню выбора действий\n";
		cout << "\n Выберите номер той команды, которую надо выполнить\n";
		cout << "\n1.   Задача о максимальном числе\n";
		cout << "\n2.   Задача о рюкзаке\n";
		cout << "\n3.   Алгоритм Дейкстры\n";
		cout << "\n0.   Выйти из программы\n";
		operation = 0;
		cin >> operation;
		switch (operation) {
		case 1:
		{
			system("cls");
			max_number();
			break;

		}
		case 2:
		{
			system("cls");
			bag_pack();
			break;
		}
		case 3:
		{
			system("cls");
			algoritm_Deyckstr();
			break;
		}
		case 0:
		{
			system("cls");
			cout << "\nПроверка: Вы действительно хотите выйти из программы? Нажмите нужную цифру\n";
			cout << "1-остаться в программе\n";
			cout << "0-выйти из прогрпммы, прощайте\n";
			cin >> exit;
			system("cls");
			break;
		}
		default:
		{
			system("cls");
			cout << "\nВы ввели номер операции, которой в программе нет\n";
			break;
		}


		}
	}

	return 0;
}