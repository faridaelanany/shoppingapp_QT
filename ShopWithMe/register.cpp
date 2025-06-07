#include "register.h"
#include "ui_register.h"
#include "findproduct.h"

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    hide();
    FindProduct *findProductWindow = new FindProduct(this);
    findProductWindow->show();
}

