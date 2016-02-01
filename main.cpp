#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    QString appIdStr = QString::number(Core::Global::appId);
    QString toLoad = "https://oauth.vk.com/authorize?client_id=" + appIdStr
                    + "&redirect_uri=blank.html&display=popup&scope=friends,messages,audio"
                      "&response_type=token&v=5.42&state=Success!";
    w.ui->webView->load(QUrl(toLoad));

    return a.exec();
}
