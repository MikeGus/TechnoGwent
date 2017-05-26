#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Field field;
    field.ally = Commander(1);
    field.ally.useAbility(field.desk);
}

MainWindow::~MainWindow()
{
    delete ui;
}
