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




class Client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Qstring text NOTIFY textChanged)

public:
    explicit Client(QObject *parent = nullptr);
    Q_INVOKABLE void clientConnect(QString address);
    //void sendMessage(const QString &message);
    //QString receiveMessage();
    void init();


signals:
    //textChanged()

public slots:
    void readClient();
    void testSlot();
    //void startConnection(QString &ip);

private:
    QTcpSocket* socket;

};

#endif // CLIENT_H
