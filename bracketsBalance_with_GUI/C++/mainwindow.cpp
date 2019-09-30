#include <iostream>
#include <string>
#include <map>
#include <stack>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_Run, SIGNAL(clicked()), this, SLOT(on_pushButton_Run_clicked()));
    connect(ui->pushButton_Clean, SIGNAL(clicked()), this, SLOT(on_pushButton_Clean_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Signal handler for the pushButtonRun clicked() signal. Qt event and signal/slot are two different
// ways to do the same thing - notice and action. Event is used when implement widgets or modify widgets.
// Signal/slot are used when using widgets, for inter-class communication.
// Here, when the pushButton_Run object is clicked, it will send a clicked() signal to the mainWindow class.
// The following function is the mainWindow's signal handler function for this signal. The mainWindow's
// constructor should "connect" this signal handler function with the click() signal by call the connect()
// function, so that, upon receive the click() signal, the mainWindow will call this handler function to
// process the signal.
// So, when user type in a string and click the run button, we need to do the following:
//  1.) Get the user typed string from textEdit object of the GUI.
//  2.) Parse the user string to see if the brackets contained, are balanced or not
//  3.) Display the results back onto the UI's on object. ( I used a label for this ).
//
//  The event and siganl/slot handling is an important aspect of GUI programming.
void MainWindow::on_pushButton_Run_clicked()
{
   // We need to get he user typed string from the text edit
    QString userStr = ui->textEdit->toPlainText();       // get the content text from textEdit
    // ui->label_ResultArea->setText(userStr);           // test event handling
    //std::string myString = userStr.toStdString();
    std::stack<char>charStack;
    bool balanced = true;
    int numberOfBrackets = 0;
    if(userStr.size() == 0)
    {
        ui->label_ResultArea->setText("You forgot to type in a string! Try again!");
        return;
    }

    for (auto ch : userStr.toStdString())                                    //  Walk the string
    {
       //for (const auto &[first, second] : charMap)
       for (const auto &kv : charMap)
       {
           if(ch == kv.first)                                   // Check to see if the char is an open bracket
           {
              charStack.push(ch);                               // ...yes, push it onto stack
              numberOfBrackets++;
              continue;
           }
           else if(ch == kv.second)                             // Check to see if the ch is a close bracket
           {
               numberOfBrackets++;
                if(!charStack.empty())                          // ...yes, and make sure the stack is not empty
                {
                    if(charStack.top() != kv.first)             // Check to see if the close bracket match the one on the stack
                    {
                        balanced = false;                       // ... no, mismatch
                        break;
                    }
                    else                                        // ... yes, got a match
                        charStack.pop();
                }
                else                                            // ... we have more close bracket
                {
                    balanced = false;
                    break;
                }
            }
        }
     }
     if(!charStack.empty() || balanced == false)                // Finally, make decision
     {
          //std::cout << "The brackets are NOT balanced." << std::endl << "\n";
         ui->label_ResultArea->setText("The brackets are NOT balanced.");
     }
     else if(numberOfBrackets == 0)
          //std::cout << "No brackets in the string." << std::endl << "\n";
         ui->label_ResultArea->setText("No brackets in the string.");
     else
          //std::cout << "The brackets are Balanced!" << std::endl << "\n";
         ui->label_ResultArea->setText("The brackets are Balanced!");

}

void MainWindow::on_pushButton_Clean_clicked()
{
   // When user click the Clean button, we need to clean the TextEdit and Result area.
   ui->textEdit->setText("");
   ui->label_ResultArea->setText("");
   // And position the curse into the testEdit
}
