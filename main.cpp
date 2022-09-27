#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

int main()
{
    int win;
    int input;
    int computerNum[4];
    int playerNum[4];

    srand(time(NULL));

    // создание рандомного набора чисел
    for (int i = 0; i < 4; ++i)
    {
        computerNum[i] = rand() % 10;

        for (int c = 0; c < 5; ++c)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (computerNum[i] == computerNum[i - j])
                {
                    computerNum[i] += 1;
                    computerNum[i] %= 10;
                }
            }
        }
    }

    // если расскоментировть 36 - 40 строки, то будет показываться созаднный набор чисел

    // for (int i = 0; i < 4; ++i)
    // {
    //     cout << computerNum[i];
    // }
    // cout << endl;

    // главный игровой цикл
    while (win != 4)
    {
        while (true)
        {
            int f = 0;
            cout << "Введите свое число (4 цифры)" << endl;
            cin >> input;

            // запись полученного числа в массив
            for (int i = 0; i < 4; ++i)
            {
                playerNum[3 - i] = input % 10;
                input /= 10;

                for (int j = 3; j > 3 - i; --j)
                {
                    if (playerNum[3 - i] == playerNum[j])
                    {
                        cout << "Нельзя вводить число с повторяющимеся цифрами" << endl;
                        cout << "____________________________" << endl;
                        cout << endl;
                        f = 1;
                        break;
                    }
                }
                if (f == 1)
                {
                    break;
                }
            }
            if (f != 1)
            {
                break;
            }
        }

        int bulls = 0;
        int cows = 0;

        // сравнивание двух массивов
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (playerNum[i] == computerNum[j])
                {
                    if (i == j)
                    {
                        bulls += 1;
                    }
                    else
                    {
                        cows += 1;
                    }
                }
            }
        }

        cout << "Быки: " << bulls << endl;
        cout << "Коровы: " << cows << endl;
        cout << "____________________________" << endl;

        win = bulls;

        cout << endl;
    }

    cout << "Поздравляю, вы победили!" << endl;
}
