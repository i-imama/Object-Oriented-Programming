#include <iostream>
#include<conio.h>
using namespace std;
class circle
{private:
             double radius,Xcor,Ycor;
 public :
 	void set(double r,double x,double y){
 	radius=r;
 	Xcor=x;
 	Ycor=y;}
 	void get(){
 	cout<<"enter radius of circle"<<endl;cin>>radius;
 	cout<<"enter x cordinate of its center"<<endl;cin>>Xcor;
	 cout<<"enter y cordinate of its center"<<endl;cin>>Ycor;	
 	}
 	void show(){
 	cout<<"radius of circle is="<<radius<<endl;
 	cout<<"x coordinate of its center is="<<Xcor<<endl;
 	cout<<"y coordinate of its center is="<<Ycor<<endl;
 	}
 	double area(){
 	double area;
 	cout<<"area of circle is="<<3.14*radius*radius<<endl;
 	}
 	double circumfrance(){
 	double circumfrance;
 	cout<<"circumfrance of circle is="<<2*3.14*radius<<endl;
 	}
};

class Rectangle{
	private:
	int length,width;
	public:
	void set(int l,int w){
	length=l;
	width=w;
	}
	void get(){
	cout<<"Enter the length ="<<endl;
	cin>>length;
	cout<<"Enter the width ="<<endl;
	cin>>width;
	}
	int perimeter(){
	int perimeter;
	cout<<"The 'perimeter' of rectangle is="<<2*(length+width)<<endl;
	}
	int area(){
	int area;
	cout<<"The area of rectangle is="<<length*width<<endl;
	}
	void draw(){
	cout<<"****************"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*                                 *"<<endl;
            cout<<"*                                 *"<<endl;	
            cout<<"****************"<<endl;
	}
};

#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
 
class Time
{
private:
     int hours ; int minutes ; int seconds ;
public:
     Time () : hours (0), minutes (0) , seconds (0) { } 
     Time( int h, int m , int s ) : hours  ( h ), minutes (m) , seconds (s) { }
 
     void print() {
           cout << setw(2) << hours   << ":"
                     << setw(2) << minutes << ":"
                     << setw(2) << seconds << endl;
     }
     void set_Hour   (int h)    { hours   = h; }
     void set_Minute (int m) { minutes = m; }
     void set_Second (int s) { seconds = s; }
     void set_Time   (int h, int m, int s)
     { hours   = h; minutes = m; seconds = s; }
 
     int Hours()          { return hours;      }
     int Minutes()   { return minutes;    }
     int Seconds()   { return seconds;    }
    
     int get_Hours()      { cout<<"Enter Hours  : "; cin >> hours;     }
     int get_Minute()     { cout<<"Enter Minutes: "; cin >> minutes;   }
     int get_Second()     { cout<<"Enter Seconds: "; cin >> seconds;   }
 
     void tick (){
           seconds++;
           if( seconds >= 60) { seconds -= 60; minutes++; }
           if( minutes >= 60) { minutes -= 60; hours++;   }
           if( hours   >= 24) { hours   -=24;}
     }
     Time add(Time T2){
           Time T;
           T.seconds = seconds + T2.seconds;
           if( T.seconds >= 60) { T.seconds -= 60; T.minutes++; }
 
           T.minutes += minutes + T2.minutes;
           if( T.minutes >= 60) { T.minutes -= 60; T.hours++;   }
 
           T.hours += hours + T2.hours;
          
           return T;
     }
};

class Rational { 
private:
     int P; int Q;
public:
     Rational  () : P(1), Q(1)
     { }            
     Rational(int n, int d) : P() , Q(d){
           Reduced_Form();
     }
     void get(){
           cout << "Enter P : "; cin >> P;
           cout << "Enter Q : "; cin >> Q;
           Reduced_Form();
     }
     void Reduced_Form(){
           int i,min;
           min = Q < P ? Q : P ;
           for (i = min ; i >= 2 ; i--){
                if (P % i == 0 && Q % i == 0){
                     P /= i;
                     Q /= i;
                     break;
                }     
           }   
     }
     void Show(){
           cout<<P<<"/"<< Q;
     }
     float floating_point(){
           float answer;
           answer = float(P) / float(Q);
           return answer; 
     }       
     Rational Add  (Rational r1, Rational r2){
           P = r1.P*r2.Q + r2.P*r1.Q;
           Q = r1.Q*r2.Q;
           Reduced_Form();
           return Rational(P, Q);
     }
 
     Rational Subtract  (Rational r1, Rational r2){
           P = r1.P*r2.Q - r2.P*r1.Q;
           Q = r1.Q*r2.Q;
           Reduced_Form();
           return Rational(P, Q);
     }
 
     Rational Multiply  (Rational r1, Rational r2){
           P = r1.P * r2.P;
           Q = r1.Q * r2.Q;
           Reduced_Form();
           return Rational(P, Q);
     }
 
     Rational Divide  (Rational r1, Rational r2){
           P = r1.P * r2.Q;
           Q = r1.Q * r2.P;
           Reduced_Form();
           return Rational(P, Q);
     }
};


int main() {
	circle c1,c2;
	c1.set(34,23,24);
	c1.show();
	c1.area();
	c1.circumfrance();
	c2.get();
	c2.show();
	c2.area();
	c2.circumfrance();
	
	Rectangle R1,R2;
	R1.set(22,44);
	R1.perimeter();
	R1.area();
	R1.draw();
	R2.get();
	R2.perimeter();
	R2.area();
	R2.draw();

	     int i;
     Time t1;
     Time t2(5,40,30);
     t1.set_Time(23,58,52);
     for(i=0 ; i<1000 ; i++){
           t1.tick(); t1.print();    
     }
     t2.print();
     Time T3 = t1.add(t2);
     T3.print();
     
          Rational r1 ,r3;
     r1.get();
     cout <<"R1 = "; r1.Show(); cout <<endl;
 
     Rational r2(3,5);
     cout <<"R2 = "; r2.Show(); cout <<endl;
 
     r1.Show(); cout<<" + "; r2.Show(); cout <<" = ";
     r3.Add(r1,r2); r3.Show(); cout <<endl;
 
     r1.Show(); cout<<" - "; r2.Show(); cout <<" = ";
     r3.Subtract(r1,r2);  r3.Show(); cout <<endl;
    
     r1.Show(); cout<<" * "; r2.Show(); cout <<" = ";
     r3.Multiply(r1,r2);  r3.Show(); cout <<endl;
    
     r1.Show(); cout<<" / "; r2.Show(); cout <<" = ";
     r3.Divide(r1,r2);    r3.Show(); cout <<endl;


            system("PAUSE");
	return 0;
}

