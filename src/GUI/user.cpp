#include "user.h"

User::User()
{
}

User::User(const QString& username)
    : m_username(username)
{
}

QString User::getUsername() const
{
    return m_username;
}

bool User::isValid() const
{
    return !m_username.trimmed().isEmpty();
}
