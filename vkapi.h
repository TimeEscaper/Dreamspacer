#ifndef VKAPI_H
#define VKAPI_H

#include <QObject>
#include <QString>
#include <QList>
#include <QNetworkReply>
#include "vkapi_types.h"

//bool CheckToken(long int masterId, QString token);

namespace Vk
{
    class VkAPI: public QObject
    {
        Q_OBJECT

        public:
            //QList<VkDialog> GetDialogs(long int masterId, QString token);
            void GetDialogs(QString token);
            //VkAPI();

        signals:
            void DialogDownloadFinished(QString data);

        public slots:
            void DialogDownloadFinished_slot(QNetworkReply* data);
    };
}

#endif
