#include"deklarasi.h"
int pilih = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initPiezoElectric();
  initMP3();
}

void loop() {

  for (int z = 0; z < 7; z++) {

    ///////////////////////////////////////////////////
    data[z] = analogRead(z);        // Read Poezoelectric signal
    Serial.print("Pin Analog ");
    Serial.print("A");
    Serial.print(z);
    Serial.print(" : ");
    Serial.println(data[z]);
    if (data[z] > minimumThresholdSignal) {             // MinimumThresholdSignal adalah batasan minimum untuk membedakan signal dengan noise

      //************************************//
      // Setting level volume both DF_MP3
      if (data[z] > minimumThresholdSignal && data[z] < ThresholdLowVolume) {
        kirimperintahVolume(volumeLow);
        Serial.println("Low Volume");
      }
      else if (data[z] > ThresholdLowVolume && data[z] < ThresholdMediumVolume ) {
        kirimperintahVolume(volumeMedium);
        Serial.println("Medium Volume");
      }

      else {
        kirimperintahVolume(volumeHigh);
        Serial.println("High Volume");
      }
      //************************************//

      //------------------------------------//
      // Memilih MP3 yang akan digunakan
      pilih++;
      if (pilih > 2) {
        pilih = 1;
      }
      //------------------------------------//

      ///////////////////////////////////////////////////
      // Memilih DF MP3 yang akan digunakan
      Serial.print("pilih : ");
      Serial.println(pilih);
      if (pilih == 1) {
        Serial.println("Command 1");
        sendMP3Command(z);
        delay(50);           // Waktu musik menyala

      }

      else if (pilih == 2) {
        Serial.println("Command 2");
        sendMP3Command2(z);
        delay(50);           // Waktu musik menyala

      }
      data[z] = 0;            // Normalisasi data pembacaan piezo eletric
      ///////////////////////////////////////////////////
    }
  }
}
