#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QtWidgets/qdialog.h>      // grostig
#include <QtWidgets/qboxlayout.h>   // grostig
#include <QtWidgets/qslider.h>      // grostig
#include <QtWidgets/qspinbox.h>     // grostig
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
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

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
