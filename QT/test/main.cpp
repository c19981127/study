#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window = new QWidget;
    window->setWindowTitle("enter your age");
    QSpinBox *spinBox = new QSpinBox;
    QSlider * slider = new QSlider;
    spinBox->setRange(0,130);
    slider->setRange(0,130);
    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));
    spinBox->setValue(35);

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window->setLayout(layout);
    window->show();
    return a.exec();
}
