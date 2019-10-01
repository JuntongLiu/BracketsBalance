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
    //explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Run_clicked();

    void on_pushButton_Clean_clicked();

private:
    Ui::MainWindow *ui;
    std::map<char, char>charMap { {'(', ')'},
                                  {'[', ']'},
                                  {'{', '}'} };
};

#endif  // MAINWINDOW_H
