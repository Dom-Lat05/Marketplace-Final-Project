#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User() {}
    User(const QString& username) : m_username(username) {}

    QString getUsername() const { return m_username; }

private:
    QString m_username;
};

#endif // USER_H
