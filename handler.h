#ifndef HANDLER_H
#define HANDLER_H

#include "arduino_data.h"

class handler
{
public:
    handler();
    double height_points();
    double weight_points();
private:
    arduino_data data;
    double current_height;
    double current_weight;
    double height;
    double weight;
};

#endif // HANDLER_H
