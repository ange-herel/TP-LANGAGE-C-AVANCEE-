#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Employe{
	char nom[100];
	char matricule[100];
	float prix;
}Employe;
typedef struct departement {
	int nombre_employe;
	Employe *tab;
	char *nom_departement;
}departement;
typedef struct Noeud {
	departement data;
	struct Noeud *suivant;
	struct Noeud *precedent;
}Noeud;
Employe creer_employe()
{
	Employe nv;
	printf("entrer le nom de l'employe: \n");
	scanf("%s",nv.nom);
	printf("entrer le matricule de l'employe : \n");
	scanf("%s",nv.matricule);
	printf("entrer le salaire de l'employe : \n");
	scanf("%f",&nv.prix);
	return nv;
}
departement creer_departement ()
{
	int i;
	char chaine[100];
	departement nv;
	printf("entrer le nombre d'employe : \n");
	scanf("%d",&nv.nombre_employe);
	nv.tab=(Employe*)malloc(nv.nombre_employe*sizeof(Employe));
	for(i=0;i<nv.nombre_employe;i++)
	{
		nv.tab[i]=creer_employe();
	}
	printf("entrer le nom du département : \n");
	scanf("%s",chaine);
	nv.nom_departement=(char*)malloc(strlen(chaine)*sizeof(char));
	if(nv.nom_departement==NULL)
	{
		printf("\n erreur d'allocation dynamique \n");
		exit(01);
	}
	strcpy(nv.nom_departement,chaine);
	return nv;	
	
}
Noeud *creer_noeud()
{
		Noeud *nv=(Noeud*)malloc(sizeof(Noeud));
	if(nv==NULL)
	{
		printf("\n erreur d'allocation dynamique\n");
		exit(01);
	}
	nv->data=creer_departement();
	nv->precedent=NULL;
	nv->suivant=NULL;
	return nv;
}
Noeud *ajouter_magique(Noeud *tete)
{
	Noeud *nv=creer_noeud();
	if(nv!=NULL)
	{
		if(tete==NULL)
		{
			tete=nv;
		}
		else {
			Noeud *parcours=tete;
			while(parcours->suivant!=NULL)
			{
				parcours=parcours->suivant;
			}
			parcours->suivant=nv;
		}
	}
	return tete;
	
}
void afficher(Noeud *tete)
{
	Noeud *parcours=tete;
	int nombre;
	while(parcours!=NULL)
	{
		printf("\n\n nom du département :%s\n",parcours->data.nom_departement);
		printf("\n\n nombre d'employe: %d\n",parcours->data.nombre_employe);
		printf("==============LISTE DES EMPLOYES ET LEUR INFORMATION=====================\n");
		for(nombre=0;nombre<parcours->data.nombre_employe;nombre++)
		{
			printf("nom de l'employe :%s\n",parcours->data.tab[nombre].nom);
		    printf("Matricule :%s\n",parcours->data.tab[nombre].matricule);
			printf("Prix :%f\n",parcours->data.tab[nombre].prix);
		}
     	parcours=parcours->suivant;
	}
}
Noeud * supprimer_dep(Noeud *tete,char* nom_dep)
{
	if(tete==NULL)
	{
		printf("\n la liste est vide \n");
	}
	else {
		Noeud *parcours=tete;
		while(parcours->suivant!=NULL && strcmp(parcours->data.nom_departement,nom_dep)!=0)
		{
			 parcours=parcours->suivant;
		}
		if(parcours==tete)
		{
		    Noeud *temp=tete;
		    tete=tete->suivant;
		    free(temp);
		    tete->precedent=NULL;
		}
		else 
		{
			parcours->precedent->suivant=parcours->suivant;
			if(parcours->suivant!=NULL)
		  {
		  		parcours->suivant->precedent=parcours->precedent;
		  }
			free(parcours);
		}
	}
	return tete;
}
Noeud *supprimer_magique(Noeud *tete,char *nom_dep)
{
	if(tete!=NULL)
	{
		Noeud *parcours=tete;
		while(parcours!=NULL)
		{
			if(strcmp(parcours->data.nom_departement,nom_dep)==0)
			{
				parcours=supprimer_dep(tete,nom_dep);
			}
			parcours=parcours->suivant;
		}
	}
	return tete;
}
int main()
{
	Noeud *tete=NULL;
	char nom_dep[100];
	int i=0;
	for(i=0;i<2;i++)
	{
		tete=ajouter_magique(tete);
	}
	afficher(tete);
	printf("entrer le nom du département a suppprimer : \n");
	scanf("%s",nom_dep);
	tete=supprimer_magique(tete,nom_dep);
	afficher(tete);
	return 0;
}
