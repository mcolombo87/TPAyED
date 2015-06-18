#ifndef CANDIDATO_H_INCLUDED
#define CANDIDATO_H_INCLUDED


#ifndef NULL
#define NULL      0
#endif

typedef struct{
        int id;
        char nombre[20];
        char PartidoPolitico[20];
}Candidato;

void constructorCandidato(Candidato candidato);

void destructorCandidato(Candidato candidato);

int getIdCandidato(Candidato candidato);

char* getNombreCandidato(Candidato &candidato);

char* getPartidoPolitico(Candidato &candidato);

void setIdCandidato(Candidato &candidato, int dato);

void setNombreCandidato(Candidato &candidato,char  dato[20]);

void setPartidoPoliticoCandidato(Candidato &candidato,char  dato[20]);


#endif // CANDIDATO_H_INCLUDED
