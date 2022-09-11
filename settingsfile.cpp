#include "settingsfile.h"

settingsfile::settingsfile()
{
    Initialize();
    QFile confFile(SETTINGS_FILE_PATH);
    confFile.open(QIODevice::ReadWrite);
    QTextStream in(&confFile);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList readData = line.split(":");
        if(!readData.isEmpty())
        {
            readFile(readData.value(0), readData.value(1));
        }
    }

    qInfo() << LOG_FILE;

    confFile.close();
}

void settingsfile::readFile(QString dataType, QString data)
{
    switch (s_mapStringValues[dataType]) {
        case NO_TYPE:
            // Do nothing
            break;
        case TRANSCEIVER_PORT:
            this->TRANCEIVER_PORT_DEFAULT = data;
            break;
        case TRANSCEIVER_BAURATE:
            this->TRANCEIVER_BAUDRATE_DEFAULT = data.toInt();
            break;
        case GPS_PORT:
            this->GPS_PORT_DEFAULT = data;
            break;
        case GPS_BAUDRATE:
            this->GPS_BAUDRATE_DEFAULT = data.toInt();
            break;
        case LORA_PORT:
            this->LORA_PORT_DEFAULT = data;
            break;
        case LORA_BAUDRATE:
            this->LORA_BAUDRATE_DEFAULT = data.toInt();
            break;
        case CONF_THRESOL_FILE_PATH:
            this->CONF_THRESOL = data;
            break;
        case IMAGES_FILE_PATH:
            this->IMAGES_FILE = data;
            break;
        case DATA_FILE_PATH:
            this->DATA_FILE = data;
            break;
        case GPS_FILE_PATH:
            this->GPS_FILE = data;
            break;
        case HISTORY_FILE_PATH:
            this->HISTORY_FILE = data;
            break;
        case LOG_FILE_PATH:
            this->LOG_FILE = data;
            break;
        case TIME_DETECT_FILE_PATH:
            this->TIME_DETECT_FILE = data;
            break;
        case HOST_MQTT:
            this->hostMqtt = data;
            break;
        case PORT_MQTT:
            this->portMqtt = data.toInt();
            break;
        case TOPIC1:
            this->topic1 = data;
            break;
        case TOPIC2:
            this->topic2 = data;
            break;
        case ACCESS_TOKEN:
            this->ACCESS_TOKEN_H = data;
            break;
        default:
            // Do nothing
            break;

    }
}

void settingsfile::Initialize()
{
    s_mapStringValues["TRANSCEIVER_PORT"] = TRANSCEIVER_PORT;
    s_mapStringValues["TRANSCEIVER_BAURATE"] = TRANSCEIVER_BAURATE;
    s_mapStringValues["GPS_PORT"] = GPS_PORT;
    s_mapStringValues["GPS_BAUDRATE"] = GPS_BAUDRATE;
    s_mapStringValues["LORA_PORT"] = LORA_PORT;
    s_mapStringValues["LORA_BAUDRATE"] = LORA_BAUDRATE;
    s_mapStringValues["CONF_THRESOL_FILE_PATH"] = CONF_THRESOL_FILE_PATH;
    s_mapStringValues["IMAGES_FILE_PATH"] = IMAGES_FILE_PATH;
    s_mapStringValues["DATA_FILE_PATH"] = DATA_FILE_PATH;
    s_mapStringValues["GPS_FILE_PATH"] = GPS_FILE_PATH;
    s_mapStringValues["HISTORY_FILE_PATH"] = HISTORY_FILE_PATH;
    s_mapStringValues["LOG_FILE_PATH"] = LOG_FILE_PATH;
    s_mapStringValues["TIME_DETECT_FILE_PATH"] = TIME_DETECT_FILE_PATH;
    s_mapStringValues["HOST_MQTT"] = HOST_MQTT;
    s_mapStringValues["PORT_MQTT"] = PORT_MQTT;
    s_mapStringValues["TOPIC1"] = TOPIC1;
    s_mapStringValues["TOPIC2"] = TOPIC2;
    s_mapStringValues["ACCESS_TOKEN"] = ACCESS_TOKEN;
}

void settingsfile::updateConfigSettings()
{
    QFile confFile(SETTINGS_FILE_PATH);
    confFile.open(QIODevice::ReadWrite);
    QTextStream in(&confFile);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList readData = line.split(":");
        readFile(readData.value(0), readData.value(1));
    }

    confFile.close();
}