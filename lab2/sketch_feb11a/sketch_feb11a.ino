int main()
{
  Serial.begin(9600);
  Serial.println("s");
  
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
      Serial.println("1");
    }
   if (!(PINB & (1<<PINB2)))
    {
      Serial.println("4");
    }
   if (!(PINB & (1<<PINB1)))
    {
      Serial.println("7");
    }
   if (!(PINB & (1<<PINB0)))
    {
      Serial.println("*");
    }
   
   PORTD |= (1<<DDD7);
   PORTD &= ~(1<<DDD6);
   
   if (!(PINB & (1<<PINB3)))
    {
      Serial.println("2");
    }
   if (!(PINB & (1<<PINB2)))
    {
      Serial.println("5");
    }
   if (!(PINB & (1<<PINB1)))
    {
      Serial.println("8");
    }
   if (!(PINB & (1<<PINB0)))
    {
      Serial.println("0");
    }
   
   PORTD |= (1<<DDD6);
   PORTD &= ~(1<<DDD5);
   
   if (!(PINB & (1<<PINB3)))
    {
      Serial.println("3");
    }
   if (!(PINB & (1<<PINB2)))
    {
      Serial.println("6");
    }
   if (!(PINB & (1<<PINB1)))
    {
      Serial.println("9");
    }
   if (!(PINB & (1<<PINB0)))
    {
      Serial.println("#");
    }
   
   PORTD |= (1<<DDD5);
   PORTD &= ~(1<<DDD4);
   
   if (!(PINB & (1<<PINB3)))
    {
      Serial.println("A");
    }
   if (!(PINB & (1<<PINB2)))
    {
      Serial.println("B");
    }
   if (!(PINB & (1<<PINB1)))
    {
      Serial.println("C");
    }
   if (!(PINB & (1<<PINB0)))
    {
      Serial.println("D");
    }
 }
}