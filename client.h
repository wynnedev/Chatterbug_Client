#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <string>
#include <iostream>

#define PORT 8888

class Client : public QTcpSocket
{
    Q_OBJECT
    Q_PROPERTY(QString data READ getData NOTIFY newData)

public:
    explicit Client(QObject *parent = nullptr);
    Q_INVOKABLE void clientConnect(QString address);
    Q_INVOKABLE QString getData();
    Q_INVOKABLE void clientDisconnect();
    Q_INVOKABLE void clientWrite(QString);
    void init();

signals:
   void newData();

public slots:
    void readClient();
    void connected();

private:
    QString _data;

};

#endif // CLIENT_H
