#include "server.h"

Server::Server()
{

}

void Server::StartServer()
{
    if(this->listen(QHostAddress::Any,PORT)){
        qDebug() << "Listening...";
    }

    else{
        qDebug() << "Server Not Started";
    }
}

void Server::incomingConnection(int socketID)
{
    qDebug() << socketID << " Connecting...";
    ThreadManager *thread = new ThreadManager(socketID, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
