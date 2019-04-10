#ifndef TESTS_H
#define TESTS_H

#include <QMessageBox>

class Tests
{
private:

public:
    void runFirstTaskTests()
    {
        QMessageBox box;
        box.setText("First tests runned");
        box.exec();
    }

    void runSecondTaskTests()
    {
        QMessageBox box;
        box.setText("Second tests runned");
        box.exec();
    }
};

#endif // TESTS_H
