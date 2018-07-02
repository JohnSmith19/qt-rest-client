#include "widget.h"
#include "ui_widget.h"
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->paramTable->setColumnCount(2);
    ui->paramTable->setHorizontalHeaderLabels(QString("key;value").split(";"));
    ui->paramTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->urlEdit->setText("http://127.0.0.1:5000/");
}

Widget::~Widget()
{
    delete ui;
}
