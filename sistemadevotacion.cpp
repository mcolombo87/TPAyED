#include <iostream>

using namespace std;

int main()
{

    bool continuar = true;
    bool opcinvalida = false;

    while(continuar == true)
    {
        system("cls"); //Menu principal
        cout << "**VOTACION en Progreso**" << endl;
        cout <<"*********************************************"<<endl;
        cout <<"\n"<<endl;
        cout << "1. Apertura de Mesas" << endl;
        cout << "2. Apertura de Urnas" << endl;
        cout << "3. Registro de Votos"<< endl;
        cout << "4. Finalizar votacion"<< endl;
        cout << "\n" << endl;
        cout << "0. Salir" << endl;

        if (opcinvalida == true)
        {
            printf("Valor Incorrecto, vuelva a ingresar una opcion valida...\n");
            opcinvalida=false;
        }


        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1: /*funcion de Apertura de Mesas*/
            //ACA Va la llamada al modulo de apertura de mesas
            break;
        case 2: /*funcion de Apertura de Urnas*/
            //ACA Va la llamada al modulo de apertura de urnas
            break;
        case 3: /*Registrar voto*/
            //ACA Va la llamada al modulo de registrar votos
            break;
        case 4: /*Finaliza la votacion*/
            //ACA Va la llamada al modulo que finaliza la votacion
            break;
        case 0:
            return 0;
            break;
        default:
            opcinvalida=true ;
            break;

        }


    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
