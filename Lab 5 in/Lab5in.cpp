// Nhan Bui
// Lab 5 In


#include <iostream>
#include "graph1.h"

using namespace std;

class FilledCircle
{
private:
    int x;
    int y;
    int radius;

public:
    // Default Constructor
    FilledCircle();
    //Getter and Setter
    bool setX(int x_val);
    int getX();
    bool setY(int y_val);
    int getY();
    bool setRadius(int r_val);
    int getRadius();
    // Draw
    void draw();
};

FilledCircle::FilledCircle()
{
    //Set private data fields to default values
    x = 0;
    y = 0;
    radius = 15;
}


bool FilledCircle::setX(int x_val)
{
    bool result = false;
    if (x_val < 0) {
        x = 0;
    }
    else if (x_val >= 640) {
        x = 639;
    }
    else {
        x = x_val;
        result = true;
    }
    //Implement rules for x_val when out of range  
    return result;
}

int FilledCircle::getX()
{
    
    return x;
}

bool FilledCircle::setY(int y_val)
{
    bool result = false;
    if (y_val < 0) {
        y = 0;
    }
    else if (y_val >= 480)
    {
        y = 479;
    }
    else {

        y = y_val;
        result = true;
    }
    //Implement rules for setting the y-coord
    return result;
}

int FilledCircle::getY()
{
    return y;
}

bool FilledCircle::setRadius(int r_val)
{
    bool result = false;
    if (r_val <= 0) {

        radius = 1;
    }
    else if (r_val > 30) {
        radius = 30;

    }
    //Implement rule for setting the radius
    else {

        radius = r_val;
        result = true;
    }
    return result;
}


int FilledCircle::getRadius()
{
    return radius;
}

void FilledCircle::draw()
{
    //Draw the filled circle
    int i = 0;
    for (i = 0; i <= radius; i++)
    {
        drawCircle(i, x, y);
    }
}

int main()
{
    //Variable Declaration/Initialization
    int i = 0;
    int x = 0;
    int y = 0;
    int radius = 0;
    bool result = false;
    // Object - instantiating object - Allocating memory for it. Default constructor is called/ invoked
    // Declare a FilledCircle object using the default Constructor

    FilledCircle circle1;

    char repeat;

    //Display the Graphics
    displayGraphics();

    do
    {
        //Prompt for the x/y coordinates
        cout << "Enter x/y coords: ";
        cin >> x >> y;

        //Prompt for the radius
        cout << "Enter radius: ";
        cin >> radius;

        //Set the x coord for circle1 – display message if x is out of range
        result = circle1.setX(x);
        if (result == false) {
            cout << "X coord has to be between 0 and 639 inclusively" << endl;
        }

        //Set the y coord for circle1 – display message if y is out of range

        result = circle1.setY(y);
        if (result == false) {
            cout << "X coord has to be betweeen 0 and 479 inclusively" << endl;
        }


        //Set the radius for cirle1 – display message if radius is out of range
        result = circle1.setRadius(radius);
        if (result == false) {
            cout << "radius has to be betweeen 1 and 30 inclusively" << endl;
        }


        //Draw the circle
        circle1.draw();

        //Display the coordinate info, radius info under the circle along with the 

        gout << setPos(circle1.getX() - circle1.getRadius(), circle1.getY() + circle1.getRadius() + 15) << "(" << circle1.getX() << "," << circle1.getY() << ")" << endg;
        gout << setPos(circle1.getX() - circle1.getRadius(), circle1.getY() + circle1.getRadius() + 30) << "Radius: " << circle1.getRadius() << endg;
        cout << "\nWould you like to repeat? (y/n): ";
        cin >> repeat;

        clearGraphics();
        system("cls");

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       