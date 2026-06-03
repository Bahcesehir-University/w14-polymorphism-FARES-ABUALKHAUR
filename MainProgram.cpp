// ============================================================
// MainProgram.cpp  —  STUDENT VERSION
// Lab: Inheritance and Polymorphism
// Standard: C++17  |  Single file only, no headers
// ------------------------------------------------------------
// Complete every TODO. Do NOT rename classes, methods, or
// functions: the autograder depends on these exact names.
// ============================================================
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// ================================
// CLASS DEFINITIONS
// ================================

// --- Base class -------------------------------------------------
class Shape {
protected:
    std::string name;
public:
    Shape(const std::string& n) : name(n) {}

    // TODO 1: Make this destructor VIRTUAL.
    virtual ~Shape() {}

    virtual double area() const = 0;

    virtual std::string describe() const {
        return name + " with area " + std::to_string(area());
    }

    std::string getName() const { return name; }
};

// --- Derived class: Circle --------------------------------------
class Circle : public Shape {
private:
    double radius;
public:
    // TODO 2: Constructor — base name "Circle", store radius
    Circle(double r) : Shape("Circle"), radius(r) {}

    // TODO 3: Override area() = PI * r * r
    double area() const override {
        return M_PI * radius * radius;
    }
};

// --- Derived class: Rectangle -----------------------------------
class Rectangle : public Shape {
protected:
    double width;
    double height;
public:
    // TODO 4: Constructor — base name "Rectangle", store width/height
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}

    // TODO 5: Override area() = width * height
    double area() const override {
        return width * height;
    }
};

// --- Derived class: Square (inherits from Rectangle) ------------
class Square : public Rectangle {
public:
    // TODO 6: Constructor — call Rectangle(side, side), then fix name
    Square(double side) : Rectangle(side, side) {
        name = "Square";
    }
    // Reuses Rectangle::area() — no override needed
};

// ================================
// FUNCTION IMPLEMENTATIONS
// ================================

// TODO 7: Sum areas polymorphically
double totalArea(const std::vector<Shape*>& shapes) {
    double total = 0.0;
    for (const Shape* s : shapes) {
        total += s->area();
    }
    return total;
}

// TODO 8: Name of the shape with the largest area
std::string largestShapeName(const std::vector<Shape*>& shapes) {
    if (shapes.empty()) return "";
    const Shape* largest = shapes[0];
    for (size_t i = 1; i < shapes.size(); ++i) {
        if (shapes[i]->area() > largest->area()) {
            largest = shapes[i];
        }
    }
    return largest->getName();
}

// ================================
// MAIN
// ================================
int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Rectangle(3.0, 4.0));
    shapes.push_back(new Square(5.0));

    for (const Shape* s : shapes) {
        std::cout << s->describe() << std::endl;
    }

    std::cout << "Total area: " << totalArea(shapes) << std::endl;
    std::cout << "Largest:    " << largestShapeName(shapes) << std::endl;

    for (Shape* s : shapes) delete s;
    return 0;
}
