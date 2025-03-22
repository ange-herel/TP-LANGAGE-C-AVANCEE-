//exercice 2: tp2 semestre 2AP

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Date {
	char jour [3];
	char mois [3];
	char annee[5];
}date;
typedef struct Produit {
	char *nom_produit;
	char reference [100];
	float montant ;
	date Dateachat;
}produit;
typedef struct liste {
	produit cellule ;
	struct liste *psuiv;
}liste;

liste *creer_liste_produits()
{
	liste *nv=(liste *)malloc(sizeof(liste));
	if(nv==NULL)
	{
		printf("erreur d'allocation dynamique \n");
		return NULL;
	}
	nv->psuiv=NULL;
	return nv;
}
int est_vide(liste *tete)
{
	if(tete==NULL)
	{
		return 1;
	}
	return 0;
}
liste *creer_produits (){

          char choix;
          char nom[100],ref[100];
          float prix;
          date dt;
          printf("saisir  ou passer directement(s/P) : \n");
          scanf(" %c",&choix);
          if(choix=='s')
          {
              printf("entrer le nom du produits : \n");
              scanf("%s",nom);
              printf("entrer la reference  du produits : \n");
              scanf("%s",ref);
              printf("entrer le prix du produits :\n");
              scanf("%f",&prix);
              printf("entrer la date d'achat du produits :\n");
              scanf("%s%s%s",dt.jour,dt.mois,dt.annee);
          }
	liste *nv1=(liste *)malloc(sizeof(liste));
	if(nv1== NULL)
	{
		printf("erreur d'allocation dynamique\n");
		return NULL;
	}
	nv1->cellule.nom_produit=(char *)malloc((strlen(nom)+1)*sizeof(char));
	if(nv1->cellule.nom_produit==NULL)
    {
        printf("erreur d'allocation dynamique \n");
    }
    else {
	strcpy(nv1->cellule.nom_produit,nom);
	strcpy(nv1->cellule.reference,ref);
	nv1->cellule.montant=prix;
    strcpy(nv1->cellule.Dateachat.annee,dt.annee);
    strcpy(nv1->cellule.Dateachat.jour,dt.jour);
    strcpy(nv1->cellule.Dateachat.mois,dt.mois);
    nv1->psuiv=NULL;
    }
    return nv1;

}
void afficher_produit (liste* produit )
{
    printf("=====================AFFICHAGE DU NOUVEAU PRODUITS=================\n");
	printf("nom produit : %s\n",produit->cellule.nom_produit);
	printf("reference produit: %s\n",produit->cellule.reference);
	printf("montant  produit : %f\n",produit->cellule.montant);
	printf("Date d'achat produit: %s\t %s\t %s \t",produit->cellule.Dateachat.jour ,produit->cellule.Dateachat.mois,produit->cellule.Dateachat.annee);


}
liste *ajouter_debut(liste *tete)
{
	liste *nv=creer_produits();
	afficher_produit(nv);
	if(nv!=NULL)
	{
		if(tete==NULL)
		{
			tete=nv;
		}
		else {
			nv->psuiv =tete;
			tete=nv;
		}
	}
	return tete;
}
void ajouter_fin(liste **tete){
	liste *nv=creer_produits();
	afficher_produit(nv);
	if(nv!=NULL)
	{
		if(*tete==NULL)
		{
			*tete=nv;
		}
		else {
			liste *temp=*tete;
			while(temp->psuiv!=NULL)
			{
				temp=temp->psuiv;
			}
			temp->psuiv=nv;

		}
	}

}
void afficher_produits(liste *tete)
{
	liste *i=tete;
	while(i!=NULL)
	{
		printf("nom produit : %s\n",i->cellule.nom_produit);
		printf("reference produit: %s\n",i->cellule.reference);
		printf("montant  produit : %f\n",i->cellule.montant);
		printf("Date d'achat produit: %s\t %s\t %s \n",i->cellule.Dateachat.jour ,i->cellule.Dateachat.mois,i->cellule.Dateachat.annee);
		i=i->psuiv;
	}

}
int longueur(liste *tete)
{
	liste *i=tete;
	int compteur=0;
	while(i!=NULL)
	{
	    compteur++;
		i=i->psuiv;
	}
	return compteur;
}
void filter_date(liste *tete,date dt)
{
	liste *temp=tete;
	while(temp!=NULL)
	{
		if(strcmp(temp->cellule.Dateachat.jour,dt.jour)==0&&strcmp(temp->cellule.Dateachat.mois,dt.mois)==0&&strcmp(temp->cellule.Dateachat.annee,dt.annee)==0)
		{
				printf("nom produit : %s\n",temp->cellule.nom_produit);
				printf("reference produit: %s\n",temp->cellule.reference);
				printf("montant  produit : %f\n",temp->cellule.montant);
				printf("Date d'achat produit: %s\t %s\t %s \n",temp->cellule.Dateachat.jour ,temp->cellule.Dateachat.mois,temp->cellule.Dateachat.annee);

		}
		temp=temp->psuiv;
	}
}
liste* supprimer_debut(liste *tete)
{
	if(tete==NULL)
	{
		printf("la liste est vide ");
	}
	else {
		liste *temp=tete;
		tete=tete->psuiv;
		free(temp);
	}
	return tete;
}
void supprimer_fin(liste **tete)
{
	if(*tete==NULL)
	{
		printf("la liste est vide\n");
	}
	else
	{
		liste *temp=*tete;
		liste *precedent;
		while(temp->psuiv !=NULL)
		{
			precedent =temp;
			temp=temp->psuiv;
		}
		   free(temp);
		   precedent->psuiv=NULL;
	}
}

liste *rembourser(liste *liste1 ,char *refer)
{
	liste *temp,*precedent;
	if(liste1==NULL)
	{
		printf("la liste est vide \n");
		return NULL;
	}
	else {
		 int trouver,pos,compteur;
		 pos=longueur(liste1);
		 temp=liste1;
		 precedent =liste1;
		 for(compteur=1;compteur<pos;compteur++)
		 {
		 	compteur++;
		 	if(strcmp(temp->cellule.reference,refer)==0)
		 	{
		 		    break;
			 }
			 precedent = temp ;
			 temp=temp->psuiv;
		 }
		 if(compteur==1)
		 {
		 	liste1=supprimer_debut(liste1);
		 }
		 else if(compteur == pos)
		 {
		 	supprimer_fin(&liste1);
		 }
		 else {
		 	    precedent->psuiv =temp->psuiv ;
		 	    free(temp);
		 }

	}
	return liste1;
}
int  menu()
{
    int  choix;
    printf("========================Menu=====================\n");
    printf("1-Verifier la liste est vide  \n");
    printf("2-creer produits et ajouter au début de la liste un produits  \n");
    printf("3-DETERMINER LA LONGUEUR DE LA LISTE DES PRODUITS \n");
    printf("4-creer produits et ajouter a la fin de la liste un produits \n");
    printf("5-afficher la liste de produits \n");
    printf("6-afficher les produits de la liste selon la date d'ajout  \n");
    printf("7-SUPPRESSION DEBUT DE LA LISTE \n");
    printf("8-SUPPRESSION FIN DE LA LISTE \n");
    printf("9-SUPPRESSION SELON LA REFERENCE DU PRODUITS DANS LA LISTES\n");
    printf("entrer votre choix :\n");
    scanf("%d",&choix);
    return choix;


}

void main()
{
	liste *tete=NULL,*nouveau;
	date dt ;
	int choix, test;
	float prix;
	 char choix2,ref[100],nom[100];
	e:
	    system("cls ");
        choix =menu();
	switch(choix)
	{

    case 1 :
         test =est_vide(tete);
        if(test ==1)
        {
            printf("liste est vide \n");
        }
        else {
             printf("liste  n' est pas vide \n");
        }

        break;
    case 2:
        tete=ajouter_debut(tete);
         break;
    case 3:
        printf("la longueur  de votre liste  est : %d\n",longueur(tete));
         break;
    case 4:
          ajouter_fin(&tete);
          break;
    case 5:
        afficher_produits(tete);
       break ;
    case 6 :
         printf("entrer la date d'ajout des produits a afficher : \n");
         scanf("%s%s%s",dt.jour,dt.mois,dt.annee);
         filter_date(tete,dt);
        break;
    case 7:
          printf("================SUPPRESSION AU DEBUT DE LA LISTE===========\n");
          tete=supprimer_debut(tete);
          break;
    case 8:
          printf("================SUPPRESSION A LA FIN DE LA LISTE===========\n");
          supprimer_fin(&tete);
          break;
    case 9:
        printf("veuiller saisir la référence du livre a supprimer : \n");
        scanf("%s",ref);
        tete=rembourser(tete,ref);
        break;
    default :
        printf("erreur de choix dans le menu \n");
        break;

	}
	if(choix>=1 && choix<=8 )
    {

        printf("souhaiter poursuivre l'une des opérations presentes dans le menu(O/N) : \n");
        scanf(" %c",&choix2);
        if(choix2=='O')
        {
            goto e;
        }
        else
        {
           printf("FIN PROGRAMME ");
        }
    }



}
//exercice TP1 langage de programmation c avancée deuxieme semestere 2AP

/*#include<stdio.h>
#include<stdlib.h>
typedef struct Noeud {
    int valeur ;
    struct Noeud *suivant;
}Noeud ;
Noeud *creer(int valeur)
{
    Noeud *nv=(Noeud *)malloc(sizeof(Noeud ));
    if(nv==NULL)
    {
        printf("erreur d'allocation dynamique \n");
        return NULL;
    }
    nv->valeur =valeur ;
    nv->suivant=NULL;
    return nv;
}
Noeud *ajouterD(Noeud *debut,int valeur )
{

    Noeud *nv=creer(valeur);
    if(nv!=NULL)
    {
        if(debut==NULL)
        {
            debut=nv;
        }
        else {
            nv->suivant=debut;
            debut=nv;
        }
    }
    return debut;
}
int taille(Noeud *debut)
{
    Noeud *temp=debut;
    int compteur=0;
    while(temp!=NULL)
    {
        compteur ++;
        temp=temp->suivant;

    }
    return compteur ;

}
Noeud *insertposition(Noeud *debut,int pos,int valeur)
{
    Noeud *nv=creer(valeur);
    Noeud *courant=debut;;
    if(nv!=NULL)
    {
        if(debut==NULL)
        {
            printf("la liste est vide \n");
        }
        else if(pos<1 || pos>taille(debut))
        {
            printf("Position invalide\n");
        }
        else if(pos==1)
        {
                   debut=ajouterD(debut,valeur);
                   return debut;
        }
        else{
              for(int i=1;i<=pos-1;i++)
              {
                   if(i==pos-1)
                   {
                       break;
                   }
                  courant =courant->suivant;
              }
              nv->suivant=courant->suivant;
             courant->suivant =nv;
        }
    }
    return debut;
}
Noeud *ajouterF(Noeud *debut,int valeur )
{
    Noeud *nv=creer(valeur);
    if(nv!=NULL)
    {
        if(debut==NULL)
        {
            debut=nv;
        }
        else {
                Noeud *temp=debut;
            while(temp->suivant!=NULL)
            {
                temp=temp->suivant;
            }
            temp->suivant=nv;
        }
    }
    return debut;
}
void rechercher(Noeud *debut,int _valeur)
{

    Noeud *courant=debut;
    int pos=0;
    while(courant!=NULL)
    {
        if(courant->valeur ==_valeur)
        {
            printf("la valeur %d est presente dans la liste a la position %d\n",_valeur,pos+1);
            break;
        }
        pos++;
        courant=courant->suivant;
    }
}
Noeud *supprimerD(Noeud *debut)
{
    if(debut==NULL)
    {
        printf("la liste est vide \n");
    }
    else {
          Noeud *temp=debut;
          debut=debut->suivant;
          free(temp);
    }
    return debut;
}
Noeud *supprimerF(Noeud *debut)
{
    if(debut==NULL)
    {
        printf("la liste est vide \n");
    }
    else {
         Noeud *temp=debut,*precedent=debut;
         while(temp->suivant!=NULL)
         {
             precedent=temp;
             temp=temp->suivant;
         }
         precedent->suivant=temp->suivant;
         free(temp);
    }
    return debut;
}
Noeud *suppressionP(Noeud *debut ,int pos )
{
    if(debut==NULL)
    {
        printf("la liste est vide \n");
        return NULL;
    }
    else if(pos<1 || pos>taille(debut))
    {
        printf("position non valide \n");
    }
    else {
           if(pos==1)
           {
               debut=supprimerD(debut);
           }
           else {
                Noeud *courant=debut,*precedent=debut;
               for (int i=1;i<pos;i++)
               {
                    precedent=courant;
                   courant=courant->suivant;
               }
               precedent->suivant=courant->suivant;
               if(courant->suivant==NULL)
               {
                   precedent->suivant=NULL;
               }
               free(courant);

           }
    }
    return debut;
}
Noeud *modifierD(Noeud *debut ,int valeur )
{
    if(debut==NULL)
    {
        printf("la liste est vide \n");
        return NULL;
    }
    debut->valeur=valeur;
    return debut ;
}
Noeud *modifierF(Noeud *debut,int valeur )
{
      if(debut ==NULL)
      {
            printf("la liste est vide \n");
            return NULL;
      }
      Noeud *temp=debut;
      while(temp->suivant!=NULL)
      {
          temp=temp->suivant;
      }
      temp->valeur=valeur;
     return debut;
}
Noeud *modifierP(Noeud *debut,int pos,int valeur)
{
    if(debut ==NULL)
    {
        printf("la liste est vide\n");
    }
    else if (pos<1 || pos>taille(debut))
    {
        printf("position invalide");
    }
    else {
            Noeud *temp=debut;
          for(int i=1;i<pos;i++)
          {
              temp=temp->suivant;
          }
           temp->valeur=valeur;
    }
    return debut;
}
void afficher(Noeud *debut)
{
    Noeud *temp=debut;
    while(temp!=NULL)
    {
        printf("%d->",temp->valeur);
        temp=temp->suivant;
    }
    printf("NULL\n");
}
void main()
{
    Noeud *debut=NULL;
    int pos;
    int valeur;
    printf("entrer un certains de nombre de valeur au début liste jusqu'a zéro :\n");
    do {
            scanf("%d",&valeur);
         if(valeur !=0)
         {
            debut=ajouterD(debut,valeur);
         }
    }while(valeur!=0);
    afficher(debut);
    printf("entrer un certains de nombre de valeur a la fin de la liste  jusqu'a zéro :\n");
    do {
            scanf("%d",&valeur);
         if(valeur !=0)
         {
            debut=ajouterF(debut,valeur);
         }
    }while(valeur!=0);
    afficher(debut);
    printf("==================AJOUT A UNE POSITION DE LA LISTE==================\n");
    printf("entrer la position a laquelle vous souhaitez inserer : \n");
    scanf("%d",&pos);
    printf("entrer une valeur :\n");
    scanf("%d",&valeur);
    debut=insertposition(debut,pos,valeur);
    afficher(debut);
    printf("=====================LA TAILLE DE VOTRE LISTE =======================\n");
    printf("la taille de votre liste est : %d\n",taille(debut));
    printf("=====================RECHERCHE D UNE VALEUR==========================\n");
    printf("entrer une valeur a rechercher au sein de la liste :\n");
    scanf("%d",&valeur);
    rechercher(debut,valeur);
    printf("==================SUPPRESSION DEBUT DE LA LISTE==================\n");
    debut=supprimerD(debut);
    afficher(debut);
    printf("==================SUPPRESSION FIN DE LA LISTE==================\n");
    debut=supprimerF(debut);
    afficher(debut);
    printf("==================SUPPRESSION A UNE POSITION  DE LA LISTE==================\n");
    printf("entrer la position a laquelle vous souhaitez supprimer : \n");
    scanf("%d",&pos);
    debut=suppressionP(debut,pos);
    afficher(debut);
    printf("===================MODIFIER VALEUR DEBUT LISTE=====================\n");
    printf("entrer la nouvelle valeur : \n");
    scanf("%d",&valeur);
    debut=modifierD(debut,valeur);
    afficher(debut);
    printf("===================MODIFIER VALEUR FIN LISTE=====================\n");
    printf("entrer la nouvelle valeur : \n");
    scanf("%d",&valeur);
    debut=modifierF(debut,valeur);
    afficher(debut);
     printf("===================MODIFIER VALEUR POSITION DE LA LISTE=====================\n");
    printf("entrer la nouvelle valeur : \n");
    scanf("%d",&valeur);
    printf("entrer la position a laquelle le changement doit se faire : \n");
    scanf("%d",&pos);
    debut=modifierP(debut,pos,valeur);
    afficher(debut);


}*/

