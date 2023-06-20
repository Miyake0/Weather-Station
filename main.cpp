#include "mbed.h"
#include "BME280.h"
#include "TextLCD.h"

Serial pc(USBTX, USBRX);

I2C i2c(PB_9, PB_8);
// AnalogIn rainSensSCor(A5);
// DigitalOut myled(LED1);
TextLCD_I2C lcd(&i2c, (0x27) << 1, TextLCD::LCD16x2);
// BME280 sensor(D14, D7);
// BME280 sensor(I2C_SDA, I2C_SCL);
BME280 sensor(D3, D6);

int main() {
    
    pc.baud(115200);
    
    // pc.printf("Temperature: %.2f °C\n");
    // pc.printf("Temperature: %.2f °C");

    
    lcd.setBacklight(TextLCD_I2C::LightOn);
    
    // lcd.printf("Hello World!\n");

    while(1) {
        // float sensorValue = rainSensor.read();
        // printf("Rain sensor value: %.2f\n", sensorValue);

        float temperature = sensor.getTemperature();
        float humidity = sensor.getPressure();
        float pressure = sensor.getHumidity();

        // pc.printf("Temperature: %.2f °C\n", temperature);
        // pc.printf("Humidity: %.2f %%\n", humidity);
        // pc.printf("Pressure: %.2f hPa\n", pressure);
        // wait(2); 
        lcd.cls();
        
        lcd.locate(0, 0);
        lcd.printf(" Temp: %.2f C", temperature);
        lcd.locate(0, 1);
        lcd.printf("Humidity: %.2f%%", humidity);

        wait(2);  

        lcd.cls();
        lcd.locate(0, 0);
        lcd.printf("Pressure: %.2f Pa ", pressure);
        lcd.locate(0, 1);
        lcd.printf("                ");
        wait(2);
        lcd.cls();


        // pc.printf("%2.2f degC, %04.2f hPa, %2.2f %%\n", sensor.getTemperature(), sensor.getPressure(), sensor.getHumidity());
        
        // lcd.locate(0, 0);
        // lcd.printf("Hello");

        // myled = 1;
        // wait(0.2);
        // myled = 0;
        // wait(0.2);
    }
}