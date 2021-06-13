// LifeGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <random>
#include <sstream>
#include "GameBoard.h"

int main()
{
    std::vector<std::vector<bool>> matrix;

    /* {
        std::ifstream fin("C:\\Users\\timav\\documents\\garbage\\someshit.txt");
        std::string str;
        while (std::getline(fin, str)) {
            std::vector<bool> temp;
            for (auto i : str) {
                temp.push_back(i - 48);
            }
            matrix.push_back(temp);
        }
    }*/
    srand(time(0));
    for (int i = 0; i != 25; ++i) {
        std::vector<bool> temp;
        for (int j = 0; j != 100; ++j) {
            temp.push_back(rand() % 2);
        }
        matrix.push_back(std::move(temp));
    }

    GameBoard gb(std::move(matrix));
    try {
        while (true) {
            system("cls");
            std::ostringstream ss;
            for (const auto& i : gb.getMatrix()) {
                for (auto j : i)
                    ss << (j ? '#' : ' ');
                ss << std::endl;
            }
            std::cout << ss.str();
            gb.iterate();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
