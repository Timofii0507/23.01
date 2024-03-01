#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Pet {
protected:
    string name;

public:
    Pet(string name) : name(name) {}
    virtual void Sound() = 0; 
    virtual void Show() = 0; 
    virtual void Type() = 0; 
};

class Dog : public Pet {
public:
    Dog(string name) : Pet(name) {}
    void Sound() override { cout << "Гав!" << endl; }
    void Show() override { cout << "Собака: " << name << endl; }
    void Type() override { cout << "Тип: Собака" << endl; }
};

class Cat : public Pet {
public:
    Cat(string name) : Pet(name) {}
    void Sound() override { cout << "Мяу!" << endl; }
    void Show() override { cout << "Кішка: " << name << endl; }
    void Type() override { cout << "Тип: Кішка" << endl; }
};

class Parrot : public Pet {
public:
    Parrot(string name) : Pet(name) {}
    void Sound() override { cout << "Кра-кра!" << endl; }
    void Show() override { cout << "Папуга: " << name << endl; }
    void Type() override { cout << "Тип: Папуга" << endl; }
};

class Hamster : public Pet {
public:
    Hamster(string name) : Pet(name) {}
    void Sound() override { cout << "Пі-пі!" << endl; }
    void Show() override { cout << "Хом'як: " << name << endl; }
    void Type() override { cout << "Тип: Хом'як" << endl; }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string petName, petType;
    cout << "Введіть ім'я тварини: ";
    cin >> petName;
    cout << "Введіть тип тварини (Собака, Кішка, Папуга, Хом'як): ";
    cin >> petType;

    Pet* pet;
    if (petType == "Собака") {
        pet = new Dog(petName);
    }
    else if (petType == "Кішка") {
        pet = new Cat(petName);
    }
    else if (petType == "Папуга") {
        pet = new Parrot(petName);
    }
    else if (petType == "Хом'як") {
        pet = new Hamster(petName);
    }
    else {
        cout << "Невідомий тип тварини!" << endl;
        return 1;
    }

    pet->Show();
    pet->Sound();
    pet->Type();

    return 0;
}
