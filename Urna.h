#ifndef URNA_H_INCLUDED
#define URNA_H_INCLUDED


#ifndef NULL
#define NULL      0
#endif

typedef struct{
        int id;
        char horaApertura[5];
        char horaCierre[5];
}Urna;

void constructorUrna(Urna urna);

void destructorUrna(Urna urna);

int getIdUrna(Urna urna);

char* getHoraAperturaUrna(Urna &urna);

char* getHoraCierreUrna(Urna &urna);

void setIdUrna(Urna &urna, int dato);

void setHoraAperturaUrna(Urna &urna,char  dato[5]);

void setHoraCierreUrna(Urna &urna,char  dato[5]);

#endif // URNA_H_INCLUDED
