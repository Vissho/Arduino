int main ()
{
  int flag = 0;
  DDRB |= (1<<DDB1);
  DDRB |= (1<<DDB0);
  while (1) 
  {
    if (PINB & (1<<PINB0))
    {
      flag++;
      flag %= 2;
      PINB &= ~ (1<<PINB0);
    }
    if (flag == 0) {
      PORTB |= (1<<PORTB1);
    } else if (flag == 1) {
      PORTB &= ~ (1<<PORTB1);
    }
    // else if (flag == 2) {
    //   PORTB |= (1<<PORTB1);
	  //   _delay_ms(1000);
	  //   PORTB &= ~ (1<<PORTB1);
	  //   _delay_ms(1000);
    // }
  }
}