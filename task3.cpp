//Напишіть клас Date, що містить константні функції - члени для отримання дня,
//місяця та року.Реалізуйте explicit конструктор, що приймає значення для дня,
//місяця та року.Поясніть, як константні функції - члени допомагають забезпечити
//незмінність об'єктів.



#include <iostream>
using namespace std;



class Date
{
private:

    int day;
    int month;
    int year;

public:
   

    explicit Date(int d, int m, int y) : day(d), month(m), year(y) {}

   
    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    
    void printDate() const {
        cout << day << "/" << month << "/" << year << endl;
    }
};

void main()
{

    Date date(19, 6, 2024);


    cout << "Day: " << date.getDay() << endl;
    cout << "Month: " << date.getMonth() << endl;
    cout << "Year: " << date.getYear() << endl;


    date.printDate();

    
}




//використання константних функцій забезпечує незмінність об'єктів, а explicit  запобігає перетворенням типів      
