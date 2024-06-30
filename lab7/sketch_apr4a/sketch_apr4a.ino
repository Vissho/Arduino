void timer() {
  DDRB |= (1 << PB1);
  TCCR1A |= (1 << WGM10) | (1 << WGM11);
  TCCR1B |= (1 << WGM12);
  
  TCCR1B |= (1 << CS10);
  
  TCCR1A |= (1 << COM1A1);
  
  OCR1A |= 128;
}

int main(void)
{
  timer();
   while(1)
   {
      for (int brightness = 0; brightness <= 1023; brightness++) {
        OCR1A &= 0;
        OCR1A |= brightness;
        _delay_ms(4);
      }
  

      for (int brightness = 1023; brightness >= 0; brightness--) {
        OCR1A &= 0;
        OCR1A |= brightness;
        _delay_ms(4);
      }
    }
}
