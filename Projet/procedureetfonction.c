#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// liste circulaire
/*typedef struct Noeud{
    int data;
     struct Noeud *suivant;
}Noeud;
typedef Noeud* liste;
liste *creer_element(int valeur)
{
    liste nv=(liste)malloc(sizeof(Noeud));
    if(nv==NULL)
    {
        printf("erreur d'allcotion dynamique \n");
        exit(01);
    }
    nv->data=valeur;
    nv->suivant=nv;
}
liste AjoutDebut(liste Fin,int valeur)
{
    liste new_element=creer_element(valeur);
    if(Fin!=NULL)
    {
        new_element->suivant=Fin->suivant;
        Fin->suivant=new_element;
    }
    else {
        Fin=new_element;
    }
    return Fin;
}
liste AjouterFin(liste Fin,int valeur)
{
     liste new_element=creer_element(valeur);
     if(Fin==NULL)
     {
         Fin=new_element;
     }
     else {
            liste temp=Fin->suivant;
            do {
                    temp=temp->suivant;

            }while(temp!=Fin->suivant);
            new_element->suivant=Fin->suivant;
            Fin->suivant=new_element;
            Fin=new_element;

     }
     return Fin;
}
int taille(liste Fin)
{
    int compteur=0;
    liste temp=Fin->suivant;
    if(Fin!=NULL)
    {
          do {
            compteur++;
            temp=temp->suivant;

        }while(temp!=Fin->suivant);

    }
    return compteur;
}
liste InsererPos(liste Fin,int valeur,int position)
{
    if(Fin==NULL || position>taille(Fin)+1 || position<1)
    {
        printf("Insertion impossible \n");
    }
    else  if(position ==1)
    {
        Fin=AjoutDebut(Fin,valeur);
    }
    else {
        liste temp=Fin->suivant;
        liste precedent=temp->suivant;
        int compteurpos=1;
        liste new_element=creer_element(valeur);
        do {
                compteurpos++;
                precedent=temp;
                temp=temp->suivant;
        }while(temp!=Fin->suivant && compteurpos<position);
        precedent->suivant=new_element;
        new_element->suivant=temp;

    }
    return Fin;
}
liste supprimerDebut(liste Fin)
{
    if(Fin==NULL)
    {
        printf("la liste est vide \n");
    }
    else if(Fin->suivant==Fin)
    {
        free(Fin);
        return NULL;
    }
    else
    {

            liste temp=Fin->suivant;
            Fin->suivant=temp->suivant;
            free(temp);
    }
    return Fin;
}
liste SupprimerFin(liste Fin)
{
    if(Fin==NULL)
    {
        printf("la liste est vide \n");
    }
    else if(Fin->suivant==Fin)
    {
        free(Fin);
        return NULL;
    }
    else {
        liste temp=Fin->suivant,precedent=Fin->suivant;
        do {
            precedent=temp;
            temp=temp->suivant;
        }while(temp->suivant!=Fin->suivant);
        precedent->suivant=temp->suivant ;
        free(temp);
        Fin=precedent;

    }
    return Fin;
}

liste supprimerpos(liste Fin,int position)
{
    if(Fin==NULL || position>taille(Fin)+1 || position<1)
    {
        printf("suppression impossible \n");
    }
    else if (position ==1)
    {
        Fin=supprimerDebut(Fin);
    }
    else
    {
        liste temp=Fin->suivant,precedent=temp->suivant;
        int compteurpos=1;
        do {
                compteurpos++;
                precedent=temp;
                temp=temp->suivant;

        }while(temp!=Fin->suivant && compteurpos<position);
        precedent->suivant=temp->suivant;
        free(temp);
        if(compteurpos==taille(Fin))
        {
            Fin=precedent;
        }

    }
    return Fin;
}
void afficher(liste Fin)
{
    liste temp=Fin->suivant;
    do {
            printf("%d\t",temp->data);
            temp=temp->suivant;

    }while(temp!=Fin->suivant);

}

void main()
{
   liste *Fin=NULL;
   int valeur,position;
   printf("=============saisie des valeurs au début de la liste ===================\n");
   for(int i=0;i<3;i++)
   {
       printf("entrer un nombre :\n");
       scanf("%d",&valeur);
       Fin=AjoutDebut(Fin,valeur);
   }
   afficher(Fin);
   printf("\n=============saisie des valeurs a la Fin de la liste ===================\n");
   for(int i=0;i<3;i++)
   {
       printf("entrer un nombre :\n");
       scanf("%d",&valeur);
       Fin=AjouterFin(Fin,valeur);
   }
   afficher(Fin);
   printf("\n===============Insérer une valeur a une position donnée=====================\n");
   printf("entrer une position : \n");
   scanf("%d",&position );
   printf("entrer un nombre dans une liste chainée  :\n");
   scanf("%d",&valeur);
   Fin=InsererPos(Fin,valeur,position);
   afficher(Fin);
   printf("\n==========SUPPRESSION AU DEBUT===========\n");
   Fin=supprimerDebut(Fin);
   afficher(Fin);
   printf("\n==========SUPPRESSION A LA FIN ===========\n");
   Fin=SupprimerFin(Fin);
   afficher(Fin);
   printf("\n==========SUPPRESSION A UNE POSITION DONNEE  ===========\n");
   printf("entrer une position : \n");
   scanf("%d",&position );
   Fin=supprimerpos(Fin,position);
   afficher(Fin);
}*/

typedef struct Noeud{
    int data;
    struct Noeud *suivant;
    struct Noeud *precedent;
}Noeud;
typedef Noeud* liste ;
liste creer_element(int valeur)
{
    liste nv=(liste )malloc(sizeof(Noeud));
    if(nv==NULL)
    {
        printf("\n erreur d'allocation dynamique \n");
        exit(01);
    }
    nv->data=valeur;
    nv->suivant=NULL;
    nv->precedent=NULL;
    return nv;
}
liste AjoutD(liste head,int valeur)
{

    liste new_element=creer_element(valeur);
    if(head==NULL)
    {
        head=new_element;
    }
    else {
        new_element->suivant=head;
        head->precedent=new_element;
        head=new_element;
    }
    return head;
}
liste AjoutF(liste head,int valeur)
{
     liste new_element=creer_element(valeur);
    if(head==NULL)
    {
        head=new_element;
    }
    else {
        liste temp=head;
        while(temp->suivant!=NULL)
        {
            temp=temp->suivant;
        }
        temp->suivant=new_element;
        new_element->precedent=temp;
    }
    return head;
}
int taille(liste head)
{

    int compteur=0;
    liste temp=head;
    while (temp!=NULL)
    {
        compteur++;
        temp=temp->suivant;
    }
    return compteur;
}
liste AjoutPosition(liste head,int valeur,int position )
{
    if(head==NULL || position >taille(head)|| position<1)
    {
        printf("opération impossible \n");
    }
    else if (position ==1)
    {
        head=AjoutD(head,valeur);
    }
    else {
        liste temp=head;
        int compteur=1;
        liste new_element=creer_element(valeur);
        while(temp!=NULL && compteur<position+1)
        {
            compteur++;
            temp=temp->suivant;
        }
        temp->precedent->suivant=new_element;
        new_element->precedent=temp->precedent;
        new_element->suivant=temp;
        temp->precedent=new_element;
    }

    return head;
}
liste SupprimerD(liste head)
{
    if(head==NULL)
    {
        printf("la liste est vide \n");
    }
    else if (head->suivant==NULL)
    {
        free(head);
        head=NULL;
    }
    else {
        liste temp=head;
        head=head->suivant;
        free(temp);
        head->precedent=NULL;
    }
    return head;
}
liste SupprimF(liste head)
{
      if(head==NULL)
    {
        printf("la liste est vide \n");
    }
    else if (head->suivant == NULL)
    {
        free(head);
        head=NULL;
    }
    else {
        liste temp=head;
        while(temp->suivant!=NULL)
        {
            temp=temp->suivant;
        }
        temp->precedent->suivant=NULL;
        free(temp);
    }
    return head;
}
liste Suppressionposition(liste head,int position )
{
    if(head==NULL || position >taille(head)|| position<1)
    {
        printf("opération impossible \n");
    }
    else if (position ==1)
    {
        head=SupprimerD(head);
    }
    else {
        liste temp=head;
        int compteur=1;
        while(temp!=NULL && compteur<position)
        {
            temp=temp->suivant;
        }
        temp->precedent->suivant=temp->suivant;
        if(temp->suivant!=NULL)
        {
            temp->suivant->precedent=temp->precedent;
        }
    }
    return head;
}
void afficher(liste head)
{
    liste temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->suivant;
    }
}
void afficherinverse(liste head)
{
     liste temp=head;
    while(temp->suivant!=NULL)
    {
        temp=temp->suivant;
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->precedent;
    }
}

void main()
{
    liste head=NULL;
   int valeur,position;
   printf("=============saisie des valeurs au début de la liste ===================\n");
   for(int i=0;i<3;i++)
   {
       printf("entrer un nombre :\n");
       scanf("%d",&valeur);
       head=AjoutD(head,valeur);
   }
   afficher(head);
   printf("\n=============saisie des valeurs a la Fin de la liste ===================\n");
   for(int i=0;i<3;i++)
   {
       printf("entrer un nombre :\n");
       scanf("%d",&valeur);
       head=AjoutF(head,valeur);
   }
   afficher(head);
   /*printf("\n===============Insérer une valeur a une position donnée=====================\n");
   printf("entrer une position : \n");
   scanf("%d",&position );
   printf("entrer un nombre dans une liste chainée  :\n");
   scanf("%d",&valeur);*/
   //head= AjoutPosition(head,valeur,position );
   //afficher(head);
   printf("\n==========SUPPRESSION AU DEBUT===========\n");
   head=SupprimerD(head);
   afficher(head);
   printf("\n==========SUPPRESSION A LA FIN ===========\n");
   head=SupprimF(head);
   afficher(head);
   printf("\n==========SUPPRESSION A UNE POSITION DONNEE  ===========\n");
   printf("entrer une position : \n");
   scanf("%d",&position );
   head=Suppressionposition(head,position);
   afficher(head);
   printf("\n=========ordre inverse============\n");
   afficherinverse(head);
}
