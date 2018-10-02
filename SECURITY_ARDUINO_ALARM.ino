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
boolean notificacion = false;
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
}
              
              void loop() { //LOOP***********************************************
                if(digitalRead(redSwitch)==LOW)
                  puertaCerrada=true;
                  else
                  puertaCerrada=false;
                if(puertaCerrada==false && alarmaON == false){
                  detachInterrupt(digitalPinToInterrupt(redSwitch));                 
                    detachInterrupt(digitalPinToInterrupt(boton));
                    cont2=0;
                    notificacion=false;
                    botonPress=false;
                    passwordUser="";  
                  }else if(puertaCerrada==true && alarmaON ==false){
                            detachInterrupt(digitalPinToInterrupt(redSwitch));
                            attachInterrupt(digitalPinToInterrupt(boton), activarTeclado, FALLING);                            
                            login();                            
                        }else if(puertaCerrada==true && alarmaON ==true && intruso==false){                           
                                  alarmaEncendida();
                                  attachInterrupt(digitalPinToInterrupt(boton), activarTeclado, FALLING);
                                  attachInterrupt(digitalPinToInterrupt(redSwitch), activarBandera, RISING);       
                                  login2();
                              }else if(intruso == true && alarmaON==true){
                                       detachInterrupt(digitalPinToInterrupt(redSwitch));          
                                       attachInterrupt(digitalPinToInterrupt(boton), activarTeclado, FALLING);                             
                                       sirena();
                                       login3();
                                    }else {
                                      intruso=true;             
                                    }
                
                
              
                if (counter != cont)
                {
                  counter = cont;                
                }               
              }
              
//METODDOS DE INTERRUPCIONES**********************************************************
void activarBandera() {
  if (millis() > timeCounter + timeThreshold)
  {
    cont++;
    if(puertaCerrada==false){
      intruso=true;
      }
     puertaCerrada=false;
    timeCounter = millis();
  }
}
void activarTeclado() {
  if (millis() > timeCounter + timeThreshold)
  {
     cont--;
    botonPress=true;
    timeCounter = millis();
  }
  
}
//METODOS DE SISTEMA************************************************************************
void login(){
  if(botonPress == true){
    notificarKeyboardON();
    callTeclado();
    debounceTeclado();
    verificarPassword();
  }
}
void login2(){
  if(botonPress == true){
    notificarKeyboardON();
    callTeclado();
    debounceTeclado();
    verificarPassword2();
  }
}
void login3(){
  if(botonPress == true){
    notificarKeyboardON();
    callTeclado();
    debounceTeclado();
    verificarPassword3();
  }
}

void verificarPassword3(){
  if(cont2==4){
      if(password==passwordUser){
          contrasenaExitosa();
          alarmaON=false;
          intruso=false;
          digitalWrite(ledRojo,LOW);
          digitalWrite(ledVerde,LOW);
          digitalWrite(bocina,LOW);
      }else{
          contrasenaErronea();
      }
    }
}
void verificarPassword2(){
  if(cont2==4){      
      if(password==passwordUser && puertaCerrada == true){
          contrasenaExitosa();
          alarmaON=false;
      }else{
          contrasenaErronea();
      }
    }
}

void verificarPassword(){
  if(cont2==4){      
      if(password==passwordUser && puertaCerrada == true){
          contrasenaExitosa();
          alarmaON=true;
      }else{
          contrasenaErronea();
      }
    }
}

void debounceTeclado(){
  if (counter2 != cont2)
  {
    counter2 = cont2;
  } 
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
      passwordUser += valor;
      valor = 0;
      cont2++;
      tecla();
      timeCounter2 = millis();
    }
  }
}
//METODOS DE NOTIFICACION************************************************
void contrasenaExitosa(){
    for(int i =0;i<=3;i++){
      digitalWrite(ledVerde,HIGH);
      digitalWrite(bocina,HIGH);
      delay(200);
      digitalWrite(ledVerde,LOW);
      digitalWrite(bocina,LOW);
      delay(200);
    }
    cont2=0;
    notificacion=false;
    botonPress=false;
    passwordUser="";
}
void contrasenaErronea(){  
      digitalWrite(ledRojo,HIGH);
      digitalWrite(bocina,HIGH);
      delay(1000); 
      digitalWrite(ledRojo,LOW);
      digitalWrite(bocina,LOW);    
    cont2=0;
    notificacion=false;
    botonPress=false;
    passwordUser="";
}

void notificarKeyboardON(){
  if(notificacion==false){
    digitalWrite(ledVerde,HIGH);
    digitalWrite(bocina,HIGH);
    delay(500);
    digitalWrite(ledVerde,LOW);
    digitalWrite(bocina,LOW);
    notificacion=true;
  }
}

void tecla(){
  digitalWrite(ledVerde,HIGH);
  digitalWrite(bocina,HIGH);
  delay(100);
  digitalWrite(ledVerde,LOW);
  digitalWrite(bocina,LOW);
}
void alarmaEncendida(){
  if(!botonPress){
  digitalWrite(ledVerde,HIGH);
  delay(100);
  digitalWrite(ledVerde,LOW);
  delay(1000);
  }
  
}

void sirena(){
 digitalWrite(ledRojo, HIGH);
 digitalWrite(ledVerde, HIGH);
 digitalWrite(bocina, HIGH);
}
