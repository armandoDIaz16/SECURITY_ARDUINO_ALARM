SISTEMA DE ALARMA DE SEGURIDAD 
==============================

### IMAGEN REAL
![real2](https://user-images.githubusercontent.com/43178846/46343675-2ce25780-c604-11e8-8f48-04687a7829ca.jpeg)

![real](https://user-images.githubusercontent.com/43178846/46343686-34096580-c604-11e8-9c25-71cdadaa2e1c.jpeg)

## DESCRIPCIÓN
==============================

==============================


Este es un sistema de alarma de seguridad, que funciona a base de tecnología electromagnetica, que nos brinda seguridad en el hogar, en la empresa o en cualquier habitación que deseemos resguardar, puede colocarse en puertas de cualquier tipo e incluso ventanas, solo se necesita instalar un solo controlador  y la seguridad puede ampliarse por todos los accesos del lugar.

> ## Diagrama de protoboard

![captura de pantalla de 2018-09-26 15-09-09](https://user-images.githubusercontent.com/43178846/46112883-cdbeb600-c1b1-11e8-82af-de3ba27fbf9d.png)


## CARACTERISTICAS 
> ### Programa
        - arduino IDE

> ### Materiales 
        - teclado matricial
        - buzzer
        - redswitch
        - jumpers
        - led
        - placa arduino UNO
        - resistores 330 Ohms y 1K Ohms
        -cable USB a micro USB


## INSTALACIÓN E INSTRUCCIONES DE USO

    1- Para que se pueda activar la alarma debe estar la puerta cerrada si la puertano está cerrada
    el sistema tendra entendido que no desea activar la alarma.
    
    2- Si usted cierra la puerta y presiona el botón significa que desea activar la alarma, si no
    presiona el botón aunque este cerrada la puerta el sistema entenderá que no desea activar la 
    alarma solo quiere tener la puerta cerrada.
    
	3- Si cierra la puerta y presiona la alarma el sistema activará el teclado para que usted teclee 
    su password pero si falla le notificará de su error con un led rojo y tendrá que presionar un 
    vez más el botón para vovlerlo a intentar, si acierta le notificará con un led verde y se 
    activará la alarma.
    
	4- Si la alarma esta activada pero nunca es interrumpido su hogar el sistema hará el mismo 
    proceso para desactivar la seguridad, activará el teclado con el botón para que usted ingrese 
    su password si falla lo pedirá de nuevo.
    
	5- si su hogar es interrumpido el sistema activará una sirena con la bocina y los leds 
    está solo se podrá desactivar presionando el botón e ingresando el password correcto de lo contrario 
    seguirá sonando.


## EXTRAS 
> ### Bibliotecas 
-LowPowerMaster

> ### Diagramas 
- Teclado matricial

![teclado_matricial_4x4_conexiones](https://user-images.githubusercontent.com/43178846/46113427-efb93800-c1b3-11e8-8c5d-08d20dafbcfb.png)
- Arduino UNO Diagram
 
![arduino](https://user-images.githubusercontent.com/43178846/46113664-ee3c3f80-c1b4-11e8-9f07-9cddca570c8e.jpg)
PREGUNTAS
=========

Enviame un correo [15240501@itleon.edu.mx]

## LICENCIA 
		Copyright (c) <2018> <José Armando Diaz Anguiano>.

		Redistribution and use in source and binary forms, with or without
		modification, are permitted provided that the following conditions are met:

		* Redistributions of source code must retain the above copyright notice, this 
		  list of conditions and the following disclaimer.

		* Redistributions in binary form must reproduce the above copyright notice, this
	 	  list of conditions and the following disclaimer in the documentation and/or other
		  materials provided with the distribution.

		* Neither the name of the copyright holder nor the names of its contributors may be
	          used to endorse or promote products derived from  this software without specific 
	          prior written permission.

		THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
		AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
		IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
		ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
		LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
		CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
		SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
		INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
		CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
		ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
		POSSIBILITY OF SUCH DAMAGE.

