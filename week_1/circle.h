class Circle
{
    private:
        double radius;
    public:
        Circle();
        Circle(double r);
        void setRadius(double r);
        double getArea();
        double getCircumference();
};

Circle::Circle() {
    this->radius = 5;
}

Circle::Circle(double r){
    this->radius = r;
}

void Circle::setRadius(double r){
    this->radius = r;
}

double Circle::getArea(){
    return 3.14 * this->radius * this->radius;
}

double Circle::getCircumference(){
    return 2*3.14*this->radius;
}