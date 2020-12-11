#include "lab5.hh"

Medicine Pharmacy::SearchTheCheapest()
{   
    int index = 0;
    int min = array_of_medicines[0].getPrice();
    for(int i = 0; i < array_size; i++){
        if(array_of_medicines[i].getPrice() < min){
            min = array_of_medicines[i].getPrice();
            index = i;
        }
    }
    return array_of_medicines[index];
} 


unsigned Pharmacy::CalculateDiscount()
{
    for(int i = 0; i < array_size; i++){
        return array_of_medicines[i].getPrice() - (array_of_medicines[i].getPrice() * 0.1);
    }
}


void Pharmacy::AddMedicine(Medicine quantity)
{
    Medicine *new_medicines_array = new Medicine[array_size + 1];

    for(int i = 0; i < array_size; i++){ 
        new_medicines_array[i] = array_of_medicines[i];
    } 

    new_medicines_array[array_size] = quantity;
    
    array_size++;
    delete[] array_of_medicines;

    array_of_medicines = new_medicines_array;
}  

void Pharmacy::RemoveMedicine(int index)
{

    Medicine *new_medicines_array = new Medicine[array_size];

    for(int i = 0; i < index; i++){ 
        new_medicines_array[i] = array_of_medicines[i]; 
    } 

    for(int i = index + 1; i < array_size; i++){
        new_medicines_array[i - 1] = array_of_medicines[i];
    }
    
    array_size--;
    delete[] array_of_medicines; 

    array_of_medicines = new_medicines_array; 
} 

bool CompareDates(tm date1, tm date2)
{
    if (date1.tm_year > date2.tm_year)
        return true;
    if (date1.tm_year == date2.tm_year && date1.tm_mon > date2.tm_mon)
        return true;
    if (date1.tm_year == date2.tm_year && date1.tm_mon == date2.tm_mon && date1.tm_mday > date2.tm_mday)
        return true;
    return false;
}

void Pharmacy::MedicineInventory()
{
    time_t epoch = time(0);
    tm* now = gmtime(&epoch);

    for (int i = 0; i < array_size; i++){
        if (CompareDates(array_of_medicines[i].getDate(), *now)){
            RemoveMedicine(i);
        }
    }
} 


void PrintMedicine(Medicine &medicine)
{
    cout << "Name: " << medicine.getName() << endl;
    cout << "Price: " << medicine.getPrice() << endl;
    cout << "Quantity: " << medicine.getQuantity() << endl;
    cout << "Is Prescription needed: " << medicine.getIsPrescriptionNeeded() << endl;
}

void Pharmacy::Print()
{
    for (int i = 0; i < array_size; i++)
    {
        PrintMedicine(array_of_medicines[i]);
        cout << " " << endl;
    }
}  

