#include "DungeonQuill.h"
#include "AbilityScore.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <iostream>
#include "DataManager.h"

//���ø�ʽ
void setQss() {
    QFile qssFile(":/qss/Source/Ubuntu.qss");
    qssFile.open(QFile::ReadOnly);
    if (qssFile.isOpen())
    {
        qApp->setStyleSheet(qssFile.readAll());
        qssFile.close();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setQss();

    //���������ڲ���
    DungeonQuill w;
    w.show();

    DataManager dataManager;
    dataManager.createDb();
    //dataManager.download();
    return a.exec();
}
