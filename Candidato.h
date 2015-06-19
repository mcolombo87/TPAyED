#ifndef CANDIDATO_H_INCLUDED
#define CANDIDATO_H_INCLUDED


#ifndef NULL
#define NULL      0
#endif

typedef struct{
        int id;
        char nombre[20];
        int PartidoPolitico;
}Candidato;

void constructorCandidato(Candidato candidato);

void destructorCandidato(Candidato candidato);

int getIdCandidato(Candidato candidato);

char* getNombreCandidato(Candidato &candidato);

int getPartidoPolitico(Candidato candidato);

void setIdCandidato(Candidato &candidato, int dato);

void setNombreCandidato(Candidato &candidato,char  dato[20]);

void setPartidoPoliticoCandidato(Candidato &candidato,int  dato);


#endif // CANDIDATO_H_INCLUDED
