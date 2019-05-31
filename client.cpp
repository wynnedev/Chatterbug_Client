#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{

}

void Client::clientConnect(QString address)
{

}

void Client::init()
{
    connect( this, SIGNAL(readyRead()), SLOT(readClient()) );

}

void Client::readClient()
{

}

void Client::testSlot(){
   qDebug() << "Test Slot Activated";
}
