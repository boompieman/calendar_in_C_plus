#include <iostream>

using namespace std;



int year,month;
int dayInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeapYear(int);
void inputDate();//input Year, Month
int calculateHowManyDays();//calculate how many days you enter
int calculateBeginWeekDayOfMonth();// calculate the weekday of month
void print();//print on monitor

int main()
{
    inputDate();
    if (isLeapYear(year)){
    dayInMonth[2]++;
    }
    cout<<"==============================="<<endl;
    cout<<'\t'<<'\t'<<"Perpetual Calendar!!"<<endl;
    print();
}

bool isLeapYear(int year){
    if ((year%400==0) || ((year%4==0) && (year%100!=0))) return true;
    else return false;
}

void inputDate(){
    cout<<"Input the year: ";
    cin>>year;
    cout<<"Input the month: ";
    cin>>month;
}

int calculateHowManyDays(){
    int howManyDays=0;

    for (int i=1;i<month;i++){
        howManyDays += dayInMonth[i];
    }
    howManyDays+=1;//adding day can calculate the week day of today
    return howManyDays;
}

int calculateBeginWeekDayOfMonth(){
    int weekDayToday;
    weekDayToday = (year-1) + ((year-1)/4) - ((year-1)/100) + ((year-1)/400) + calculateHowManyDays();
    weekDayToday +=7;
    weekDayToday%=7;
    return weekDayToday;
}

void print(){
    int date=0;
    int ctr = calculateBeginWeekDayOfMonth();

    cout<<endl;
    cout<<"SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT"<<endl;
    for (int i=0;i<calculateBeginWeekDayOfMonth();i++) cout<<'\t';

    for(int i = 0;i<dayInMonth[month];i++){
        ctr++;
        date++;
        cout<<date<<'\t';
        if (ctr%7==0){
            cout<<'\n';
        }
    }
}


