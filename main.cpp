#include <QCoreApplication>

#include "MySmartPointer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "\n==== MY SMART POINTER ====" << std::endl;
    CreateSmartPointer::runMySmartPointer();



    return a.exec();
}
