#include <VirtualWire.h>

const int led_pin = 13;
const int transmit_pin = 12;
// const int transmit_en_pin = 3;

void setup()
{
  Serial.begin(9600);           // start serial for output
  // Initialise the IO and ISR
  vw_set_tx_pin(transmit_pin);
  // vw_set_ptt_pin(transmit_en_pin);
  // vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);	 // Bits per sec
  pinMode(led_pin, OUTPUT);
}

byte count = 1;

void loop()
{
  char msg[5] = {117, 'h','e', 232};
  Serial.println("transmitting");
  msg[4] = count;
  digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, 7);
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(led_pin, LOW);
  delay(200);
  count = count + 1;
}