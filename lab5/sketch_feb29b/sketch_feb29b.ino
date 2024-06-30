#define F_CPU 16000000UL 
  
void timer_normal_inter(){
  TCCR1B |= (1 << WGM12);

  //Предделитель - 1024
  TCCR1B |= (1 << CS10)|(1 << CS12);

  //Частота прерываний
  //OCR1A = Частота_мк / (Предделитель * Частота)
  OCR1A = F_CPU / (1024 * 1);   //15625

  //Разрешить прерывание по совпадению A
  TIMSK1 |= (1 << OCIE1A);
}

void button() {
  
  DDRD &= ~(1 << PD2);
  PORTD |= (1 << PD2);

  EICRA |= (1 << ISC01); // Установка флага ISC01 для обработки на уровне сигнала
  EIMSK |= (1 << INT0); // Разрешение внешнего прерывания INT0
}

int main(void){

  Serial.begin(9600);
  //cli();
  timer_normal_inter(); //после инициализации на выводе OC0B (11) будет ШИМ сигнал 
  button();
  sei();

    while (1){

    }
}

ISR (TIMER1_COMPA_vect){
 
  Serial.println("I");
}

ISR(INT0_vect) {
  Serial.println("C");
}