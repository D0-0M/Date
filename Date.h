#pragma once 
#include <iostream>

class Date {
private:
    int day, month, year;

public:
    Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {};

    bool leapYear() 
    {
        return (year % 4 == 0 && year % 100 == 0 && year % 400 == 0);
    }
    int Days_in_Months() 
    {
        int monthD = 31;
        if (month == 4 || month == 6 || month == 9 || month == 11) 
        {
            monthD--;
        }
        if (month == 2) 
        {
            if (leapYear()) 
            {
                monthD = 29;
            }
            else 
            {
                monthD = 28;
            }
        }
        return monthD;
    }
    void formatDate() {
        if (month < 10) {
            std::cout << 0;
        }
        std::cout << month << "/";
        if (day < 10) {
            std::cout << 0;
        }
        std::cout << day << "/";
        if (year < 0) {
            std::cout << year * -1 << " a.e.c\n";
        }
        else {
            std::cout << year << std::endl;
        }
    }

    Date* operator +(int days) {
        Date* new_Date = new Date(month, day, year);
        while (new_Date->day + days > new_Date->Days_in_Months()) {
            days -= (new_Date->Days_in_Months() - new_Date->day);
            new_Date->addMonth(1);
            new_Date->day = 0;
        }
        new_Date->day += days;
        return new_Date;
    }

    Date* operator -(int days) {
        Date* new_Date = new Date(month, day, year);
        while (new_Date->day - days < 1) {
            days -= new_Date->day;
            new_Date->subtractMonth(1);
            new_Date->day = new_Date->Days_in_Months();
        }
        new_Date->day -= days;
        return new_Date;
    }

    

    //Prefix
    Date& operator ++() {
        ++day;
        return *this;
    }
    Date& operator --() {
        --day;
        return *this;
    }

    //postfix
    Date operator ++(int) {
        Date copy(month, day, year);
        ++day;
        return copy;
    }
    Date operator --(int) {
        Date copy(month, day, year);
        --day;
        return copy;
    }

};