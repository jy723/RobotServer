#pragma once

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class DitServer : public QObject
{
    Q_OBJECT
public:
    explicit DitServer(QObject *parent = 0);

signals:
	void commandSend();

public slots:
    void newConnection();
    void clientDisconnected();
    void readSocket();
	void writeSocket();

private:
    QTcpServer *m_pServer;
    QList<QTcpSocket *> m_pClientConnections;
};
