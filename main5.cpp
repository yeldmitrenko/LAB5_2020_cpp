#include "lab5.cpp"

int main()
{

    Medicine ob1("No-spa", 46, 20, "no");

    PrintMedicine(ob1);
    cout << " " << endl;

    Medicine ob2("Spasmalgon", 35, 7, "no");

    PrintMedicine(ob2);
    cout << " " << endl;

    Medicine ob3("Nimid", 63, 39, "no");

    PrintMedicine(ob3);
    cout << " " << endl;

    Medicine ob4("Vita-melatonin", 125, 12, "yes");

    PrintMedicine(ob4);
    cout << " " << endl;


    Pharmacy pharmacy;

    pharmacy.AddMedicine(ob1);
    pharmacy.AddMedicine(ob2);
    pharmacy.AddMedicine(ob3);
    pharmacy.AddMedicine(ob4);

    pharmacy.RemoveMedicine(1);
    pharmacy.Print();

    cout << "The cheapest: " << pharmacy.SearchTheCheapest().getName() << endl;

    return 0;

}  