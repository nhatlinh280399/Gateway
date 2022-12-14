#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QPixmap>
#include <QSettings>
#include <QTime>
#include <QLabel>

#include "communication/protocols/messages/messageID.h"
#include "settingsfile.h"
#include "console.h"
#include "serialport.h"
#include "mqttclient.h"

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createMqttClient();
    void AlwaysOpenSerialPort();

private:


signals:
    void signalMqttSubcribe();
    void signalMqttPublic(QString message);

private slots:
    void onPrintSensorData(int idSensor, double lat, double lon, float temp, float hum, float dust);
    void on_pushButton_clicked();
    void onMqttConntected();
    void onMqttConnecting();
    void onMqttDisconnect();
    void onSubcribeTopic(bool result);
    void checkSerialPort();
    void onMqttSubUpdateState(QString state);
    void onMqttSubMessage(QString message);
    void onMqttSubQos(quint8 qos);

    void on_disconnectMqttButton_clicked();

    void on_connectMqttButton_clicked();

    void on_clearButton_clicked();

    void on_subButton_clicked();

public:
    settingsfile* config;
private:
    Ui::MainWindow *ui;
    Console* console;
    QThread* thread_lora;
    QString _organizationName, _appname;
    bool transceiverStarted, sended, detectedFlag, loraStarted, subcribeSuccess = false;
    serialport* lora;
    mqttclient* mqttClient;
    QString attributes;
};
#endif // MAINWINDOW_H
