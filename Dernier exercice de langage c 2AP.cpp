/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Plat {// il s'agit de structure imbriquée 
	char nom[100];
	char categorie[100];
	float prix;
}Plat;
typedef struct ElementPlat {
	Plat data;
	struct ElementPlat *suivant;
	struct ElementPlat *precedent;
}ElementPlat;
typedef struct Menu {
	ElementPlat* head_plat;
	char nom_menu[100];
} Menu ;
typedef struct Elementmenu {
	Menu data;
	struct Elementmenu *suivant ;
	struct Elementmenu *precedent ;
}Elementmenu;
typedef Elementmenu *liste_menu;

void afficherPlatParCategorie(Menu M ,char* categorie)// la version que j'ai faite 
{
	Menu parcours=M;
	int compteur=0;
	while(parcours.head_plat->suivant !=NULL)
	{
		if(strcmp(M.head_plat->data.categorie,categorie) ==0)
		{
			printf("PLAT %d : %s",compteur+1,M.head_plat->data.nom);
		}
		parcours.head_plat=parcours.head_plat->suivant;
	}
}

   //la version faite par le professeur 
   void afficherPlatParCategorie(Menu M, char* categorie)
   {
 	
	    li	
		}

liste_menu chercherParNom(liste_menu Em ,char* nom)
{
	liste_menu parcours = Em;
	int test=0;
	while(parcours!=NULL)
	{
		if(strcmp(parcours->data.nom_menu,nom)==0)
		{
			printf("Menu :%s \n",parcours->data.menu);//dans ce cas il s'agit de retourner l'adresse du menu et nom d'afficher les menu donc on va remplacer cette ligne de code par un return parcours->data.nom_menu
			test=1;
			break;
		}
		parcours=parcours->suivant;
    }
    printf("AUCUN MENU NE PORTANT SE NOM EXISTE AU SEIN DE LA BASE DE DONNEES");
    return NULL;
}
ElementPlat * chercherParNomPlat(Elementmenu *Em ,char* nom )//fonction fausse faudra que je le refasse a la maison tête reposer 
{
	Elementmenu *parcours =Em ;
	while(parcours!=NULL)
	{
		if(strcmp(parcours->data.head_plat->data.nom,nom)==0)
		{
			return parcours->data.head_plat->data.nom;
		}
		parcours=parcours->suivant;
	}
	printf("PLAT INEXISTANT AU SEIN DE LA BASE DE DONNEES \n")
	return head;
}
ElementPlat * chercherParNomPlat2(ElementPlat *EP ,char *nom)
{
	ElementPlat *parcours=Ep;
	while(parcours!=NULL)
	{
		if(strcmp(parcours->data.nom,nom)==0)
		{
			return parcours;
		}
		parcours=parcours->suivant;
	}
	return NULL;
}
ElementPlat *getParCategorie(Menu M ,char * categorie)
{
	Menu parcours=M;
	ElementPlat *head=NULL;
	while(parcours.head_plat!=NULL)
	{
		 if(strcmp(parcours.head_plat->data.categorie,categorie)==0)
		 {
		 	if(head==NULL)
		 	{
		 		head=parcours.head_plat;
			 }
			 else {
			 	head->suivant=head_plat;
			 }
		 }
		 parcours.head_plat=parcours.head_plat->suivant;
	}
	return head;
}

ElementPlat* new_element(Plat p)
{
	ElementPlat* newE=(ElementPlat*)malloc(sizeof(ElementPlat));
	if(NewE!=NULL)
	{
		  NewE->P=p;
		  NewE->next=NULL;
		  NewE->prev=NULL;
	}
	return NewE;
}
ElementPlat *getPlatSupPrix(Menu M,float prix)
{
    ElementPlat* temp=M.head_plat;
    ElementPlat* Lp=NULL;
    while(temp!=NULL)
    {
    	if(temp->data.prix > prix)
    	{
    		Lp=InsertD(Lp,temp->data);
    		temp=temp->suivant;
		}
	}
	return Lp;
}
int nbrPlat(Menu M)
{
	int ct=0;
	ElementPlat* temp=M.head_plat;
	while(temp!=NULL)
	{
		ct++;
		temp=temp->suivant;
	}
	return ct;
}

ElementMenu* InsertDM(ElementMenu* L, Menu m)
{
	ElementMenu* NewE=new_element(m);
	if(NewE!=NULL)
	{
		if(L!=NULL)
		{
			NewE->suivant=L;
			L->precedent=NewE;
		}
		L=NewE;
	}
	return L;
}
ElementMenu*getMenuParNbrPlat(ElementMenu *EM)
{
	ElementMenu* temp=Em;
	ElementMenu* LM =NULL;
	while(temp!=NULL)
	{
		if(nbrPlat(temp->M)>20)
		{
			LM=InsertDM(LM,temp->M);
			temp=temp->suivant;
		}
	}
	return LM;
}
ElementPlat* ajoutParOrdrePrix(ElementPlat *Ep,Plat p)
{
	 if(Ep==NULL || p.prix <= Ep->precedent.prix)
	 Ep=InsertD(Ep,p);
	 else {
	 	ElementPlat* NewE=NewElement(p);
	 	if(newE!=NULL)
	 	{
	 		ElementPlat* temp=Ep;
	 		while(temp->suivant && temp->suivant < p.prix)
	 		{
	 			temp=temp->suivant;
			 }
			 	NewE->suivant=temp->suivant ;
	 			NewE->precedent=temp;
	 			if(temp->suivant!=NULL)
	 			{
	 				temp->suivant->precedent=NewE;
	 				temp->suivant=NewE;
				 }
			 
		 }
	 }
	 return Ep;
}
suppression
 ElementPlat* supprimerParNom(ElementPlat* Ep,char* nom)
 {
 	ElementPlat* temp=Ep;
 	if(Ep==NULL)
 	{
 		printf("Laliste des plats est vide.\n");
	 }
	 else if(strcmp(Ep->P.Nom,nom)==0)
	 {
	 	 Ep=Ep->suivant;
	 	 if(Ep!=NULL)
	 	 {
	 	 	Ep->precedent=NULL;
	 	 	free(temp);
		  }
	 }
	 else {
	 	  while(temp!=NULL  && strcmp(temp->P.nom,nom)!=0)
	 	  {
	 	  	  temp=temp->suivant;
		   }
		   if(temp==NULL)
		   {
		   	 printf("le plat est introuvables \n");
		   }
		   else {
		   	  temp->precedent->suivant=temp->suivant;
		   	  if(temp->suivant!=NULL)
		   	  {
		   	  	 temp->suivant->precedent=temp->precedent;
		   	  	 free(temp);
				 }
		   }
	 }
	 return Ep;
 }*/
/*#include<stdio.h>
#include<stdlib.h>
typedef struct Noeud {
	int data;
	struct Noeud *suivant ;
	struct Noeud *precedent ;
}Noeud;
typedef Noeud* liste;
liste creer_noeud (int data)
{
	liste nv=(liste )malloc(sizeof(Noeud));
	if(nv==NULL)
	{
		printf("erreur d'allocation dynamique \n");
		exit(01);
	}
	nv->data=data;
	nv->suivant=NULL;
	nv->precedent=NULL;
	return nv;
	
}
liste ajouter_D(liste head,int data)
{
	liste nv=creer_noeud(data);
	if(head==NULL)
	{
		head=nv;
	}
	else {
		 nv->suivant=head;
		 head->precedent=nv;
		head=nv;
	}
	return head;
}
liste ajouter_F(liste head,int data)
{
	liste nv=creer_noeud(data);
	if(head==NULL)
	{
		head=nv;
	}
	else {
		 liste temp=head;
		 while(temp->suivant!=NULL)
		 {
		 	temp=temp->suivant;
		 }
		 temp->suivant=nv;
		 nv->precedent=temp;
	}
	return head;
}
int taille (liste head)
{
	liste temp=head;
	int compteur=0;
	while(temp!=NULL)
	{
		compteur++;
		temp=temp->suivant ;
	}
	return compteur;
}
liste ajouter_position(liste head ,int data ,int position )
{
	 if(head==NULL || position>taille(head)+1 || position<1)
	 {
	 	printf("\n erreur position \n");
	 }
	 else if (position==1)
	 {
	 	   head=ajouter_F(head,data);
	 }
	 else {
	 	   liste temp=head;
	 	   liste nv=creer_noeud(data);
	 	   int compteur=0;
	 	   while(temp->suivant!=NULL && compteur<position-1)
	 	   {
	 	   	   temp=temp->suivant;
			}
			nv->suivant=temp->suivant;
			temp->suivant->precedent=nv;
			temp->suivant=nv;
			nv->precedent=temp;
			
			
	 	
	 }
	 return head;
}
void afficher(liste head)
{
	liste temp=head;
	int compteur=0;
	while(temp!=NULL)
	{
		printf("valeur %d : %d\n",compteur+1,temp->data);
		compteur++;
		temp=temp->suivant;
	}
	
}
void afficher_inverse(liste head)
{
	liste temp=head;
	int compteur=0;
	while(temp->suivant!=NULL)
	{
		temp=temp->suivant;
	}
	while(temp!=NULL)
	{
		printf("valeur %d : %d\n",compteur+1,temp->data);
		compteur++;
		temp=temp->precedent;
	}
}
void liberer_liste(liste head)
{
	liste temp=head,reserve;
	while(temp!=NULL)
	{
		reserve=temp;
		temp=temp->suivant;
		free(reserve);
	}
	printf("\033[32m\n Memoire libre \033[0m\n");
}
int  main()
{
	liste head=NULL;
	int i,data,position;
	printf(" \n=====================AJOUT DES ELEMENTS AU DEBUT DE LA LISTE=====================\n");
	for(i=0;i<2;i++)
	{
		printf("entrer la valeur %d de la liste :\n",i+1);
		scanf("%d",&data);
		head=ajouter_D(head,data);
	}
	printf("\n================AFFICHAGE ORDRE CORRECTE================\n");
	afficher(head);
	printf("\n ================INVERSE AFFICHAGE================\n");
	afficher_inverse(head);
    liberer_liste(head);
    head=NULL;
	printf(" \n=====================AJOUT DES ELEMENTS A LA FIN DE LA LISTE=====================\n");
	for(i=0;i<3;i++)
	{
		printf("entrer la valeur %d de la liste :\n",i+1);
		scanf("%d",&data);
		head=ajouter_F(head,data);
	}
	printf("\n================AFFICHAGE ORDRE CORRECTE================\n");
	afficher(head);
	printf("\n ================INVERSE AFFICHAGE================\n");
	afficher_inverse(head);
   	printf(" \n=====================AJOUT DES ELEMENTS A DES POSITIONS DONNEES  DE LA LISTE=====================\n");
	printf("entrer la valeur %d de la liste :\n",i+1);
	scanf("%d",&data);
	printf("entrer la position  auquel vous souhaitez insérez un élement dans la liste : \n");
	scanf("%d",&position);
	head=ajouter_position(head ,data,position );
	printf("\n================AFFICHAGE ORDRE CORRECTE================\n");
	afficher(head);
	printf("\n ================INVERSE AFFICHAGE================\n");
	afficher_inverse(head);
	 liberer_liste(head);
    head=NULL;
    return 0;
    
}*/

/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Noeud {
	int data;
	struct Noeud  *suivant;
}Noeud;
typedef Noeud* Pile;
Pile Initialiser_pile()
{
	return NULL;
}
Pile creer_noeud (int data)
{
	Pile nv=(Pile )malloc(sizeof(Noeud));
	if(nv==NULL)
	{
		printf("\n errreur d'allocation dynamique \n");
		exit(01);
	}
	nv->data=data;
	nv->suivant=NULL;
	return nv;
}
Pile Empiler(Pile head,int data)
{
	Pile nv=creer_noeud(data);
	if(head==NULL)
	{
		head=nv;
	}
	else {
		nv->suivant=head;
		head=nv;
	}
	return head;
}
int est_vide(Pile head)
{
	return (head==NULL);
}
int Sommet_pile(Pile head)
{
	if(head!=NULL)
	{
		return head->data;
	}
	else {
		printf("La pile est vide \n");
		return -1;
	}
}
int taille (Pile head)
{
	Pile temp=head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->suivant;
	}
	return count ;
}
Pile Depiler(Pile head)
{
	if(head!=NULL)
	{
		if(head->suivant==NULL)
		{
			free(head);
			head=NULL;
		}
		else {
			Pile temp=head;
			head=head->suivant;
			free(temp);
		}
	}
	return head;
}
void ViderPile(Pile head)
{
	if(head==NULL)
	{
		printf("la PILE EST VIDE \n");
		return ;
	}
	Pile temp;
	while(head!=NULL)
	{
		temp=head;
		head=head->suivant;
		free(temp);
	}
	printf("\033[34m La pile a été vidé complètement \033[0m\n");
	
}
void afficher_pile(Pile head)
{
	Pile temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->suivant;
	}
	
}

main()
{
	Pile head=NULL;
	int data,i;
	printf("\033[33.5m Vérification De LA PLEINITUDE DE LA PILE \033[0m\n");
	if(est_vide(head))
	{
		printf("La PILE EST VIDE \n");
	}
	else {
		printf("La Pile n'est pas vide \n");
	}
	for(i=0;i<2;i++)
	{
		printf("entrer une valeur a rajouter au sein de notre Pile : \n");
		scanf("%d",&data);
		head=Empiler(head,data);
		printf("\033[38mAJOUT PILE REUSSI \033[0m\n");
	    system("cls");
		
	}
	printf("\033[36m==================AFFICHAGE DE LA PILE==================\033[0m\n");
	afficher_pile(head);
	printf("\nla taille de la Pile est : %d\n",taille(head));
	printf("\n033[36m le Sommet de votre Pile est :%d\033[0m\n",Sommet_pile(head));
	printf("\033[32m========================DEPILEMENT DANS LA PILE=============================\033[0m\n");
	head=Depiler(head);
	afficher_pile(head);
	printf("\n033[32m========================DEPILEMENT TOTALEMENT  DANS LA PILE=============================\033[0m\n");
    ViderPile(head);
	

}*/

/*#include<stdio.h>
#include<stdlib.h>
typedef struct Livre {
	char references[100];
	char titre  [100];
	float prix;
	int type;
}Livre;
typedef struct Noeud1 {
    	Livre data1;
	struct Noeud1  *suivant;
	struct Noeud1 *Precedent;
}Noeud1;
typedef Noeud1* liste1 ;
liste1  creer_noeud(Livre data)
{
	liste1 nv=(liste1 )malloc(sizeof(Noeud1));
	if(nv==NULL)
	{
		printf("\nerreur d'allocation dynamique \n");
		return NULL;
	}
	nv->data1=data;
	nv->suivant=NULL;
	nv->Precedent=NULL;
	return nv;
	

}
liste1 AjoutF(liste1 head,Livre data)
{
	liste1 nv=creer_noeud(data);
	if(nv!=NULL)
	{
		if(head==NULL)
		{
			head=nv;
		}
		else {
			liste1 temp=head;
			while(temp->suivant!=NULL)
			{
				temp=temp->suivant;
			}
			temp->suivant=nv;
			nv->Precedent=temp;
		}
	}
	return head;
}
liste1 AjoutD(liste1 head,Livre data)
{
	liste1 nv=creer_noeud(data);
	if(nv!=NULL)
	{
		if(head==NULL)
		{
			head=nv;
		}
		else {
			nv->suivant=head;
			head->Precedent=nv;
			head=nv;
			
		}
	}
	return head;
}

liste1 AjoutLivre(liste1 head,Livre data)
{
	if(data.type==0)
	{
		head=AjoutD(head,data);
	}
	else {
		head=AjoutF(head,data);
	}
	return head;
}
liste1 AjoutTri(liste1 head,Livre data)
{
	liste1 nv=creer_noeud(data);
 	if(nv!=NULL)
 	{
 		if(head==NULL)
 		{
 			head=nv;
		 }
		 else if(head->data1.prix>nv->data1.prix)
		 {
		 	nv->suivant=head;
		 	head->Precedent=nv;
		 	head=nv;
		 }
		 else {
		 		liste1 temp=head;
		 		while(temp->suivant!=NULL && nv->data1.prix > temp->data1.prix)
		 		{
		 			temp=temp->suivant;
			 	}
			 	if(temp->suivant==NULL && nv->data1.prix>temp->data1.prix)
			 	{
			 			temp->Precedent->suivant=nv;
				 }
			 	nv->Precedent=temp->Precedent;
			    nv->suivant=temp;
			 
		 }
	 }
	 return head;
}
void afficher(liste1 head)
{
	liste1 temp=head;
	int count=0;
	while(temp!=NULL)
	{
		printf("===========Livre %d===========\n",count+1);
		printf("titre:%s\n",temp->data1.titre);
		printf("reference:%s\n",temp->data1.references);
		printf("Prix:%f\n",temp->data1.prix);
		printf("type:%d\n",temp->data1.type);
		count++;
		temp=temp->suivant;
	}
}
liste1 SupprimD(liste1 head)
{
	if(head!=NULL)
	{
		if(head->suivant==NULL)
		{
			free(head);
			head=NULL;
		}
		else  {
			liste1 temp=head;
			head=head->suivant;
			free(temp);
			head->Precedent=NULL;
		}
	}
	return head;
}
liste1 SupprimF(liste1 head)
{
	if(head!=NULL)
	{
		if(head->suivant==NULL)
		{
			free(head);
			head=NULL;
		}
		else {
			liste1 temp=head;
			while(temp->suivant!=NULL)
			{
				temp=temp->suivant;
			}
			temp->Precedent->suivant=NULL;
			free(temp);
		}
	}
	return head;
}

liste1 Supprim(liste1 head)
{
	if(head==NULL)
	{
		printf("la liste est vide \n");
		exit(01);
	}
	else {
		liste1 temp=head;
		while(temp!=NULL)
		{
			if(temp->data1.prix<250)
			{
				if(temp==head)
				{
				    head=SupprimD(head);
				}
				else {
					if(temp->suivant!=NULL)
					{
							temp->suivant->Precedent=temp->Precedent;
					}
					temp->Precedent->suivant=temp->suivant;
					free(temp);
					
				}
			}
			temp=temp->suivant;
		}
	}
	return head;
}
int nbr_livre(liste1 head)
{
	int count=0;
	liste1 temp=head;
	while(temp!=NULL)
	{
		if(temp->data1.prix>250)
		{
			count++;
		}
		temp=temp->suivant;
	}
	return count;
}
main()
{
	liste1 head=NULL;
	Livre data;
	int i;
	for(i=0;i<4;i++)
	{
	printf("\033[34m ==========================INSERER LIVRE==========================\033[0m\n");
	printf("Entrer le nom du livre : \n");
	scanf("%s",data.titre);
	printf("Entrer la reference du livre : \n");
	scanf("%s",data.references);
	printf("Entrer le prix du livre : \n");
	scanf("%f",&data.prix);
	printf("Entrer la categorie du livre : \n");
	scanf("%d",&data.type);
	head=AjoutLivre(head,data);
	}
	afficher(head);
	printf("le nombre de livre dont le prix est superieure a 250dhs est :%d",nbr_livre(head));
	printf("\033[34m ==========================Suppression Debut de la LISTE ==========================\033[0m \n");
	head=SupprimD(head);
	afficher(head);
	printf("\033[34m ==========================SUPPRESSIOIN  FIN de la LISTE ==========================\033[0m \n");
	head=SupprimF(head);
	afficher(head);
	printf("\033[34m ==========================Suppression DANS LA LISTE Des livres dont le prix est inférieure a 250dhs==========================\033[0m \n");
	head=Supprim(head);
	afficher(head);
}*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Etudiant{
	char nom[100];
	char Cne[100];
	char cycle;
	int nbr_absence;
	float notes[5];
}Etudiant;
typedef struct Noeud {
	Etudiant data;
	struct Noeud *suivant;
	struct Noeud *precedent;
}Noeud;
typedef Noeud* liste;

liste creer_noeud(Etudiant data)
{
	liste nv=(liste)malloc(sizeof(Noeud));
	if(nv==NULL)
	{
		printf("\n erreur d'allocation dynamique\n");
		exit(01);
	}
	nv->data=data;
	nv->suivant=NULL;
	nv->precedent=NULL;
	return nv;
}
liste AjoutFin(liste head,Etudiant data)
{
	liste nv=creer_noeud(data);
	if(nv!=NULL)
	{
		if(head==NULL)
		{
			head=nv;
		}
		else {
			liste temp=head;
			while(temp->suivant!=NULL)
			{
				temp=temp->suivant;
			}
			temp->suivant=nv;
			nv->precedent=temp;
		}
	}
	return head;
	
}
liste AjoutD(liste head,Etudiant data)
{
	liste nv=creer_noeud(data);
	if(nv!=NULL)
	{
		if(head==NULL)
		{
			head=nv;
		}
		else {
				nv->suivant=head;
				head->precedent=nv;
				head=nv;
		}
	}
	return head;
	
}
liste Supprim(liste head,const char *cne)
{
	if(head!=NULL)
	{
		liste temp=head;
		while(temp!=NULL && strcmp(temp->data.Cne,cne)!=0)
		{
			temp=temp->suivant;
		}
		if(temp!=NULL)
		{
		   	if(temp->suivant==NULL && head->suivant==NULL)
		   	{
		   		free(head);
		   		head=NULL;
		   		
			 }
			else if(temp->suivant==NULL && head->suivant!=NULL)
			{
				temp->precedent->suivant=NULL;
				free(temp);
			}
			else {
				temp->precedent->suivant=temp->suivant;
				temp->suivant->precedent=temp->precedent;
			}
		}
		else {
			printf("\n le cne n'existe pas dans la base de données \n");
		}
	
	}
	return head;
}
void afficher(liste head)
{
	liste temp=head;
	int count=0;
	int count1=0;
	while(temp!=NULL)
	{
		printf("nom de l'étudiant %d : %s\n cne:%s\n cycle:%c nombre d'heure d'absence :%d\t",count++,temp->data.nom,temp->data.Cne,temp->data.cycle,temp->data.nbr_absence);
		while(count1<5)
		{
			printf("note %d :%d\t",temp->data.notes[count1]);
			count1++;
		}
		printf("\n");
		count++;
		temp=temp->suivant;
	}
}
int nbr_totale_absence(liste head)
{
	int compteur=0;
	liste temp=head;
	while(temp!=NULL)
	{
		if(temp->data.cycle=='I')
		{
			 compteur+=temp->data.nbr_absence;
		}
		temp=temp->suivant;
	}
	return compteur;
}
/*liste Inverser_liste(liste head)
{
	liste temp=head,reserve=NULL;
	while(temp->suivant!=NULL)
	{
		temp=temp->suivant;
	}
	while(temp!=NULL)
	{
		reserve=temp->precedent;
		temp->precedent=temp->suivant;
		temp->suivant=reserve;
		temp = temp->precedent;
	}
	return reserve;
}*/
liste Inverser_liste(liste head)
{
    if (head == NULL) return NULL; // Cas de liste vide

    liste temp = head, reserve = NULL;
    
    // Aller jusqu'au dernier élément
    while (temp->suivant != NULL)
    {
        temp = temp->suivant;
    }

    // Inversion des pointeurs
    while (temp != NULL)
    {
        reserve = temp->precedent;
        temp->precedent = temp->suivant;
        temp->suivant = reserve;
        
        // Avancer vers le précédent (qui devient le suivant)
        temp = temp->precedent;
    }

    // La nouvelle tête est l'ancien dernier élément
    return reserve;
}

main()
{
	liste head=NULL;
	Etudiant data;
	int count,count1;
	for(count1=0;count1<2;count1++)
	{
			printf("===============Informations Etudiant===============\n");
	printf("Entrer le nom de l'étudiant %d: \n",count1+1);
	scanf("%s",data.nom);
	printf("Entrer le cne de l'étudiant %s: \n",data.nom);
	scanf("%s",data.Cne);	
	printf("Entrer le cycle : \n");
	scanf(" %c",&data.cycle);
	printf("Entrer le nombre d'heure d'absence d'heure : \n");
	scanf("%d",&data.nbr_absence);
	printf("Entrer les  notes  \n");
	for(count=0;count<5;count++)
	{
		printf("note %d : \n",count+1);
		scanf("%f",&data.notes[count]);
	}
	 head=AjoutD(head,data);

	}
	afficher(head);
	printf("\nle nombre d'heures d'absence  pour le site préparatoire est :%d\n",nbr_totale_absence(head));
	printf("\n===============afficher la liste inversé===============\n");
	head=Inverser_liste(head);
	afficher(head);
	
}




