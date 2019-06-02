#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "threadmanager.h"

#define PORT 8888

class Server : public QTcpServer
{
public:
    Server();
    void StartServer();

signals:

public slots:

protected:
    void incomingConnection(int socketID);
};

#endif // SERVER_H
