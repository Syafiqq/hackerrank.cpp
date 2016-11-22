//
// Created by syafiq on 11/22/16.
//

#include <cmath>
#include <vector>
#include <iostream>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
using namespace std;

class Person
{
    public :
        Person(int id) : id(id)
        {}

        virtual void putdata() = 0;
        virtual void getdata() = 0;

    protected:
        string name;
        int age;
        int id;
};

class Professor : public Person
{
    public:
        Professor() : Person(++Professor::counter)
        {

        }

        virtual void putdata() override
        {
            cout << this->name << ' ' << this->age << ' ' << this->publication << ' ' << this->id <<  endl;
        }

        virtual void getdata() override
        {
            string name;
            int age;
            int publication;
            cin >> name >> age >> publication;

            this->name = name;
            this->age = age;
            this->publication = publication;
        }

    private:
        int publication;
        static int counter;
};


class Student : public Person
{
    public:
        Student() : Person(++Student::counter)
        {
            this->marks = new int[6];
            this->total = 0;
        }

        virtual void putdata() override
        {
            cout << this->name << ' ' << this->age << ' ' << this->total << ' ' << this->id << endl;
        }

        virtual void getdata() override
        {
            string name;
            int age;
            cin >> name >> age;

            this->name = name;
            this->age = age;

            int mark;
            for(int i = -1, is = 6; ++i < is;)
            {
                cin >> mark;
                this->marks[i] = mark;
                this->total += mark;
            }
        }

    private:
        int* marks;
        int total;
        static int counter;
};

int Student::counter = 0;
int Professor::counter = 0;

int main()
{

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
#pragma clang diagnostic pop