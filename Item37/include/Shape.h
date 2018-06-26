#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
    public:
        Shape();
        virtual ~Shape();
        enum ShapeColor { Red, Green, Blue };
        virtual void draw(ShapeColor color = Red) const = 0;

    protected:

    private:
};

class Rectangle : public Shape
{
public:
    void draw(ShapeColor color = Green) const;
};

class Circle : public Shape
{
public:
    void draw(ShapeColor color) const;
};

#endif // SHAPE_H
