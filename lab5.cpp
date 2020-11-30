#include "lab5.hh"

Medicine Pharmacy::The_Cheapest()
{   
    int index = 0;
    int min = arr[0].getPrice();
    for(int i = 0; i < ARR; i++){
        if(arr[i].getPrice() < min){
            min = arr[i].getPrice();
            index = i;
        }
    }
    return arr[index];
} 


unsigned Pharmacy::Discount()
{
    for(int i = 0; i < ARR; i++){
        return arr[i].getPrice()-(arr[i].getPrice()*0.1);
    }
}


void Pharmacy::AddMedicine(Medicine quantity)
{
    Medicine *new_arr = new Medicine[ARR + 1];

    for(int i = 0; i < ARR; i++){ 
        new_arr[i] = arr[i];
    } 

    new_arr[ARR] = quantity;
    
    ARR++;

    delete[] arr;

    arr = new_arr;
}  

void Pharmacy::RemoveMedicine(int index)
{

    Medicine *new_arr = new Medicine[ARR];

    for(int i = 0; i < index; i++){ 
        new_arr[i] = arr[i]; 
    } 

    for(int i = index+1; i < ARR; i++){
        new_arr[i-1] = arr[i];
    }
    
    ARR--;

    delete[] arr; 

    arr = new_arr; 
} 

bool CompareDates(tm d1, tm d2)
{
    if (d1.tm_year > d2.tm_year)
        return true;
    if (d1.tm_year == d2.tm_year && d1.tm_mon > d2.tm_mon)
        return true;
    if (d1.tm_year == d2.tm_year && d1.tm_mon == d2.tm_mon && d1.tm_mday > d2.tm_mday)
        return true;
    return false;
}

void Pharmacy::Inventory()
{
    time_t epoch = time(0);
    tm* now = gmtime(&epoch);

    for (int i = 0; i < ARR; i++){
        if (CompareDates(arr[i].getDate(), *now)){
            RemoveMedicine(i);
        }
    }
}


void print(Medicine &m)
{
    cout << "Name: " << m.getName() << endl;
    cout << "Price: " << m.getPrice() << endl;
    cout << "Quantity: " << m.getQuantity() << endl;
    cout << "Is Prescription needed: " << m.getIsPrescriptionNeeded() << endl;
}

void Pharmacy::Print()
{
    for (int i = 0; i < ARR; i++)
    {
        print(arr[i]);
        cout << " " << endl;
    }
}  

