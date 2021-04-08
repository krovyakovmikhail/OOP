// OOP_lesson7_DZ.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <regex>


using namespace std;

//	1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. 
//	Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и date. 
//  Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа к полям класса Date, а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.
//	Затем переместите ресурс, которым владеет указатель today в указатель date. Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.

class Date
{
private:
	int m_day, m_month, m_year;

public:
	Date()
	{
		m_day = 1;
		m_month = 1;
		m_year = 2000;
	};
	Date(int d, int m, int y) : m_day(d), m_month(m), m_year(y)
	{};
	~Date()
	{};

	void setDay(int d)
	{
		m_day = d;
	};
	void setMonth(int m)
	{
		m_month = m;
	};
	void setYear(int y)
	{
		m_year = y;
	};

;
	friend ostream& operator << (ostream& out, const Date& date)
	{
		out << date.m_day << "." << date.m_month << "." << date.m_year;
		return out;
	};
	friend bool operator > (const Date& date1, const Date& date2)
	{
		 
		
			if (date1.m_year > date2.m_year) // по годам
			{
				return true;
			}


			if (date1.m_year == date2.m_year) // если года равны, проверим по месяцам.
			{
				if (date1.m_month != date2.m_month)
				{
					if (date1.m_month > date2.m_month) // сравнивем по месяцам.
					{
						return true;
					}
				}
			}

			if (date1.m_year == date2.m_year) // если года равны, проверим по месяцам.
			{
				if (date1.m_month == date2.m_month) // и если месяца равны, сравниваем по дням. 
				{
					if (date1.m_day > date2.m_day)
					{
						return true;
					}
				}					
			}


			
		 return false; 
		


	};
	friend bool operator < (const Date& date1, const Date& date2)
	{
		

		if (date1.m_year < date2.m_year) // 
		{
			return true;
		}


		if (date1.m_year == date2.m_year) // если года равны, проверим по месяцам.
		{			
			if (date1.m_month < date2.m_month) // сравнивем по месяцам.
				{
					return true;
				}
		}

		if (date1.m_year == date2.m_year) // если года равны, проверим по месяцам.
		{
			if (date1.m_month == date2.m_month) // и если месяца равны, сравниваем по дням. 
			{	
				if (date1.m_day < date2.m_day)
				{
					return true;
				}
			}
		}


		return false;  	


	};
	

};





//	2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
//	Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой(сравнение происходит по датам).Функция должна вернуть более позднюю дату.
//	Создайте функцию, которая обменивает ресурсами(датами) два умных указателя, переданных в функцию в качестве параметров.
//	Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.


Date date_comparison(const Date& date1, const Date& date2) // Функция должна вернуть более позднюю дату, а что возвращать в случае если даты равны. 
{
	if (date1 > date2)
		return date1;
	else if (date1 < date2) 
		return date2;
	else // иначе даты равны . 
	{
		cout << "the dates are equal " << endl;
		return date1; // вернем одну из дат и сообщим что они равны.
		
	}

};

void sharing_resources_date(unique_ptr<Date>& date1, unique_ptr<Date>& date2) // Создайте функцию, которая обменивает ресурсами(датами) два умных указателя, переданных в функцию в качестве параметров.
{
	unique_ptr<Date> temp_date = make_unique <Date>();

	temp_date = move(date1); // переместим во временный указатель данные одного из указателей чтобы не потерять их. 
	date1 = move(date2); // переместим в первый указатель ресурсы второго указателя
	date2 = move(temp_date); // а теперь во второй вернем ресурсы из первого
	// при завершении работы этой функции умный укзатель temp_date  будет удален?  вроде должен быть удален он же умный указатель)
	
};


int main()

{	
	
	// задание 1
	unique_ptr<Date> today = make_unique <Date>();
	unique_ptr<Date> date = make_unique <Date>();

	today->setDay(3);
	today->setMonth(4);
	today->setYear(2021);

	cout << "today " << *today << endl;


	date = move(today);

	cout << "date " << *date << endl;

	if (today)
	{
		cout << "today not null" << endl;

		if (date)
		{
			cout << "date not null" << endl;
		}
		else
		{
			cout << "date null" << endl;
		}
	}
	else
	{
		cout << "today  null" << endl;

		if (date)
		{
			cout << "date not null" << endl;
		}
		else
		{
			cout << "date null" << endl;
		}
	}

	// Задание 2

	unique_ptr<Date> date1 = make_unique <Date>(5,5,2025);
	unique_ptr<Date> date2 = make_unique <Date>(10,10,2010);

	cout << "---------------------" << endl;
	cout << "date1 " << *date1 << endl;
	cout << "date2 " << *date2 << endl;

	cout << "date comparison: " << date_comparison(*date1, *date2) << endl;

	cout << "---------------------" << endl;
	if (date1)
	{
		cout << "today not null" << endl;
	}
	if (date2)
	{
		cout << "today not null" << endl;
	}

	cout << "---------------------" << endl;
	cout << "sharing_resources_date: " << endl;

	sharing_resources_date(date1, date2); // вызываем функцию обмена ресусами, отправляем в нее умные указатели.


	cout << "date1 " << *date1 << endl;
	cout << "date2 " << *date2 << endl;



}

