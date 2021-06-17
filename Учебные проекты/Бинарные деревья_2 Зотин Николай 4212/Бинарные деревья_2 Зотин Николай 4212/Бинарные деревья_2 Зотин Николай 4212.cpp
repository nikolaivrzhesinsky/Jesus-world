#include <iostream>
#include<iostream>
#include <string>
#include <stdio.h>
using namespace std;
struct Node {
	int key;
	Node* left;
	Node* rihgt;
};
class tree {
public:
	tree() {//создание дерева
		root = NULL;
	}
	void set_newnode();
	void print_tree();
	void delete_tree();
	int counter = 0;
	void show_counter();
	void delete_i();
	void straight_obhod();
	void simetric_obhod();
	void back_obhod();
private:

	void straight_obhod(Node* order);
	void simetric_obhod(Node* order);
	void back_obhod(Node* order);
	void delete_i(int v_key, Node* order);
	Node* serching(int v_key, Node* order);
	Node* serching_of_min(Node* order);
	void set_newnode(int v_key, Node* order);
	void delete_tree(Node* order);
	void show_counter(Node* order);
	Node* root;//узел дерева
	Node* before = NULL;//предок искомого элемента
	Node* before_min = NULL;//предок элеммента для замены
};
void tree::straight_obhod() {
	counter = 0;
	straight_obhod(root);


}
void tree::simetric_obhod() {
	counter = 0;
	simetric_obhod(root);

}
void tree::back_obhod() {

	back_obhod(root);

}
void tree::straight_obhod(Node* order) {
	if (order != NULL) {
		cout << order->key;
		straight_obhod(order->left);
		straight_obhod(order->rihgt);
	}
}
void tree::simetric_obhod(Node* order) {
	if (order != NULL) {

		straight_obhod(order->left);
		cout << order->key;
		straight_obhod(order->rihgt);
	}
}
void tree::back_obhod(Node* order) {
	if (order != NULL) {

		straight_obhod(order->left);
		straight_obhod(order->rihgt);
		cout << order->key;
	}
}
Node* tree:: serching_of_min(Node* order) {
	while (order->left != NULL) {
		before_min = order;
		return serching_of_min(order->left);
	}
	return order;
}
Node* tree::serching(int v_key, Node* order) {//функция поиска элемента по ключу
	if (order != NULL) {
		if (v_key == order->key) {
			return order;
		}
		if (v_key < order->key) {
			before = order;
			return serching(v_key, order->left);
		}
		else {
			before = order;
			return serching(v_key, order->rihgt);

		}
	}
	else return NULL;
}
void tree::delete_i() {
	if (root == NULL) {
		cout << " Дерево пустое\n";
	}
	else {
		int m_key;
		cout << " Введите ключ элемента, который нужно удалить.\n";
		cin >> m_key;
		delete_i(m_key, root);
	}
}
void tree::delete_i(int v_key, Node* order) {//функция пок не готова
	Node* node_to_delete=NULL;
	node_to_delete = serching(v_key, order);//найдем место элемента с ключем в дереве если такой есть
	if (before != NULL) {
		cout << " Ключ родителя " << before->key << endl;
	}
	if (node_to_delete == NULL) {
		cout << " Такого эдемента нет в дереве\n";
	}
	else {
		if (node_to_delete->left == NULL && node_to_delete->rihgt == NULL) {//случай когда лист.
			if (before->key < node_to_delete->key) {
				delete node_to_delete;
				before->rihgt = NULL;
				cout << " Узел удален\n";
			}
			else {
				delete node_to_delete;
				before->left= NULL;
				cout << " Узел удален\n";
			}	
		}
		
		else {
			if (node_to_delete->left == NULL && node_to_delete->rihgt != NULL) {//случай, когда у узла есть правое поддерево
				if (before->key < node_to_delete->key) {
					before->rihgt = node_to_delete->rihgt;
					delete node_to_delete;
					cout << " Узел удален\n";
				}
				else {
					before->left = node_to_delete->rihgt;
					delete node_to_delete;

					cout << " Узел удален\n";
				}
			}
			else {
				if (node_to_delete->left != NULL && node_to_delete->rihgt == NULL) {//случай, когда у узла есть левое поддерево
					if (before->key < node_to_delete->key) {
						before->rihgt = node_to_delete->left;
						delete node_to_delete;
						cout << " Узел удален\n";
					}
					else {
						before->left = node_to_delete->left;
						delete node_to_delete;

						cout << " Узел удален\n";
					}
				}
				else {
					if (node_to_delete->left != NULL && node_to_delete->rihgt != NULL) {//случай, когда у узла есть 2 поддерева
						Node* tmp = NULL;
						Node* elem_min = serching_of_min(node_to_delete->rihgt);//поиск элемента для замены.
						cout << "  Ключ элемнта для замены " << elem_min->key << endl;
							node_to_delete->key = elem_min->key;
							before_min->left = elem_min->rihgt;
							delete elem_min;
							cout << " Элемента удален\n";
						
						
					}
				}
			}
		}
		
	}
	
}
void tree::show_counter() {
	show_counter(root);
	cout << " Количесво листьев в дереве-" << counter << endl;
	counter = 0;
}
void tree::show_counter(Node* order) {
	if (order != NULL) {
		counter++;
		show_counter(order->left);
		show_counter(order->rihgt);
	}


}
void tree::delete_tree() {
	if (root == NULL) {
		cout << "Дерево пустое, удалять нечего\n";
	}
	else {
		delete_tree(root);
		cout << " Элементы успешно удалены\n";
		root = NULL;
	}
}
void tree::delete_tree(Node* order) {
	if (order != NULL) {
		delete_tree(order->left);
		delete_tree(order->rihgt);
		delete order;
	}

}
void tree::set_newnode(int v_key, Node* order) {
	if (v_key < order->key) {
		if (order->left != NULL) {
			set_newnode(v_key, order->left);
		}
		else {
			order->left = new Node;
			order->left->key = v_key;
			order->left->left = NULL;
			order->left->rihgt = NULL;
			cout << " Новый узел " << order->left->key << " создан\n";

		}

	}
	else if (v_key >= order->key) {
		if (order->rihgt != NULL) {
			set_newnode(v_key, order->rihgt);
		}
		else {
			order->rihgt = new Node;
			order->rihgt->key = v_key;
			order->rihgt->left = NULL;
			order->rihgt->rihgt = NULL;
			cout << " Новый узел " << order->rihgt->key << " создан\n";

		}
	}
}
void tree::set_newnode() {
	int m_key;
	cout << "\n Введите ключь нового узла -";
	cin >> m_key;
	if (root != NULL) {
		set_newnode(m_key, root);
	}
	else {
		root = new Node;
		root->key = m_key;
		root->left = NULL;
		root->rihgt = NULL;

		cout << " Новый узел " << root->key << " создан\n";

	}
}
void tree::print_tree() {

}
int main()
{
	setlocale(LC_ALL, "rus");
	tree element;
	int exit = 1;
	int operation;
	while (exit == 1) {
		cout << "\n\n\n           Меню выбора действий\n";
		cout << "\n Выберите номер той команды, которую надо выполнить\n";
		cout << "\n1.   Создание бинарного дерева. \n";
		cout << "\n2.   Удалить бинарное дерево.\n";
		cout << "\n3.   Добавить узел в бинарное дерево.\n";
		cout << "\n4.   Удалить узел из бинарного дерева. \n";
		cout << "\n5.   Вывод на экран содержимого дерева.\n";
		cout << "\n6.   Количество листьев дерева.\n";
		cout << "\n7.   Пhямой обход дереваю\n";
		cout << "\n8.   Симетричный обход дерева\n";
		cout << "\n9.   Обратный обход дерева\n";
		cout << "\n0.  Выйти из программы\n";
		operation = 0;
		cin >> operation;
		switch (operation) {
		case 1:
		{
			system("cls");
			cout << "         1.Пустое дерево создано.\n";
			break;
		}
		case 2:
		{
			system("cls");
			element.delete_tree();
			break;
		}
		case 3:
		{
			system("cls");
			cout << " Добавление нового узла\n";
			element.set_newnode();

			break;
		}
		case 4:
		{
			system("cls");
			element.delete_i();
			break;
		}
		case 6:
		{
			system("cls");
			element.show_counter();
			break;
		}
		case 7:
		{
			system("cls");
			element.straight_obhod();
			break;
		}
		case 8:
		{
			system("cls");
			element.simetric_obhod();
			break;
		}
		case 9:
		{
			system("cls");
			element.back_obhod();
			break;
		}
		case 0:
		{
			system("cls");
			cout << "\nПроверка: Вы действительно хотите выйти из программы? Нажмите гужную цифру\n";
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

