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
    maintext.addbracket(")");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_openbracket_clicked()
{
    maintext.addbracket("(");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_one_clicked()
{
    maintext.addnum("1");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_two_clicked()
{
    maintext.addnum("2");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_three_clicked()
{
    maintext.addnum("3");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_multiply_clicked()
{
    maintext.addopr("*");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_divide_clicked()
{
    maintext.addopr("/");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_six_clicked()
{
    maintext.addnum("6");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_five_clicked()
{
    maintext.addnum("5");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_four_clicked()
{
    maintext.addnum("4");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_seven_clicked()
{
    maintext.addnum("7");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_eight_clicked()
{
    maintext.addnum("8");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_nine_clicked()
{
    maintext.addnum("9");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_plus_clicked()
{
    maintext.addopr("+");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_minus_clicked()
{
    maintext.addopr("-");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_zero_clicked()
{
    maintext.addnum("0");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_decimal_clicked()
{
    maintext.adddecimal(".");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_cuberoot_clicked()
{
    maintext.addopr("^");
    maintext.addbracket("(");
    maintext.addnum("1");
    maintext.addopr("/");
    maintext.addnum("3");
    maintext.addbracket(")");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_squareroot_clicked()
{
    maintext.addopr("^");
    maintext.addbracket("(");
    maintext.addnum("1");
    maintext.addopr("/");
    maintext.addnum("2");
    maintext.addbracket(")");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_square_clicked()
{
    maintext.addopr("^");
    maintext.addbracket("(");
    maintext.addnum("2");
    maintext.addbracket(")");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_cube_clicked()
{
    maintext.addopr("^");
    maintext.addbracket("(");
    maintext.addnum("3");
    maintext.addbracket(")");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_power_clicked()
{
    maintext.addopr("^");
    maintext.addbracket("(");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_sin_clicked()
{
    maintext.addfunc("sin");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_cos_clicked()
{
    maintext.addfunc("cos");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_tan_clicked()
{
    maintext.addfunc("tan");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_ln_clicked()
{
    maintext.addfunc("ln");
    ui->label_primary->setText(QString::fromStdString(maintext.display()));
}

void calc::on_button_log_clicked()
{
    maintext.addfunc("log");
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
        char placehold;
        placehold = maintext.display()[maintext.display().length()-1];
        if(placehold == '*' || placehold == '/' || placehold == '^'){
            maintext.addnum("1");
        }else if(placehold == '+' || placehold == '-'){
            maintext.addnum("0");
        }else if(placehold == '('){
            maintext.addnum("1");
            maintext.addbracket(")");
        }
        sectext.setdisplay(maintext.display());
        maintext.answer();
        if(maintext.display() == "DIVBYZERO" || maintext.display() == "nan" || maintext.display() == "inf"){
            ui->label_primary->setText(QString::fromStdString("ERROR"));
            ui->label_secondary->setText(QString::fromStdString("cannot divide by zero"));
            QTimer::singleShot(2000, this, SLOT(seclabelclear()));
            maintext.setdisplay("ERROR");
            sectext.setdisplay("");
        }else if(maintext.display() == "POWERROR"){
            ui->label_primary->setText(QString::fromStdString("ERROR"));
            ui->label_secondary->setText(QString::fromStdString("negative base to any power is not supported"));
            QTimer::singleShot(2000, this, SLOT(seclabelclear()));
            maintext.setdisplay("ERROR");
            sectext.setdisplay("");
        }else if(maintext.display() == "LOGERROR"){
            ui->label_primary->setText(QString::fromStdString("ERROR"));
            ui->label_secondary->setText(QString::fromStdString("logarithm is only defined for positive numbers"));
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
