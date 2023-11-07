#include <QCoreApplication>


#include "MySmartPointer.h"
#include "MySharedPointer.h"

#include "Task.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    std::cout << "\n==== MY SMART POINTER ====" << std::endl;
//    CreateSmartPointer::runMySmartPointer();

//    std::cout << "\n==== MY SHARED POINTER ====" << std::endl;
//    CreaateSharedPointer::runMySharedPointer();


    std::cout << "\n==== TASKS ====" << std::endl;
    Task::runTask();





    return a.exec();
}
