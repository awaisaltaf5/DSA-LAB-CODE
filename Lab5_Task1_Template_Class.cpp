#include <iostream>
using namespace std;
template <class T>
class Myclass
{
private:
    T num;

public:
    void input()
    {
        cout << "\nEnter the number: ";
        cin >> num;
    }
    void display() const
    {
        cout << "Entered Number: " << num;
    }
};
int main()
{
    Myclass<int> intobj;
    cout << "For Integer:";
    intobj.input();
    intobj.display();
    Myclass<float> floatobj;
    cout << "\n\nFor Float:";
    floatobj.input();
    floatobj.display();

    return 0;
}