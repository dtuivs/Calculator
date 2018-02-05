#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void set_Digit_Display();

    void set_ans_button();

    void resetValues();

    float evaluate(int operate, float valueA, float valueB);

    void check_operate();

    void value_shift(int operation);

    void on_button_equals_clicked();

    void on_button_1_clicked();

    void on_button_2_clicked();

    void on_button_3_clicked();

    void on_button_4_clicked();

    void on_button_5_clicked();

    void on_button_6_clicked();

    void on_button_7_clicked();

    void on_button_8_clicked();

    void on_button_9_clicked();

    void on_button_0_clicked();

    void on_button_dot_clicked();

    void on_button_clear_clicked();

    void on_button_plus_clicked();

    void on_button_subtract_clicked();

    void on_button_multiply_clicked();

    void on_button_divide_clicked();

    void on_button_ans_clicked();

    void on_button_backspace_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
