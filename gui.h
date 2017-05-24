#ifndef GUI_H
#define GUI_H

#include <QDialog>
#include "handler.h"

namespace Ui {
class GUI;
}

class GUI : public QDialog{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = 0);
    ~GUI();
     Ui::GUI *ui;

private slots:
     void on_button1_clicked();
     void on_button2_clicked();
     void on_button3_clicked();
     void on_button4_clicked();

private:
     handler hdl;
     double teams [4];
     void update_score(int);
};

#endif // GUI_H
