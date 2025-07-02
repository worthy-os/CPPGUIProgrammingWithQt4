#include <QtWidgets/QApplication> // #include <QtWidgets/QApplication> grostig
#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculator calc;
    calc.show();
    return app.exec();
}
