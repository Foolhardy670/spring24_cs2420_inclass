#include<iostream>
using namespace std;

template <class T>
class Circle
{
    private:
        T radius;

    public:
        Circle();
        Circle(T r);
        void setRadius(T r);
        T getArea();
        T getCircumference();
};

template <class T>
Circle<T>::Circle() {
    this->radius = 5;
}

template <class T>
Circle<T>::Circle(T r){
    this->radius = r;
}

template <class T>
void Circle<T>::setRadius(T r){
    this->radius = r;
}

template <class T>
T Circle<T>::getArea(){
    return 3.14 * this->radius * this->radius;
}

template <class T>
T Circle<T>::getCircumference(){
    return 2*3.14*this->radius;
}

int main(void)
{
    Circle <int> c1;
    Circle <double> c2 (21.7);
    Circle <int> *c3 = new Circle<int>();
    Circle <int> *c4 = new Circle<int>( 12.9 );

    cout<<"c1.area: "<<c1.getArea()<<endl;
    cout<<"c2.area: "<<c2.getArea()<<endl;
    cout<<"c3.area: "<<c3->getArea()<<endl;
    cout<<"c4.area: "<<c4->getArea()<<endl;
    return 0;
}