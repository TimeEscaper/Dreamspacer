#include "vkapi.h"
#include "global.h"
#include "debug.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>

using namespace Vk;

void Vk::VkAPI::GetDialogs(QString token)
{
    QString queryUrl = "https://api.vk.com/method/messages.getDialogs?count=1&access_token="+token;
    QNetworkAccessManager downloader;
    connect(&downloader,SIGNAL(finished(QNetworkReply*)),this,SLOT(DialogDownloadFinished_slot(QNetworkReply*)));
    downloader.get(QNetworkRequest(QUrl(queryUrl)));
    Debug::DebugMessage("Hi!");
}

void VkAPI::DialogDownloadFinished_slot(QNetworkReply *data)
{
    emit DialogDownloadFinished(data->readAll());
    delete data;
}
