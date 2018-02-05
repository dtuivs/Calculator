#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

QString displayNumber = "";
bool dotPressed = false;
int operate = 0;
float value_hold;
float ans;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_Digit_Display()
{
    float number = displayNumber.toFloat();
    ui->digit_display->display(number);
}

void MainWindow::set_ans_button()
{
    QString ANS = QString::number(ans);
    ui->button_ans->setText(ANS);
}

void MainWindow::resetValues()
{
    value_hold = NULL;
    dotPressed = false;
    displayNumber = "";
    operate = 0;
}

float MainWindow::evaluate(int operate, float valueA, float valueB)
{
    float c;
    if(operate == 1){
        c = valueA + valueB;
    }else if(operate ==2){
        c = valueA - valueB;
    }else if(operate == 3){
        c = valueA * valueB;
    }else if(operate == 4){
        c = valueA / valueB;
    }else{
        c = 0;
    }
    return c;
}

void MainWindow::check_operate(){
    if(operate != 0){
        value_hold = evaluate(operate, value_hold, displayNumber.toFloat());
        QString value = QString::number(value_hold);
        displayNumber = value;
        set_Digit_Display();
    }
}

void MainWindow::value_shift(int operation){
    if (displayNumber == ""){
        value_hold = ans;
    }else{
        value_hold = displayNumber.toFloat();
    }

    operate = operation;
    displayNumber = "";
    dotPressed = false;
}

void MainWindow::on_button_equals_clicked()
{
    if(value_hold == NULL)
    {
        ans = displayNumber.toFloat();
        set_ans_button();
    }
    else
    {
        float C;
        if(operate != 0)
        {
            C = evaluate(operate, value_hold, displayNumber.toFloat());
        }
        else
        {
            C = displayNumber.toFloat();
        }
        ans = C;
        set_ans_button();
        QString c = QString::number(C); //Convert float C (uppercase) to QString c (lowercase)
        displayNumber = c;
        set_Digit_Display();
        resetValues();
    }
}

void MainWindow::on_button_1_clicked()
{
    displayNumber = displayNumber + "1";
    set_Digit_Display();
}

void MainWindow::on_button_2_clicked()
{
    displayNumber = displayNumber + "2";
    set_Digit_Display();
}

void MainWindow::on_button_3_clicked()
{
    displayNumber = displayNumber + "3";
    set_Digit_Display();
}

void MainWindow::on_button_4_clicked()
{
    displayNumber = displayNumber + "4";
    set_Digit_Display();
}

void MainWindow::on_button_5_clicked()
{
    displayNumber = displayNumber + "5";
    set_Digit_Display();
}

void MainWindow::on_button_6_clicked()
{
    displayNumber = displayNumber + "6";
    set_Digit_Display();
}

void MainWindow::on_button_7_clicked()
{
    displayNumber = displayNumber + "7";
    set_Digit_Display();
}

void MainWindow::on_button_8_clicked()
{
    displayNumber = displayNumber + "8";
    set_Digit_Display();
}

void MainWindow::on_button_9_clicked()
{
    displayNumber = displayNumber + "9";
    set_Digit_Display();
}

void MainWindow::on_button_0_clicked()
{
    displayNumber = displayNumber + "0";
    set_Digit_Display();
}

void MainWindow::on_button_dot_clicked()
{
    if(dotPressed == false){
        dotPressed = true;
        if(displayNumber == ""){
            displayNumber = "0.";
        }else{
        displayNumber = displayNumber + ".";
        }
        set_Digit_Display();
    }
}

void MainWindow::on_button_clear_clicked()
{
    resetValues();
    set_Digit_Display();
}

void MainWindow::on_button_plus_clicked()
{
    check_operate();
    value_shift(1);
}

void MainWindow::on_button_subtract_clicked()
{
    check_operate();
    value_shift(2);
}

void MainWindow::on_button_multiply_clicked()
{
    check_operate();
    value_shift(3);
}

void MainWindow::on_button_divide_clicked()
{
    check_operate();
    value_shift(4);
}

void MainWindow::on_button_ans_clicked()
{
    QString ANS = QString::number(ans);
    displayNumber = ANS;
    set_Digit_Display();
}

void MainWindow::on_button_backspace_clicked()
{
    QString omitted = displayNumber.left(displayNumber.length() - 1);
    displayNumber = omitted;
    set_Digit_Display();
}


