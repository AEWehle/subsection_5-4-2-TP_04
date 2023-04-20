//=====[Libraries]=============================================================

// para ver si es bloqueante algo poner un breakpoint en donde se sospecha
//dar al run y si se queda sin avanzar en algun lado esperando, eso es bloqueante

// hay una funcion bloqeuante en
// /home/studio/workspace/subsection_5-4-2-tp_04/modules/pc_serial_com/pc_serial_com.cpp
// la funcion 
// static void pcSerialComStringRead( char* str, int strLength )
// es bloqueante ya que se queda esperando a que el ususario escriba
// cuando lee despues lo escribe
// la funcion se usa en 
//static void commandSetDateAndTime() para setear el año mes y dia
//
// la forma de solucionarlo es haciendo una maquina de estados cuando pide la fecha, 
// cada estado es el valor que esta pidiendo
// los archivos modificados son pc_serial_com.cpp y su .h con un enum de los estados de fecha
// agregamos el bool datecomplete
// pcSerialComUpdate tiene un if de si tiene que pedir mas datos de fecha
// commandSetDateAndTime() ahora tiene el switch de la maquina de estados
// pcSerialComStringRead ahora devuelve un int con la cantidad de digitos recibidos
// pcSerialComCommandUpdate la opcion s tiene el cambio de bool

// funcion bloqueante por delay en 
// /home/studio/workspace/subsection_5-4-2-tp_04/modules/smart_home_system/smart_home_system.cpp
// la funcion 
//void smartHomeSystemUpdate()
// llama un delay de 10ms, pero no seconsidera bloqueant ya que es muy chico
#include "smart_home_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    smartHomeSystemInit();
    while (true) {
        smartHomeSystemUpdate();
    }
}