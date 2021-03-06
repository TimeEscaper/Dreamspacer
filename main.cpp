#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "sec.h"
#include "debug.h"
#include "vkapi.h"
#include <fstream>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QEventLoop>
using namespace std;

using namespace Vk;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.InterfaceVisibility(false);

    Core::Sec::UserSession User;
    ifstream input("udf.dat",ios::binary);
    if(input)
    {
        //Добавить проверку токена, ID и MAC-адреса
        input.read((char*)&User,sizeof(User));
        Core::Global::token = User.token;
        Core::Global::masterId = User.userId;

        w.InterfaceVisibility(true);

       /* QNetworkAccessManager downloader;
        QNetworkRequest getRequest;
        getRequest.setUrl(QUrl("https://api.vk.com/method/messages.getDialogs?count=1&access_token="+Core::Global::token));
        QNetworkReply *res;
       // QObject::connect(res,SIGNAL(finished()),this,SLOT(GetDialogFinished()));
        res = downloader.get(getRequest);

        QEventLoop ev;
        QObject::connect(&downloader,SIGNAL(finished(QNetworkReply*)),&ev,SLOT(quit()));
        ev.exec();

        Debug::DebugMessage(res->readAll());*/

        VkAPI vk;
        QObject::connect(&vk,SIGNAL(DialogDownloadFinished(QString)),&w,SLOT(Vk_DialogDownloadFinished(QString)));
        vk.GetDialogs(Core::Global::token);

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
