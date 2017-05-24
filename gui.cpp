#include "gui.h"
#include "ui_dialog.h"
#include "QDebug"

GUI::GUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
    for (int i =0; i<4; i++){
        teams.push_back(0);
    }
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

    ui->lcd1->display(teams[0]);
    ui->lcd2->display(teams[1]);
    ui->lcd3->display(teams[2]);
    ui->lcd4->display(teams[3]);

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
