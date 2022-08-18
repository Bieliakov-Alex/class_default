#include <iostream>
#include <cmath>

class A{
public:
    //A():x{0}{}
    A() = default;
    A(int arg): x{1}{}
    A(int arg1, int arg2): x{1}{ x = arg1 * arg2; x = 2; }
    int GetX() const {return x;}
    int GetY() const {return y++;}
    static int GetStatic(){return -3;}
    //static int static_var;
private:
    //int x{-10};
    int x;
    mutable int y{0};
};

class B: public A{
public:
   int GetAX(){return GetX();}
};

class B2;

class B1{
public:
     B1() = default;
     explicit B1(const B2&){}
};

class B2{

};

//static int a_var{-1};

int main(){
    int x ;

    A a1, a2{-5}, a3{-5,-10};

    std::cout<<x<<std::endl;
    std::cout<<a1.GetX()<<" "<<a2.GetX()<<" "<<a3.GetX()<<std::endl;
    std::cout<<std::endl;
    std::cout<<a1.GetY()<<std::endl;
    std::cout<<a1.GetY()<<std::endl;
    std::cout<<a1.GetY()<<std::endl;
    std::cout<<a1.GetY()<<std::endl;
    std::cout<<std::endl;

    B b1;
    std::cout<<b1.GetAX()<<std::endl;

    //std::cout<<std::endl<<a_var<<std::endl;

    //std::cout<<std::endl<<a1.static_var<<std::endl;
    std::cout<<std::endl<<a1.GetStatic()<<std::endl;
    std::cout<<std::endl<<A::GetStatic()<<std::endl;
    //std::cout<<std::endl<<A::static_var<<std::endl;

    int some_var = (int)3.9; //bad, c-style
    some_var = int(3.7); //slightly better, but also unsafe
    //some_var = int{3.8}; //int(3.7)
    some_var = static_cast<int>(3.8);
    some_var = static_cast<int>(std::round(3.5));

    std::cout<<some_var<<std::endl;

    short some_new_var = 1;
    some_var = static_cast<int>(some_new_var);

    B1 obj1;
    B2 obj2;
    //obj1 = obj2; - implicit convertion from B2 to B1
    obj1 = static_cast<B1>(obj2);
    obj1 = B1{obj2};
    //obj2 = static_cast<B2>(obj1);
    
    return 0;
}