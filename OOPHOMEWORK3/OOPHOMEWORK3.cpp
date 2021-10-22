#include <iostream>

using namespace std;

void obzac()
{
    cout << "\n\n//====================================HomeWork====================================//\n\n";
}
void obzac1()
{
    cout << "\n\n//======================================END======================================//\n\n";
}
void obzac2()
{
    cout << "\n\n//-------------------------------------------------------------------------------//\n\n";
}


/*HOMEWORK1
Создать абстрактный класс Figure (фигура). 
Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
*/
class Figure //изначально он был отцом(основателем семейства класса, но у параллелограмма появились дети и теперь этот класс будет дедом.
{
protected:
    virtual void area() = 0; //чисто виртуальная функция area() (площадь).
};

class Parallelogram : protected Figure 
{
protected:
    double base;   //основание(тело, тушка) праллелограмма.
    double height; //высота праллелограмма.
public:
    Parallelogram(double x_base, double v_height) : base(x_base), height (v_height){}
    void area() override //для того, чтобы для каждого дочернего класса не вызывать в мейне функцию. дабы сократить код в мейне.
    {
        cout << "The parallelogram area is " << base * height << endl;
    }
    /*double getBase() { return base; } //необходимо для 2рого решения, которое предоставлено в мейне.
    double getHeight() { return height; }
    */
};

class Circle : protected Figure
{
public:
    double radius;   //радиус окружности.
    double P;        //число Пи для окружности.
public:
    Circle(double x_radius, double v_p) : radius(x_radius), P(v_p=3.14) {} //для окружности мы не юзаем "Пи окружности"
    void area() override
    {
        cout << "The area of the circle is " << 3.14 * (radius * radius) << endl; //1 радиус это грубо говоря половина окружности, благодаря (radius * radius) мы грубо говоря получим диаметр окружности.
    }
};

class Rectangle : protected Parallelogram //ребенок Parallelogram'а
{
public:
    Rectangle(double x_base, double v_height) : Parallelogram (x_base, v_height) {}
    void area() override 
    {
        cout << "The rectangle area is " << base * height << endl;
    }
};

class Square : protected Parallelogram //ребенок Parallelogram'а
{
public:
    Square(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override 
    {
        cout << "The square area is " << base * height << endl;
    }
};

class Rhombus : protected Parallelogram //ребенок Parallelogram'а
{
public:
    Rhombus(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override 
    {
        cout << "The rhombus area is " << base * height << endl;
    }
};

/*HOMEWORK2
Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
От этих классов наследует класс Minivan (минивэн). 
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
Обратить внимание на проблему «алмаз смерти».
*/
class Car
{
protected:
    string company, model; //поля для класса. стринг дает возможность писать большим колл-вом строк, а не с 1 символом.
public:
    Car() {}
    Car(string xCompany, string vModel) : company(xCompany), model(vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    virtual ~Car()
    {
        cout << "\nДеструктор базового класса Car сработал!";  //деструктор базового класса.
    }
};

class PassengerCar : virtual public Car
{
public:
    
    PassengerCar() {}
    PassengerCar(string xCompany, string vModel) : Car(xCompany, vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    ~PassengerCar()
    {
        cout << "\nДеструктор наследника PassengerCar сработал!"; //деструктор наследника.
    }
};

class Bus : virtual public Car
{
public:
    
    Bus() {}
    Bus(string xCompany, string vModel) : Car(xCompany, vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    ~Bus()
    {
        cout << "\nДеструктор наследника Bus сработал!"; //деструктор наследника.
    }
};

class Minivan : public PassengerCar, public Bus //делаем сразу двойное присвоение.
{
public:
    
    Minivan(string xCompany, string vModel) : Car(xCompany, vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    ~Minivan()
    {
        cout << "\nДеструктор множественного наследника Minivan сработал!"; //деструктор множественного наследования.
    }
};

/*HOMEWORK3
Создать класс: Fraction (дробь). 
Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). 
Предусмотреть, чтобы знаменатель не был равен 0. 
Перегрузить:
1.математические бинарные операторы (+, -, *, /) для выполнения действий с дробями 
2.унарный оператор (-)
3.логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 
*/
class Fraction 
{
protected:
    double numerator, denominator; //перевод: numerator(числитесь), denominator(знаменатель).
public:
    Fraction() {}
    Fraction(double iNumerator, double iDenominator) : numerator(iNumerator), denominator(iDenominator) 
    {
        if (denominator == 0) denominator = 0.00000001; //предусмотреть, чтобы знаменатель не был равен 0, поэтому делаем условие.
    }
    friend Fraction operator+(const Fraction& d1, const Fraction& d2); //176 строка: математические бинарные операторы (+, -, *, /) для выполнения действий с дробями.
    friend Fraction operator-(const Fraction& d1, const Fraction& d2);
    friend Fraction operator*(const Fraction& d1, const Fraction& d2);
    friend Fraction operator/(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1); //сам себя загоянешь в минус. 177 строка 2."унарный оператор (-)".
    
    //для дополнительного ПО.
    /*void setDenominator(double iDenominator)
    {
        if (iDenominator == 0) iDenominator = 0.00000001;
        denominator = iDenominator;
    }

    void setNumerator(double iNumerator)
    {
        numerator = iNumerator;
    }
    */

    double getNumerator() //необходимы в данном случае для сравнения (bool), через дружественные перегрузки ничего не работает, без гет'а.
    {
        return numerator;
    }

    double getDenominator()
    {
        return denominator;
    }

    void Print()
    {
        cout << "Numerator:" << numerator << " denominator:" << denominator << endl;
    }

};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator + d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator - d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.numerator, d1.denominator * d2.denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator, d1.denominator * d2.numerator);
}

Fraction operator-(const Fraction& d1)
{
    return Fraction(-d1.numerator, d1.denominator);
}

bool operator==(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if ((d1.getNumerator() == d2.getNumerator()) && (d1.getDenominator() == d2.getDenominator())) return true;
    else return false;
}

bool operator!=(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if (d1 == d2) return false;
    else return true;
}

bool operator<(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if ((d1.getNumerator() / d1.getDenominator()) < (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator>(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if ((d1.getNumerator() / d1.getDenominator()) > (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator<=(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if (!(d1 > d2)) return true;
    else return false;
}

bool operator>=(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if (!(d1 < d2)) return true;
    else return false;
}



int main()
{
    {
        obzac();
        double x_base;
        double v_height;
        cout << "Parallelogram\n" << "entered first value: ";
        cin >> x_base;
        cout << "entered second value: ";
        cin >> v_height;
        Parallelogram paral(x_base, v_height);
        paral.area();

        obzac2();
        double x_radius;
        double P = 3.1415;
        cout << "Circle\n" << "entered radius: ";
        cin >> x_radius;
        Circle circ(x_radius, P);
        circ.area();

        obzac2();
        cout << "Rectangle\n" << "entered first value: ";
        cin >> x_base;
        cout << "entered second value: ";
        cin >> v_height;
        Rectangle rect(x_base, v_height);
        rect.area();

        obzac2();
        cout << "Square\n" << "entered first value: ";
        cin >> x_base;
        cout << "entered second value: ";
        cin >> v_height;
        Square squar(x_base, v_height);
        squar.area();

        obzac2();
        cout << "Rombus\n" << "entered first value: ";
        cin >> x_base;
        cout << "entered second value: ";
        cin >> v_height;
        Rhombus romb(x_base, v_height);
        romb.area();
        obzac1();


        //2РОЙ ВАРИАНТ РЕШЕНИЯ.
        /*int v_height(3), x_base(5);
        Parallelogram parallelogram(x_base, v_height);
        parallelogram.area();

        int v_height(4), x_base(10);
        Rectangle rectangle(x_base, v_height);
        rectangle.area();

        int v_height(6), x_base(24);
        Square square(x_base, v_height);
        square.area();

        int v_height(2), x_base(11);
        Rhombus rhombus(x_base, v_height);
        rhombus.area();
        */

        ///////////////////////////////////////////////////////////////////////////////////////////////
        
        //3ТИЙ ВАРИАНТ РЕШЕНИЯ.
        /*Rectangle rect(30, 50);
        Circle circle(30);

        std::cout << "Rectangle square: " << rect.getSquare() << std::endl;
        std::cout << "Circle square: " << circle.getSquare() << std::endl;
        */

        //////////////////////////////////////////////////////////////////////////////////////////////

    }

    {
        obzac();
        Car* car = new Car("Doodge", "Demon");
        obzac2();
        PassengerCar* passengercar = new PassengerCar("laFerrari", "Pick");
        obzac2();
        Bus* bus = new Bus("Renault", "Bus");
        obzac2();
        Minivan* minivan = new Minivan("Audi", "eTron");
        obzac2();
        delete minivan;
        delete bus;
        delete passengercar;
        delete car;
        obzac1();
    }

    {
        obzac();
        Fraction d1(6, 7);
        Fraction d2(3, 6);
        (d1 + d2).Print();
        (d1 - d2).Print();
        (d1 * d2).Print();
        (d1 / d2).Print();
        (-d1).Print();
        obzac2();
        if (d1 == d2) cout << "\nFraction 1 == Fraction 2";
        if (d1 != d2) cout << "\nFraction 1 != Fraction 2";
        if (d1 > d2) cout << "\nFraction 1 > Fraction 2";
        if (d1 <= d2) cout << "\nFraction 1 <= Fraction 2";
        if (d1 < d2) cout << "\nFraction 1 < Fraction 2";
        if (d1 >= d2) cout << "\nFraction 1 >= Fraction 2";
        obzac1();
    }
}
