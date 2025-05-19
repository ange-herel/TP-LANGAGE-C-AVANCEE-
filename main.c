#include<stdio.h>
#include<stdlib.h>
#include<direct.h>
#include<string.h>
#include<time.h>
/*typedef struct Maladie{
    char nom_maladie[100];
    char symptome[100];
    int dangerosite;

    char traitements[100];
}Maladie;
typedef struct Departements
{
    char nomdepartements[100];
}Departements;
typedef  struct Patient {
    char nom_patient[100];
    char ID[100];
    int age ;
    Maladie data;
    char status[100];
    char chambre[100];
    char nom_hopital[100];
}Patient;
typedef struct Hopital
{
    char nom_hopital[100];
    char adresse[100];
    char numero_telephone[100];
    char email[100];
    Departements departements[100];
    int nombretotaldelits;
    char horaireouverture[3];
    Patient data_patient;

}Hopital;

typedef struct Hopitaux{
    Hopital data;
    struct Hopitaux *suivant;
    struct Hopitaux *precedent;
}Hopitaux;
typedef Hopitaux* liste;
liste  creer_hopital()
{

    char nomtemporaire[100]="HOPITAL";
    char chemin[100]="C:/Users/User/Desktop/nouveaudossier/nouveau/";
    liste data1=(liste )malloc(sizeof(Hopitaux));
    if(data1==NULL)
    {
        printf("erreur d'allocation dynamique \n");
        exit(01);
    }
    printf("\n===========Saisie information hopital===========\n");
    printf("1-nom_hopital:\n");
    scanf("%s",data1->data.nom_hopital);
    printf("2-adresse_hopital:\n");
    scanf("%s",data1->data.adresse);
    printf("3-numero de telephone de l'hopital:\n");
    scanf("%s",data1->data.numero_telephone);
    /*printf("4-les départements de l'hopital:\n");
    scanf("%s",data->data.departements.nomdepartements);
    printf("5-nombre de lits totale hopital:\n");
    scanf("%d",&data1->data.nombretotaldelits);
    printf("6-horaireouverture de l'hopital:\n");
    scanf("%s",data1->data.horaireouverture);
    data1->suivant=NULL;
    data1->precedent=NULL;
     FILE *rp1=fopen("nom_hopitaux.txt","a+");
    fprintf(rp1 ,"%s\n",data1->data.nom_hopital);
    fclose(rp1);
    strcat(nomtemporaire,data1->data.nom_hopital);
     if (_mkdir(nomtemporaire) == 0)
     {
             printf("Dossier créé avec succès.\n");
     }
    else
    {
         perror("Erreur lors de la création du dossier");
    }

    strcat(chemin,nomtemporaire);
    strcat(chemin,"/");
    FILE *tp=fopen("chemin.txt","a+");
    fprintf(tp,"\n %s ",chemin);
    fclose(tp);
    strcat(chemin,nomtemporaire);
    strcat (chemin,".txt");
    FILE *fp=fopen(chemin,"a+");
    fprintf(fp,"\n nom_hopital :%s \t adresse : %s\t numero_de_telephone:%s \t nombre de lits : %d\t horaire d'ouverture :%s",data1->data.nom_hopital,data1->data.adresse,data1->data.numero_telephone,data1->data.nombretotaldelits,data1->data.horaireouverture);
    fclose(fp);
    return data1;

}
liste Ajout_debut_hopitaux(liste head)
{
    liste new_element=creer_hopital();
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

liste Ajout_Fin_hopitaux(liste head)
{
    liste new_element=creer_hopital();

    if(head==NULL)
     {
         head=new_element;
     }
    else {
        liste temp=head;
        while (temp->suivant !=NULL)
        {
            temp=temp->suivant;
        }
        temp->suivant=new_element;
        new_element->precedent=temp;
    }
    return head;
}
void afficherhopital(liste head)
{
    liste temp=head;
    while(temp!=NULL)
    {        printf("nom_hopital:%s\t adresse hopital :%s\t numero de telephone de l'hopital:%s\t nombre de lits totale hopital:%d\t horaireouverture de l'hopital:%s\n",temp->data.nom_hopital,temp->data.adresse,temp->data.numero_telephone,temp->data.nombretotaldelits,temp->data.horaireouverture);
         temp=temp->suivant;
    }
}
Patient creer_patient()
{
     Patient data1;
    if(data1==NULL)
     {
         printf("erreur d'allocation dynamique\n");
         exit(01);
     }
     printf("entrer le nom du patient : \n");
     scanf("%s",data1.nom_patient);
     printf("entrer l'ID du patient : \n ");
     scanf("%s",data1.ID);
     printf("entrer l'age du patient : \n");
     scanf("%d",&data1.age);
     printf("entrer le statut du patient : \n");
     scanf("%s",data1.status);
     if(strcmp(data1.status,"Malade")!=0)
     {
         strcpy(data1.data.nom_maladie,"aucune");
         strcpy(data1.data.symptome,"aucune");
         strcpy(data1.data.traitements,"aucune");
         data1.data.dangerosite=0;
     }
     else {
        printf("entrer le nom de la maladie du patient : \n");
        scanf("%s",data1.data.nom_maladie);
        printf("entrer les symptome du patient : \n");
        scanf("%s",data1.data.symptome);
        printf("entrer le traitements du patient : \n");
        scanf("%s",data1.data.traitements);
        printf("entrer la dangérosité de la maladie selon l'échelle croissant : \n");
        scanf("%d",&data1.data.dangerosite);
     }
     printf("entrer l'hopital(nom_hopital) auquel est affecté le patient : \n");
     scanf("%s",data1.nom_hopital);
     return data1;
}
liste affectation_patient_hopital(liste head)
{
    liste temp=head;
    Patient data=creer_patient();
    char chemin[100];
     char nom[100]="HOPITAL";
    while(temp!=NULL && strcmp(temp->data.nom_hopital,data.nom_hopital)!=0)
    {
        temp=temp->suivant;
    }
    if(temp==NULL)
    {
        printf("hopital entrer par le  patient n'existe pas dans la base de donnee ");
        return NULL;
    }
    else {
          strcpy(temp->data.data_patient.nom_patient,data.nom_hopital);
          strcpy(temp->data.data_patient.nom_hopital,data.nom_patient);
        strcpy(temp->data.data_patient.status,data.status);
         strcpy(temp->data.data_patient.ID,data.ID);
        strcpy(temp->data.data_patient.data.nom_maladie,data.data.nom_maladie);
          strcpy(temp->data.data_patient.data.symptome,data.data.symptome);
          strcpy(temp->data.data_patient.data.traitements,data.data.traitements);
          temp->data.data_patient.data.dangerosite=data.data.dangerosite;
    }
    strcat(nom,data.nom_hopital);
    FILE *fp=fopen("chemin.txt","r");
    while(fscanf(fp,"%s",chemin)!=EOF )
    {
        if(strstr(chemin,nom)!=NULL)
        {
            strcat(chemin,data.nom_patient);
            strcat(chemin,".txt");
            FILE *fp_patient=fopen(chemin,"w+");
            fprintf(fp_patient ,"nom_patient :%s \t  ID: %s\t Status : %s\t nom_maladie: %s\t symptome :%s\t traitements :%s\t dangérosité maladie :%d\t",data.nom_patient,data.ID,data.data.nom_maladie,data.data.symptome,data.data.traitements,data.data.dangerosite);
            fclose(fp_patient);
            break;
        }
    }

    return head;
}
int menuGestionMaladie()
{
     int choix;
     printf("\n==========MENU Principale GESTION HOSPITALIERE===========\n");
     printf("1-AJOUT DEBUT LISTE  HOPITAL :\n");
      printf("2-creer_patient : \n");
     printf("3-AJOUT FIN LISTE HOPITAL: \n");
     printf("2-creer_patient : \n");
     printf("3-Creer maladie : \n");
     printf("3-QUITTER");
     printf("saisir votre choix ");
     scanf("%d",&choix);
     return choix;
}

int menu()
{
    int choix;

    printf("\n==========MENU Principale===========\n");
    printf("1-GESTION DES MALADIES:\n");
    printf("2- GESTION HOPITAUX: \n");
    printf("3-Quitter");
    printf("saisir votre choix: \n");
    scanf("%d",&choix);
}
int main()
{
      liste head_hopitaux=NULL;
      e:
      int choix=menu();
      system("cls");
      switch(choix)
      {
          case 1:
              choix=menuGestionMaladie();
              system("cls");
              switch(choix)
              {
                  case 1:   head_hopitaux=Ajout_debut_hopitaux(head_hopitaux);
                            afficherhopital(head_hopitaux);
                            goto e;
                    break;
                  case 2:    head_hopitaux=Ajout_FIN_hopitaux();
                             afficherhopital(head_hopitaux);
                              break;
                              head_hopitaux=affectation_patient_hopital(head_hopitaux);
                              afficherhopital(head_hopitaux);
                    break;
              }
              break;


      }
return 0;

}*/
typedef struct Maladie{//pile
    char nom_maladie[100];
    char symptome[100];
    int dangerosite;
    char traitements[100];
    struct Maladie *suivant;
}Maladie;
typedef Maladie* liste_maladie;
typedef struct patient{//file
    char nom_patient[100];
    char ID[100];
    int age ;
    Maladie data;
    char status[100];
    char chambre[100];
    char nom_hopital[100];
    struct patient *suivant;
}patient;
typedef patient *liste_patient;
typedef struct hopital{//liste doublement chainee
    char nom_hopital[100];
    char adresse[100];
    char numero_telephone[100];
    char email[100];
    char nomdepartements[100];
    int nombretotaldelits;
    char horaireouverture[3];
    liste_patient headpatienthopital;
    liste_maladie headMaladiehopital;
    //liste_patient patienthopital;
    //liste_maladie Maladiehopital;
    struct hopital *suivant;
    struct hopital *precedent;
}hopital;
typedef hopital* liste;
liste  creer_hopital()
{

    char nomtemporaire[100]="HOPITAL";
    char chemin[100]="C:/Users/User/Desktop/nouveaudossier/nouveau/";
    char cheminpatient[100];
    liste data1=(liste )malloc(sizeof(hopital));
    if(data1==NULL)
    {
        printf("erreur d'allocation dynamique \n");
        exit(01);
    }
    printf("\n===========Saisie information hopital===========\n");
    printf("1-nom_hopital:\n");
    scanf("%s",data1->nom_hopital);
    printf("2-adresse_hopital:\n");
    scanf("%s",data1->adresse);
    printf("3-numero de telephone de l'hopital:\n");
    scanf("%s",data1->numero_telephone);
    printf("4-les départements de l'hopital:\n");
    scanf("%s",data1->nomdepartements);
    printf("5-nombre de lits totale hopital:\n");
    scanf("%d",&data1->nombretotaldelits);
    printf("6-horaireouverture de l'hopital:\n");
    scanf("%s",data1->horaireouverture);
    data1->suivant=NULL;
    data1->precedent=NULL;
    data1->headpatienthopital=NULL;
    data1->headMaladiehopital=NULL;
     FILE *rp1=fopen("nom_hopitaux.txt","a+");// va être utiliser lors de la création de la fonction hopital existant
    fprintf(rp1 ,"nom hopital:%s\n",data1->nom_hopital);
    fclose(rp1);
    strcat(nomtemporaire,data1->nom_hopital);// pour concatener le Hopital +nom_hopital
     if (_mkdir(nomtemporaire) == 0)
     {
             printf("\033[32;40m");
             printf("Dossier créé avec succès.\n");
             printf("\033[0m");
     }
    else
    {
         perror("Erreur lors de la création du dossier");//affiche une erreur systèmes
    }

    strcat(chemin,nomtemporaire);
    strcpy(cheminpatient,chemin);
    strcat(cheminpatient,"/");
    printf("chemin actuel : %s\n",cheminpatient);
   /* strcat(cheminpatient,"DOSSIER PATIENT");
    if (_mkdir(cheminpatient) == 0)
     {
             printf("Dossier PATIENT créé avec succès.\n");
     }
    else
    {
         perror("Erreur lors de la création du dossier PATIENT\n");
    }*/
    FILE *fichier1=fopen("chemindossierpatient.txt","a+");
    fprintf(fichier1,"\n %s ",cheminpatient);
    fclose(fichier1);
    FILE *tp=fopen("chemin.txt","a+");
    fprintf(tp,"\n %s ",chemin);
    fclose(tp);
    strcat(chemin,"/");
    strcat(chemin,nomtemporaire);
    strcat (chemin,".txt");
    FILE *fp=fopen(chemin,"a+");
    fprintf(fp,"\n nom_hopital :%s \t adresse : %s\t numero_de_telephone:%s \t nombre de lits : %d\t horaire d'ouverture :%s",data1->nom_hopital,data1->adresse,data1->numero_telephone,data1->nombretotaldelits,data1->horaireouverture);
    fclose(fp);
    strcat(chemin,"/");
    return data1;

}
liste Ajout_debut_hopitaux(liste head)
{
    liste new_element=creer_hopital();
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

liste Ajout_Fin_hopitaux(liste head)
{
    liste new_element=creer_hopital();
    if(head==NULL)
     {
         head=new_element;
     }
    else {
        liste temp=head;
        while (temp->suivant !=NULL)
        {
            temp=temp->suivant;
        }
        temp->suivant=new_element;
        new_element->precedent=temp;
    }
    return head;
}
liste Supprimerdebuthopital(liste head)
{
    if(head==NULL)
    {
        printf("liste vide\n");
        exit(01);
    }
    else if(head->suivant==NULL)
    {
        printf("liste vide \n");
        free(head);
        exit(01);
    }
    else {
           liste reserve=head;
           head=head->suivant;
           free(reserve);
           head->precedent=NULL;
           return head ;
      }


}
liste SupprimerFin(liste head)
{
    if(head==NULL)
    {
        printf("AUCUN HOPITAL DANS LES PARAGES\n");
        exit(01);
    }
    else {
        liste temp=head;
        while(temp->suivant!=NULL)
        {
           temp= temp->suivant;
        }
        temp->precedent->suivant=NULL;
        free(temp);
        return head;
    }

}




void creer_fichier_patient(const char *chemin_dossier_hopital, const patient *patient_info) {
    // Déclaration d'un tableau de caractères pour construire le chemin du fichier patient
    char chemin_fichier_patient[256];
    // Copie le chemin du dossier de l'hôpital dans la variable chemin_fichier_patient
    strcpy(chemin_fichier_patient, chemin_dossier_hopital);
    // Ajoute un séparateur de répertoire
    strcat(chemin_fichier_patient, "/");
    // Concatène l'ID du patient au chemin pour former le nom du fichier
    strcat(chemin_fichier_patient, patient_info->ID);
    // Ajoute l'extension ".txt" au nom du fichier
    strcat(chemin_fichier_patient, ".txt");

    // Ouvre le fichier en mode écriture ("w+"). Si le fichier n'existe pas, il est créé.
    // Si le fichier existe, son contenu est écrasé.
    FILE *fp_patient = fopen(chemin_fichier_patient, "w+");
    // Vérifie si l'ouverture du fichier a réussi
    if (fp_patient == NULL) {
        // Affiche un message d'erreur si l'ouverture a échoué
        perror("Erreur lors de la création/ouverture du fichier patient");
        return; // Quitte la fonction en cas d'erreur
    }

    // Écrit les informations du patient dans le fichier
    fprintf(fp_patient, "Nom du patient: %s\n", patient_info->nom_patient);
    fprintf(fp_patient, "ID: %s\n", patient_info->ID);
    fprintf(fp_patient, "Âge: %d\n", patient_info->age);
    fprintf(fp_patient, "Statut: %s\n", patient_info->status);
    fprintf(fp_patient, "Chambre: %s\n", patient_info->chambre);
    fprintf(fp_patient, "Nom de l'hôpital: %s\n", patient_info->nom_hopital);

    // Écrit les informations sur la maladie si le patient est malade
    if (strcmp(patient_info->status, "Malade") == 0) {
        fprintf(fp_patient, "\n--- Informations sur la maladie ---\n");
        fprintf(fp_patient, "Nom de la maladie: %s\n", patient_info->data.nom_maladie);
        fprintf(fp_patient, "Symptômes: %s\n", patient_info->data.symptome);
        fprintf(fp_patient, "Traitements: %s\n", patient_info->data.traitements);
        fprintf(fp_patient, "Niveau de dangerosité: %d\n", patient_info->data.dangerosite);
    }

    // Ferme le fichier pour enregistrer les modifications
    fclose(fp_patient);
    // Affiche un message indiquant que le fichier a été créé avec succès
    printf("Fichier patient créé pour l'ID: %s dans le dossier de l'hôpital.\n", patient_info->ID);
}

// Fonction pour ajouter à chaque dossier de chaque hôpital les fichiers de ses patients
void ajouter_fichiers_patients_hopitaux(liste head) {
    // Vérifie si la liste des hôpitaux est vide
    if (head == NULL) {
        printf("Aucun hôpital existant.\n");
        return; // Quitte la fonction si aucun hôpital n'est présent
    }

    // Déclare un pointeur temporaire pour parcourir la liste des hôpitaux
    liste hopital_actuel = head;
    // Déclare un pointeur temporaire pour parcourir la liste des patients de l'hôpital actuel
    liste_patient patient_actuel;
    // Déclare un tableau de caractères pour stocker le chemin du dossier de l'hôpital
    char chemin_dossier_hopital[256];
    // Déclare un tableau de caractères temporaire pour construire le nom du dossier
    char nom_dossier_temporaire[150] = "HOPITAL";

    // Parcours la liste de tous les hôpitaux
    while (hopital_actuel != NULL) {
        // Reconstruit le nom du dossier de l'hôpital pour chaque hôpital
        strcpy(nom_dossier_temporaire, "HOPITAL");
        strcat(nom_dossier_temporaire, hopital_actuel->nom_hopital);

        // Construit le chemin complet du dossier de l'hôpital
        strcpy(chemin_dossier_hopital, "C:/Users/User/Desktop/nouveaudossier/nouveau/");
        strcat(chemin_dossier_hopital, nom_dossier_temporaire);

        // Parcours la liste des patients de l'hôpital actuel
        patient_actuel = hopital_actuel->headpatienthopital;
        while (patient_actuel != NULL) {
            // Appelle la fonction pour créer le fichier du patient dans le dossier de l'hôpital actuel
            creer_fichier_patient(chemin_dossier_hopital, patient_actuel);
            // Passe au patient suivant dans la liste
            patient_actuel = patient_actuel->suivant;
        }
        // Passe à l'hôpital suivant dans la liste
        hopital_actuel = hopital_actuel->suivant;
    }
    printf("Fichiers des patients créés dans les dossiers de chaque hôpital.\n");
}













liste AjouterpatientFin(liste head,const char* nom_hopital)
{
     char ligne[100],reserve1[100]="HOPITAL";
    if(head==NULL)
    {
        printf("\n hopital inexistant \n");
        exit(01);
    }
    else {
         liste temp=head;
         while(temp->suivant!=NULL && strcmp(temp->nom_hopital,nom_hopital)!=0){
            temp=temp->suivant;
         }
         liste_patient nouveaupatient=(liste_patient)malloc(sizeof(patient));
         if(nouveaupatient==NULL)
         {

             printf("erreur d'allocation dynamique \n");
         }
    else {


                     printf("entrer le nom du patient : \n");
                     scanf("%s",nouveaupatient->nom_patient);
                     printf("entrer l'ID du patient : \n ");
                     scanf("%s",nouveaupatient->ID);
                     printf("entrer l'age du patient : \n");
                     scanf("%d",&nouveaupatient->age);
                     printf("entrer le statut du patient : \n");
                     scanf("%s",nouveaupatient->status);
                    /* printf("entrer le nom de la maladie du patient : \n");
                    scanf("%s",nouveaupatient->data.nom_maladie);
                    printf("entrer les symptome du patient : \n");
                    scanf("%s",nouveaupatient->data.symptome);
                    printf("entrer le traitements du patient : \n");
                    scanf("%s",nouveaupatient->data.traitements);
                    printf("entrer la dangérosité de la maladie selon l'échelle croissant : \n");
                    scanf("%d",&nouveaupatient->data.dangerosite);*/
                    if(strcmp(nouveaupatient->status,"Visitant")==0)
                    {
                        strcpy(nouveaupatient->data.nom_maladie,"aucune");
                        strcpy(nouveaupatient->data.symptome,"aucune");
                        strcpy(nouveaupatient->data.traitements,"aucune");
                        nouveaupatient->data.dangerosite=0;
                     }
                    else {
                                printf("entrer le nom de la maladie du patient : \n");
                                scanf("%s",nouveaupatient->data.nom_maladie);
                                printf("entrer les symptome du patient : \n");
                                scanf("%s",nouveaupatient->data.symptome);
                                printf("entrer le traitements du patient : \n");
                                scanf("%s",nouveaupatient->data.traitements);
                                printf("entrer la dangérosité de la maladie selon l'échelle croissant : \n");
                                scanf("%d",&nouveaupatient->data.dangerosite);
                                liste_maladie maladie1=(liste_maladie)malloc(sizeof(Maladie));
                                if(maladie1==NULL)
                                {
                                    printf("erreur d'allocation dynamique \n");
                                }
                                else {
                                      strcpy(maladie1->nom_maladie,nouveaupatient->data.nom_maladie);
                                      strcpy(maladie1->symptome,nouveaupatient->data.symptome);
                                      strcpy(maladie1->traitements,nouveaupatient->data.traitements);
                                      maladie1->dangerosite=nouveaupatient->data.dangerosite;
                                }

                                maladie1->suivant=NULL;
                                if(temp->headMaladiehopital==NULL)
                                {
                                    temp->headMaladiehopital=maladie1;
                                }
                                else {
                                       maladie1->suivant=temp->headMaladiehopital;
                                       temp->headMaladiehopital=maladie1;
                                }
                     }
                     nouveaupatient->suivant=NULL;
               if(temp->headpatienthopital==NULL)
            {
                 temp->headpatienthopital=nouveaupatient;
              }
              else {

                     liste_patient parcours=temp->headpatienthopital;
                     while(parcours->suivant!=NULL)
                     {
                         parcours=parcours->suivant;
                     }
                     parcours->suivant=nouveaupatient;
                }



               /*FILE *p4=fopen("chemindossierpatient.txt","r");
               strcat(reserve1,nouveaupatient->nom_hopital);
               while(fgets(ligne,sizeof(ligne),p4))
               {
                   if(strstr(ligne,reserve1)!=NULL)
                   {
                        ligne[strcspn(ligne, "\n")] = '\0';
                        strcat(ligne,nouveaupatient->nom_patient);
                        strcat(ligne,".txt");
                        FILE *p5=fopen(ligne,"a+");
                        fprintf(p5,"nom du patient : %s \t age :%d\t statut:%s\t ID :%s \t symptome patient : %s\t nom de la maladie du patient :%s\tl'ID du patient :%s\tle traitements du patient : %s\t la dangérosité de la maladie selon l'échelle croissant :%d\n",nouveaupatient->nom_patient,nouveaupatient->age,nouveaupatient->ID,nouveaupatient->data.symptome,nouveaupatient->data.nom_maladie,nouveaupatient->data.traitements,nouveaupatient->data.dangerosite);
                        fclose(p5);
                        break;
                   }
               }
                fclose(p4);*/


         }


    }
    return head;

}

liste SupprimpatientFin(liste head)
{
    if(head==NULL)
    {
        printf("\n hopital inexistant \n");
        exit(01);
    }
    else {
                if(head->headpatienthopital==NULL)
                {
                    printf("AUCUN PATIENT EXISTANT\n");
                }
                else if (head->headpatienthopital->suivant==NULL)
                {
                    printf("PATIENT SUPPRIME");
                    free(head->headpatienthopital);
                }
                else {
                         liste_patient temp=head->headpatienthopital;
                         head->headpatienthopital=head->headpatienthopital->suivant;
                         free(temp);

                }
            }
    return head;

}
liste Supprim_maladieTOUTE(liste head)
{
     int test=0;
      if(head==NULL)
    {
        printf("\n hopital inexistant \n");
        exit(01);
    }
    else {
                liste_maladie temp;
                liste parcours=head;
                while(parcours!=NULL)
                {
                                    if(parcours->headMaladiehopital==NULL)
                    {
                            printf("AUCUNE MALADIE EXISTANT\n");
                    }
                        else if (parcours->headMaladiehopital->suivant==NULL)
                    {
                                printf("MALADIE SUPPRIME");
                                free(head->headMaladiehopital);
                                break;
                        }
                        else {

                                while(parcours->headMaladiehopital!=NULL)
                              {

                                temp=parcours->headMaladiehopital;
                                parcours->headMaladiehopital=parcours->headMaladiehopital->suivant;
                                free(temp);
                              }
                              parcours->headMaladiehopital=NULL;

                        }
                       parcours=parcours->suivant;
                }
            }
    return head;
}
liste trier_ordrecroissant_maladie(liste head)
{
    if(head==NULL)
    {
        printf("AUCUN HOPITAL EXISTANT POUR EFFECTUER CETTE TACHE\n");
    }
    else {
          liste_maladie temp1,temp2;
          liste parcours=head;
          Maladie reserve;
          while(parcours!=NULL)
          {
              temp1=parcours->headMaladiehopital;
              while(temp1->suivant!=NULL)
              {
                 temp2=temp1->suivant;
                  while(temp2!=NULL)
                  {
                      if(temp1->dangerosite > temp2->dangerosite)
                      {
                          strcpy(reserve.nom_maladie,temp1->nom_maladie);
                          strcpy(temp1->nom_maladie,temp2->nom_maladie);
                          strcpy(temp2->nom_maladie,reserve.nom_maladie);
                          strcpy(reserve.symptome,temp1->symptome);
                          strcpy(temp1->symptome,temp2->symptome);
                          strcpy(temp2->symptome,reserve.symptome);
                          strcpy(reserve.traitements,temp1->traitements);
                          strcpy(temp1->traitements,temp2->traitements);
                          strcpy(temp2->traitements,reserve.traitements);
                          reserve.dangerosite=temp1->dangerosite;
                          temp1->dangerosite=temp2->dangerosite;
                          temp2->dangerosite=reserve.dangerosite;
                      }
                      temp2=temp2->suivant;
                  }
                  temp1=temp1->suivant;
              }
              parcours=parcours->suivant;
          }
    }
    return head;
}
liste trier_ordredecroissant_maladie(liste head)
{
    if(head==NULL)
    {
        printf("AUCUN HOPITAL EXISTANT POUR EFFECTUER CETTE TACHE\n");
    }
    else {
          liste_maladie temp1,temp2;
          liste parcours=head;
          Maladie reserve;
          while(parcours!=NULL)
          {
              temp1=parcours->headMaladiehopital;
              while(temp1->suivant!=NULL)
              {
                 temp2=temp1->suivant;
                  while(temp2!=NULL)
                  {
                      if(temp1->dangerosite < temp2->dangerosite)
                      {
                          strcpy(reserve.nom_maladie,temp1->nom_maladie);
                          strcpy(temp1->nom_maladie,temp2->nom_maladie);
                          strcpy(temp2->nom_maladie,reserve.nom_maladie);
                          strcpy(reserve.symptome,temp1->symptome);
                          strcpy(temp1->symptome,temp2->symptome);
                          strcpy(temp2->symptome,reserve.symptome);
                          strcpy(reserve.traitements,temp1->traitements);
                          strcpy(temp1->traitements,temp2->traitements);
                          strcpy(temp2->traitements,reserve.traitements);
                          reserve.dangerosite=temp1->dangerosite;
                          temp1->dangerosite=temp2->dangerosite;
                          temp2->dangerosite=reserve.dangerosite;
                      }
                      temp2=temp2->suivant;
                  }
                  temp1=temp1->suivant;
              }
              parcours=parcours->suivant;
          }
    }
    return head;
}
void  Rechercher_Maladie(liste head,const char * nom_maladie)
{
      if(head==NULL)
      {
          printf("AUCUN HOPITAL EXISTANT\n");
          return ;
      }
      else {

              liste temp=head;
              liste_maladie temp1;
              int compteur=0;
              char reserve[100][100];
              while(temp!=NULL)
              {
                  temp1=temp->headMaladiehopital;
                  while(temp1!=NULL)
                  {
                      if(strcmp(temp1->nom_maladie,nom_maladie)==0)
                      {

                          strcpy(reserve[compteur],temp->nom_hopital);
                          compteur++;
                          break;
                      }
                      temp1=temp1->suivant;
                  }
                  temp=temp->suivant;
              }
                 printf("%s existe dans les hopitaux suivants :",nom_maladie);
                for(int i=0;i<compteur;i++)
            {
                printf("%s\t",reserve[i]);
                }
      }

}
void affichermaladieparhopitaux(liste head)
{
           liste temp=head;
           liste_maladie temp1;
           int compteur=0,compteur1=0;
              while(temp!=NULL)
    {

            printf("========================INFORMATION HOPITAL %d========================\n",compteur+1);
            temp1=temp->headMaladiehopital;
           while(temp1!=NULL)
            {
                printf("\n=========Maladie %d==========\n",compteur1+1);
                printf("nom de la maladie du patient :%s\n l'ID du patient :%s\n le traitements du patient : %s\n la dangérosité de la maladie selon l'échelle croissant :%d\n",temp1->nom_maladie,temp1->symptome,temp1->traitements,temp1->dangerosite);
                compteur1++;
                temp1=temp1->suivant;
            }
            compteur++;
            temp=temp->suivant;
    }
}
void afficherhopital2(liste head)
{
    liste temp=head;
    liste_patient temp1=head->headpatienthopital;
    while(temp!=NULL)
    {

       printf("nom_hopital:%s\n adresse hopital :%s\n numero de telephone de l'hopital:%s\n nombre de lits totale hopital:%d\n horaireouverture de l'hopital:%s\n",temp->nom_hopital,temp->adresse,temp->numero_telephone,temp->nombretotaldelits,temp->horaireouverture);
      temp=temp->suivant;
    }
}
void afficherpatient(liste head)
{
    liste temp=head;
    liste_patient temp1;
    while(temp!=NULL)
    {
           temp1=temp->headpatienthopital;

                while(temp1!=NULL)
            {
                printf("\n=========PATIENT==========\n");
                printf("\n nom du patient : %s\n age :%d\n status :%s\n",temp1->nom_patient,temp1->age,temp1->status);
                temp1=temp1->suivant;
            }
            temp=temp->suivant ;
    }
}
void afficherhopital(liste head)
{
    liste temp=head;
    liste_patient temp1=head->headpatienthopital;
    int compteur=0;
    while(temp!=NULL)
    {

            printf("========================INFORMATION HOPITAL %d========================\n",compteur+1);
            printf("nom_hopital:%s\n adresse hopital :%s\n numero de telephone de l'hopital:%s\n nombre de lits totale hopital:%d\n horaireouverture de l'hopital:%s\n",temp->nom_hopital,temp->adresse,temp->numero_telephone,temp->nombretotaldelits,temp->horaireouverture);
            temp1=temp->headpatienthopital;
            compteur++;
                while(temp1!=NULL)
            {
                printf("\n=========PATIENT==========\n");
                printf("\n nom du patient : %s\n age :%d\n status :%s\n",temp1->nom_patient,temp1->age,temp1->status);
                printf("nom de la maladie du patient :%s\n l'ID du patient :%s\n le traitements du patient : %s\n la dangérosité de la maladie selon l'échelle croissant :%d\n",temp1->data.nom_maladie,temp1->data.symptome,temp1->data.traitements,temp1->data.dangerosite);
                temp1=temp1->suivant;
            }
           temp=temp->suivant;
    }

}
int menuPatient()
{
    int choix;
    printf("\n=========MENU PATIENT==============\n");
    printf("\n 1-AJOUTER PATIENT HOPITAL(FIN file)\n");
    printf("\n 2-AFFICHER PATIENT HOPITAUX(info patient et hopitaux)");
    printf("\n 3-SUPPRIMER PATIENT HOPITAUX(suppression fin)\n");
    printf("entrer votre choix: \n");
    scanf("%d",&choix);
    return choix;
}

int menuMaladie()
{
    int choix;
    printf("\n=========MENU MALADIE==============\n");
    printf("\n 1-supprimer maladiehopital(Debut pile)\n");
    printf("\n 2-supprimer toutes les maladies des hopitaux");
    printf("\n 3-afficher maladie par hopitaux\n");
    printf("\n 4-TRI MALADIE\n");
    printf("\n 5-RECHERCHER MALADIE \n");
    printf("\n entrer votre choix: \n");
    scanf("%d",&choix);
    return choix;
}
int menuhopital()
{
    int choix;
   printf("\n=========MENU HOPITAL===========\n");
   printf("\n 1-AJOUTER DEBUT HOPITAL\n");
   printf("\n 2-AJOUTER FIN HOPITAL\n");
   printf("\n 3-AFFICHER HOPITAL (informations)\n");
   printf("\n 4-SUPPRIMER HOPITAL DEBUT\n");
   printf("\n 5-SUPPRIMER HOPITAL DEBUT\n");
   printf("entrer votre choix : \n");
   scanf("%d",&choix);
   return choix;
}
int menu()
{
    int choix;
    printf("\n=============MENU==================\n");
    printf("1-HOPITAL\n");
    printf("2-MALADIE\n");
    printf("3-PATIENT\n");
    printf("4-QUITTER");
    printf("\n entrer votre choix : \n");
    scanf("%d",&choix);
    return choix;
}

void main()
{

    liste head=NULL;
    int choix,choix1,choix3;
    char reserve[100];
    char choix2;
    e:
        sleep(2);
        system("cls");
        printf("\033[34m");
    choix=menu();
    switch(choix)
    {
       case 1:
             choix1=menuhopital();
             switch(choix1)
             {
                case 1:
                       head=Ajout_debut_hopitaux(head);
                   break;
                case 2:
                        head=Ajout_Fin_hopitaux(head);
                    break;
                case 3:
                      afficherhopital(head);
                      break;
                case 4:
                      head=Supprimerdebuthopital(head);
                      break;
                case 5:
                      head=Supprimerdebuthopital(head);
                      break;
             }
             goto e;
          break;
        case 2:
            choix2=menuMaladie();
            switch(choix2)
            {
                    case 1:
                           head=Supprim_maladieTOUTE(head);
                            break;
                    case 2:
                           head=Supprim_maladieTOUTE(head);
                          break;
                    case 3:
                          affichermaladieparhopitaux(head);
                        break;
                    case 4:
                          do {
                                printf("\n entrer votre choix de tri (C/D) : \n");
                                scanf(" %c",&choix2);
                                if(choix2!='C'|| choix2!='D')
                                {
                                    printf("erreur du choix de tri \n");
                                }
                          }while(choix2!='C'&& choix2!='D');
                           printf("\n entrer votre choix de tri (C/D) : \n");
                           scanf(" %c",&choix2);
                           if(choix2 == 'c')
                           {
                               head=trier_ordrecroissant_maladie(head);
                           }
                           else {
                                head=trier_ordredecroissant_maladie(head);
                           }
                        break;
                    case 5:
                           printf("\n entrer le nom de maladie que vous souhaiter rechercher: \n");
                           scanf("%s",reserve);
                           Rechercher_Maladie(head,reserve);
                           break;
            }
            goto e;
          break;
        case 3:
              choix3=menuPatient();
              switch(choix3)
              {
                case 1:
                    printf("\n entrer le nom de l'hopital auquel vous souhaitez ajoutez un patient : \n");
                    scanf("%s",reserve);
                    head=AjouterpatientFin(head,reserve);
                    ajouter_fichiers_patients_hopitaux(head);
                    break;
                case 2:
                      afficherpatient(head);
                     break;
                case 3:
                      head=SupprimpatientFin(head);
                     break;

              }
              goto e;
          break;
         case 4:
               printf("\n-----------FIN PROGRAMME------------\n");
               exit(01);
          break;


    }











    /*liste head=NULL;
    char nom_maladie[100];
    for(int i=0;i<2;i++)
    {
      head=Ajout_Fin_hopitaux(head);
    }
    afficherhopital2(head);
    for(int i=0;i<1;i++)
    {
        head=AjouterpatientFin(head,"TCHENGUE");
         ajouter_fichiers_patients_hopitaux(head);
    }
       for(int i=0;i<1;i++)
    {
        head=AjouterpatientFin(head,"BILLY");
        ajouter_fichiers_patients_hopitaux(head);
    }
    afficherhopital(head);
    printf("\n==========suppression hopital debut ===================\n");
    head=Supprimerdebuthopital(head);
    afficherhopital(head);
    printf("\n===========supprimer patient Fin =========================\n");
    head=SupprimpatientFin(head);
    afficherhopital(head);
    printf("\n ==================liste des maladies trier par ordre croissant=========================\n");
    head=trier_ordrecroissant_maladie(head);
    affichermaladieparhopitaux( head);
     printf("\n ==================liste des maladies trier par ordre decroissant=========================\n");
    head=trier_ordredecroissant_maladie(head);
    affichermaladieparhopitaux( head);
    printf("\n ====================RECHERCHER LES HOPITAUX QUI ONT UNE MALADIE PRECISES========================\n");
    printf("entrer le nom de la maladie a rechercher au sein des hopitaux: \n");
    scanf("%s",nom_maladie);
    Rechercher_Maladie(head,nom_maladie);
  /*  printf("\n============affichermaladieparhopitaux=================\n");
    affichermaladieparhopitaux(head);*/
   /* printf("\n\n==========SUPPRESSION TOUTE MALADIE====================\n");
    head=Supprim_maladieTOUTE(head);
    affichermaladieparhopitaux( head);*/
    /*printf("\n============affichermaladieparhopitaux=================\n");
    affichermaladieparhopitaux(head);*/

}
