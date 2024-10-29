#include "MainWindowIlichev.h"

#include <QApplication>

// int sum( int lhs, int rhs ){
//     return lhs + rhs;
// }

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowIlichev w;
    w.show();
    return a.exec();

    // auto f_sum = std::bind(sum, 3, std::placeholders::_1);
    // std::cout << f_sum(7);
}
