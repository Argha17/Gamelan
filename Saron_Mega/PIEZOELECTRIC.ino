void initPiezoElectric() {
  for (int v = 0; v < 7; v++) {
    // Pin analog Mode
    pinMode(v, INPUT);
    delay(10);
  }

}
