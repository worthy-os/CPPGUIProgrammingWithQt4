#ifndef FINDFILEDIALOG_H
#define FINDFILEDIALOG_H

#include <QtWidgets>
#include <QtWidgets/qdialog.h>      // grostig

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTableWidget;

class FindFileDialog : public QDialog
{
    Q_OBJECT

public:
    FindFileDialog(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QLabel *namedLabel;
    QLabel *lookInLabel;
    QLineEdit *lookInLineEdit;
    QLineEdit *namedLineEdit;
    QCheckBox *subfoldersCheckBox;
    QTableWidget *tableWidget;
    QLabel *messageLabel;
    QPushButton *findButton;
    QPushButton *stopButton;
    QPushButton *closeButton;
    QPushButton *helpButton;
};

#endif
