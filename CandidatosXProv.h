#ifndef CANDIDATOSXPROV_H_INCLUDED
#define CANDIDATOSXPROV_H_INCLUDED

#ifndef NULL
#define NULL      0
#endif

typedef struct{
        int id;
        int voto;
        char nombre[20];
        int PartidoPolitico;
}CandidatosXProv;

void constructorCandidatosXProv(CandidatosXProv candXprov);

void destructorCandidatosXProv(CandidatosXProv candXprov);

int getIdCandidatosXProv(CandidatosXProv candXprov);

char* getNombreCandidatosXProv(CandidatosXProv &candXprov);

int getPartidoCandidatosXProv(CandidatosXProv candXprov);

int getVotosCandidatosXProv(CandidatosXProv candXprov);

void setIdCandidatosXProv(CandidatosXProv &candXprov, int dato);

void setNombreCandidatosXProv(CandidatosXProv &candXprov,char  dato[20]);

void setPartidoCandidatosXProv(CandidatosXProv &candXprov,int  dato);

void setVotosCandidatosXProv(CandidatosXProv &candXprov,int  dato);



#endif // CANDIDATOSXPROV_H_INCLUDED
