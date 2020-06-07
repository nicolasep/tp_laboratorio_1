#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout,NULL);

	int flagCarga = 0;
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();


    do{
    	utn_getNumero(&option,"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
					          "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
					          "3. Alta de empleado\n"
					          "4. Modificar datos de empleado\n"
					          "5. Baja de empleado\n"
					          "6. Listar empleados\n"
					          "7. Ordenar empleados\n"
					          "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
					          "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
					          "10. Salir\n","OPCION INCORRECTA\n",1,10,2);

        switch(option)
        {
            case 1:
            	if(flagCarga)
            	{
            		printf("El archivo ya fue cargado\n");
            	}
            	else
            	{
            		if(!controller_loadFromText("data3.csv",listaEmpleados))
            		{
                	flagCarga = 1;
            		}
            		else
            		{
            			printf("El archivo no se pudo cargar\n");
            		}
            	}

                break;
            case 2:
            	if(flagCarga)
				{
					printf("El archivo ya fue cargado\n");
				}
				else
				{
					if(!controller_loadFromBinary("data2.bin",listaEmpleados))
					{
					flagCarga = 1;
					}
					else
					{
						printf("El archivo no se pudo cargar\n");
					}
				}

            	break;
            case 3:

            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	if(!ll_len(listaEmpleados))
				{
					printf("Primero debe ingresar al menos un empleado\n");
				}
            	else
            	{
            		controller_editEmployee(listaEmpleados);
            	}

            	break;
            case 5:
            	if(!ll_len(listaEmpleados))
				{
					printf("Primero debe ingresar al menos un empleado\n");
				}
				else
				{
					controller_removeEmployee(listaEmpleados);
				}

            	break;
            case 6:
            	if(!ll_len(listaEmpleados))
				{
					printf("Primero debe ingresar al menos un empleado\n");
				}
				else
				{
					controller_ListEmployee(listaEmpleados);
				}

            	break;
            case 7:
            	if(!ll_len(listaEmpleados))
				{
					printf("Primero debe ingresar al menos dos empleado\n");
				}
				else
				{
					controller_sortEmployee(listaEmpleados);
				}


            	break;
            case 8:
            	//guardar en modo texto probar
            	if(!ll_len(listaEmpleados))
				{
					printf("No hay empleados a guardar\n");
				}
				else
				{
					controller_saveAsText("data3.csv",listaEmpleados);
				}

            	break;
            case 9:
            	//guardar en modo binario probar
            	if(!ll_len(listaEmpleados))
				{
					printf("No hay empleados a guardar\n");
				}
				else
				{
					controller_saveAsBinary("data2.bin",listaEmpleados);
				}

            	break;
        }
    }while(option != 10);

    //system("pause");

    return 0;
}
