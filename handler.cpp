#include "handler.h"

handler::handler()
{
    current_height  = 0; //Makes sure the height starts at 0
    current_weight  = 0; //Makes sure the weight starts at 0
}

double handler::height_points(){//This method makes sure that points are not given for trash already in the trashcan
    if (data.get_height() >current_height+0.5){ //if-statement to check if new trash was thrown into the trashcan
        height = data.get_height()-current_height; //Sets the height 
        current_height = data.get_height(); //sets the current height
        return height; //returns the height
    }//end of if-statement
    else{//if the level of trash does not change nothing is done and 1 is returned
        return 1; 
    }//end of else-statement
}

double handler::weight_points(){//This method makes sure that points are not given for trash already in the trashcan
    if (data.get_weight() >current_weight+10){ //if-statement to check if new trash was thrown into the trashcan
        weight = data.get_weight()-current_weight;//Sets the weight 
        current_weight = data.get_weight();//sets the current weight
        return weight; //returns the weight
    }//end of if-statement
    else{
        return 1;
    }//end of else-statement
}
