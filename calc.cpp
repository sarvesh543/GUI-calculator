#include "calc.h"
#include "ui_calc.h"
#include "functions.h"
#include "displaystring.h"
#include "history.h"
#include <QString>
#include <string>
#include <QTimer>

//All
//most of logic is in other classes and functions
//this part handles ui and connects everything together

calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this);
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
    ui->label_secondary->setText(QString::fromStdString(""));
}

calc::~calc()
{
    delete ui;
}

void calc::seclabelclear()
{
    if(ui->label_secondary->text() == QString::fromStdString("cannot divide by zero") || ui->label_secondary->text() == QString::fromStdString("invalid brackets")){
        ui->label_secondary->setText(QString::fromStdString(""));
    }
}

void calc::updatehistory()
{
    if(5 > history.size()){
        ui->label_hist_5->setText(QString::fromStdString("0"));
    }else{
        ui->label_hist_5->setText(QString::fromStdString(history.showsecondaryhistory(4).append("=").append(history.showmainhistory(4))));
    }
    if(4 > history.size()){
        ui->label_hist_4->setText(QString::fromStdString("0"));
    }else{
        ui->label_hist_4->setText(QString::fromStdString(history.showsecondaryhistory(3).append("=").append(history.showmainhistory(3))));
    }
    if(3 > history.size()){
        ui->label_hist_3->setText(QString::fromStdString("0"));
    }else{
        ui->label_hist_3->setText(QString::fromStdString(history.showsecondaryhistory(2).append("=").append(history.showmainhistory(2))));
    }
    if(2 > history.size()){
        ui->label_hist_2->setText(QString::fromStdString("0"));
    }else{
        ui->label_hist_2->setText(QString::fromStdString(history.showsecondaryhistory(1).append("=").append(history.showmainhistory(1))));
    }
    if(1 > history.size()){
        ui->label_hist_1->setText(QString::fromStdString("0"));
    }else{
        ui->label_hist_1->setText(QString::fromStdString(history.showsecondaryhistory(0).append("=").append(history.showmainhistory(0))));
    }
}

void calc::histloadbutton(int buttonslotindex)
{
    if(history.size() >= buttonslotindex){
        maintext.setdisplay(history.showmainhistory(buttonslotindex - 1));
        sectext.setdisplay(history.showsecondaryhistory(buttonslotindex - 1));
        ui->label_primary->setText(QString::fromStdString(maintext.display()));
        ui->label_secondary->setText(QString::fromStdString(sectext.display()));
    }else{
        maintext.setdisplay("0");
        sectext.setdisplay("");
        ui->label_primary->setText(QString::fromStdString(maintext.display()));
        ui->label_secondary->setText(QString::fromStdString(sectext.display()));
    }
    ui->tabWidget->setCurrentIndex(0);
}




void calc::on_button_clearone_clicked()
{
    maintext.clearelement();
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_clearall_clicked()
{
    maintext.cleardisplay();
    sectext.setdisplay("");
    ui->label_secondary->setText(QString::fromStdString(sectext.display()));
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_closebracket_clicked()
{
    maintext.addtodisplay(")");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_openbracket_clicked()
{
    maintext.addtodisplay("(");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_one_clicked()
{
    maintext.addtodisplay("1");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_two_clicked()
{
    maintext.addtodisplay("2");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_three_clicked()
{
    maintext.addtodisplay("3");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_multiply_clicked()
{
    maintext.addtodisplay("*");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_divide_clicked()
{
    maintext.addtodisplay("/");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_six_clicked()
{
    maintext.addtodisplay("6");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_five_clicked()
{
    maintext.addtodisplay("5");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_four_clicked()
{
    maintext.addtodisplay("4");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_seven_clicked()
{
    maintext.addtodisplay("7");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_eight_clicked()
{
    maintext.addtodisplay("8");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_nine_clicked()
{
    maintext.addtodisplay("9");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_plus_clicked()
{
    maintext.addtodisplay("+");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_minus_clicked()
{
    maintext.addtodisplay("-");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_zero_clicked()
{
    maintext.addtodisplay("0");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_decimal_clicked()
{
    maintext.addtodisplay(".");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_equals_clicked()
{
    if(bracketerror(maintext.display())){
        maintext.setdisplay("ERROR");
        ui->label_primary->setText(QString::fromStdString("ERROR"));
        ui->label_secondary->setText(QString::fromStdString("invalid brackets"));
        QTimer::singleShot(2000, this, SLOT(seclabelclear()));
    }else{
        sectext.setdisplay(maintext.display());
        maintext.answer();
        if(maintext.display() == "DIVBYZERO" || maintext.display() == "nan"){
            ui->label_primary->setText(QString::fromStdString("ERROR"));
            ui->label_secondary->setText(QString::fromStdString("cannot divide by zero"));
            QTimer::singleShot(2000, this, SLOT(seclabelclear()));
            maintext.setdisplay("ERROR");
            sectext.setdisplay("");
        }else{
            ui->label_primary->setText(QString::fromStdString(maintext.display()));
            ui->label_secondary->setText(QString::fromStdString(sectext.display()));
            history.removelastdata();
            history.addata(maintext.display(), sectext.display());
            updatehistory();
        }
    }
}

void calc::on_button_hist_one_clicked()
{
    histloadbutton(1);
}

void calc::on_button_hist_two_clicked()
{
    histloadbutton(2);
}

void calc::on_button_hist_three_clicked()
{
    histloadbutton(3);
}

void calc::on_button_hist_four_clicked()
{
    histloadbutton(4);
}

void calc::on_button_hist_five_clicked()
{
    histloadbutton(5);
}

void calc::on_clearhistory_clicked()
{
    history.clearhist();
    updatehistory();

}
