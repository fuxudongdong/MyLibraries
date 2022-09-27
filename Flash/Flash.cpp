#include "Arduino.h"
#include "Flash.h"
#include <FS.h>
#define BLINKER_WIFI
#include <ArduinoJson.h>

String json = "";

Flash::Flash(String my_file) : fileName(my_file)
{
    fileName = "/" + fileName;
}

Flash::~Flash()
{
}

bool Flash::exists()
{
    SPIFFS.begin();
    return SPIFFS.exists(fileName);
}

String Flash::getContent(String str)
{
    if (SPIFFS.begin())
    { // 打开闪存文件系统
        Serial.println("闪存文件系统打开成功");
    }
    else
    {
        Serial.println("闪存文件系统打开失败");
    }
    if (SPIFFS.exists(fileName))
    {
        Serial.println("找到" + fileName);
        const size_t capacity = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 156; //分配一个内存空间
        DynamicJsonDocument doc(capacity);                                       // 声明json处理对象
        File file = SPIFFS.open(fileName, "r");
        deserializeJson(doc, file); // json数据序列化
        String str1 = doc[str];
        Serial.println(str + ":" + str1);
        file.close();
        return str1;
    }
    else
    {
        Serial.println("不存在" + fileName);
        return "";
    }
}

void Flash::add(String strName, String str)
{
    if (json == "")
    {
        json += "{\"" + strName + "\":\"";
        json += str;
    }
    else
    {
        json += "\",\"" + strName + "\":\"";
        json += str;
    }
}

void Flash::save()
{
    if (SPIFFS.remove(fileName))
    {
        Serial.println("删除旧" + fileName + "成功");
    }
    else
    {
        Serial.println("删除旧" + fileName + "失败");
    }
    json += "\"}";
    Serial.println(json);
    File file = SPIFFS.open(fileName, "w");
    file.println(json); //将数据写入config.json文件中
    Serial.println("文件写入成功！");
    file.close();
    json = "";
}

void Flash::remove()
{
    if (SPIFFS.remove(fileName))
    {
        Serial.println("删除旧" + fileName + "成功");
    }
    else
    {
        Serial.println("删除旧" + fileName + "失败");
    }
}
