#define F_CPU 16000000UL

constexpr uint16_t freq[4][4] = {
    {261, 277, 293, 311},
    {329, 349, 369, 392},
    {415, 440, 466, 493},
    {523, 554, 587, 622}
};

void delay_us(uint16_t us) { while (us--) _delay_us(1); }

void t(uint16_t frequency)
{

  PORTB |= (1 << PB4);
    delay(1 / (2 * frequency));
    PORTB &= ~(1 << PB4);
    delay(1 / (2 * frequency));
}

void mytone(uint16_t frequency)
{
  uint16_t period = (F_CPU / 6) / frequency;
  uint16_t half_period = period / 2;
  for (int i = 0; i < 10; i++) {
    PORTB |= (1 << PB4);
    delay_us(half_period);
    PORTB &= ~(1 << PB4);
    delay_us(half_period);
  }
}

void keyboard()
{
  Serial.begin(9600);
  Serial.print("s");
  
  PORTB |= (1<<PORTB0);
  PORTB |= (1<<PORTB1);
  PORTB |= (1<<PORTB2);
  PORTB |= (1<<PORTB3);
  
  DDRD |= (1<<DDD4);
  DDRD |= (1<<DDD5);
  DDRD |= (1<<DDD6);
  DDRD |= (1<<DDD7);
 while (1)
 {
   PORTD &= ~(1<<DDD7);
   PORTD |= (1<<DDD6);
   PORTD |= (1<<DDD5);
   PORTD |= (1<<DDD4);

   //Serial.println("-");
   if (!(PINB & (1<<PINB3)))
    {
     _delay_ms(5);
      mytone(freq[0][0]);
      _delay_ms(10);
      Serial.print("1");
    }
   if (!(PINB & (1<<PINB2)))
    {
     _delay_ms(5);
      mytone(freq[1][0]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB1)))
    {
     _delay_ms(5);
      mytone(freq[2][0]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB0)))
    {
     _delay_ms(5);
     mytone(freq[3][0]);
      _delay_ms(10);
    }
   
   PORTD |= (1<<DDD7);
   PORTD &= ~(1<<DDD6);
   
   if (!(PINB & (1<<PINB3)))
    {
     _delay_ms(5);
      mytone(freq[0][1]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB2)))
    {
     _delay_ms(5);
      mytone(freq[1][1]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB1)))
    {
     _delay_ms(5);
      mytone(freq[2][1]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB0)))
    {
     _delay_ms(5);
      mytone(freq[3][1]);
      _delay_ms(10);
    }
   
   PORTD |= (1<<DDD6);
   PORTD &= ~(1<<DDD5);
   
   if (!(PINB & (1<<PINB3)))
    {
     _delay_ms(5);
      mytone(freq[0][2]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB2)))
    {
     _delay_ms(5);
     mytone(freq[1][2]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB1)))
    {
     _delay_ms(5);
      mytone(freq[2][2]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB0)))
    {
     _delay_ms(5);
      mytone(freq[3][2]);
      _delay_ms(10);
    }
   
   PORTD |= (1<<DDD5);
   PORTD &= ~(1<<DDD4);
   
   if (!(PINB & (1<<PINB3)))
    {
     _delay_ms(5);
      mytone(freq[0][3]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB2)))
    {
     _delay_ms(5);
      mytone(freq[1][3]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB1)))
    {
     _delay_ms(5);
      mytone(freq[2][3]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB0)))
    {
     _delay_ms(5);
      mytone(freq[3][3]);
      _delay_ms(10);
    }
 } 
}

int state = 0;

void music()
{
  _delay_ms(5);
   mytone(440);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(165);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(440);
  _delay_ms(25);
  
  _delay_ms(30);
  
  _delay_ms(5);
   mytone(440);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(165);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(440);
  _delay_ms(25);
  
  _delay_ms(30);

  _delay_ms(5);
  mytone(330);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(294);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(262);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(494); 
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(440);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(494);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(262);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(294);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(330);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(165);
  _delay_ms(25);
  
  _delay_ms(5);
  mytone(440);
  _delay_ms(25);
  Serial.print("m");

}

int main()
{
  Serial.begin(9600);

  DDRB |= (1<<PB4);
  //keyboard();
  //while(1)music();
}
