#include "textfinder.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("TextEditor");
    a.setApplicationDisplayName("TextEditor");
    TextFinder w;
    w.show();
    return a.exec();
}
