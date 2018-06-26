#ifndef Shape22_H
#define Shape22_H



class Shape2
{
    public:
        Shape2();
        virtual ~Shape2();
        enum ShapeColor { Red, Green, Blue };
        void draw(ShapeColor color = Red) const;
        virtual void drawImpl() const;

    protected:

    private:
};

class Rectangle2 : public Shape2
{
public:
    void drawImpl() const;
};

#endif // Shape22_H
