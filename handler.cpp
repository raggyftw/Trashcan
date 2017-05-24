#include "handler.h"

handler::handler()
{
    current_height  = 0;
    current_weight  = 0;
}

double handler::height_points(){
    if (data.get_height() >current_height+0.5){
        height = data.get_height()-current_height;
        current_height = data.get_height();
        return height;
    }
    else{
        return 1;
    }
}

double handler::weight_points(){
    if (data.get_weight() >current_weight+10){
        weight = data.get_weight()-current_weight;
        current_weight = data.get_weight();
        return weight;
    }
    else{
        return 1;
    }
}
