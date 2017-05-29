#ifndef HANDLER_H
#define HANDLER_H

#include "arduino_data.h"

class handler
{
public:
    handler();
    double height_points(); //method to get the height from the arduino
    double weight_points(); //method to get the weight from the arduino
private:
    arduino_data data; //Creates an object of the arduino_data class
    double current_height; //double to store the current height
    double current_weight; //double to store the current weight
    double height; //double to store the height
    double weight; //double to store the weight
};//end of handler class

#endif // HANDLER_H
