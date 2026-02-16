//Nhan Bui
//Lab5out


#include <iostream>
#include "graph1.h"

using namespace std;

class Clock
{
private:
    int hour;
    int min;
    int sec;


public:
    Clock();
    bool setHour(int hour);
    bool setMin(int min);
    bool setSec(int sec);
    int getHour();
    int getMin();
    int getSec();
    void draw();

};

Clock::Clock()
{
    hour = 0;
    min = 0;
    sec = 0;
}

bool Clock::setHour(int hour_val)
{
    bool result = false;

    if (hour_val < 0)
    {
        hour = 0;
    }
    else if (hour_val > 11)
    {
        hour = 11;
    }
    else
    {
        hour = hour_val;
        result = true;
    }
    return result;
}

int Clock::getHour()
{
    return hour;
}

bool Clock::setMin(int min_val)
{
    bool result = false;

    if (min_val < 0)
    {
        min = 0;
    }
    else if (min_val > 59)
    {
        min = 59;
    }
    else
    {
        min = min_val;
        result = true;
    }
    return result;
}

int Clock::getMin()
{
    return min;
}

bool Clock::setSec(int sec_val)
{
    bool result = false;

    if (sec_val < 0)
    {
        sec = 0;
    }
    else if (sec_val > 59)
    {
        sec = 59;
    }
    else
    {
        sec = sec_val;
        result = true;
    }
    return result;
}

int Clock::getSec()
{
    return sec;
}

void Clock::draw()
{
    const double PI = 3.14159265;
    int center_x = 320;
    int center_y = 240;
    
    int end_x = 0;
    int end_y = 0;
    int length_of_hand = 0;
    
    int line = 0;
    double alpha = 0;
    int rect = drawRect(0, 0, 640, 480);
    setColor(rect, 255, 255, 255);
    displayPNG("clock_face.png", 123, 50);

 

    alpha = sec * 6;
    length_of_hand = 150; // initialize of 2nd hand as 150


    if (alpha >= 0 && alpha < 90)
    {
        end_x = center_x + (cos((90 - alpha) * PI / 180.0)) * length_of_hand;
        end_y = center_y - (sin((90 - alpha) * PI / 180.0)) * length_of_hand;

    }
    else if (alpha >= 90 && alpha < 180)
    {
        end_x = center_x + (cos((alpha - 90) * PI / 180.0)) * length_of_hand;
        end_y = center_y + (sin((alpha - 90) * PI / 180.0)) * length_of_hand;

    }
    else if (alpha >= 180 && alpha < 270)
    {
        end_x = center_x - (cos((270 - alpha) * PI / 180.0)) * length_of_hand;
        end_y = center_y + (sin((270 - alpha) * PI / 180.0)) * length_of_hand;

    }
    else if (alpha >= 270 && alpha < 360)
    {
        end_x = center_x - (cos(((double)alpha - 270) * PI / 180.0)) * length_of_hand;
        end_y = center_y - (sin(((double)alpha - 270) * PI / 180.0)) * length_of_hand;
    }

  
    line = drawLine(center_x, center_y, end_x, end_y, 1);
   
   
    setColor(line, 255, 0, 0);
    

    alpha = min * 6 + (sec / 60.0) * 6;
    length_of_hand = 180;

    if (alpha >= 0 && alpha < 90)
    {
        end_x = center_x + (cos((90 - alpha) * PI / 180.0)) * length_of_hand;
        end_y = center_y - (sin((90 - alpha) * PI / 180.0)) * length_of_hand;

    }
    else if (alpha >= 90 && alpha < 180)
    {
        end_x = center_x + (cos((alpha - 90) * PI / 180.0)) * length_of_hand;
        end_y = center_y + (sin((alpha - 90) * PI / 180.0)) * length_of_hand;

    }
    else if (alpha >= 180 && alpha < 270)
    {
        end_x = center_x - (cos((270 - alpha) * PI / 180.0)) * length_of_hand;
        end_y = center_y + (sin((270 - alpha) * PI / 180.0)) * length_of_hand;

    }
    else if (alpha >= 270 && alpha < 360)
    {
        end_x = center_x - (cos(((double)alpha - 270) * PI / 180.0)) * length_of_hand;
        end_y = center_y - (sin(((double)alpha - 270) * PI / 180.0)) * length_of_hand;
    }

    line = drawLine(center_x, center_y, end_x, end_y, 2);
    setColor(line, 0, 0, 0);


    alpha = hour * 30 + (min / 60.0) * 30;
    length_of_hand = 133;

    if (alpha >= 0 && alpha < 90)
    {
        end_x = center_x + (cos((90 - alpha) * PI / 180.0)) * length_of_hand;
        end_y = center_y - (sin((90 - alpha) * PI / 180.0)) * length_of_hand;

    }
    else if (alpha >= 90 && alpha < 180)
    {
        end_x = center_x + (cos((alpha - 90) * PI / 180.0)) * length_of_hand;
        end_y = center_y + (sin((alpha - 90) * PI / 180.0)) * length_of_hand;

    }
    else if (alpha >= 180 && alpha < 270)
    {
        end_x = center_x - (cos((270 - alpha) * PI / 180.0)) * length_of_hand;
        end_y = center_y + (sin((270 - alpha) * PI / 180.0)) * length_of_hand;

    }
    else if (alpha >= 270 && alpha < 360)
    {
        end_x = center_x - (cos((alpha - 270) * PI / 180.0)) * length_of_hand;
        end_y = center_y - (sin((alpha - 270) * PI / 180.0)) * length_of_hand;
    }

    line = drawLine(center_x, center_y, end_x, end_y, 2);
    setColor(line, 0, 0, 0);
}

int main()
{
    int hour = 0;
    int min = 0;
    int sec = 0;
    char repeat = 'y';

    bool result;
    Clock clock1;


    displayGraphics();

    do
    {
        cout << "Enter the number of seconds: ";
        cin >> sec;
        cout << "Enter the number of minutes: ";
        cin >> min;
        cout << "Enter the number of hours: ";
        cin >> hour;

        result = clock1.setSec(sec);

        if (result == false)
        {
            cout << "Error message, the value of seconds must be between 0 - 59 inclusive)" << endl;
        }

        result = clock1.setMin(min);

        if (result == false)
        {
            cout << "Error message, the value of seconds must be between 0 - 59 inclusive)" << endl;
        }
        result = clock1.setHour(hour);

        if (result == false)
        {
            cout << "Error message, the value of seconds must be between 0 - 12 inclusive)" << endl;
        }

        clock1.draw();

        gout << setPos(280, 440) << setColor(0, 0, 0) << "Time: " << hour << ":" << min << ":" << sec << endg;

        cout << "Repeat? (Y/N)";
        cin >> repeat;

       

        clearGraphics();
        system("cls");

    } while (tolower(repeat) == 'y');

    return 0;

}


