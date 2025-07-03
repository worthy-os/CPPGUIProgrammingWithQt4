#include <QtCore>
#include <QDialog>
#include <QtGui>
#include <QtNetwork>
#include <QtQml>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QSortFilterProxyModel>
#include <QtWidgets>
#include "colornamesdialog.h"

ColorNamesDialog::ColorNamesDialog(QWidget *parent)
    : QDialog(parent)
{
    sourceModel = new QStringListModel(this);
    sourceModel->setStringList(QColor::colorNames());

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(sourceModel);
    proxyModel->setFilterKeyColumn(0);

    listView = new QListView;
    listView->setModel(proxyModel);
    listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    filterLabel = new QLabel(tr("&Filter:"));
    filterLineEdit = new QLineEdit;
    filterLabel->setBuddy(filterLineEdit);

    syntaxLabel = new QLabel(tr("&Pattern syntax:"));
    syntaxComboBox = new QComboBox;
    /* syntaxComboBox->addItem(tr("Regular expression"), QRegularExpression::RegExp);
    syntaxComboBox->addItem(tr("Wildcard"), QRegularExpression::Wildcard);
    syntaxComboBox->addItem(tr("Fixed string"), QRegularExpression::FixedString); */
    syntaxComboBox->addItem(tr("Regular expression"), 0); // TODO??: integers are probably trash, but AI suggested it, just trying to get it to compile. grostig
    syntaxComboBox->addItem(tr("Wildcard"), 1);
    syntaxComboBox->addItem(tr("Fixed string"), 2);
    syntaxLabel->setBuddy(syntaxComboBox);

    connect(filterLineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(reapplyFilter()));
    connect(syntaxComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(reapplyFilter()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(listView, 0, 0, 1, 2);
    mainLayout->addWidget(filterLabel, 1, 0);
    mainLayout->addWidget(filterLineEdit, 1, 1);
    mainLayout->addWidget(syntaxLabel, 2, 0);
    mainLayout->addWidget(syntaxComboBox, 2, 1);
    setLayout(mainLayout);

    setWindowTitle(tr("Color Names"));
}

void ColorNamesDialog::reapplyFilter()
{
    /* QRegularExpression::PatternSyntax syntax =
            QRegularExpression::PatternSyntax(
                syntaxComboBox->itemData( syntaxComboBox->currentIndex() ).toInt()
            );
    QRegularExpression regExp(filterLineEdit->text(), Qt::CaseInsensitive, syntax);
    proxyModel->setFilterRegularExpression(regExp); // proxyModel->setFilterRegExp(regExp); grostig TODO??: instead of reg exp: Role?? */

    QString pattern = filterLineEdit->text(); // Get the pattern from the filter input, grostig

    int syntaxIndex = syntaxComboBox->itemData(syntaxComboBox->currentIndex()).toInt(); // Get the syntax selection from the combo box, grostig

           // Create the QRegularExpression based on the syntax, grostig
    QRegularExpression regExp;
    switch (syntaxIndex) {
    case 0: // Regular expression
        regExp = QRegularExpression(pattern);
        break;
    case 1: // Wildcard
        regExp = QRegularExpression(QRegularExpression::wildcardToRegularExpression(pattern));
        break;
    case 2: // Fixed string
        regExp = QRegularExpression(QRegularExpression::escape(pattern));
        break;
    default:
        // Fallback to regular expression
        regExp = QRegularExpression(pattern);
        break;
    }
    regExp.setPatternOptions(QRegularExpression::CaseInsensitiveOption); // Set case-insensitive option, grostig
    proxyModel->setFilterRegularExpression(regExp); // Apply the filter to the proxy model, grostig
}
