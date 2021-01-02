#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include "displaystring.h"
#include "functions.h"
#include "history.h"


QT_BEGIN_NAMESPACE
namespace Ui { class calc; }
QT_END_NAMESPACE

class calc : public QMainWindow
{
    Q_OBJECT

public:
    calc(QWidget *parent = nullptr);
    ~calc();

public slots:
    void seclabelclear();
    void updatehistory();
    void histloadbutton(int buttonslotindex);

private slots:
    void on_button_clearone_clicked();

    void on_button_clearall_clicked();

    void on_button_closebracket_clicked();

    void on_button_openbracket_clicked();

    void on_button_one_clicked();

    void on_button_two_clicked();

    void on_button_three_clicked();

    void on_button_multiply_clicked();

    void on_button_divide_clicked();

    void on_button_six_clicked();

    void on_button_five_clicked();

    void on_button_four_clicked();

    void on_button_seven_clicked();

    void on_button_eight_clicked();

    void on_button_nine_clicked();

    void on_button_plus_clicked();

    void on_button_minus_clicked();

    void on_button_zero_clicked();

    void on_button_decimal_clicked();

    void on_button_equals_clicked();

    void on_button_hist_one_clicked();

    void on_button_hist_two_clicked();

    void on_button_hist_three_clicked();

    void on_button_hist_four_clicked();

    void on_button_hist_five_clicked();

    void on_clearhistory_clicked();

    void on_button_cuberoot_clicked();

    void on_button_squareroot_clicked();

    void on_button_square_clicked();

    void on_button_cube_clicked();

    void on_button_power_clicked();

    void on_button_sin_clicked();

    void on_button_cos_clicked();

    void on_button_tan_clicked();

    void on_button_ln_clicked();

    void on_button_log_clicked();

private:
    Ui::calc *ui;
    Displaystring maintext;
    Displaystring sectext;
    History history;

};
#endif // CALC_H
