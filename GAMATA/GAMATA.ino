#define IN1  13   // Pines para M1
#define IN2  12   // Pines para M1
#define IN3  11   // Pines para M1
#define IN4  10   // Pines para M1
#define ON1 9     // Pines para M2
#define ON2 8     // Pines para M2
#define ON3 7     // Pines para M2
#define ON4 6     // Pines para M2

String comando;

// Variables necesarias para el motor.
int steps_left = 4095;
boolean Direction = true;
boolean Direction2 = true;
int Steps = 0;
int Steps2 = 0;
int a = 0;
int Paso [ 8 ][ 4 ] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};






void setup() {
  // Setup necesario para los motores
  Serial.begin(9600);
  comando.reserve(200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ON1, OUTPUT);
  pinMode(ON2, OUTPUT);
  pinMode(ON3, OUTPUT);
  pinMode(ON4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (comando.equals("subir")) {
    Direction = false;
    Direction2 = true;
    motores();
  }

  if (comando.equals("bajar")) {
  Direction = true;
  Direction2 = false;
  motores();
  }
}
/* Inicia el codigo para el motor

*/
void motores() {
  for (int a = 0; a < 4; a++) {
    while (steps_left > 0) {
      stepper();    // Avanza un paso
      stepper2();
      steps_left-- ;  // Un paso menos
      delay (1) ;
    }
    steps_left = 4095;
  }
  delay(2000);
}

void stepper() {
  digitalWrite( IN1, Paso[Steps][ 0] );
  digitalWrite( IN2, Paso[Steps][ 1] );
  digitalWrite( IN3, Paso[Steps][ 2] );
  digitalWrite( IN4, Paso[Steps][ 3] );
  SetDirection();
}

void stepper2() {
  digitalWrite( ON1, Paso[Steps2][ 0] );
  digitalWrite( ON2, Paso[Steps2][ 1] );
  digitalWrite( ON3, Paso[Steps2][ 2] );
  digitalWrite( ON4, Paso[Steps2][ 3] );
  SetDirection2();
}

void SetDirection() {
  if (Direction)
    Steps++;
  else
    Steps--;
  Steps = ( Steps + 7 ) % 7 ;
}

void SetDirection2() {
  if (Direction2)
    Steps2++;
  else
    Steps2--;
  Steps2 = ( Steps2 + 7 ) % 7 ;
}

/*
   Terminan los codigos para los motores
*/
