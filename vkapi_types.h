#ifndef VKAPI_TYPES_H
#define VKAPI_TYPES_H

#include <QString>
#include <QList>

namespace Vk
{
    typedef enum { MESSAGE,IMAGE,VIDEO,DOCUMENT,DIALOG,CHAT } VkType;

    class VkObject
    {
        public:
            VkType type;
    };

    class VkMessage: public VkObject
    {
        public:
            VkType type = MESSAGE;
            long int id;
            long int authorId, receiverId;
            long int chatId;
            bool readState;
            bool isOut;
            QString title;
            QString body;
    };

    class VkDialog: public VkObject
    {
        public:
            VkType type = DIALOG;
            long int talkerId;
            long int ownerId;
            long int id;
    };

    class VkChat: public VkDialog
    {
        public:
            VkType type = CHAT;
            long int chatId;
            long int adminId;
            QString title;
            QList<long int> members;
    };
}


#endif // VKAPI_TYPES_H

