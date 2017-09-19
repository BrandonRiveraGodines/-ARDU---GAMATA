#define IN1  13   // Pines para M1
#define IN2  12   // Pines para M1
#define IN3  11   // Pines para M1
#define IN4  10   // Pines para M1
#define ON1 9     // Pines para M2
#define ON2 8     // Pines para M2
#define ON3 7     // Pines para M2
#define ON4 6     // Pines para M2

// Variables necesarias para el motor.
int steps_left=4095;
boolean Direction = true;
boolean Direction2 = true;
int Steps = 0;
int Steps2 = 0;
int a = 0;
int Paso [ 8 ][ 4 ] ={   
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

}
