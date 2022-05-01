#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void on_push_pressed();
    void change_first_button_text_slot(int counter);
    void change_second_button_text_slot(int counter);
    void change_third_button_text_slot(int counter);

signals:
    void change_first_button_text(int counter);
    void change_second_button_text(int counter);
    void change_third_button_text(int counter);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
