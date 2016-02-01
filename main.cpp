#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "sec.h"
#include "debug.h"
#include <fstream>
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Core::Sec::UserSession User;
    ifstream input("udf.dat",ios::binary);
    if(input)
    {
        //Добавить проверку токена, ID и MAC-адреса
        input.read((char*)&User,sizeof(User));
        Core::Global::token = User.token;
        Core::Global::masterId = User.userId;
        w.ui->webView->setVisible(false);
    }
    else
    {
        QString appIdStr = QString::number(Core::Global::appId);
        QString toLoad = "https://oauth.vk.com/authorize?client_id=" + appIdStr
                        + "&redirect_uri=blank.html&display=popup&scope=friends,messages,audio"
                          "&response_type=token&v=5.44&state=Success!";
        w.ui->webView->load(QUrl(toLoad));
    }
    return a.exec();
}
