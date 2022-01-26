
/*
	1.На входе мы получаем число
		1.1 Число и номера пуктов
			1.1.1. Тяжело реализуемо, потому что мы не знаем сколько пунктов выберет пользователь и какие
				1.1.1.1. Пользователь вводит число, цифры которого = номера пуктов.
				1.1.1.2. Сортируем номера пунктов, выбранных пользователем.
					( Проверяем наличие номеров пунктов в введенном числе начиная с последнего и до первого  (1).
					Совпадения записываем в другую переменную (CHOOSED_POINTS) путем домножения на 10. )
						1.1.1.2.1.  Сначала сравниваем с номером последнего пункта (в нашем случае 5):
									ostatok = CP % 10, Если ostatok == 5, то выходим из цикла возращая 5,
									сохраняем 5: sorted_CP = 0*10 + 5
									Даллее проверяем 4:
									
	2. На выходе список со свойствами числа
		2.1. Выбранные пользователем пункты (Номера которых есть в COOSED_POINTS) выполнить.
			2.1.1  Пункты выполняются в порядке возрастания номеров.
			2.1.2. Так как (1) последняя цифра COOSED_POINTS меньше остальных и равна номеру самого первого из выполняемях пунктов.
			2.1.2.1. Если номер  пункта в очереди на выполнение == последней цифре COOSED_POINTS то выполнить пункт, иначе пропустить пункт
			2.1.3. Номер выполненного пункта убираем из COOSED_POINTS делением на 10 самого COOSED_POINTS.

	//сопоставить номера функций с самими функциями (1 - кол. цифр, 2 - четность и т.д.)


*/

#include <iostream>

int cin_integer_function()										//Вводит числа
{
	int a;															//a - временная переменная, которую введет пользователь и вернеёт функция.
	std::cin >> a;													
	return a;														
}

int restart_client_call_functiom()								//Спрашивает пользователя о перезапуске кода и отправляет его ответ client_call()
{
	int restart_client_call_1;
	std::cout << "Enter << 1 >> to continue, any other number to stop: ";
	restart_client_call_1 = cin_integer_function();					//Получем от пользователя его мнение о перезапуске программы ( 1 == перезупуск )	
	return restart_client_call_1;									//И возращаем это мнение в основную функцию ( client_call() )
}

int counting_numbers(int integer)								//Считает знаки в введённом числе
{																	//integer - Вводимое число, то, в котором будут подсчиты-тся знаки
	int numbers = 1;												//Количество знаков в введённом числе (то что будем возращать)
	if (integer >= 0)
	{
		while (integer >= 10)
		{
			integer = integer / 10;
			numbers++;
		}
		return numbers;
	}
	else
	{
		while (integer <= -10)
		{
			integer = integer / 10;
			numbers++;
		}
		return numbers;
	}
}

int pow_10_function(int index)									//Возращает 10 в степени аргумента функции
{
	int degree = 1;
	while (index > 0)
	{
		degree = degree * 10;
		index--;
	}
	return degree;
}

float counting_factorial(int integer)							//Считает факториал от введённого числа (про тип возврата ниже)
{
	if (integer < 0)
	{
		integer = -integer;											//Для обхода сложностей перемножения чётного/нечетного количества ...
	}																//...отрицательных чисел программа работает только с положительными.
	float factorial = integer;										//float -  тип данных с плавающей точкой
	while (integer > 1)
	{
		integer = integer - 1;
		factorial = factorial * integer;
	}
	return factorial;
}

int searching_next_prime_number(int prime)						//Выводит следущее простое число
{
	int prime_copy = prime + 1, mem = 0, esc = 0;					//О дааа, esc же так сильно нагружает систему...
	while (esc < 10000)
	{

		for (int i1 = prime_copy - 1; i1 > 1; i1--)
		{
			if (prime_copy % i1 == 0)
			{
				mem++;
			}
		}

		if (mem == 0)
		{
			return prime_copy;
		}
		else
		{
			mem = 0;
			prime_copy++;
		}
		esc++;
	}
	return prime_copy;
}

int searching_number_in_CP(int CP, int number)					//Выводит number, если он есть в составе цифр числа CP. (else return 0)
{
	int i1 = counting_numbers(CP);									//i1 - счетчик, значение которого равно количеству введенных пунктов
	for (i1; i1 >= 0; i1--)
	{
		if (CP > 0)													//Ветвление для обработки положительных ...
		{
			if (CP % 10 == number)									
			{
				return number;											//Если номер пункта присутствует в CP, нас это уже устраивает.
			}
			else														//Если совпадения нет, откидываем последнюю цифру и по новой.
			{
				CP = CP / 10;
			}
		}
		else														// ... и отрицательных входных данных
		{
			if (-CP % 10 == number)		
			{
				return number;
			}
			else
			{
				CP = CP / 10;
			}
		}
	}
	return 0;														//Если за весь цикл совпадений не нашлось --> возращаем 0.
}

int sorting_CHOOSED_POITS_function(int CP)						//Сортирует цифры в введённом числе в порядок по убыванию (от 5 до 1)
{
	if (CP == 0)
	{
		return 54321;
	}
	int sorted_CP = 0;												//Сюда будем записывать отсор-ные пункты (от большего к меньшему подряд)
	for (int i1 = 5; i1 >= 1; i1--)									//i1 просто отсчитывает от 5 до 1
	{
		if (searching_number_in_CP(CP, i1) != 0)
		{
			sorted_CP = sorted_CP * 10 + searching_number_in_CP(CP, i1);
		}
		else
		{
			std::cout << "Item number " << i1 << " will be skipped" << std::endl;
		}
	}
	return sorted_CP;												//После окончания работы цикла возращаем отсорт-ные номера пунктов
}

int on_or_off_item(int item, int CP)							//Решает, включен ли пункт в CHOOSED_POINTS или нет (если да возращает № пункта)
{
	if (CP % 10 == item)
	{
		return item;
	}
	else
	{
		return 0;
	}
}

int ITEM_1_counting_numbers(int MD, int CP)
{
	if (on_or_off_item(1, CP) == 1)
	{
		CP = CP / 10;
		std::cout << std::endl << ">---  ITEM 1 <<Counting digits>>  ---<" << std::endl;
		int numbers = counting_numbers(MD);
		if (numbers == 1)
		{
			std::cout << "There is 1 digit in " << MD << std::endl;
		}
		else
		{
			std::cout << "There are " << numbers << " digits in " << MD << std::endl;
		}
	}
	return CP;
}

int ITEM_2_dividing_at_categories(int MD, int CP)				//Разбивает MAIN_DIGIT на разряды
{
	if (on_or_off_item(2, CP) == 2)
	{
		CP = CP / 10;
		std::cout << std::endl << ">---  ITEM 2 <<Dividing at categories>>  ---<" << std::endl;
		int REM, i1 = 1, i2 = counting_numbers(MD);							//REM - коэффициент перед разрядом, i1 и i2 - счетчики.
		std::cout << MD << " = ";
		while (i1 <= i2)
		{
			REM = MD % 10;
			MD = MD / 10;
			REM = REM * pow_10_function(i1 - 1);
			std::cout << REM;
			if (i1 != i2)
			{
				std::cout << " + ";
			}
			else
			{
				std::cout << std::endl;
			}
			i1++;
		}
	}
	return CP;
}

int ITEM_3_counting_factorial(int MD, int CP)					//Считает факториал от MAIN_DIGIT
{
	if (on_or_off_item(3, CP) == 3)
	{
		CP = CP / 10;
		std::cout << std::endl << ">---  ITEM 3 <<Counting factorial>>  ---<" << std::endl;
		std::cout << "|" << MD << "|! = " << counting_factorial(MD) << std::endl;
	}
	return CP;
}

int ITEM_4_searching_divisors(int MD, int CP)					//Выводит делители числа
{
	if (on_or_off_item(4, CP) == 4)
	{
		CP = CP / 10;
		std::cout << std::endl << ">---  ITEM 4 <<Serching for divisors>>  ---<" << std::endl;
		std::cout << MD << " divides by: " << std::endl;
		int MD_copy = MD;											//Копия MD, которую можно менять и сравнивать с оригиналом
		while (MD_copy >= 1)
		{ 
			if (MD % MD_copy == 0)
			{
				std::cout << MD_copy;
				if (MD_copy != 1)
				{
					std::cout << ",  ";
				}
				else
				{
					std::cout << ".";
				}
			}
			MD_copy--;
		}
		std::cout << std::endl;
	}
	return CP;
}

int ITEM_5_dividing_by_primi_digits(int MD, int CP)
{
	if (on_or_off_item(5, CP) == 5)
	{
		CP = CP / 10;
		std::cout << std::endl << ">---  ITEM 5 <<Dividing by primi digits>>  ---<" << std::endl;
		std::cout << MD << " consists of: " << std::endl;
		int prime = 2;
		while (MD > 1)
		{
			int sum = 0;
			while (MD % prime == 0)
			{
				MD = MD / prime;
				sum++;
			}
			if (sum == 0)
			{
				prime = searching_next_prime_number(prime);
			}
			if (sum == 1)
			{
				std::cout << prime;
				if (MD != 1)
				{
					std::cout << ", ";
				}
				else
				{
					std::cout << ".";
				}
			}
			if (sum > 1)
			{
				std::cout << prime << "^" << sum;
				if (MD != 1)
				{
					std::cout << ", ";
				}
				else
				{
					std::cout << ".";
				}
			}
		}
	}
	return CP;
}

int client_call()												//Главная функция, которая обрабатывает одно обращение пользователя.
{
	int CHOOSED_POINTS;
	std::cout << "Enter the items you need in a row," << std::endl << "or enter < 0 > to skip this stage: ";
	CHOOSED_POINTS = cin_integer_function();						//Вводим выбранные пункты
	//sorting CHOOSED_POINTS
	CHOOSED_POINTS = sorting_CHOOSED_POITS_function(CHOOSED_POINTS);//Отсортировываем выбранные пункты
	std::cout << "CHOOSED_POINTS after sorting: " << CHOOSED_POINTS << std::endl;
	std::cout << "Enter your nuber: ";
	int MAIN_DIGIT = cin_integer_function();						//Вводим число пользователя
	std::cout << "Your nuber is " << MAIN_DIGIT << std::endl;

	CHOOSED_POINTS = ITEM_1_counting_numbers(MAIN_DIGIT, CHOOSED_POINTS);

	std::cout << std::endl << "CHOOSED_POINTS after ITEM 1: " << CHOOSED_POINTS << std::endl;

	CHOOSED_POINTS = ITEM_2_dividing_at_categories(MAIN_DIGIT, CHOOSED_POINTS);

	std::cout << std::endl << "CHOOSED_POINTS after ITEM 2: " << CHOOSED_POINTS << std::endl;

	CHOOSED_POINTS = ITEM_3_counting_factorial(MAIN_DIGIT, CHOOSED_POINTS);

	std::cout << std::endl << "CHOOSED_POINTS after ITEM 3: " << CHOOSED_POINTS << std::endl;

	CHOOSED_POINTS = ITEM_4_searching_divisors(MAIN_DIGIT, CHOOSED_POINTS);

	std::cout << std::endl << "CHOOSED_POINTS after ITEM 4: " << CHOOSED_POINTS << std::endl;

	CHOOSED_POINTS = ITEM_5_dividing_by_primi_digits(MAIN_DIGIT, CHOOSED_POINTS);

	std::cout << std::endl << "CHOOSED_POINTS after ITEM 4: " << CHOOSED_POINTS << std::endl;



	int restart_client_call_2;										//Переменная, от значения которой будет зависеь рестарт программы
	restart_client_call_2 = restart_client_call_functiom();			//Узнаем от пользователя его решение продолжении/остановке работы программы
	if (restart_client_call_2 == 1)									//Индикация перезапука программы вслучае выбора такогого
	{
		std::cout << std::endl << "Loading ... " << std::endl << std::endl;
	}
	return restart_client_call_2;									//передаем решение о рестарте в main()
}

int main()														//Ну типа main ()
{
    std::cout << "The program successfuly started!";
	std::cout << std::endl << "--------------------------------" << std::endl;
	int restart_client_call_3 = 1;									//Переменная, от значения которой будет зависеь рестарт программы
	while (restart_client_call_3 == 1)								
	{
		restart_client_call_3 = client_call();						//В конце clien_call обязан быдь оеператор ввода переменной ... 
	}																//... и возврат введенного значения
	std::cout << "--------------------------------" << std::endl;
	std::cout << "See you next time!" << std::endl;
	return 0;
}

/*
Задача: Написать скрипт, который будет раскладывать введённое число на простые множители.

Решение: 
	Перебираем простые числа, начиная с наименьшего (2)

		1. На входе мы получаем число пользователя (MD)
		2. Оно попадает в цикл, где будет делиться пока не станет 1
			2.1. В цикле оно попадет в while, где проверяется его делимость на первое простое число (2)
				2.1.1. Если оно делиться на первое простое ->
				 2.1.1.1. Разделить на первое простое
				 2.1.1.2. Счетчик +++
				2.2. Если оно уже/еще не делиться на простое ->
				 2.2.1.1. Если счетчик == 0 ->
					2.2.1.1.2.1 Сгенерировать следущее простое и в п. 2.1.
						2.2.1.1.2.1.1. На входе получаем простое число (2)
						2.2.1.1.2.1.2. Прибовляем к нему 1 (prostoe = prostoe + 1)
						2.2.1.1.2.1.3. prostoe попадает в цикл, где оно делиться на все предыдущие числа кроме 1
							2.2.1.1.2.1.3.1. Если ни одно не разделилось с остаком 0 - простое, return
							2.2.1.1.2.1.3.2. Если есть одно и более делений - составное, prostoe + 1 и в п. 2.2.1.1.2.1.3.
				 2.2.1.2. Если счетчик != 0 -> 
					2.2.1.2.2.1. Вывести простое и счетчик
					2.2.1.2.2.2. Сгенерировать следущее простое и в п. 2.1.
						2.2.1.2.2.2.1. На входе получаем простое число (2)
						2.2.1.2.2.2.2. Прибовляем к нему 1 (prostoe = prostoe + 1)
						2.2.1.1.2.1.3. prostoe попадает в цикл, где оно делиться на все предыдущие числа кроме 1
							2.2.1.2.2.2.3.1. Если ниодно не разделилось с остаком 0 - простое, return
							2.2.1.2.2.2.3.2. Если есть одно и более делений - составное, prostoe + 1 и в п. 2.2.1.2.2.2.3.








	int vernu_kol_deleniy (int MD, int prostoe)
	{
	int sh = 0
	while (MD_copy % prostoe == 0)
	{
		MD_copy = MD_copy / prostoe (2)
		sh++
	}
	return prostoe0sh
	}



	prostoe = prime_function (a)
	While (MD >= 1)
	{
		if (MD % prostoe (2) == 0)
		{
			std::cout << prostoe (2)
			MD = MD / prosoe
		}



		else
		{
			sleduShee prostoe
		}
	}
	

	Введенное число делим на результаты работы этого скрипта пока оно не станет 1
		IF Введённое число делится на простое ---> делить
		ELSE Создать следущее простое

*/

/*
Задача: случайный набор цифр от 1 до 5 расположить в порядке убывания

Решение: 
	1. Ищем в числе максимальную цифру (5), если не наши, искать повторо бесполезно

		Нужна функция, которая на вход получает  1. Выбранные пункты (CP),  2. Номер пункта (number), а
		на выходе отвечает на вопрос, Есть ли среди выпбранных пуктов(CP) введённый пункт (number).

		Отдельная функция, которая получает число (CHOOSED_POINTS) и номер пункта, а далее:
			IF номер п. присутствует в числе, то return номер п.
			ELSE return 0; 
			скормить функции (число, 5) if (номер п. != 0; память = память * 10 + номер п.) 
			скормить функции (число, 4) if (номер п. != 0; память = память * 10 + номер п.)
			скормить функции (число, 3) if (номер п. != 0; память = память * 10 + номер п.)
			скормить функции (число, 3) if (номер п. != 0; память = память * 10 + номер п.)
			скормить функции (число, 1) if (номер п. != 0; память = память * 10 + номер п.)
		Придумать цикл while или for для всего этого
*/		
	
/*
Задача: Написать функцию, которая будет проверять наличие номера пункта в CHOOSED_POINTS

Решение:
	1. Функция на вход получает номер пункта и CHOOSED_POINTS, а на выходе будет отправлять номер пункта 
	если пункт имеется в CHOOSED_POINTS, или просто 0 если этого пунктва там нет.
		name_functiom (<<punkt>>, CP) { if (CP % 10 == <<punkt>>) { return <<pumkt>> } else { return 0 } }
	2. За функцией должен идти оператор if:
		if <<возращаемое значение>> == номеру пункта --> Выполнить пункт
	3. Всё это запихнуть в функцию, посвящённую самому пункту.
*/

/*
Задача: Написать функцию, которая ищен факториал от введенног числа

Решение:
	n! = n * (n-1) * (n-2) * (n-3) * ... * 2 * 1
	Функция вычитает из n единичку и если n >= 1 умножает его на предыдущее
		int factorial = n
		if ( n > 1)
		{
			n = n - 1
			factorial = factorial * n
		}
		else { return factorial }
*/

/*
Задача: Написать программу, котора будет раскладывать по разрядам введённое число

Решаение:
	Программа на вхоже будет получать число (A), а на выходе должна выводиться сумма чисел, 
	являющихся разрядами введённого числа. Как это сделать?
		1. Узнать последнюю цифру числа (Last)
		2. Умножить на 10 столько раз, сколько таких чисел уже было найдено до этого
			Написать функцию, которая на входе получает число, а на выхоже возращает
			10 в степениэтого числа
			Если i1 - количество уже найденных Last (количество уже сделанных ходов), 
			то нам нужно:
			Last = Last * functia (i1) <==> Last = Last * 10^i1
		3. С функцией: Умножить Last на pow_10_function ( количество ходов )	
		4. Вывести получившеееся число и за ним знак "+".
*/

/*
Задача: Написать программу, которая выводит все числа, которые нацело делятся на введённое

Решение:
	Програма, которая на входе получает число, а результатом своей работы выводит на экран список чисел, 
	которые делфятся на введённое без остатка.

*/
