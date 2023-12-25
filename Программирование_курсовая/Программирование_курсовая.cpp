#include <iostream>
#include <list>
#include <stack>


class Node {
public:
    int key;
    Node* p;

    Node(int k) {
        key = k;
        p = nullptr;
    }

    ~Node() {
        delete p;
    }
};

class Stack {
private:
    std::list<Node*> stack;
    int max_size;

public:
    Stack(int max) {
        max_size = max;
    }

    Stack(const Stack& other) {
        max_size = other.max_size;
        for (Node* node : other.stack) {
            Node* newNode = new Node(node->key);
            stack.push_back(newNode);
        }
    }

    ~Stack() {
        for (Node* node : stack) {
            delete node;
        }
    }

    void push(int value) {
        if (stack.size() >= max_size) {
            std::cout << "Стек переполнен." << std::endl;
            return;
        }

        Node* node = new Node(value);
        stack.push_back(node);
    }

    void pop() {
        if (stack.empty()) {
            std::cout << "Нет объектов для удаления." << std::endl;
            return;
        }

        Node* node = stack.back();
        stack.pop_back();
        std::cout << "Удаленный элемент: " << node->key << std::endl;
        delete node;
    }

    void remove() {
        for (Node* node : stack) {
            delete node;
        }
        stack.clear();
        std::cout << "Стек удалён." << std::endl;
    }


    void print() {
        if (stack.empty()) {
            std::cout << "Стек пуст." << std::endl;
            return;
        }
        std::cout << "Содержимое стека: ";
        for (Node* node : stack) {
            std::cout << node->key << " ";
        }
        std::cout << std::endl;
    }

    int length() {
        return stack.size();
    }
};

int main() {

    setlocale(LC_ALL, "RU");

    int max_size;
    std::cout << "Введите максимальный размер стека: ";
    std::cin >> max_size;

    Stack stack(max_size);

    int choice = 0;
    while (true) {
        std::cout << std::endl << "Список операций: " << std::endl << std::endl;
        std::cout << "1. Вывести стек в терминал" << std::endl;
        std::cout << "2. Добавить элемент" << std::endl;
        std::cout << "3. Удалить элемент и вывести на экран" << std::endl;
        std::cout << "4. Удалить весь стек" << std::endl;
        std::cout << "5. Вывести информацию о длине стека" << std::endl;
        std::cout << "6. Копировать весь стек в новый объект" << std::endl;
        std::cout << "7. Выход из программы\n" << std::endl;
        std::cout << "Введите номер выбранной операции: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            stack.print();
            break;

        case 2:
            int value;
            std::cout << "Введите значение нового элемента: ";
            std::cin >> value;
            stack.push(value);
            break;

        case 3:
            stack.pop();
            stack.print();
            break;

        case 4:
            stack.remove();
            break;

        case 5:
            std::cout << "Длина стека: " << stack.length() << std::endl;
            break;

        case 6:
            {
            Stack copyStack(stack);  // создание нового объекта copyStack с помощью конструктора копирования, который мы определили в классе Stack
            std::cout << "Стек скопирован." << std::endl;
            }
        break;

        case 7:
            std::cout << "Осуществляется выход из программы..." << std::endl;
            return 0;

        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}