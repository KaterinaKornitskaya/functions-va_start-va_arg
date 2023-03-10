// functions va_start, va_arg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdarg.h>
/* 
  Написать программу, которая реализует функцию с неограниченным количеством
  параметров, организовывающую форматированный вывод на экран.
  Используйте функции va_start() и va_arg()
*/

// 1ый вариант - Ф-ия с произвольным количеством аргументов, количество 
// передается
void show1(int num, ...)  // num - кол-во параметров
{
    int* pnum = &num;  // адрес 1-го элемента в списке параметров
    for (; num; num--)  // цикл по кол-ву параметров
    {
        // разименовываем и выводи значение каждого следующего параметра
        std::cout << *(++pnum) << std::endl;
    }
}

// 2-ой вариант, Ф-ия с произвольным количеством аргументов, передается 
// первый из параметров
void show2(int num, ...)  // num - 1ый из параметров
{
    int* pnum = &num;  // адрес 1-го элемента в списке параметров
    while (*pnum)  // пока параметр на равен 0
    {
        // разименовываем и выводи значение каждого следующего параметра
        std::cout << *(pnum++) << std::endl;
    }
}

int main1()
{
    show1(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9);
    std::cout << std::endl;
    show2(11, 22, 33, 44, 55, 0);

    return 0;
}


// вариант с использованием ф-ий va_start() и va_arg()
void show(int num, bool type, ...)  // num - кол-во параметров
{                                   // type - тип переменной 
	char* arg_ptr;  // указатель на список параметров

	va_start(arg_ptr, num);  // получаем адрес первого параметра

	va_arg(arg_ptr, bool);  // пропускаем втрой параметр

	while (num--)  // цикл по количеству параметров
	{
		(type)
            // вывод на экран - если true - параметры типа инт
			? std::cout << va_arg(arg_ptr, int) << std::endl
            // вывод на экран - если false - параметры типа char
			: std::cout << va_arg(arg_ptr, char) << std::endl;
	}
	
}

int main()
{
	show(4, true, 1, 2, 3, 4);
    std::cout << std::endl;
	show(3, false, 'a', 'b', 'c');

	return 0;
}