#include <iostream>
#include <iomanip>
using namespace std;
// class declaration section
class Date
{
  private:
    int month;
    int day;
    int year;

  public:
    Date(int, int, int); // constructor
    void showDate();           // member method to display a date
    void dayOfWeek();
};
// class implementation section
Date::Date(int mm, int dd, int yyyy)
{
  month = mm;
  day = dd;
  year = yyyy;
}

void Date::dayOfWeek(){
  cout << day << month << year << endl;
  if(month < 3){
      month = month + 12;
      year = year - 1;
  }
  int century = (int)(year/100);
  int year_aux = year % 100;
  int T = day + (int)((26*(month+1)/10) + year_aux + (year_aux/4)*(century/4)-2*century);
  int dayWeek = T%7;
  if (dayWeek < 0) {
    dayWeek = dayWeek + 7;
  }
  cout << dayWeek << endl;
}
int main() {
  Date d(7,9,2018);
  d.dayOfWeek();
  return 0;
}

**********************************************************************************************************************************

#include <iostream>
#include <string>

using namespace std;
// class declaration section
class Date
{
  private:
    long yyyymmdd;

  public:
    Date(long); // constructor
    Date(int,int,int);
    void showDate();
};
// class implementation section
Date::Date(long fecha){
  yyyymmdd = fecha;
}
Date::Date(int mm, int dd, int yyyy){
  auto s1 = to_string(yyyy);
  auto s2 = to_string(mm);
  auto s3 = to_string(dd);
  string fecha = s1 + s2 + s3;
  yyyymmdd = stol(fecha);

}
void Date::showDate(){
  cout << yyyymmdd << endl;
}

int main() {
  Date d(7,9,2018);
  d.showDate();
  return 0;
}

**********************************************************************************************************************************

//classdeclarationsection
#include <time.h>
#include <iostream>
using namespace std;

class Elevator {
  private:
    int elNum;
    int currentFloor;
    int highestFloor;
  public:
    Elevator(int=1,int=1,int=15);//constructor
    bool request(int);
};
//classimplementationsection
Elevator::Elevator(int idnum,int cfloor,int maxfloor){
  elNum=idnum;
  currentFloor=cfloor;
  highestFloor=maxfloor;
}
bool Elevator::request(int newfloor){
  if (newfloor==currentFloor) {
    cout<<"\nElevator"<<elNum<<"is calling in the same floor "<<currentFloor<<endl;
    return true;
  }
  else if(newfloor>currentFloor){
    cout<<"\nElevator"<<elNum<<"starting at floor"<<currentFloor<<endl;
    while(newfloor>currentFloor){
      currentFloor++;//addonetocurrentfloor
      cout<<"Going Up - now at floor"<<currentFloor<<endl;
    }
    cout<<"Elevator"<<elNum<<"stopping at floor"<<currentFloor<<endl;
  }
  else{
    cout<<"\nElevator"<<elNum<<"starting at floor"<<currentFloor<<endl;
    while(newfloor<currentFloor)
    {
      currentFloor--;//subtractonefromcurrentfloor
      cout<<"Going Down - now at floor"<<currentFloor<<endl;
    }
    cout<<"Elevator"<<elNum<<"Stopping at floor"<<currentFloor<<endl;
  }
  return false;
}
int main(){
  srand (time(NULL));
  Elevator a;//declare1objectoftypeElevator
  int veces = 0;
  int numero = 0;
  bool igual = true;
  while (veces != 5) {
    numero = 1+rand()%15;
    igual = a.request(numero);
    if (!igual) {
      veces++;
    }
  }

  return 0;
}

**********************************************************************************************************************************

#include <iostream>

using namespace std;


class Circle {


private:
  int xCenter;
  int yCenter;
  double radius;
  static double scaleFactor;

public:
  Circle(int,int,double);
  static void setScale(double);
  static double getScale();
  void getData();
};

double Circle::scaleFactor = 0.0;

Circle::Circle(int x, int y, double r):xCenter(x),yCenter(y),radius(r){

}
void Circle::setScale(double scale){
  scaleFactor = scale;
}

double Circle::getScale(){
  return scaleFactor;
}
void Circle::getData(){
  cout << "x: " << xCenter << endl;
  cout << "y: " << yCenter << endl;
  cout << "r: " << radius << endl;
}
int main() {
  Circle c(1,3,1.4);
  c.setScale(1.1);
  cout << "Scale: " << c.getScale() << endl;
  c.getData();
}

**********************************************************************************************************************************

#include <iostream>

using namespace std;

class Fractions {
  private:
    int num;
    int denom;

  public:
    Fractions(int=1,int=1);
    void addition(Fractions);
    void substraction(Fractions);
    void multiplication(Fractions);
    void division(Fractions);
    int getNum();
    int getDenom();

};

Fractions::Fractions(int n, int dm):num(n),denom(dm){

}
void Fractions::addition(Fractions f){
  int res_num = (num*f.getDenom()+denom*f.getNum());
  int res_denom = (denom*f.getDenom());
  cout << res_num << "/" << res_denom << endl;
}
void Fractions::substraction(Fractions f){
  int res_num = (num*f.getDenom()-denom*f.getNum());
  int res_denom = (denom*f.getDenom());
  cout << res_num << "/" << res_denom << endl;
}
void Fractions::multiplication(Fractions f){
  int res_num = (num*f.getNum());
  int res_denom = (denom*f.getDenom());
  cout << res_num << "/" << res_denom << endl;
}
void Fractions::division(Fractions f){
  int res_num = (num*f.getDenom());
  int res_denom = (denom*f.getNum());
  cout << res_num << "/" << res_denom << endl;
}
int Fractions::getNum(){
  return num;
}
int Fractions::getDenom(){
  return denom;
}

int main() {
  Fractions f1(1,4);
  Fractions f2(3,10);
  f1.addition(f2);
  f1.substraction(f2);
  f1.multiplication(f2);
  f1.division(f2);
  return 0;
}

**********************************************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;
// class declaration section
class Date{
  private:
    int month;
    int day;
    int year;
  public:
    Date(int = 7, int = 4, int = 2012);   // constructor
    void showDate();      // method to display a date
    void swap(Date&);    // method to swap two dates
};
// class implementation section
Date::Date(int mm, int dd, int yyyy) {
  month = mm;
  day = dd;
  year = yyyy;
}
void Date::showDate(){

  cout << setfill('0') << setw(2) << month << '/' << setw(2) << day << '/' << setw(2) << year % 100;
  return;
}
void Date::swap(Date& temp) // method to swap two dates
{
  int tempstore;
  // swap the day member
  tempstore = temp.day;
  temp.day = day;
  day = tempstore;
  // swap the month member
  tempstore = temp.month;
  temp.month = month;
  month = tempstore;
  // swap the year member
  tempstore = temp.year;
  temp.year = year;
  year = tempstore;
  return;
}

int main(){
  Date oldDate(4,3,1999);
  Date newDate(12,18,2012);

  cout << "The date stored in oldDate is ";
  oldDate.showDate();
  cout << "\nThe date stored in newDate is ";
  newDate.showDate();
  newDate.swap(oldDate);  // swap dates by passing an address
  cout << "\n\nAfter the swap:\n"<<endl;
  cout << "The date stored in oldDate is ";
  oldDate.showDate();
  cout << "\nThe date stored in newDate is ";
  newDate.showDate();
  cout << endl;
  return 0;
}

**********************************************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;
// class declaration section
class Date
{
  private:
    int month, day, year;

  public:
    Date(int = 7, int = 4, int = 2012);  // constructor
    // constructor for converting from long to Date
    Date(long);
    void showDate();
    void juliaRepresentation();

};
// class implementation section
Date::Date(int mm, int dd, int yyyy)  // constructor
{
  month = mm;
  day = dd;
  year = yyyy;
}
// constructor for converting from long to Date
Date::Date(long findate)
{
  year = int(findate/10000.0);
  month = int((findate - year * 10000.0)/100.0);
  day = int(findate - year * 10000.0 - month * 100.0);
}
// member function to display a date
void Date::showDate(){
  cout << setfill('0')
       << setw(2) << month << '/'
       << setw(2) << day << '/'
       << setw(2) << year % 100;
  return;
}

void Date::juliaRepresentation(){
  long mp = 0;
  long yp = 0;
  if (month <= 2) {
    mp = 0;
    yp = year-1;
  }else{
    mp = (int)(0.4*month+2.3);
    yp = year;
  }
  long t = (int)(yp/4) - (int)(yp/100) + (int)(yp/400);
  long jd = 365*year + 31*(month-1)+day+t-mp;
  cout << jd << endl;
}
int main(){
  //Date a;   // initialized by the default constructor
  Date a(1,31,2011);  // initialize with a long integer
  Date b(3,16,2012);   // initialize with the specified values
  cout << "date a: ";
  a.showDate();
  cout << endl;
  a.juliaRepresentation();
  cout << "date b: ";
  b.showDate();
  cout << endl;
  b.juliaRepresentation();
  cout << "\n";
  //a = Date(20150103L);  // convert a long to a Date
  //cout << "Date a is now ";
  //a.showDate();
  //cout << ".\n";
  return 0;
}

**********************************************************************************************************************************

#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
// class declaration section
class Complex
{
  // friends list
  friend double addreal(Complex&, Complex&);
  friend double addimag(Complex&, Complex&);
  friend Complex producto(Complex&, int);
  private:
    double real;
    double imag;
  public:
    Complex(double = 0, double = 0);  // constructor
    void display();

};
// class implementation section
Complex::Complex(double rl, double im)
{
  real = rl;
  imag = im;
}
void Complex::display()
{
  char sign = '+';
  if(imag < 0) sign = '-';
  cout << real << sign << abs(imag) << 'i' << endl;
  return;
}

// friend implementations
double addreal(Complex &a, Complex &b)
{
  return(a.real + b.real);
}
double addimag(Complex &a, Complex &b)
{
  return(a.imag + b.imag);
}

Complex producto(Complex &a,int real){
  Complex c(real*a.real,real*a.imag);
  return c;
}

int main(){
  srand(time(NULL));
  int number = 1+rand()%20;
  Complex a(3.2, 5.6);
  Complex d;
  cout << "Number: " << endl;
  a.display();
  cout << "Product: " << endl;
  cout << number << endl;
  d = producto(a,number);
  cout << "Result: " << endl;
  d.display();
  return 0;
}

**********************************************************************************************************************************

#include <iostream>
#include <time.h>
using namespace std;

class Custumer {

  private:
    int minutes;
    int gas;
  public:
    Custumer(int,int);
    void reOrder(int,int);
    void order();
};

Custumer::Custumer(int m, int g):minutes(m),gas(g){

}
void Custumer::order(){
  cout << "Minutes: " << minutes << endl;
  cout << "Gas: " << gas << " gallons" <<endl;
}

void Custumer::reOrder(int m, int g){
  minutes = m;
  gas = g;
}

int main() {
  srand(time(NULL));
  int custumers = 0;
  int m = 1+rand()%15;
  int g = 3+rand()%15;
  Custumer c(m,g);
  while (custumers != 10) {
    cout << "Custumer attended: " << custumers+1 << endl;
    c.order();
    m = 1+rand()%15;
    g = 3+rand()%15;
    custumers++;
    c.reOrder(m,g);
  }
  return 0;
}

**********************************************************************************************************************************

#include <iostream>
#include <time.h>
using namespace std;

class Custumer {

  private:
    int minutes;
    int gas;

  public:
    static int numberGrade1;
    static int numberGrade2;
    static int numberGrade3;
    Custumer(int,int);
    void reOrder(int,int);
    void order(int);
    static void totalGrade1(int);
    static void totalGrade2(int);
    static void totalGrade3(int);
    static void totalGrades();
};

int Custumer::numberGrade1 = 0;
int Custumer::numberGrade2 = 0;
int Custumer::numberGrade3 = 0;

Custumer::Custumer(int m, int g):minutes(m),gas(g){

}
void Custumer::order(int octane){
  cout << "Minutes: " << minutes << endl;
  cout << "Gas: " << gas << " gallons" <<endl;
  cout << "Octane: " << octane << endl;
}

void Custumer::reOrder(int m, int g){
  minutes = m;
  gas = g;
}

void Custumer::totalGrade1(int total){
  numberGrade1 += total;
}
void Custumer::totalGrade2(int total){
  numberGrade2 += total;
}
void Custumer::totalGrade3(int total){
  numberGrade3 += total;
}
void Custumer::totalGrades(){
  cout << "Total grade1: " << numberGrade1 << endl;
  cout << "Total grade2: " << numberGrade2 << endl;
  cout << "Total grade3: " << numberGrade3 << endl;
}

int main() {
  srand(time(NULL));
  int custumers = 0;
  int m = 1+rand()%15;
  int g = 3+rand()%15;
  int grade = rand()%3;
  int grades[3] = {87,93,97};
  Custumer c(m,g);
  while (custumers != 10) {

    if (grades[grade]==87) {
      c.totalGrade1(g);
    }else if(grades[grade]==93){
      c.totalGrade2(g);
    }else{
      c.totalGrade3(g);
    }
    cout << "Custumer attended: " << custumers+1 << endl;
    c.order(grades[grade]);
    m = 1+rand()%15;
    g = 3+rand()%15;
    grade = rand()%3;
    custumers++;
    c.reOrder(m,g);
    cout << endl;
  }
  c.totalGrades();
  return 0;
}
