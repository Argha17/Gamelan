
static int8_t buff_send[8] = {}; //buffer untuk pengiriman perintah
static int8_t buff_send2[8] = {}; //buffer untuk pengiriman perintah
static int8_t buff_send_volume[8] = {}; //buffer untuk pengiriman perintah

/************ Command byte **************************/
#define Next                  0X01
#define Previous              0X02
#define Volume_up             0X04
#define Volume_down           0X05
#define Volume_set            0X06


#define Reset                 0X0C
#define Play                  0X0D
#define Pause                 0X0E
#define Play_song_in_folder   0X0F


int data[7];
#define minimumThresholdSignal 30
#define volumeLow 0X0A              // Volume 10
#define volumeMedium 0X14           // Volume 20
#define volumeHigh 0X1E             // Volume 30
#define ThresholdLowVolume 50          // Batas Volume Low
#define ThresholdMediumVolume 100      // Batas Volume Medium
#define ThresholdHighVolume  150       // Batas Volume  High

// 30-900
