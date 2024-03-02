#include "Shape.h"

int main() {
    vector<Shape*> shapes;

    cout << "Enter data for each shape:" << endl;

    int x, y, side, width, height, radius;

    cout << "Square: x, y, side" << endl;
    cin >> x >> y >> side;
    shapes.push_back(new Square(x, y, side));

    cout << "Rectangle: x, y, width, height" << endl;
    cin >> x >> y >> width >> height;
    shapes.push_back(new Rectangle(x, y, width, height));

    cout << "Circle: x, y, radius" << endl;
    cin >> x >> y >> radius;
    shapes.push_back(new Circle(x, y, radius));

    cout << "Ellipse: x, y, width, height" << endl;
    cin >> x >> y >> width >> height;
    shapes.push_back(new Ellipse(x, y, width, height));

    for (Shape* shape : shapes) {
        shape->Save();
        shape->Show();
    }

    for (Shape* shape : shapes) {
        shape->Load();
        shape->Show();
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
