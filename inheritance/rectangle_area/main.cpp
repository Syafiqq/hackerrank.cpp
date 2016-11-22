
/*
 * This <hackerrank_cpp> project in package created by : 
 * Name         : syafiq
 * Date / Time  : 22 November 2016, 3:28 PM.
 * Email        : syafiq.rezpector@gmail.com
 * Github       : syafiqq
 */
#include <iostream>

using namespace std;

class Rectangle
{
    public:
        Rectangle()
        {
            this->width = this->height = 0;
        }

        virtual void display()
        {
            cout << this->width << ' ' << this->height << endl;
        }

    protected:
        int width;
        int height;
};

class RectangleArea : public Rectangle
{
    public:
        RectangleArea()
        {

        }

        void read_input()
        {
            int width, height;
            cin >> width >> height;

            this->width = width;
            this->height = height;
            this->area = width * height;
        }

        virtual void display() override
        {
            cout << this->area << endl;
        }

    private:
        int area;
};



int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}