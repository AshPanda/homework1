/*
1. Создать класс Power, который содержит два вещественных числа.Этот класс должен иметь две переменные - члена для хранения этих вещественных чисел.
Еще создать два метода : один с именем set, который позволит присваивать значения объявленным в классе переменным, второй — calculate, 
который будет выводить результат возведения первого числа в степень второго числа.Задать значения этих двух чисел по умолчанию.

2. Написать класс с именем RGBA, который содержит 4 переменные - члена типа std::uint8_t : m_red, m_green, m_blue и m_alpha
(#include cstdint для доступа к этому типу).Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha.
Написать функцию print(), которая будет выводить значения переменных - членов.

3. Написать класс, который реализует функциональность стека.Класс Stack должен иметь :
• private - массив целых чисел длиной 10;

• private целочисленное значение для отслеживания длины стека;

• public - метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;

• public - метод с именем push(), который будет добавлять значение в стек.push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;

• public - метод с именем pop() для вытягивания и возврата значения из стека.Если в стеке нет значений, то должно выводиться предупреждение;

• public - метод с именем print(), который будет выводить все значения стека.*/

#include <iostream>
#include <cmath>
#include <cstdint>

class Power 
{
    double first = 2;
    double second = 12;
public:
    void setValues(double first, double second) {
        this->first = first;
        this->second = second;
    }
    double calculate() {
       double result = pow(first, second);
       return result;
    };
};

class RGBA
{
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;

public:
    void setValuesRGBA(std::uint8_t red, std::uint8_t blue, std::uint8_t green, std::uint8_t alpha) {
        this->m_red = red;
        this->m_green = green;
        this->m_blue = blue;
        this->m_alpha = alpha;
    }
    void print() {
        printf("RGBA: red=%d, green=%d, blue=%d, alpha=%d\n", m_red, m_green, m_blue, m_alpha);
    }
};

class Stack
{
private:
    int array[10];
    int count;
public:
    void reset() {
        count = 0;
        for (size_t i = 0; i < 10; ++i)
        {
            array[i] = 0;
        }
    }
    bool push(int value) {
        if (count < 10)
        {
            array[count++] = value;
            return true;
        }
        else
        {
            return false;
        }
    }
    int pop() {
        if (count < 0)
        {
            std::cout << "Warning! The stack is empty!" << std::endl;
            return -1;
        }
        else
        {
            return array[count--];
        }
    }
    void print() {
        std::cout << "( ";
        for (int i = 0; i < count; ++i)
            std::cout << array[i] << ' ';
        std::cout << ")\n";
    }

};

int main()
{
    std::cout <<"Task #1 \n" << std::endl;
    Power p;
    std::cout << p.calculate() << std::endl;
    p.setValues(3, 9);
    std::cout << p.calculate() << std::endl;
    std::cout << "\nTask #2 \n" << std::endl;
    RGBA r0;
    r0.print();
    RGBA r1;
    r1.setValuesRGBA(12, 53, 31, 89);
    r1.print();
    std::cout << "\nTask #3 \n" << std::endl;
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;

}


