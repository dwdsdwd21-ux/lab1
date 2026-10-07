#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

namespace {

const int kMaxArraySize = 100;

void ClearInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int ReadInt(const std::string& prompt, int min, int max) {
  int value;
  while (true) {
    std::cout << prompt;
    std::cin >> value;
    if (std::cin.fail() || std::cin.peek() != '\n' || value < min ||
        value > max) {
      ClearInput();
      std::cout << "Ошибка! Введите целое число от " << min << " до " << max
                << ".\n";
    } else {
      return value;
    }
  }
}

double ReadDouble(const std::string& prompt, double min, double max) {
  double value;
  while (true) {
    std::cout << prompt;
    std::cin >> value;
    if (std::cin.fail() || std::cin.peek() != '\n' || value < min ||
        value > max) {
      ClearInput();
      std::cout << "Ошибка! Введите число от " << min << " до " << max
                << ".\n";
    } else {
      return value;
    }
  }
}

char ReadDigitChar(const std::string& prompt) {
  std::string line;
  while (true) {
    std::cout << prompt;
    std::cin >> line;
    if (line.size() == 1 && line[0] >= '0' && line[0] <= '9') {
      return line[0];
    }
    ClearInput();
    std::cout << "Ошибка! Нужна одна цифра от 0 до 9.\n";
  }
}

int ReadArray(int arr[], const std::string& name) {
  int size = ReadInt("Размер массива " + name + " (1-100): ", 1,
                     kMaxArraySize);
  for (int i = 0; i < size; ++i) {
    arr[i] = ReadInt(name + "[" + std::to_string(i) + "] = ", -1000, 1000);
  }
  return size;
}

void PrintArray(const int arr[], int size) {
  std::cout << "[";
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i];
    if (i < size - 1) std::cout << ", ";
  }
  std::cout << "]\n";
}

double Fraction(double x) { return x - static_cast<int>(x); }

int CharToNum(char x) { return x - '0'; }

bool Is2Digits(int x) {
  return (x >= 10 && x <= 99) || (x >= -99 && x <= -10);
}

bool IsInRange(int a, int b, int num) {
  return num >= std::min(a, b) && num <= std::max(a, b);
}

bool IsEqual(int a, int b, int c) { return a == b && b == c; }

int Abs(int x) {
  if (x < 0) return -x;
  return x;
}

bool Is35(int x) {
  if (x % 15 == 0) return false;
  return x % 3 == 0 || x % 5 == 0;
}

int Max3(int x, int y, int z) {
  int max = x;
  if (y > max) max = y;
  if (z > max) max = z;
  return max;
}

std::string Age(int x) {
  int last_two = x % 100;
  int last = x % 10;
  std::string word;
  if (last_two >= 11 && last_two <= 14) {
    word = "лет";
  } else if (last == 1) {
    word = "год";
  } else if (last >= 2 && last <= 4) {
    word = "года";
  } else {
    word = "лет";
  }
  return std::to_string(x) + " " + word;
}

std::string Day(int x) {
  switch (x) {
    case 1: return "понедельник";
    case 2: return "вторник";
    case 3: return "среда";
    case 4: return "четверг";
    case 5: return "пятница";
    case 6: return "суббота";
    case 7: return "воскресенье";
    default: return "это не день недели";
  }
}

std::string ListNums(int x) {
  std::string result;
  for (int i = 0; i <= x; ++i) {
    result += std::to_string(i) + " ";
  }
  return result;
}

std::string Chet(int x) {
  std::string result;
  for (int i = 0; i <= x; i += 2) {
    result += std::to_string(i) + " ";
  }
  return result;
}

int NumLen(long x) {
  if (x == 0) return 1;
  int count = 0;
  while (x != 0) {
    x /= 10;
    ++count;
  }
  return count;
}

void Square(int x) {
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < x; ++j) std::cout << '*';
    std::cout << '\n';
  }
}

void RightTriangle(int x) {
  for (int i = 1; i <= x; ++i) {
    for (int j = 0; j < x - i; ++j) std::cout << ' ';
    for (int j = 0; j < i; ++j) std::cout << '*';
    std::cout << '\n';
  }
}

int FindFirst(const int arr[], int size, int x) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) return i;
  }
  return -1;
}

int MaxAbs(const int arr[], int size) {
  int result = arr[0];
  for (int i = 1; i < size; ++i) {
    if (Abs(arr[i]) > Abs(result)) result = arr[i];
  }
  return result;
}

int* Add(const int arr[], int size, const int ins[], int ins_size, int pos) {
  int* result = new int[size + ins_size];
  int k = 0;
  for (int i = 0; i < pos; ++i) result[k++] = arr[i];
  for (int i = 0; i < ins_size; ++i) result[k++] = ins[i];
  for (int i = pos; i < size; ++i) result[k++] = arr[i];
  return result;
}

int* ReverseBack(const int arr[], int size) {
  int* result = new int[size];
  for (int i = 0; i < size; ++i) {
    result[i] = arr[size - 1 - i];
  }
  return result;
}

int* FindAll(const int arr[], int size, int x, int* result_size) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) ++count;
  }
  *result_size = count;
  if (count == 0) return nullptr;

  int* result = new int[count];
  int k = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) result[k++] = i;
  }
  return result;
}

void RunMethods() {
  std::cout << "\n--- Задание 1. Методы ---\n"
               "1) Дробная часть\n2) Букву в число\n3) Двузначное\n"
               "4) Диапазон\n5) Равенство\n";
  switch (ReadInt("Выберите задачу: ", 1, 5)) {
    case 1: {
      double x = ReadDouble("x = ", -1e6, 1e6);
      std::cout << "Результат: " << Fraction(x) << '\n';
      break;
    }
    case 2: {
      char x = ReadDigitChar("Символ-цифра x = ");
      std::cout << "Результат: " << CharToNum(x) << '\n';
      break;
    }
    case 3: {
      int x = ReadInt("x = ", -1000000, 1000000);
      std::cout << "Результат: " << Is2Digits(x) << '\n';
      break;
    }
    case 4: {
      int a = ReadInt("a = ", -1000000, 1000000);
      int b = ReadInt("b = ", -1000000, 1000000);
      int num = ReadInt("num = ", -1000000, 1000000);
      std::cout << "Результат: " << IsInRange(a, b, num) << '\n';
      break;
    }
    case 5: {
      int a = ReadInt("a = ", -1000000, 1000000);
      int b = ReadInt("b = ", -1000000, 1000000);
      int c = ReadInt("c = ", -1000000, 1000000);
      std::cout << "Результат: " << IsEqual(a, b, c) << '\n';
      break;
    }
  }
}

void RunConditions() {
  std::cout << "\n--- Задание 2. Условия ---\n"
               "1) Модуль числа\n2) Тридцать пять\n3) Тройной максимум\n"
               "4) Возраст\n5) День недели\n";
  switch (ReadInt("Выберите задачу: ", 1, 5)) {
    case 1: {
      int x = ReadInt("x = ", -1000000, 1000000);
      std::cout << "Результат: " << Abs(x) << '\n';
      break;
    }
    case 2: {
      int x = ReadInt("x = ", -1000000, 1000000);
      std::cout << "Результат: " << Is35(x) << '\n';
      break;
    }
    case 3: {
      int x = ReadInt("x = ", -1000000, 1000000);
      int y = ReadInt("y = ", -1000000, 1000000);
      int z = ReadInt("z = ", -1000000, 1000000);
      std::cout << "Результат: " << Max3(x, y, z) << '\n';
      break;
    }
    case 4: {
      int x = ReadInt("Возраст (0-150): ", 0, 150);
      std::cout << "Результат: " << Age(x) << '\n';
      break;
    }
    case 5: {
      int x = ReadInt("Номер дня (-100..100): ", -100, 100);
      std::cout << "Результат: " << Day(x) << '\n';
      break;
    }
  }
}

void RunLoops() {
  std::cout << "\n--- Задание 3. Циклы ---\n"
               "1) Числа подряд\n2) Четные числа\n3) Длина числа\n"
               "4) Квадрат\n5) Правый треугольник\n";
  switch (ReadInt("Выберите задачу: ", 1, 5)) {
    case 1: {
      int x = ReadInt("x (0-100): ", 0, 100);
      std::cout << "Результат: " << ListNums(x) << '\n';
      break;
    }
    case 2: {
      int x = ReadInt("x (0-100): ", 0, 100);
      std::cout << "Результат: " << Chet(x) << '\n';
      break;
    }
    case 3: {
      int x = ReadInt("x = ", -2000000000, 2000000000);
      std::cout << "Результат: " << NumLen(x) << '\n';
      break;
    }
    case 4:
      Square(ReadInt("Размер (1-20): ", 1, 20));
      break;
    case 5:
      RightTriangle(ReadInt("Высота (1-20): ", 1, 20));
      break;
  }
}

void RunArrays() {
  std::cout << "\n--- Задание 4. Массивы ---\n"
               "1) Поиск первого значения\n2) Поиск максимального\n"
               "3) Добавление массива в массив\n4) Возвратный реверс\n"
               "5) Все вхождения\n";
  int task = ReadInt("Выберите задачу: ", 1, 5);

  int arr[kMaxArraySize];
  int size = ReadArray(arr, "arr");

  switch (task) {
    case 1: {
      int x = ReadInt("x = ", -1000, 1000);
      std::cout << "Результат: " << FindFirst(arr, size, x) << '\n';
      break;
    }
    case 2:
      std::cout << "Результат: " << MaxAbs(arr, size) << '\n';
      break;
    case 3: {
      int ins[kMaxArraySize];
      int ins_size = ReadArray(ins, "ins");
      int pos = ReadInt("pos (0-" + std::to_string(size) + "): ", 0, size);
      int* result = Add(arr, size, ins, ins_size, pos);
      std::cout << "Результат: ";
      PrintArray(result, size + ins_size);
      delete[] result;
      break;
    }
    case 4: {
      int* result = ReverseBack(arr, size);
      std::cout << "Результат: ";
      PrintArray(result, size);
      delete[] result;
      break;
    }
    case 5: {
      int x = ReadInt("x = ", -1000, 1000);
      int result_size = 0;
      int* result = FindAll(arr, size, x, &result_size);
      std::cout << "Результат: ";
      PrintArray(result, result_size);
      delete[] result;
      break;
    }
  }
}

}

int main() {
#ifdef _WIN32
  SetConsoleCP(65001);
  SetConsoleOutputCP(65001);
#endif
  std::cout << std::boolalpha;

  while (true) {
    std::cout << "\n===== Лабораторная работа №1 =====\n"
                 "1) Методы\n2) Условия\n3) Циклы\n4) Массивы\n0) Выход\n";
    switch (ReadInt("Ваш выбор: ", 0, 4)) {
      case 0:
        std::cout << "До свидания!\n";
        return 0;
      case 1:
        RunMethods();
        break;
      case 2:
        RunConditions();
        break;
      case 3:
        RunLoops();
        break;
      case 4:
        RunArrays();
        break;
    }
  }
}
