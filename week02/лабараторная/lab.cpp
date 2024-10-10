#include  <iostream>		//для использования потоков ввода/вывода


int nTwin=1;			//глобальная переменная
	//переменная объявлена в
						//пространстве имен - TwinSpace

#define	  stop do{ } while(0);

int main()
{
	// ********************************************************
	//Задание 9. Циклы.

	//Задание 9.1 Напишите фрагмент кода, который реализует с помощью for
	//следующую логику: найти сумму заданного диапазона целых чисел.
	//Введите границы с помощью потока ввода или с помощью средств отладки.
	//Предусмотрите защиту от ввода нижней границы больше, чем верхней.
	{
		
		//сформироыать границы диапазона
		int low, high, sum;
		//проверить корректность значений
		do
		{
			std::cout << "Введите начало отсчёта (a): ";
			std::cin >> low;

			std::cout << "Введите конец отсчёта (b): ";
			std::cin >> high;
		} while (high < low);
		// вычислить сумму
		for (int i = low; i <= high; i ++) {
            sum += i;
        }

		std::cout<< "Сумма всех элементов: " << sum << std::endl;
		
		// проверить в отладчике значение
		stop
		
	}


	//Задание 9.2 Напишите фрагмент кода, который реализует с помощью do-while
	//следующую логику: на каждой итерации цикла ввести с консоли целое значение
	// и покинуть цикл, если значение удовлетворяет условию: 
	// значение больше или равно 10 и четное.
	//Замечание: проверка на четность с использованием операции остатка от деления
	//нацело генерирует очень неэффективный код. Попробуйте реализовать альтернативный
	//вариант.
	/*
	{
		int x;
        bool flag = false;

		do
		{
			std::cout << "Введите число: ";
			std::cin >> x;
        
			for (int i = 10; i <= x; i += 2)
			{
				if (x - i == 0) {
                    flag = true; 
                    break;
                }
			};

		} while (x >= 10 && not(flag));
		
		std::cout<< "\nФрагмент программы окончен." << std::endl;
	}

	//Задание 9.3 Напишите фрагмент кода, который реализует с помощью while
	//следующую логику: исходно int x = 0; 
	//на каждой итерации x=x+1, sum=sum+1/x
	//найти значение x, при котором sum>1.7

	{
		int x = 0;
		float sum = 0;
		
		while (sum < 1.7) {
			x++;
			sum += (1.f/x);
		};

		std::cout<< "sum = " << sum << std::endl;
		std::cout<< "x = " << x << std::endl;
	}
	*/
	return 0;//код (80) завершения приложения
}	// Конец функции main()