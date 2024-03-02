#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual void Show() = 0;
    virtual void Save() = 0;
    virtual void Load() = 0;
    virtual ~Shape() {}
};

class Square : public Shape {
private:
    int x;
    int y;
    int side;
public:
    Square(int x, int y, int side);
    void Show() override;
    void Save() override;
    void Load() override;
};

class Rectangle : public Shape {
private:
    int x;
    int y;
    int width;
    int height;
public:
    Rectangle(int x, int y, int width, int height);
    void Show() override;
    void Save() override;
    void Load() override;
};

class Circle : public Shape {
private:
    int x;
    int y;
    int radius;
public:
    Circle(int x, int y, int radius);
    void Show() override;
    void Save() override;
    void Load() override;
};

class Ellipse : public Shape {
private:
    int x;
    int y;
    int width;
    int height;
public:
    Ellipse(int x, int y, int width, int height);
    void Show() override;
    void Save() override;
    void Load() override;
};

#endif
