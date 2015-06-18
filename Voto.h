#ifndef VOTO_H_INCLUDED
#define VOTO_H_INCLUDED

#ifndef NULL
#define NULL      0
#endif

typedef struct{
        int id;
        int idCandidato;
}Voto;

void constructorVoto(Voto voto);

void destructorVoto(Voto voto);

int getIdVoto(Voto voto);

int getIdCandidatoVoto(Voto voto);

void setIdVoto(Voto &voto, int dato);

void setIdCandidatoVoto(Voto &voto,int  dato);


#endif // VOTO_H_INCLUDED
