#include <bits/stdc++.h>
#include "Student.cpp"
using namespace std;

int main()
{
    Student *s1 = new Student;
    Student s2;
    Student *s3 = new Student[2];

    s3[0].setAge(100);
    s3[0].setRoll(30);

    Student *s4 = new Student(s3[0]);
    
    
     
    s1->setRoll(212);
    s1->setAge(21);

    s2.setAge(20);
    s2.setRoll(10);

    s1->display();
    s2.display();

    s3[0].display();

    s4->display();

    return 0;
}