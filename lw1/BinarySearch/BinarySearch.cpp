#include <iostream>
#include <fstream>

using namespace std;

int BinarySearch(int list[], int item)
{
    int low = 0;
    int high = sizeof(list) / sizeof(int);
    int mid, guess;

    while (low <= high)
    {
        mid = (low + high) / 2;
        guess = list[mid];
        if (guess == item)
        {
            return mid;
        }
        if (guess > item)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "rus");

    int count, key, result;

    ifstream input("input.txt");
    if (!input.is_open())
    {
        puts("Не удалось открыть файл для чтения");
        return 1;
    }

    puts("Введите элемент, который хотите найти.");
    cin >> key;

    input >> count;

    int *arr = new int[count];
    char ch;

    for (int i = 0; i < count; i++)
    {
        input >> ch;
        arr[i] = ch - '0';
    }
    result = BinarySearch(arr, key);
    if (result == -1)
    {
        puts("Такого элемента не существует");
    }
    else
    {
        cout << "Элемент " << key << " находится на " << result + 1 << " позиции.";
    }
    return 0;
}