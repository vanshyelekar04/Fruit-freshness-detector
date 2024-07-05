const int MQ4_PIN = A0;
const int SAFE_food = 150;
const int SPOILED_food = 250;
void setup() {  
  Serial.begin(9600);
}

void loop() {
  int mq4_read = analogRead(MQ4_PIN);
float ppm = (mq4_read / 1024.0) * 5000 / 10;      //CALIBRATION OF MQ-4 METHANE SENSOR.
Serial.println("Gas concentration: ");
Serial.println(ppm);
Serial.println(" ppm");
Serial.print("Gas conc:");
Serial.print(ppm);
Serial.println(" ppm");
if (ppm > SAFE_food) {
  Serial.print("Food is ");
  if (ppm > SPOILED_food) {
      Serial.print("spoiled");
      Serial.println("");
    } 
    
    else {
      Serial.print("safe");
      Serial.println("");
    }
  }

  delay(60000);                     //readings per minute
}
