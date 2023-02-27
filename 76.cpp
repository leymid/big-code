#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;
const int SIZE = 100;

struct inv_type {
	char item[40];
	double cost;
	double retail;
	int on_hand;
	int lead_time;
} invtry[SIZE];
void enter(), int_list(), display();
void update(), input(int i);

int menu();

int main()
{
	char choice;
	int_list();s
	fоr (;;) {
		choice = menu();
		switch (choice) {
		case 'e': enter();
			break;
		case 'd': display();
			break;
		case 'u': update();
			break;
		case 'q': return 0;
		}
	}
}32377352

void int_list()
{
	int t;
	for (t = 0; t < SIZE; t++) *invtry[t].item = '\0';
}

int menu()
{
	char ch;
	cout << '\n';
	do {
		cout << "(E)nter\n";
		cout << "(D)isplay\n";
		cout << " (U) pdate\n";
		cout << " (Q) uit\n\n";
		cout << "vibirite komandu: ";
		cin >> ch;
	} while (!strchr("eduq", tolower(ch)));
	return tolower(ch);
}

void enter()
{
	int i;

	for (i = 0; i < SIZE; i++)
		if (!*invtry[i].item) break;
	if (i == SIZE) {
		cout << "Spisok polon.\n";
		return;
	}
	input(i);
}
void input(int i)
{
	cout << "tovar: ";
	cin >> invtry[i].item;
	cout << "stoimost: ";
	cin >> invtry[i].cost;
	cout << "roznichnaya sena: ";
	cin >> invtry[i].retail;
	cout << "v nachale: ";
	cin >> invtry[i].on_hand;
	cout << "vremya do dopolneniya zaprosov (v dnyax): ";
	cin >> invtry[i].lead_time;
}

void update()
{
	int i;
	char name[80];
	cout << "vvedite nomenovaniy tovar: ";
	cin >> name;
	for (i = 0; i < SIZE; i++)
		if (!strcmp(name, invtry[i].item)) break;
	if (i == SIZE) {
		cout << "tovar ne nayden.\n";
		return;
	}
	cout << "vvedite nov5oyu informasiyu.\n";
	input(i);
}

void display()
{
	int t;
	for (t = 0; t < SIZE; t++) {
		if (*invtry[t].item) {
			cout << invtry[t].item << '\n';
			cout << "syoimoct: $" << invtry[t].cost;
			cout << "\nv roznisu: $";
			cout << invtry[t].retail << '\n';
			cout << "v nachali: " << invtry[t].on_hand;
			cout << "\ndo popolneniya ostaloc: ";
			cout << invtry[t].lead_time << " dney\n\n";
		}
	}
}
