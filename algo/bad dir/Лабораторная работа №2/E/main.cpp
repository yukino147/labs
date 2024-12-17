/*Задание №21
Попытался сделать программу с контролем ошибок.
Не получилось использовать кириллицу, поэтому имена пользователей должны быть
написаны на английском, в поддерживаемом isalpha формате.*/
#include <fstream>
#include <iostream>
#include <cstring>
#include <clocale>
//#include <Windows.h>

using namespace std;

string file = "card-file.txt";
fstream card;

int ids = 0;

struct Sub {
	short id;
};

bool alpha(const char c)
{
    //return (c >= 'А' && c <= 'я') || c == 'ё' || c == 'Ё';
    return (isalpha(c));
}

int add() {
	char *number = new char [20], *lastname = new char [20], *name = new char [20], *time_s = new char [20];
	//SetConsoleCP(1251);
	//SetConsoleCP(866);
	card.open(file, fstream::out | fstream::app);
	bool cancont = true;

	Sub user;
	user.id = ++ids;
	//cout << "\nВы добавляете нового абонента с ID " << user.id << endl;
	cout << "\nVy dobavlyaete novogo abonenta s ID " << user.id << endl;

	//cout << "Введите номер абонента(номер начинается с 10000 и заканчивается 99999: ";
	cout << "Vvedite novogo abonenta(nomer nachinaetsya s 10000 i zakanchivaetsya 99999: ";
	cin >> number;
	//cout << "\nНомер абонента: " << number << endl;
	cout << "\nNomer abonenta: " << number << endl;
	if (strlen(number) != 5) {
		ids--;
		//cout << "\n⚠ Вы неправильно ввели номер! Заполните данные нового абонента заного." << endl;
		cout << "\n⚠ Vy nepravilno vveli nomer! Zapolnite dannye novogo abonenta zanogo." << endl;
		number = new char [20];
		card.close();
		add();
	}
	if (number[0] == '0') {
		ids--;
		//cout << "\n⚠ Вы неправильно ввели номер! Номер не должен начинаться с нуля! Заполните данные нового абонента заного." << endl;
		cout << "\n⚠ Vy nepravilno vveli nomer! Nomer ne dolzhen nachinatsya s nulya! Zapolnite dannye novogo abonenta zanogo." << endl;
		number = new char [20];
		card.close();
		add();
	}
	for (int i = 0; i < strlen(number); i++) {
		if (!isdigit(number[i])) {
			cancont = false;
			break;
		}
	}
	if (!cancont) {
		ids--;
		//cout << "\n⚠ Вы неправильно ввели номер! Номер должен содержать только цифры! Заполните данные нового абонента заного." << endl;
		cout << "\n⚠ Vy nepravilno vveli nomer! Nomer dolzhen soderzhat' tol'ko cyphry(digits)! Zapolnite dannye novogo abonenta zanogo." << endl;
		number = new char [20];
		card.close();
		add();
	}

	cout << "\nВведите фамилию абонента: ";
	cin >> lastname;
	cout << "\nФамилия абонента: " << lastname << endl;
	for (int i = 0; i < strlen(lastname); i++) {
		if (!alpha(lastname[i])) {
			cancont = false;
			break;
		}
	}
	if (!cancont) {
		ids--;
		//cout << "\n⚠ Вы неправильно ввели фамилию! Фамилия должна содержать только буквы! Заполните данные нового абонента заного." << endl;
		cout << "\n⚠ Vy nepravilno vveli phamiliyu! Phamiliya dolzhna soderzhat tol'ko bukvi! Zapolnite dannye novogo abonenta zanogo." << endl;
		lastname = new char [20];
		card.close();
		add();
	}
	if (strlen(lastname) < 3) {
		ids--;
		//cout << "\n⚠ Вы неправильно ввели фамилию! Фамилия должна содержать не менее 3 символов! Заполните данные нового абонента заного." << endl;
		cout << "\n⚠ Vy nepravilno vveli phamiliyu! Phamiliya dolzhna soderzhat ne menee 3 simvolov! Zapolnite dannye novogo abonenta zanogo." << endl;
		lastname = new char [20];
		card.close();
		add();
	}

	//cout << "\nВведите имя абонента: ";
	cout << "\nVvedite imya abonenta: ";
	cin >> name;
	//cout << "\nИмя абонента: " << name << endl;
	cout << "\nImya abonenta: " << name << endl;
	for (int i = 0; i < strlen(name); i++) {
		if (!alpha(name[i])) {
			cancont = false;
			break;
		}
	}
	if (!cancont) {
		ids--;
		//cout << "\n⚠ Вы неправильно ввели имя! Имя должно содержать только буквы! Заполните данные нового абонента заного." << endl;
		cout << "\n⚠ Vy nepravilno vveli imya! Imya dolzhno soderzhat tol'ko bukvi! Zapolnite dannye novogo abonenta zanogo." << endl;
		name = new char [20];
		card.close();
		add();
	}
	if (strlen(name) < 3) {
		ids--;
		//cout << "\n⚠ Вы неправильно ввели имя! Имя должно содержать не менее 3 символов! Заполните данные нового абонента заного." << endl;
		cout << "\n⚠ Vy nepravilno vveli imya! Imya dolzhno soderzhat ne menee 3 simvolov! Zapolnite dannye novogo abonenta zanogo." << endl;
		name = new char [20];
		card.close();
		add();
	}

	//cout << "\nВведите время разговора абонента(в секундах): ";
	cout << "\nVvedite vremya razgovora abonenta(v secundax): ";
	cin >> time_s;
	//cout << "\nВремя разговора абонента: " << time_s << endl;
	cout << "\nVremya razgovora abonenta: " << time_s << endl;
	for (int i = 0; i < strlen(time_s); i++) {
		if (!isdigit(time_s[i])) {
			cancont = false;
			break;
		}
	}
	if (!cancont) {
		ids--;
		//cout << "\n⚠ Вы неправильно ввели время! Время должно содержать только цифры! Заполните данные нового абонента заного." << endl;
		cout << "\n⚠ Vy nepravilno vveli vremya! Vremya dolzhno soderzhat' tol'ko cyphry(digits)! Zapolnite dannye novogo abonenta zanogo." << endl;
		time_s = new char [20];
		card.close();
		add();
	}
	if (time_s[0] == '0') {
		ids--;
		//cout << "\n⚠ Вы неправильно ввели время разговора! Время не должно начинаться с нуля. Заполните данные нового абонента заного." << endl;
		cout << "\n⚠ Vy nepravilno vveli vremya razgovora! Vremya ne dolzhno nachinatsya s nulya. Zapolnite dannye novogo abonenta zanogo." << endl;
		time_s = new char [20];
		card.close();
		add();
	}
	card << user.id << " " << number << " " << lastname << "_" << name << " " << time_s << "\n";
	card.close();
	return 0;
}

void print() {
	if (ids == 0) {
		//cout << "Картотека пуста." << endl;
		cout << "Kartoteka pusta." << endl;
	} else {
		card.open(file, fstream::in);

		//cout << "\nID | Номер абонента | Фамилия & Имя | Время разговора\n" << endl;
		cout << "\nID | Nomer abonenta | Phamiliya & Imya | Vremya razgovora\n" << endl;
		char ch;
		while (card.get(ch)) {
			if (ch == ' ') cout << " |";
			if (ch == '_') ch = ' ';
			cout << ch;
		}
		card.close();
	}
}

void notice() {
	char chprice[5];
	int price;
	//cout << "\nВведите сколько стоит 1 минута разговора " << endl;
	cout << "\nVvedite skol'ko stoit 1 minuta razgovora " << endl;
	cin >> chprice;
	for (int i = 0; i < strlen(chprice); i++) {
		if (!isdigit(chprice[i])) {
			//cout << "\n⚠ Вы неправильно ввели cтоимость! Стоимость должна содержать только цифры!" << endl;
			cout << "\n⚠ Vy nepravilno vveli stoimost'! Stoimost' dolzhna soderzhat tol'ko cyphry(digits)!" << endl;
			break;
			notice();
		}
	}
	
	for (int i = 0; i < strlen(chprice); i++) {
		if (i == 0) price = chprice[i] - '0';
		else {
			price *= 10;
			price += chprice[i] - '0';
		}
	}
	//cout << "1 минута разговора стоит – " << price << " ₽" << endl;
	cout << "1 minuta razgovora stoit – " << price << " ₽" << endl;

	card.open(file, fstream::in);
	char ch;
	char *id = new char[5], *number = new char[5], *user = new char[40], *chtime = new char[5];
	short spaces = 0;
	int t = 0, time, pay;
	while (card.get(ch)) {
		if (spaces == 0) {
			while (ch != ' ') {
				id[t] = ch;
				t++;
				card.get(ch);
			}
			t = 0;
		}
		if (spaces == 1) {
			while (ch != ' ') {
				number[t] = ch;
				t++;
				card.get(ch);
			}
			t = 0;
		}
		if (spaces == 2) {
			while (ch != ' ') {
				user[t] = ch;
				t++;
				card.get(ch);
			}
			t = 0;
			/*for (int i = 0; i < strlen(user); i++) {
				if (user[i] == '_') user[i] = ' ';
			}*/
		}
		if (spaces == 3) {
			while (ch != '\n') {
				chtime[t] = ch;
				t++;
				card.get(ch);
			}
			t = 0;
		}
		if (ch == ' ') spaces++;
		if (ch == '\n') {
			spaces = 0;
			for (int i = 0; i < strlen(chtime); i++) {
				if (i == 0) time = chtime[i] - '0';
				else {
					time *= 10;
					time += chtime[i] - '0';
				}
			}
			time /= 60;
			pay = time * price;
			if (pay > 0) {
				//cout << "⚡ Пользователь с ID " << id << " номером " << number << " именем " << user << " должен заплатить " << pay << "рублей" << endl;
				//cout << "\n⌛ Пользователь с ID " << id << " номером " << number << " именем ";
				cout << "\n⌛ Polzovatel' s ID " << id << " nomerom " << number << " imenem ";
				for (int i = 0; i < strlen(user); i++) {
					if (user[i] == '_') cout << " ";
					else cout << user[i];
				}
				//cout << " должен заплатить " << pay << " рублей" << endl;
				cout << " dolzhen zaplatit' " << pay << " rubley" << endl;
			}
			id = new char [5]; number = new char [5]; user = new char [40]; chtime = new char[5];
		}
	}
}

int enter() {
	unsigned event;

	//cout << "\nВыберите действие, которое вы хотите совершить с картотекой абонентов.\n\nВведите:\n• 0 для выхода из программы;\n• 1 для добавления новых абонентов в картотеку;\n• 2 для вывода картотеки на экран;\n• 3 для извещения на оплату телефонного разговора;\n\n";
	cout << "\nVyberite deystvie, kotoroe vy xotite sovershit' s Kartotekoy abonentov.\n\nVvedite:\n• 0 dlya vyxoda iz programmy;\n• 1 dlya dobavleniya novyx abonentov v kartoteku;\n• 2 dlya vyvoda kartoteki na ekran;\n• 3 dlya izvesheniya na oplatu telefonnogo razgovora;\n\n";
	cin >> event;

	if (event == 0) {
		//cout << "Вы выбрали действие 0 - выход из программы.\n";
		cout << "Vy vybrali deystvie 0 - vyxod iz programmy.\n";
		return 0;
	} else
	if (event == 1) {
		//cout << "Вы выбрали действие 1 - добавление новых абонентов в картотеку.\n";
		cout << "Vy vybrali deystvie 1 - dobavlenie novyx abonentov v kartoteku.\n";
		add();
	} else
	if (event == 2) {
		//cout << "Вы выбрали действие 2 - вывод картотеки на экран.\n";
		cout << "Vy vybrali deystvie 2 - vyvod kartoteki na ekran.\n";
		print();
	} else
	if (event == 3) {
		//cout << "Вы выбрали действие 3 – вывод извещения на оплату\n";
		cout << "Vy vybrali deystvie 3 – vyvod izvesheniya na oplatu\n";
		notice();
	} else {
		//cout << "Неверное действие! Выберите от 0 до 3:" << endl;
		cout << "Nevernoe deystvie! Vyberite ot 0 do 3:" << endl;
		enter();
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	card.open(file, fstream::in);
	if (!card.is_open()) {
		//cout << "\n⚠ Отсутствует файл картотеки " << file << endl << "♺ Создаю новый..." << endl;
		cout << "\n⚠ Otsutstvuet phayl kartoteki " << file << endl << "♺ Sozdayu noviy..." << endl;
		ofstream newfile;
		newfile.open(file);
		newfile.close();
		card.open(file, fstream::in);
	}

	char ch;
	while (card.get(ch)) {
		if (ch == '\n') ids++;
	}
	card.close();

	//cout << "\nКол-во абонентов - " << ids << endl;
	cout << "\nKol-vo abonentov - " << ids << endl;

	enter();

	cout << endl;
	card.close();
}