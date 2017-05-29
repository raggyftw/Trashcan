#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this); //Declaring that the UI will be established in this file
}// End of constructor

Dialog::~Dialog()
{
    delete ui;
}// End of descructor 
