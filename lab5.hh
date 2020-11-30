#include <iostream>
#include <string>
#include <ctime>

using namespace std;

tm ExpirationDate(int day, int month, int year)
{
    struct tm date;

    date.tm_mday;
    date.tm_mon;
    date.tm_year;

    return date;
} 

class Medicine
{
    unsigned price;
    string name;
    tm date;
    int quantity;
    string IsPrescriptionNeeded;

public:
    Medicine(){};
    Medicine(string name, unsigned price, int quantity, string IsPrescriptionNeeded)
    {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->IsPrescriptionNeeded = IsPrescriptionNeeded;
    };
    ~Medicine(){};


    string getName() {return name;};
    unsigned getPrice() {return price;};
    int getQuantity() {return quantity;};
    string getIsPrescriptionNeeded() {return IsPrescriptionNeeded;};
    tm getDate() {return date;};

    bool CompareDates(tm d1, tm d2);
};


class Pharmacy
{ 
    Medicine *arr;
    int ARR;
public:

    Pharmacy(int ARR){
        this->ARR = ARR;
        arr = new Medicine[ARR];
    };

    Pharmacy(){
        arr = new Medicine[ARR];
        ARR = 0;
    };

    ~Pharmacy(){
        delete[] arr;
    };

    Medicine The_Cheapest();
    unsigned Discount();
    void AddMedicine(Medicine quantity);
    void RemoveMedicine(int index);
    void Inventory();
    void Print();
};