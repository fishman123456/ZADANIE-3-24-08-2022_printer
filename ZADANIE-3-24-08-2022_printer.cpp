// ZADANIE-3-24-08-2022_printer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// код от алексея 
/*void Add(string per, int pr) {
	if (!isFull()) {
		int ind = length;
		for (int i = 0; i < length; i++) {
			if (pr > Pri[i]) {
				ind = i;
				break;
			}
		}
		length++;

		for (int j = length; j > ind; j--) {
			Wait[j] = Wait[j - 1];
			Pri[j] = Pri[j - 1];
		}

		Wait[ind] = per;
		Pri[ind] = pr;
	}
	else
		cout << "Wait for print is full\n";
 }
 */

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class PrintPrioriti
{
	char* Person;//Очередь

	int* Pri;//приоритеты

	int MaxPersonLength;//Максимальный размер очереди

	int PersonLength;//Текущий размер очереди

public:
	
	PrintPrioriti(char n,int m);//Конструктор
	
	~PrintPrioriti();//Деструктор
	
	void Add(int c);//Добавление элемента
	
	int Extract();//Извлечение элемента
	
	void Clear();//Очистка очереди
	
	bool IsEmpty();//Проверка существования элементов в очереди
	
	bool IsFull();//Проверка на переполнение очереди
	
	int GetCount();//Количество элементов в очереди
	
	void Show();//демонстрация очереди
};
void PrintPrioriti::Show() {
	cout << "\n-----------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < PersonLength; i++) {
		cout << Person[i] << " ";
	}
	cout << "\n-----------------------------------\n";
}
PrintPrioriti::~PrintPrioriti()
{
	//удаление очереди
	delete[]Person;
}
PrintPrioriti::PrintPrioriti(char n, int m)
{
	//получаем размер
	PersonLength = m;
	//создаем очередь
	Person = new char[PersonLength];
	//Изначально очередь пуста
	PersonLength = 0;
}
void PrintPrioriti::Clear()
{
	//Эффективная "очистка" очереди
	PersonLength = 0;
}
bool PrintPrioriti::IsEmpty()
{
	//Пуст?
	return PersonLength == 0;
}
bool PrintPrioriti::IsFull()
{
	//Полон?
	return PersonLength == MaxPersonLength;
}
int PrintPrioriti::GetCount()
{
	//Количество присутствующих в стеке элементов
	return PersonLength;
}
void PrintPrioriti::Add(int c)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и вставляем новый элемент
	if (!IsFull())
		Person[PersonLength++] = c;
}
int PrintPrioriti::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty()) {
		//запомнить первый
		int temp = Person[0];
		//сдвинуть все элементы
		for (int i = 1; i < PersonLength; i++)
			Person[i - 1] = Person[i];
		PersonLength--;
		//вернуть первый(нулевой)
		return temp;
	}
	else //Если в очереди элементов нет
		return -1;
}


void main()
{
	srand(time(0));
	//создание очереди
	PrintPrioriti QU('yu',25);
	//заполнение части элементов
	for (int i = 0; i < 5; i++) {
		QU.Add(rand() % 50);
	}
	//показ очереди
	QU.Show();
	//извлечение элемента
	QU.Extract();
	//показ очереди
	QU.Show();
}