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
    void Sound() override { cout << "���!" << endl; }
    void Show() override { cout << "������: " << name << endl; }
    void Type() override { cout << "���: ������" << endl; }
};

class Cat : public Pet {
public:
    Cat(string name) : Pet(name) {}
    void Sound() override { cout << "���!" << endl; }
    void Show() override { cout << "ʳ���: " << name << endl; }
    void Type() override { cout << "���: ʳ���" << endl; }
};

class Parrot : public Pet {
public:
    Parrot(string name) : Pet(name) {}
    void Sound() override { cout << "���-���!" << endl; }
    void Show() override { cout << "������: " << name << endl; }
    void Type() override { cout << "���: ������" << endl; }
};

class Hamster : public Pet {
public:
    Hamster(string name) : Pet(name) {}
    void Sound() override { cout << "ϳ-�!" << endl; }
    void Show() override { cout << "���'��: " << name << endl; }
    void Type() override { cout << "���: ���'��" << endl; }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string petName, petType;
    cout << "������ ��'� �������: ";
    cin >> petName;
    cout << "������ ��� ������� (������, ʳ���, ������, ���'��): ";
    cin >> petType;

    Pet* pet;
    if (petType == "������") {
        pet = new Dog(petName);
    }
    else if (petType == "ʳ���") {
        pet = new Cat(petName);
    }
    else if (petType == "������") {
        pet = new Parrot(petName);
    }
    else if (petType == "���'��") {
        pet = new Hamster(petName);
    }
    else {
        cout << "�������� ��� �������!" << endl;
        return 1;
    }

    pet->Show();
    pet->Sound();
    pet->Type();

    return 0;
}
