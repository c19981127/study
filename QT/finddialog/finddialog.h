#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QMainWindow>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class FindDialog : public QDialog
{
    Q_OBJECT
public:
    FindDialog(QWidget *parent = 0);
signals:
    void findNext(const QString &str,Qt::CaseSensitivity cs);
    void findPrevious(const QString &dtr,Qt::CaseSensitivity cs);
private slots:
    void findClicked();
    void enableFindButton(const QString &text);
 private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};
#endif
