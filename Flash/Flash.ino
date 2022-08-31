#include "Flash.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
  Flash fl("WiFiConfig.json");
  fl.add("auth", "3740927092323");
  fl.add("ssid", "24332");
  fl.add("pswd", "dfs");
  fl.save();
  fl.getContent("ssid");
  delay(3000);
}
