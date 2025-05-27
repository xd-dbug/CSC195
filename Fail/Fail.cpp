#include <iostream>
#include <vector>

using namespace std;

class Shape {
public:
    Shape() {}
    ~Shape() {}

    virtual float Area() = 0;
};

class Circle : public Shape {
public:
    Circle(float r) { m_radius = r; };
    ~Circle() {}

    float Area()  {
        return 3.14f * m_radius * m_radius;
    }

    void SetRadius(float radius) { radius = radius; }
    float GetRadius() { return m_radius; }

private:
    float m_radius;
};

class Rectangle : public Shape {
public:
    Rectangle(float w, float h) {
        m_width = w;
        m_height = h;
    }

    float Area() override {
        return m_width * m_height;
    }

private:
    float m_width;
    float m_height;
};

int main() {
    vector<Shape*> shapes;

    Circle* c = new Circle(1.0f);
    c->SetRadius(3.0f);
    Rectangle* r = new Rectangle(4.0f, 5.0f);

    shapes.push_back(c);
    shapes.push_back(r);

    for (int i = 0; i < shapes.size(); i++)
    {
        cout << "Area: " << shapes[i]->Area() << endl;
        if (dynamic_cast<Circle*>(shapes[i])) {
            cout << "Circle radius: " << dynamic_cast<Circle*>(shapes[i])->GetRadius() << endl;
        }
    };

    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();

    return 0;
};




