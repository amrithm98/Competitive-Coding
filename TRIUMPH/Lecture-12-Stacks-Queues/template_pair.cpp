#include <bits/stdc++.h>
using namespace std;

template <typename T,typename V>
class Pair
{
    T first;
    V second;

    public:
        void setFirst(T x)
        {
            first = x;
        }
        void setSecond(V y)
        {
            second = y;
        }
        T getFirst()
        {
            return first;
        }
        V getSecond()
        {
            return second;
        }
};

int main()
{
    Pair<int,int> p1;
    p1.setFirst(10);
    p1.setSecond(20);

    cout << p1.getFirst() << " " << p1.getSecond() << endl;

    Pair<char,int> p2;
    p2.setFirst('A');
    p2.setSecond(100);

    Pair<Pair<char,int>,double> student;
    student.setFirst(p2);
    student.setSecond(99.99);

    cout << student.getFirst().getFirst() << " " << student.getFirst().getSecond() << " " << student.getSecond();
    cout << endl;

    return 0;
}