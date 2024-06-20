//�������� ���� Date, �� ������ ��������� ������� - ����� ��� ��������� ���,
//����� �� ����.��������� explicit �����������, �� ������ �������� ��� ���,
//����� �� ����.�������, �� ��������� ������� - ����� ����������� �����������
//��������� ��'����.



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




//������������ ����������� ������� ��������� ��������� ��'����, � explicit  ������� ������������� ����      
