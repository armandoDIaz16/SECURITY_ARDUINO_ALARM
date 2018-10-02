//esta librería nos permite ahorrar energía******************************
#include "LowPower.h"
//COMPONENTES DIGITALES***************************************************
int redSwitch = 2;
int boton = 3;
int ledRojo = 13;
int ledVerde = 5;
int bocina = 4;
//VARIABLES DE PRUEBA*****************************************************
boolean encender;
int cont = 0;
long timeCounter = 0;
int timeThreshold = 200;
int counter = 0;
//VARIABLES DEL TECLADO***************************************************
int  renglon1 = 10;   //RENGLONES
int  renglon2 = 9;
int  renglon3 = 8;
int  renglon4 = 7;
//COLUMNAS
int  colum1 = A1;
int  colum2 = A2;
int  colum3 = A3;
int  colum4 = A4;
char  valores []   =  {'1', '2', '3', 'A'}; //MATRIZ
char  valores2 []   = {'4', '5', '6', 'B'};
char  valores3 []   = {'7', '8', '9', 'C'};
char  valores4 []   = {'*', '0', '#', 'D'};
//VARIABLES DE CONTROL*******************************************************
boolean puertaCerrada;
boolean alarmaON;
boolean tecladoON;
String password = "1234";
String passwordUser = "";
char valor;
boolean bajoConsumo;
boolean botonPress;
boolean passwordCorrect = false;
int contPassword = 0;
int cont2 = 0;
long timeCounter2 = 0;
int timeThreshold2 = 200;
int counter2 = 0;
boolean intruso;
void setup() {
  //CONFIGURACION DEL TECLADO************************************************
  //declaraciones del teclado
  pinMode(renglon1, OUTPUT);
  pinMode(renglon2, OUTPUT);
  pinMode(renglon3, OUTPUT);
  pinMode(renglon4, OUTPUT);

  pinMode(colum1, INPUT_PULLUP);
  pinMode(colum2, INPUT_PULLUP);
  pinMode(colum3, INPUT_PULLUP);
  pinMode(colum4, INPUT_PULLUP);

  digitalWrite(renglon1, HIGH);
  digitalWrite(renglon2, HIGH);
  digitalWrite(renglon3, HIGH);
  digitalWrite(renglon4, HIGH);
  //COMPONENTES DIGITALES***************************************************
  pinMode(redSwitch, INPUT);
  pinMode(boton, INPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(bocina, OUTPUT);
  //VARIABLES DE CONTROL*****************************************************
  alarmaON = false;
  tecladoON = false;
  bajoConsumo = false;
  botonPress=false;
  intruso = false;
  //VARIABLES DE PRUEBA*****************************************************
  encender = false;
  //LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  //attachInterrupt(digitalPinToInterrupt(boton), activarTeclado, FALLING);
  //attachInterrupt(digitalPinToInterrupt(redSwitch), activarBandera, RISING);
  Serial.begin(9600);
}
              
              void loop() { //LOOP***********************************************
                if(digitalRead(redSwitch)==LOW)
                  puertaCerrada=true;
                  else
                  puertaCerrada=false;

                if(puertaCerrada==false && alarmaON == false){
                    Serial.println("la puerta esta abierta y la alarma desactivada");
                    delay(1000);
//                  tecladoON = false;
//                  detachInterrupt(boton);
//                  detachInterrupt(redSwitch);
                  }else if(puertaCerrada==true && alarmaON ==false){
                            Serial.println("la puerta esta cerrada y la alarma desactivada");
                            delay(1000);
                        }else if(puertaCerrada==true && alarmaON ==true){
                                //attachInterrupt(digitalPinToInterrupt(boton), activarTeclado, FALLING);
                                //attachInterrupt(digitalPinToInterrupt(redSwitch), activarBandera, RISING);
                               // login2();
                              }else if(intruso == true){
                                      //attachInterrupt(digitalPinToInterrupt(boton), activarTeclado, FALLING);
//                                       digitalWrite(ledRojo, HIGH);
//                                       digitalWrite(ledVerde, HIGH);
//                                       digitalWrite(bocina, HIGH);
                                          //login2();
                                    }
                
                if (encender == true) {
                  digitalWrite(ledRojo, HIGH);
                  digitalWrite(ledVerde, HIGH);
                  digitalWrite(bocina, HIGH);
                } else if (passwordCorrect == true) {
                  digitalWrite(ledRojo, LOW);
                  digitalWrite(ledVerde, LOW);
                  digitalWrite(bocina, LOW);
                }
              
                if (counter != cont)
                {
                  counter = cont;
                  // Serial.println(counter);
                  Serial.flush();
                }
              
                if (tecladoON == true)
                {
                  callTeclado();
              
                  if (counter2 != cont2)
                  {
                    counter2 = cont2;
                    Serial.println(counter2);
                    Serial.flush();
                  }
                  if (cont2 == 4)
                  {
                    Serial.println(passwordUser);
                    if (passwordUser == password)
                      passwordCorrect = true;
                  }
                }
              }
              
//METODDOS DE INTERRUPCIONES**********************************************************
void activarBandera() {
  if (millis() > timeCounter + timeThreshold)
  {
    cont++;
    encender = true;
    timeCounter = millis();
    //detachInterrupt(boton);
  }
}
void activarTeclado() {
  if (millis() > timeCounter + timeThreshold)
  {
    cont--;
    encender = false;
    tecladoON = true;
    timeCounter = millis();
  }
  //METODOS DE SISTEMA************************************************************************
}
void callTeclado() {
  teclado(renglon1, valores, valor);
  teclado(renglon2, valores2, valor);
  teclado(renglon3, valores3, valor);
  teclado(renglon4, valores4, valor);
}

//metodo que ayuda a leer cada parte del teclado
void teclado(int renglon, char valores [], char valor) {

  digitalWrite(renglon, LOW);

  if (digitalRead(colum1) == LOW)
    valor = valores[0];
  else if (digitalRead(colum2) == LOW)
    valor = valores[1];
  else if (digitalRead(colum3) == LOW)
    valor = valores[2];
  else if (digitalRead(colum4) == LOW)
    valor = valores[3];

  digitalWrite(renglon, HIGH);
  if (millis() > timeCounter2 + timeThreshold2)
  {
    if (valor != 0) {
      //  delay(500);
      //    teclaledRojo();
      passwordUser += valor;
      valor = 0;
      cont2++;
      timeCounter2 = millis();
      //delay(500);

    }
  }
}
