#include "lab5.cpp"

int main()
{

    Medicine ob1("No-spa", 46, 20, "no");

    print(ob1);
    cout << " " << endl;

    Medicine ob2("Spasmalgon", 35, 7, "no");

    print(ob2);
    cout << " " << endl;

    Medicine ob3("Nimid", 63, 39, "no");

    print(ob3);
    cout << " " << endl;

    Medicine ob4("Vita-melatonin", 125, 12, "yes");

    print(ob4);
    cout << " " << endl;


    Pharmacy p;

    p.AddMedicine(ob1);
    p.AddMedicine(ob2);
    p.AddMedicine(ob3);
    p.AddMedicine(ob4);

    p.RemoveMedicine(1);
    p.Print();

    cout << "The cheapest: " << p.The_Cheapest().getName() << endl;

    return 0;

}  