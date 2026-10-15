
// библиотеки
#include <iostream>
#include <string>
#include <Windows.h>

int main()
{

    // чтобы в консоли норм писало по-русски
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::string input; // сюда читаем то, что ввел чел в меню
    char choose;       // из строки берем только первую букву, это и будет выбор

    // крутим меню, пока не выберут выход
    while (true)
    {
        system("cls"); // чистим экран, чтобы не было каши

        std::cout << "1 - Мин и макс\n";
        std::cout << "2 - Сумма\n";
        std::cout << "3 - Прибыль\n";
        std::cout << "4 - Зарплата\n";
        std::cout << "0 - Выход\n";
        std::cout << "\nВвод: ";

        // читаем целую строку, а не одну букву, чтобы лишний enter не ломал ввод
        std::getline(std::cin, input);
        choose = input[0];

        if (choose == '0')
        {
            // выход, вылетаем из цикла
            break;
        }
        else if (choose == '1')
        {
            // пункт 1. ищем мин и макс в массиве
            system("cls");

            const int size = 10;
            int arr[size]{};

            // заполняем случайными числами от 0 до 99 и сразу вывод
            std::cout << "Массив: ";
            for (int i = 0; i < size; i++)
            {
                arr[i] = rand() % 100;
                std::cout << arr[i] << " ";
            }

            // сначала считаем, что и мин и макс это первый элемент
            int min_num = arr[0];
            int max_num = arr[0];

            // идем по массиву и сравниваем каждый элемент
            for (int i = 0; i < size; i++)
            {
                if (arr[i] < min_num)
                {
                    min_num = arr[i]; // нашли число меньше, запоминаем
                }
                if (arr[i] > max_num)
                {
                    max_num = arr[i]; // нашли число больше, запоминаем
                }
            }

            std::cout << "\n\nМин: " << min_num;
            std::cout << "\nМакс: " << max_num << "\n";
            system("pause"); // ждем нажатия, чтобы успеть прочитать
        }
        else if (choose == '2')
        {
            // пункт 2: сумма элементов, которые меньше введённого числа
            system("cls");

            const int size = 10;
            int arr[size]{};
            int from, to, number;

            std::cout << "Начало диапазона: ";
            std::cin >> from;
            std::cout << "Конец диапазона: ";
            std::cin >> to;
            std::cout << "Введите число: ";
            std::cin >> number;
            std::cin.ignore(); // не совсем понял для чего это тут(

            // если начало больше конца, диапазон какой-то неправильный
            if (from > to)
            {
                std::cout << "\nНекорректный ввод\n";
            }
            else
            {
                int sum = 0;

                std::cout << "\nМассив: ";
                for (int i = 0; i < size; i++)
                {
                    // формула даёт случайное число от from до to
                    arr[i] = rand() % (to - from + 1) + from;
                    std::cout << arr[i] << " ";

                    // если число меньше нужного, добавляем в сумму
                    if (arr[i] < number)
                    {
                        sum += arr[i];
                    }
                }

                std::cout << "\n\nСумма меньше " << number << ": " << sum << "\n";
            }
            system("pause");
        }
        else if (choose == '3')
        {
            // пункт 3. прибыль по месяцам, ищем лучший и худший месяц
            system("cls");

            int profit[12]{}; // по одной ячейке на каждый мес
            int start, finish;

            // вводим прибыль за весь год
            for (int i = 0; i < 12; i++)
            {
                std::cout << "Прибыль за " << i + 1 << " месяц: ";
                std::cin >> profit[i];
            }

            // теперь спрашиваем, с какого по какой мес смотреть
            std::cout << "Начало диапазона: ";
            std::cin >> start;
            std::cout << "Конец диапазона: ";
            std::cin >> finish;
            std::cin.ignore();

            // месяцы бывают только с 1 по 12, и начало не должно быть больше конца
            if (start < 1 || finish > 12 || start > finish)
            {
                std::cout << "\nНеверный ввод\n";
            }
            else
            {
                // запоминаем номера месяцев, а не саму прибыль
                int max_month = start;
                int min_month = start;

                for (int i = start; i <= finish; i++)
                {
                    // в массиве месяцы с нуля, поэтому везде i - 1
                    if (profit[i - 1] > profit[max_month - 1])
                    {
                        max_month = i;
                    }
                    if (profit[i - 1] < profit[min_month - 1])
                    {
                        min_month = i;
                    }
                }

                std::cout << "\nМакс прибыль: " << max_month << " месяц (" << profit[max_month - 1] << ")\n";
                std::cout << "\nМин прибыль: " << min_month << " месяц (" << profit[min_month - 1] << ")\n";
            }
            system("pause");
            }
        else if (choose == '4')
        {
            // пункт 4. считаем зарплату трёх менеджеров
            system("cls");

            double sales[3]{};  // сколько продали
            double salary[3]{}; // сколько им платить

            // вводим продажи каждого менеджера
            for (int i = 0; i < 3; i++)
            {
                std::cout << "Продажи менеджера " << i + 1 << ": ";
                std::cin >> sales[i];
            }
            std::cin.ignore();

            // оклад 200 и процент от продаж, чем больше продал, тем выше процент
            for (int i = 0; i < 3; i++)
            {
                if (sales[i] < 500)
                {
                    salary[i] = 200 + sales[i] * 0.03; // меньше 500 - 3%
                }
                else if (sales[i] <= 1000)
                {
                    salary[i] = 200 + sales[i] * 0.05; // от 500 до 1000 - 5%
                }
                else
                {
                    salary[i] = 200 + sales[i] * 0.08; // больше 1000 - 8%
                }
            }

            // ищем, у кого зарплата больше всех
            int best = 0;
            for (int i = 0; i < 3; i++)
            {
                if (salary[i] > salary[best])
                {
                    best = i;
                }
            }

            // лучшему даем премию 200
            salary[best] += 200;

            std::cout << "\n";
            for (int i = 0; i < 3; i++)
            {
                std::cout << "Менеджер " << i + 1 << ": " << salary[i] << "$\n";
            }

            // best считали с нуля, а менеджеры у нас с единицы, поэтому + 1
            std::cout << "\nЛучший менеджер: " << best + 1 << " (премия 200$)\n";
            system("pause");
            }
        else
        {
            // ввели что-то, чего нет в меню (на всякий)
            std::cout << "\n\nНекорректный ввод";
            system("pause");
            }
    }

    // конец проги
    return 0;
}