// OOP_lesson_8_DZ.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


void clearScr()
{
	//system("cls");
	cout << "\x1B[2J\x1B[H";
}
//  задание 1.
//	Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, если второй параметр равен 0.
//	 В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
//

template <typename T>
const T& t_div(const T& a, const T& b)
{	
	if (b == 0)
		throw "DivisionByZero";
	else
	return a /b;
}
//============================================================================================================================================================================
//	Задание 2.
//	Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра. 
//	Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a. 
//	Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a. В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n. 
//	Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
class Ex
{
private:
	double x;

public:

	Ex(double d) : x(d) {};

	~Ex() {};

	friend std::ostream& operator << (std::ostream& out, const Ex& Ex)
	{
		out << Ex.x;
		return out;
	};
		
};

class Bar
{
private:
	double y;

public:
	Bar() : y(0) {};
	~Bar() {};

void setBar(double a)
	{
	if (a + y > 100)
		throw Ex(a*y);
	else
		y = a;
	};

};

//============================================================================================================================================================================
//	Задание 3.
//	Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию. 
//	Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне). 
//	Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, 
//	а также выводящую подробную информацию о всех возникающих ошибках.

class OffTheField // класс перехватывающий выход робота за пределы.
{
private:
	int m_x;
	int m_y;
	char m_direction;

public:

	OffTheField(int y, int x, char dir) : m_y(y), m_x(x), m_direction(dir) {};

	~OffTheField() {};

	friend std::ostream& operator << (std::ostream& out, const OffTheField& OF)
	{
		out << " position : " << OF.m_y << "x" << OF.m_x << " direction :";

		if ((OF.m_direction == 'w') || (OF.m_direction == 'W'))
			out << " left" << endl;
		if ((OF.m_direction == 's') || (OF.m_direction == 'S'))
			out << " down" << endl;
		if ((OF.m_direction == 'a') || (OF.m_direction == 'A'))
			out << " left" << endl;
		if ((OF.m_direction == 'd') || (OF.m_direction == 'D'))
			out << " right" << endl;

		return out;
	};
};

class IllegalCommand //класс перехватывающий команду на смену координаты.  (направление не находится в нужном диапазоне). 
{
	int m_x;
	int m_y;
	char m_direction;

public:

	IllegalCommand(int y, int x, char dir) : m_y(y), m_x(x), m_direction(dir) {};

	~IllegalCommand() {};

	friend std::ostream& operator << (std::ostream& out, const IllegalCommand& IC)
	{
		out << " position : " << IC.m_y << "x" << IC.m_x << " direction :";
		if ((IC.m_direction == 'w') || (IC.m_direction =='W'))
			out << " left" << endl;
		if ((IC.m_direction == 's') || (IC.m_direction == 'S'))
			out << " down" << endl;
		if ((IC.m_direction == 'a') || (IC.m_direction == 'A'))
			out << " left" << endl;
		if ((IC.m_direction == 'd') || (IC.m_direction == 'D'))
			out << " right" << endl;
		return out;
	};

};


class Robot
{
protected:
	char m_name;

public:
	Robot(char s) : m_name(s) 
	{};
	~Robot() 
	{};

	void moving (char &t, int &coord, int &coord2) //движение робота по полю. //метод меняет значение координаты по адресу.// перемещение на 1 позицию от текущей.
	{
		
		if ((t == 'W') || (t == 'w'))

			coord--;

		if ((t == 's') || (t == 'S'))
			coord++;

		if ((t == 'A') || (t == 'a'))
			coord--;

		if ((t == 'D') || (t == 'd'))
			coord++;

		if ((coord < 0) || (coord > 10))

			throw OffTheField(t,coord, coord2);
			

		//если коодината будет мньше 0 или больше 10 значит робот уйдет за пределы поля.

	};

	char getName()
	{
		return m_name;
	};


};

void printField(char(&f)[10][10])
{
	
	for (size_t i = 0; i < 10; i++)
	{
		cout << endl;
		
		for (size_t j = 0; j < 10; j++)
		{
			cout << f[i][j] << " "; // проинициализировал массив. 
		}
	}
};


int main()
{
	// хадание 1.
	try 
	{
		int res = t_div(8, 0);
		std::cout << res <<std:: endl;
		
	}
	catch (const char* ex)
	{
		std::cerr <<  ex << std:: endl;
	}
	//============================================================================================================================================================================
	//Задание 2. 

	Bar bar;
	int n; 
		while (1)
		{

			std::cout << "Enter: " << std::endl;
			std::cin >> n;
			if (n == 0)
				break;
			try
			{
				bar.setBar(n);
			}
			catch (Ex& exp)
			{
				std::cout <<"Exeption " <<exp << std::endl;
			}

		}
		clearScr();
    //============================================================================================================================================================================
		// Задание 3
		
		const char size = 10;
		char field[size][size]; // это поле 10х10
		char turn = 1;
		int coord_x = 5;
		int coord_y = 5;

		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				field[i][j] = '.'; // проинициализировал массив. 
			}
		}

		

		

		Robot bot('r'); // создан объект робот

		field[coord_y][coord_x] = bot.getName(); // Поставим бота на поле
		printField(field);
		
		mark1:
		while (1)
		{
			if (turn == 48)
				break;
			else
			{
				cout << endl;
				cout << " robot control WASD " << endl;
				cout << " to exit, press 0 " << endl;
				
				cin >> turn;

				try
				{
					
					if (((turn == 'W') || (turn == 'w')) && (coord_y == 0)) // если по Y стояли на 0 координате, следующая просчитаная коодрината будет -1
						throw IllegalCommand(coord_y, coord_x, turn); //выбрасываем исключение класса IllegalCommand

					if (((turn == 'S') || (turn == 's')) && (coord_y == 10)) //eсли по Y была получена команда вниз и стояли на координате 10 
						throw IllegalCommand(coord_y, coord_x, turn);

					if (((turn == 'A') || (turn == 'a')) && (coord_x == 0))
						throw IllegalCommand(coord_y, coord_x, turn);

					if (((turn == 'A') || (turn == 'a')) && (coord_x == 10))
						throw IllegalCommand(coord_y, coord_x, turn);
					//если мы ловим исключение данного класса то исключание класса OffTheField уже не поймать, но специально допущена ошибка!


					if (((turn == 'W') || (turn == 'w')) || ((turn == 'S') || (turn == 's'))) // движение по y
					{

						field[coord_y][coord_x] = '.';

						bot.moving(turn, coord_y, coord_x);

						field[coord_y][coord_x] = bot.getName();  
					}
					if (((turn == 'A') || (turn == 'a')) || ((turn == 'd') || (turn == 'D'))) // движение по x
					{
						field[coord_y][coord_x] = '.';
						bot.moving(turn, coord_y, coord_x);  // здесь ошибка в координатах если движение происходит по координате x (A/S) будет вызыватся исключение класса OffTheField
						field[coord_y][coord_x] = bot.getName();
					}

					clearScr();

					printField(field);
				}
				catch (IllegalCommand& IC)
				{
					cout << "Exeption! Illegal Command! robot will go beyond! " << IC << std::endl;
				}
				catch (OffTheField& off)
				{
					cout << "Exeption! robot went out of bounds!" << off << std::endl;
				}
				catch (out_of_range& ex)
				{
					cerr << "out_of_range" << endl;
				}
				catch (exception& expt)
				{
					cerr << expt.what() << endl;
				}
				catch (...)
				{
					cerr << "Exeption!" << endl;
				}
			}
			
			

		};
		
	







	
		
	
}

