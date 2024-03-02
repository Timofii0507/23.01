#include "Shape.h"

Square::Square(int x, int y, int side) : x(x), y(y), side(side) {}
void Square::Show() {
    cout << "Square: x = " << x << ", y = " << y << ", side = " << side << endl;
}
void Square::Save() {
    ofstream file("shapes.txt", ios::app);
    if (file.is_open()) {
        file << "Square " << x << " " << y << " " << side << "\n";
        file.close();
    }
    else {
        cout << "Error: couldn't open the file" << endl;
    }
}
void Square::Load() {
    ifstream file("shapes.txt");
    if (file.is_open()) {
        string type;
        int x, y, side;
        while (file >> type >> x >> y >> side) {
            if (type == "Square") {
                this->x = x;
                this->y = y;
                this->side = side;
                break;
            }
        }
        file.close();
    }
    else {
        cout << "Error: couldn't open the file" << endl;
    }
}

Rectangle::Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
void Rectangle::Show() {
    cout << "Rectangle: x = " << x << ", y = " << y << ", width = " << width << ", height = " << height << endl;
}
void Rectangle::Save() {
    ofstream file("shapes.txt", std::ios::app);
    if (file.is_open()) {
        file << "Rectangle " << x << " " << y << " " << width << " " << height << "\n";
        file.close();
    }
    else {
        cout << "Error: couldn't open the file" << endl;
    }
}
void Rectangle::Load() {
    ifstream file("shapes.txt");
    if (file.is_open()) {
        string type;
        int x, y, width, height;
        while (file >> type >> x >> y >> width >> height) {
            if (type == "Rectangle") {
                this->x = x;
                this->y = y;
                this->width = width;
                this->height = height;
                break;
            }
        }
        file.close();
    }
    else {
        cout << "Error: couldn't open the file" << endl;
    }
}

Circle::Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}
void Circle::Show() {
    cout << "Circle: x = " << x << ", y = " << y << ", radius = " << radius << std::endl;
}
void Circle::Save() {
    ofstream file("shapes.txt", ios::app);
    if (file.is_open()) {
        file << "Circle " << x << " " << y << " " << radius << "\n";
        file.close();
    }
    else {
        cout << "Error: couldn't open the file" << endl;
    }
}
void Circle::Load() {
    ifstream file("shapes.txt");
    if (file.is_open()) {
        string type;
        int x, y, radius;
        while (file >> type >> x >> y >> radius) {
            if (type == "Circle") {
                this->x = x;
                this->y = y;
                this->radius = radius;
                break;
            }
        }
        file.close();
    }
    else {
        std::cout << "Error: couldn't open the file" << std::endl;
    }
}

Ellipse::Ellipse(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
void Ellipse::Show() {
    std::cout << "Ellipse: x = " << x << ", y = " << y << ", width = " << width << ", height = " << height << std::endl;
}
void Ellipse::Save() {
    ofstream file("shapes.txt", ios::app);
    if (file.is_open()) {
        file << "Ellipse " << x << " " << y << " " << width << " " << height << "\n";
        file.close();
    }
    else {
        cout << "Error: couldn't open the file" << endl;
    }
}
void Ellipse::Load() {
    ifstream file("shapes.txt");
    if (file.is_open()) {
        std::string type;
        int x, y, width, height;
        while (file >> type >> x >> y >> width >> height) {
            if (type == "Ellipse") {
                this->x = x;
                this->y = y;
                this->width = width;
                this->height = height;
                break;
            }
        }
        file.close();
    }
    else {
        cout << "Error: couldn't open the file" << endl;
    }
}
