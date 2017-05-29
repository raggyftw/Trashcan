#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}//end of namespace Ui

class Dialog : public QDialog //Establishing inheritance from the Class QDialog to Dialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0); //declares constructor
    ~Dialog(); //Declares destructor

private:
    Ui::Dialog *ui;
};//End of Dialog

#endif // DIALOG_H
