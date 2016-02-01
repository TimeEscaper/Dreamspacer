#ifndef SEC_H
#define SEC_H

#include <QString>

namespace Core
{
    namespace Sec
    {
        struct UserSession
        {
            char token[120];
            long int userId;
        };

        bool SaveSession(QString Token, long int UserId);
    }
}

#endif // SEC_H

