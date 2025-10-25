#pragma once

#include <QObject>
#include <QString>

using namespace std;

class IpcClient : public QObject {
    Q_OBJECT
public:
    using QObject::QObject;
    virtual ~IpcClient() = default;

    virtual void connectToLocalSocket(const QString& path) = 0;
    virtual void sendCommand(const QString& cmd) = 0;

signals:
    void eventReceived(const QString& event);
    void responseReceived(const QString& response);
};
