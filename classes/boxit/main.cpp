//
// Created by syafiq on 11/16/16.
//

#include <iostream>
#include<bits/stdc++.h>

using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box
{

    public:
        Box()
        {
            this->init(0, 0, 0);
        }

        Box(long long l, long long b, long long h)
        {
            this->init(l, b, h);
        }

        Box(const Box &box)
        {
            this->init(box.l, box.b, box.h);
        }

        long long getLength() // Return box's length
        {
            return this->l;
        }

        long long getBreadth() // Return box's breadth
        {
            return this->b;
        }

        long long getHeight() //Return box's height
        {
            return this->h;
        }

        long long CalculateVolume()
        {
            return this->getLength() * this->getBreadth() * this->getHeight();
        }

        friend bool operator<(const Box &a, const Box &b)
        {
            bool status = false;
            if (a.l < b.l)
            {
                status = true;
            }
            else if (a.l == b.l)
            {
                if (a.b < b.b)
                {
                    status = true;
                }
                else if (a.b == b.b)
                {
                    if (a.h < b.h)
                    {
                        status = true;
                    }
                }
            }
            return status;
        }

        friend ostream &operator<<(ostream &out, Box &b)
        {
            out << b.l << ' ' << b.b << ' ' << b.h;
            return out;
        }

    private:
        long long l, b, h;

        void init(long long l, long long b, long long h)
        {
            this->l = l;
            this->b = b;
            this->h = h;
        }

};

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }

    }
}

int main()
{
    check2();
}