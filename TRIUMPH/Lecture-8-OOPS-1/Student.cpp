#include <iostream>
using namespace std;

class Student
{
    public:

        int rollNo;

    private:

        int age;

    public:

        void setAge(int a)
        {
            if(a <= 0)
                return;
            age = a;
        }

        int getAge()
        {
            return age;
        }

        int getRoll()
        {
            return rollNo;
        }

        void setRoll(int r)
        {
            if(r <= 0)
                return;

            rollNo = r;
        }

        void display()
        {
            cout << "\nRoll No : " << rollNo;
            cout << "\nAge: " << age;

            cout << endl;
        }
};