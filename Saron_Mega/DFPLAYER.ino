
void initMP3() {
  Serial1.begin(9600);
  delay(500);

  // Uji semua musik
  for (int k = 1; k <= 7; k++) {
    kirimperintah(Play_song_in_folder, 0x01, k);
    delay(1000);
  }

  Serial2.begin(9600);
  delay(500);

  // Uji semua musik
  for (int k = 1; k <= 7; k++) {
    kirimperintah2(Play_song_in_folder, 0x01, k);
    delay(1000);
  }

  kirimperintahVolume(volumeLow);

}

void sendMP3Command(int c) {
  switch (c) {

    case 0:       // Mainkan lagu 1
      Serial.println("Masuk ke file 1");
      kirimperintah(Play_song_in_folder, 0x01, 0x01);
      break;

    case 1:       // Mainkan lagu 2
      Serial.println("Masuk ke file 2");
      kirimperintah(Play_song_in_folder, 0x01, 0x02);
      break;

    case 2:       // Mainkan lagu 3
      Serial.println("Masuk ke file 3");
      kirimperintah(Play_song_in_folder, 0x01, 0x03);
      break;

    case 3:       // Mainkan lagu 4
      Serial.println("Masuk ke file 4");
      kirimperintah(Play_song_in_folder, 0x01, 0x04);
      break;

    case 4:       // Mainkan lagu 5
      Serial.println("Masuk ke file 5");
      kirimperintah(Play_song_in_folder, 0x01, 0x05);
      break;

    case 5:       // Mainkan lagu 6
      Serial.println("Masuk ke file 6");
      kirimperintah(Play_song_in_folder, 0x01, 0x06);
      break;

    case 6:       // Mainkan lagu 7
      Serial.println("Masuk ke file 7");
      kirimperintah(Play_song_in_folder, 0x01, 0x07);
      break;

    case 'n':       // Next
      Serial.println("Next music");
      kirimperintah(Next, 0x00, 0x00);
      break;

    case 'p':       // Previous
      Serial.println("Previous music");
      kirimperintah(Previous, 0x00, 0x00);
      break;

    case 'P':       // Play
      Serial.println("Play music");
      kirimperintah(Play, 0x00, 0x00);
      break;

    case 'u':       // Volume up
      Serial.println("Volume up  music");
      kirimperintah(Volume_up, 0x00, 0x00);
      break;

    case 'd':       // Valome down
      Serial.println("Volume down music");
      kirimperintah(Volume_down, 0x00, 0x00);
      break;

    case 's':         // Volume setting
      Serial.println("Volume Setting music");
      kirimperintah(Volume_set, 0x00, 0x1e);
      break;

    case 'r':         // Reset music
      Serial.println("Reset settingan");
      kirimperintah(Reset, 0x00, 0x00);
      break;

    case 'l':         // Play music
      Serial.println("Paly music");
      kirimperintah(Play, 0x00, 0x00);
      break;

    case 'e':         // Pause music
      Serial.println("Pause music");
      kirimperintah(Pause, 0x00, 0x00);
      break;

  }
}

void sendMP3Command2(int c) {
  switch (c) {

    case 0:       // Mainkan lagu 1
      Serial.println("Masuk ke file 1");
      kirimperintah2(Play_song_in_folder, 0x01, 0x01);
      break;

    case 1:       // Mainkan lagu 2
      Serial.println("Masuk ke file 2");
      kirimperintah2(Play_song_in_folder, 0x01, 0x02);
      break;

    case 2:       // Mainkan lagu 3
      Serial.println("Masuk ke file 3");
      kirimperintah2(Play_song_in_folder, 0x01, 0x03);
      break;

    case 3:       // Mainkan lagu 4
      Serial.println("Masuk ke file 4");
      kirimperintah2(Play_song_in_folder, 0x01, 0x04);
      break;

    case 4:       // Mainkan lagu 5
      Serial.println("Masuk ke file 5");
      kirimperintah2(Play_song_in_folder, 0x01, 0x05);
      break;

    case 5:       // Mainkan lagu 6
      Serial.println("Masuk ke file 6");
      kirimperintah2(Play_song_in_folder, 0x01, 0x06);
      break;

    case 6:       // Mainkan lagu 7
      Serial.println("Masuk ke file 7");
      kirimperintah2(Play_song_in_folder, 0x01, 0x07);
      break;

    case 'n':       // Next
      Serial.println("Next music");
      kirimperintah2(Next, 0x00, 0x00);
      break;

    case 'p':       // Previous
      Serial.println("Previous music");
      kirimperintah2(Previous, 0x00, 0x00);
      break;

    case 'P':       // Play
      Serial.println("Play music");
      kirimperintah2(Play, 0x00, 0x00);
      break;

    case 'u':       // Volume up
      Serial.println("Volume up  music");
      kirimperintah2(Volume_up, 0x00, 0x00);
      break;

    case 'd':       // Valome down
      Serial.println("Volume down music");
      kirimperintah2(Volume_down, 0x00, 0x00);
      break;

    case 's':         // Volume setting
      Serial.println("Volume Setting music");
      kirimperintah2(Volume_set, 0x00, 0x1e);
      break;

    case 'r':         // Reset music
      Serial.println("Reset settingan");
      kirimperintah2(Reset, 0x00, 0x00);
      break;

    case 'l':         // Play music
      Serial.println("Paly music");
      kirimperintah2(Play, 0x00, 0x00);
      break;

    case 'e':         // Pause music
      Serial.println("Pause music");
      kirimperintah2(Pause, 0x00, 0x00);
      break;

  }
}


void kirimperintah(int8_t command, int8_t dat1, int8_t dat2)
{
  delay(20);
  buff_send[0] = 0x7e;
  buff_send[1] = 0xff;
  buff_send[2] = 0x06;
  buff_send[3] = 0x0f;
  buff_send[4] = 0x00;   // 0x00 NO, 0x01 feedback
  buff_send[5] = (int8_t)(dat1);
  buff_send[6] = (int8_t)(dat2);
  buff_send[7] = 0xef;

  for (uint8_t i = 0 ; i < 8; i++)
  {
    Serial1.write(buff_send[i]) ;
  }
  Serial.println("Musik MP3 1 menyala ");
  //  Serial.println();
}


void kirimperintah2(int8_t command, int8_t dat1, int8_t dat2)
{
  delay(20);
  buff_send2[0] = 0x7e;
  buff_send2[1] = 0xff;
  buff_send2[2] = 0x06;
  buff_send2[3] = 0x0f;
  buff_send2[4] = 0x00;   // 0x00 NO, 0x01 feedback
  buff_send2[5] = (int8_t)(dat1);
  buff_send2[6] = (int8_t)(dat2);
  buff_send2[7] = 0xef;

  for (uint8_t i = 0 ; i < 8; i++)
  {
    Serial2.write(buff_send2[i]) ;
  }
  Serial.println("Musik MP3 2 menyala ");
  //  Serial.println();
}


void kirimperintahVolume(int8_t volumeLevel)
{
  // 7E FF 06 06 00 00 1E EF
  delay(20);
  buff_send_volume[0] = 0x7e;
  buff_send_volume[1] = 0xff;
  buff_send_volume[2] = 0x06;
  buff_send_volume[3] = Volume_set;
  buff_send_volume[4] = 0x00;   // 0x00 NO, 0x01 feedback
  buff_send_volume[5] = 0x00;
  buff_send_volume[6] = (int8_t)(volumeLevel);
  buff_send_volume[7] = 0xef;

  for (uint8_t i = 0 ; i < 8; i++)
  {
    Serial1.write(buff_send_volume[i]) ;
    Serial2.write(buff_send_volume[i]) ;
  }
  Serial.println();
}
