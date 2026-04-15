#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User();
    User(const QString& username);

    QString getUsername() const;
    bool isValid() const;

private:
    QString m_username;
};

#endif // USER_H
