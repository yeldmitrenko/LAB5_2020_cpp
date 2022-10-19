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
    private:
        unsigned price;
        string name;
        tm date;
        int quantity;
        string is_prescription_needed;

    public:
        Medicine(){};
        Medicine(string name, unsigned price, int quantity, string is_prescription_needed)
        {
            this->name = name;
            this->price = price;
            this->quantity = quantity;
            this->is_prescription_needed = is_prescription_needed;
        };
        ~Medicine(){};


        string getName() { return name; };
        unsigned getPrice() { return price; };
        int getQuantity() { return quantity; };
        string getIsPrescriptionNeeded() { return is_prescription_needed; };
        tm getDate() { return date; };

        bool CompareDates(tm d1, tm d2);
}; 


class Pharmacy
{ 
    private:
        Medicine *array_of_medicines;
        int array_size;
    public:

        Pharmacy(int array_size){
            this->array_size = array_size;
            array_of_medicines = new Medicine[array_size];
        };

        Pharmacy(){
            array_of_medicines = new Medicine[array_size];
            array_size = 0;
        };

        ~Pharmacy(){
            delete[] array_of_medicines;
        };

        Medicine SearchTheCheapest();
        unsigned CalculateDiscount();
        void AddMedicine(Medicine quantity);
        void RemoveMedicine(int index);
        void MedicineInventory();
        void Print(); 
}; 