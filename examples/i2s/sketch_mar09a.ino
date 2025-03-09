// #include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"
#define I2S_DOUT     25
#define I2S_BCLK      27
#define I2S_LRC        26
Audio audio;
String ssid =    "NHATROVN-tret-01";
String password = "nhatrovn.vn";
void setup() {
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  while (WiFi.status() != WL_CONNECTED)
  delay(1500);
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(50);
  audio.connecttohost("http://vis.media-ice.musicradio.com/CapitalMP3");
}
void loop()
{
  audio.loop();
}
