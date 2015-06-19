#ifndef PARTIDOSXPROV_H_INCLUDED
#define PARTIDOSXPROV_H_INCLUDED

#ifndef NULL
#define NULL      0
#endif

typedef struct{
        int id;
        int votos;
        char nombre[20];
}PartidosXProv;

void constructorPartidosXProv(PartidosXProv partXprov);

void destructorPartidosXProv(PartidosXProv partXprov);

int getIdPartidosXProv(PartidosXProv partXprov);

char* getNombrePartidosXProv(PartidosXProv &partXprov);

int getVotosPartidosXProv(PartidosXProv partXprov);

void setIdPartidosXProv(PartidosXProv &partXprov, int dato);

void setNombrePartidosXProv(PartidosXProv &partXprov,char  dato[20]);

void setVotosPartidosXProv(PartidosXProv &partXprov,int  dato);

#endif // PARTIDOSXPROV_H_INCLUDED
