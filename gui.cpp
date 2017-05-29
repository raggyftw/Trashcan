#include "gui.h"
#include "ui_dialog.h"
#include "QDebug"

GUI::GUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GUI)//Setting up the Ui in the GUI class
{
    ui->setupUi(this);
    for (int i =0; i<4; i++){//For loop to add all 4 teams to the teams vector 
        teams.push_back(0);
    }//end of for-loop
}


GUI::~GUI()
{

    delete ui;
}


void GUI::update_score(int team) 
{
    if(hdl.height_points()*hdl.weight_points() != 1){
    teams[team]+=hdl.height_points()*hdl.weight_points();
    }

    ui->lcd1->display(teams[0]);//Update the LCD with the 1st element of the vector
    ui->lcd2->display(teams[1]);//Update the LCD with the 2nd element of the vector
    ui->lcd3->display(teams[2]);//Update the LCD with the 3rd element of the vector
    ui->lcd4->display(teams[3]);//Update the LCD with the 4th element of the vector

}

void GUI::on_button1_clicked()
{
    update_score(0);
}

void GUI::on_button2_clicked()
{
    update_score(1);
}


void GUI::on_button3_clicked()
{
    update_score(2);
}

void GUI::on_button4_clicked()
{
    update_score(3);
}
