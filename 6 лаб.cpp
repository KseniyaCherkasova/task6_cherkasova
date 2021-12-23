#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));

    int k;
    int n;
    int** matrix;
    int* a;
    char ch;

    do
    {
        n = -1;

        while (n <= 0)
        {
            cout << "Укажите размер квадратной матрицы: "; cin >> n;

            if (n <= 0)
                cout << "ОШИБКА! n должно быть больше нуля" << endl << endl;
        }

        cout << "Укажите 'а'. Всего значений: " << n << ". Рандом или ручной ввод? (1 или 2) "; cin >> k;


        a = new int[n];

        if (k == 1)
        {
            for (int i = 0; i < n; i++)
                a[i] = rand() % 10 - 5;
        }
        else {
            for (int i = 0; i < n; i++)
                cin >> a[i];
        }


        matrix = new int* [n];


        cout << "a:        matrix:" << endl;
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];

            cout << setw(2) << a[i] << "      ";
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = rand() % 10 - 5;
                cout << setw(3) << matrix[i][j] << " ";
            }
            cout << endl;
        }




        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] > 0)
                    {
                        matrix[i][j] = 1;
                    }
                    else if (matrix[i][j] < 0)
                    {
                        matrix[i][j] = -1;
                    }
                }
            }
        }

        cout << "Матрица после выполнения программы: " << endl;
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << setw(2) << matrix[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++)
            delete[] matrix[i];

        delete[] matrix;
        delete[] a;

        cout << "Ещё раз выполнить? ввести y - да, n - нет: "; cin >> ch;
    } while (ch != 'n');

}
