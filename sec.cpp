#include "sec.h"
#include <fstream>
#include <QMessageBox>
using namespace std;

bool Core::Sec::SaveSession(QString Token, long int UserId)
{
    UserSession User;
    strcpy(User.token,Token.toStdString().c_str());
    User.userId = UserId;

    ofstream output("udf.dat",ios::binary);
    if(!output)
        return false;

    //Добавить проверку на успешность записи
    output.write((char*)&User,sizeof(User));
    output.close();

    return true;
}
