#include "mainwindow.h"
main_window::main_window(QWidget * parent)
    :QObject(parent)
{
    widget = new QWidget;
    update = new QPushButton("update");
    connect(update, SIGNAL(clicked()), this, SLOT(set_x())); 
    type = new QLabel("Type");
    Bytes = new QLabel("Bytes");
    length = new QLabel("Length");
    src = new QLabel("SIP");
    dst = new QLabel("DIP");
    SMac = new QLabel("SMac");
    DMac = new QLabel("DMac");
    mask = new QLabel("Mask");
    type_n = new QLineEdit;
    Bytes_n = new QLineEdit;
    src_n = new QLineEdit;
    dst_n = new QLineEdit;
    SMac_n = new QLineEdit;
    DMac_n = new QLineEdit;
    length_n = new QLineEdit;
    comtent = new QTextEdit;
    mask_n = new QLineEdit;
    comtent->resize(100,16);

    top = new QHBoxLayout;
    top->addWidget(type);
    top->addWidget(type_n);
    top->addWidget(Bytes);
    top->addWidget(Bytes_n);
    top->addWidget(length);
    top->addWidget(length_n);

    button = new QHBoxLayout;
    button->addWidget(mask);
    button->addWidget(mask_n);
    button->addWidget(update);

    src_L = new QHBoxLayout;
    src_L->addWidget(src);
    src_L->addWidget(src_n);
    src_L->addWidget(SMac);
    src_L->addWidget(SMac_n);

    des_L = new QHBoxLayout;
    des_L->addWidget(dst);
    des_L->addWidget(dst_n);
    des_L->addWidget(DMac);
    des_L->addWidget(DMac_n);

    comtent_n = new QHBoxLayout;
    comtent_n->addWidget(comtent);
    main = new QVBoxLayout;
    main->addLayout(top);
    main->addLayout(src_L);
    main->addLayout(des_L);
    main->addLayout(comtent_n);
    main->addLayout(button);

    widget->setLayout(main);
}
void main_window::set_bytes(int number_n)
{
    Bytes_n->setText(QString::number(number_n));
}
void main_window::set_type(QString text)
{
    type_n->setText(text);
}
void main_window::set_length(int number_n)
{
    length_n->setText(QString::number(number_n));
}
void main_window::set_src(QString text)
{
    src_n->setText(text);
}
void main_window::set_dst(QString text)
{
    dst_n->setText(text);
}
void main_window::set_SMac(QString text)
{
    SMac_n->setText(text);
}
void main_window::set_DMac(QString text)
{
    DMac_n->setText(text);
}
void main_window::set_comtent(QString text)
{
    comtent->setText(text);
}
void main_window::set_mask(QString text)
{
    mask_n->setText(text);
}
void main_window::set_x()
{
   count_x=true;
   widget->close();
}
void main_window::show()
{
    widget->show();
}
