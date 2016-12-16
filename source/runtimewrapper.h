#ifndef RUNTIMEWRAPPER_H
#define RUNTIMEWRAPPER_H
#include <QtCore>
#include "runtime.h"
#include "message.h"
class RuntimeWrapper : public QThread
{
    Q_OBJECT
public:
    RuntimeWrapper(QObject *parent=0,int num=0,int id=0);
    void processMessage(Message);
    void stopWaitForPlayer(int);
    void playerOffline(int);
signals:
    void emitMessage(Message);
protected:
    void run() Q_DECL_OVERRIDE;
private:
    void waitForPlayer(int);
    void removePlayer(int);
    void processRuntimeMessage(Message);
    int roomID;
    bool isWaiting;
    runtime rt;
    QMutex waitLock;
    QWaitCondition waitForResponse;
    QVector<int> waitList;
};

#endif // RUNTIMEWRAPPER_H
