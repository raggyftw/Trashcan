#ifndef GUI_H
#define GUI_H

#include <QDialog>
#include "handler.h"
#include <vector>


namespace Ui {
class GUI;//Declaring that the namespace of the Ui is within GUI
}//End of namespace Ui

class GUI : public QDialog //The GUI class inherits all public atributes from the QDialog Class
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = 0);// Declaring contructor
    ~GUI(); // Declaring destructor
     Ui::GUI *ui; //Setting up the UI


private slots:
     void on_button1_clicked();//Creating method for clicking on button 1
     void on_button2_clicked();//Creating method for clicking on button 2
     void on_button3_clicked();//Creating method for clicking on button 3
     void on_button4_clicked();//Creating method for clicking on button 4

private:
     handler hdl;//Creating a object of the handler class
     std::vector<double> teams;//Creating vector to store the teams point's
     void update_score(int); //method to update the score


};//End of the GUI class

#endif // GUI_H
