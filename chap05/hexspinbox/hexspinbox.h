#ifndef HEXSPINBOX_H
#define HEXSPINBOX_H
#include <QtCore>
#include <QDialog>
#include <QtGui>
#include <QtNetwork>
#include <QtQml>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QtWidgets>
//class QRegExpValidator;  // grostig

class HexSpinBox : public QSpinBox
{
    Q_OBJECT

public:
    HexSpinBox(QWidget *parent = 0);

protected:
    QValidator::State validate(QString &text, int &pos) const;
    int valueFromText(const QString &text) const;
    QString textFromValue(int value) const;

private:
    QRegularExpressionValidator *validator;  // grostig expanded name
};

#endif
