#ifndef VKAPI_TYPES_H
#define VKAPI_TYPES_H

#include <QString>

namespace VkAPI
{
    typedef enum { MESSAGE,IMAGE,VIDEO,DOCUMENT } VkType;

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
}


#endif // VKAPI_TYPES_H

