#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Renderer {
  virtual string what_to_render_as() const = 0;
};

struct RasterRenderer : Renderer {
    string what_to_render_as() const override { return "pixels";}
};

struct VectorRenderer : Renderer {
    string what_to_render_as() const override { return "lines";}
};

struct Shape {
    const Renderer &r;
    Shape(const Renderer &r): r(r) {}
    string name;
    string str() const {
        ostringstream os;
        os << "Drawing " << name << " as " << r.what_to_render_as();
        return os.str();
    }
};

struct Triangle : Shape {
    explicit Triangle(const Renderer &r)
        : Shape(r) {
        name = "Circle";
    }
};

struct Square : Shape {
    explicit Square(const Renderer &r)
        : Shape(r) {
        name = "Square";
    }
};

/**
struct VectorSquare : Square
{
    string str() const
    {
        return "Drawing " + name + " as lines";
    }
}

struct RasterSquare : Square
{
    string str() const
    {
        return "Drawing " + name + " as pixels";
    }
}
*/
// imagine e.g. VectorTriangle/RasterTriangle etc. here
