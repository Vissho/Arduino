#define F_CPU 16000000UL

void timer_n()
{
  TCNT1 = 50536;
  TCCR1B |= (1 << CS10) | (1 << CS12);
}

void timer_ctc()
{
  //TCCR1A |= (1 << COM1A1);
  TCCR1B |= (1 << WGM12); // Режим 4: Clear Timer On Compare (Сброс по совпадению)

  //TCCR1B |= (1 << CS11);              //8
  //Предделитель - 1024
  TCCR1B |= (1 << CS10)|(1 << CS12);

  //Частота прерываний
  OCR1A = 49000;   //15625
  TCNT1 = 0;

}

int main()
{
  Serial.begin(9600);

  //timer_n();
  timer_ctc();
  //sei();

  while(1)
  {
    //if((TIFR1 & (1 << TOV1)) == 1)
     //{
      // Serial.println("I");
      // TIFR1 |= (1 << TOV1);
    //   TCNT1 = 50536;
    // }

    if((TIFR1 & (1 << OCF1A))){

      Serial.println("C");
      TIFR1 |= (1 << OCF1A);
      TCNT1 = 0;
    }
  }
}