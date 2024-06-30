#define F_CPU 16000000UL

constexpr uint16_t freq[4][4] = {
    {261, 277, 293, 311},
    {329, 349, 369, 392},
    {415, 440, 466, 493},
    {523, 554, 587, 622}
};

char c1[16] = {
  	0b00001100, // = 0
    0b00001000, // = 1
    0b00001100, // = 2
    0b00001100, // = 3
    0b00001000, // = 4
    0b00000100, // = 5
    0b00000100, // = 6
    0b00001100, // = 7
    0b00001100, // = 8
    0b00001100, // = 9
    0b00001100, // = A
    0b00000000, // = B
    0b00000100, // = C
    0b00001000, // = D
    0b00000100, // = E
    0b00000100  // = F
};

char c2[16] = {
  	0b00111100, // = 0
    0b00100000, // = 1
    0b00011010, // = 2
    0b00110010, // = 3
    0b00100110, // = 4
    0b00110110, // = 5
    0b00111110, // = 6
    0b00100000, // = 7
    0b00111110, // = 8
    0b00110110, // = 9
    0b00101110, // = A
    0b00111110, // = B
    0b00011100, // = C
    0b00111010, // = D
    0b00011110, // = E
    0b00001110  // = F
};

void delay_us(uint16_t us) { while (us--) _delay_us(1); }

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

int time = 0;

void timer(){
  TCCR1B |= (1 << WGM12);

  TCCR1B |= (1 << CS10)|(1 << CS12);

  OCR1A = F_CPU / (1024 * 1);

  TIMSK1 |= (1 << OCIE1A);
}

ISR (TIMER1_COMPA_vect){
  time--;
}

void indicator()
{
 while(time)
 {
   PORTD &= ~(1 << PD2);
   PORTD &= ~(1 << PD3);
   PORTC &= ~(1 << PC0);
   PORTC &= ~(1 << PC1);
   PORTC &= ~(1 << PC2);
   PORTC &= ~(1 << PC3);
   PORTC &= ~(1 << PC4);
   PORTC &= ~(1 << PC5);
   
   PORTD |= (c1[time]);
   PORTC |= (c2[time]);
   
   _delay_ms(100);
 }
  PORTD &= ~(1 << PD2);
   PORTD &= ~(1 << PD3);
   PORTC &= ~(1 << PC0);
   PORTC &= ~(1 << PC1);
   PORTC &= ~(1 << PC2);
   PORTC &= ~(1 << PC3);
   PORTC &= ~(1 << PC4);
   PORTC &= ~(1 << PC5);
   
   PORTD |= (c1[0]);
   PORTC |= (c2[0]);
   
   _delay_ms(100);
}

void keyboard()
{
  timer();
  sei();
  
  DDRD |= (1 << PD2);
  DDRD |= (1 << PD3);
  
  DDRC |= (1 << PC0);
  DDRC |= (1 << PC1);
  DDRC |= (1 << PC2);
  DDRC |= (1 << PC3);
  DDRC |= (1 << PC4);
  DDRC |= (1 << PC5);
  
  DDRB |= (1 << PB4);
  PORTB |= (1 << PB4);
  
  PORTB |= (1<<PORTB0);
  PORTB |= (1<<PORTB1);
  PORTB |= (1<<PORTB2);
  PORTB |= (1<<PORTB3);
  
  DDRD |= (1<<DDD4);
  DDRD |= (1<<DDD5);
  DDRD |= (1<<DDD6);
  DDRD |= (1<<DDD7);
  
  PORTD &= ~(1 << PD2);
   PORTD &= ~(1 << PD3);
   PORTC &= ~(1 << PC0);
   PORTC &= ~(1 << PC1);
   PORTC &= ~(1 << PC2);
   PORTC &= ~(1 << PC3);
   PORTC &= ~(1 << PC4);
   PORTC &= ~(1 << PC5);
   
   PORTD |= (c1[0]);
   PORTC |= (c2[0]);
   
   _delay_ms(100);
 while (1)
 {
   PORTD &= ~(1<<DDD7);
   PORTD |= (1<<DDD6);
   PORTD |= (1<<DDD5);
   PORTD |= (1<<DDD4);

   if (!(PINB & (1<<PINB3)))
    {
     time = 1;
     indicator();
     _delay_ms(5);
      mytone(freq[0][0]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB2)))
    {
     time = 5;
     indicator();
     _delay_ms(5);
      mytone(freq[1][0]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB1)))
    {
     time = 9;
     indicator();
     _delay_ms(5);
      mytone(freq[2][0]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB0)))
    {
     time = 13;
     indicator();
     _delay_ms(5);
     mytone(freq[3][0]);
      _delay_ms(10);
    }
   
   PORTD |= (1<<DDD7);
   PORTD &= ~(1<<DDD6);
   
   if (!(PINB & (1<<PINB3)))
    {
     time = 2;
     indicator();
     _delay_ms(5);
      mytone(freq[0][1]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB2)))
    {
     time = 6;
     indicator();
     _delay_ms(5);
      mytone(freq[1][1]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB1)))
    {
     time = 10;
     indicator();
     _delay_ms(5);
      mytone(freq[2][1]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB0)))
    {
     time = 14;
     indicator();
     _delay_ms(5);
      mytone(freq[3][1]);
      _delay_ms(10);
    }
   
   PORTD |= (1<<DDD6);
   PORTD &= ~(1<<DDD5);
   
   if (!(PINB & (1<<PINB3)))
    {
     time = 3;
     indicator();
     _delay_ms(5);
      mytone(freq[0][2]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB2)))
    {
     time = 7;
     indicator();
     _delay_ms(5);
     mytone(freq[1][2]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB1)))
    {
     time = 11;
     indicator();
     _delay_ms(5);
      mytone(freq[2][2]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB0)))
    {
     time = 15;
     indicator();
     _delay_ms(5);
      mytone(freq[3][2]);
      _delay_ms(10);
    }
   
   PORTD |= (1<<DDD5);
   PORTD &= ~(1<<DDD4);
   
   if (!(PINB & (1<<PINB3)))
    {
     time = 4;
     indicator();
     _delay_ms(5);
      mytone(freq[0][3]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB2)))
    {
      Serial.print("B ");
     time = 8;
     indicator();
     _delay_ms(5);
      mytone(freq[1][3]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB1)))
    {
      Serial.print("C ");
     time = 12;
     indicator();
     _delay_ms(5);
      mytone(freq[2][3]);
      _delay_ms(10);
    }
   if (!(PINB & (1<<PINB0)))
    {
     time = 15;
     indicator();
     _delay_ms(5);
      mytone(freq[3][3]);
      _delay_ms(10);
    }
 } 
}

int main()
{
  keyboard();
}
