#include <16F887.h>
#device ADC=10
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#use RS232(BAUD=9600,BITS=8,STOP=1,PARITY=N,xmit=PIN_C6,rcv=PIN_C7)
#define BTN_PIN PIN_B0
#define RELAY_PIN PIN_D0

void main()
{
   set_tris_b(0b11111111);
   set_tris_d(0b10011111);
   set_tris_e(0b001);
   output_low(RELAY_PIN);

   int relay_state = 0;
   
   while (true)
   {
      if (input(BTN_PIN) == 0)
      {
         delay_ms(50);
         output_toggle(RELAY_PIN);
         relay_state = input(RELAY_PIN);
         if (relay_state == 1)
         {
            printf("Relay is ON\r\n");
         }
         else
         {
            printf("Relay is OFF\r\n");
         }

         while (input(BTN_PIN) == 0);
         delay_ms(50);
      }
   }
}
