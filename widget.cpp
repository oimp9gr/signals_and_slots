#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_push_pressed()));
    connect(this, SIGNAL(change_first_button_text(int)), this, SLOT(change_first_button_text_slot(int)));
    connect(this, SIGNAL(change_second_button_text(int)), this, SLOT(change_second_button_text_slot(int)));
    connect(this, SIGNAL(change_third_button_text(int)), this, SLOT(change_third_button_text_slot(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_push_pressed()
{
    static int counter = 0;
    counter++;

    if (counter % 3 == 1) {
        emit change_first_button_text(counter);
    } else {
        emit change_first_button_text(-1);
    }

    if (counter % 3 == 2) {
        emit change_second_button_text(counter);
    } else {
        emit change_second_button_text(-1);
    }

    if (counter % 3 == 0) {
        emit change_third_button_text(counter);
    } else {
        emit change_third_button_text(-1);
    }
}

void Widget::change_first_button_text_slot(int counter)
{
    ui->pushButton_1->setText(counter != - 1 ? QString::number(counter) : "");
}

void Widget::change_second_button_text_slot(int counter)
{
    ui->pushButton_2->setText(counter != - 1 ? QString::number(counter) : "");
}

void Widget::change_third_button_text_slot(int counter)
{
    ui->pushButton_3->setText(counter != - 1 ? QString::number(counter) : "");
}

