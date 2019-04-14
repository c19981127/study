#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QSize>
#include <QTextEdit>
#include <QObject>
#include <QApplication>
extern bool count_x;
class main_window : public QObject 
{
    Q_OBJECT
private:
    QApplication *app;
    QWidget * widget;
    QPushButton * update ;
    QSize * comtent_size;
    QLabel * type;
    QLabel *src;
    QLabel * dst;
    QLabel * SMac;
    QLabel * DMac;
    QLabel * Bytes;
    QLabel * length;
    QLabel * mask;
    QLineEdit * type_n;
    QLineEdit * src_n;
    QLineEdit * dst_n;
    QLineEdit * SMac_n;
    QLineEdit * DMac_n;
    QLineEdit * Bytes_n;
    QLineEdit * length_n;
    QTextEdit * comtent;
    QLineEdit * mask_n;
    QHBoxLayout * top;
    QHBoxLayout * comtent_n;
    QHBoxLayout * button;
    QHBoxLayout * src_L;
    QHBoxLayout * des_L;
    QVBoxLayout * main;
public:
    main_window(QWidget *parent = 0);
    void show();
    void set_type(QString text);
    void set_src(QString text);
    void set_dst(QString text);
    void set_SMac(QString text);
    void set_DMac(QString text);
    void set_bytes(int number);
    void set_length(int number);
    void set_comtent(QString text);
    void set_mask(QString text);
public slots:
    void set_x();

};
#endif // MAINWINDOW_H
