//MEHDAOUI BRAHIM - 2AP3
//ELMEHDI BELMOKHTAR - 2AP3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct {
	//identifiant
	char Id[50];
	//mot de passe
	char PASSWORD[50];
	
}Utilisateur;

Utilisateur Ajout_utilisateur (char ch1[50],char ch2[50])
{  
	Utilisateur UTL;

	//ajout de l'utilisateur
	strcpy(UTL.Id,ch1);
	strcpy(UTL.PASSWORD,ch2);

	
	return UTL;

}

int LOGIN (char ch1[50],char ch2[50],Utilisateur *p,int i)
{

	int a;

	if(strcmp(ch1,p[0].Id)==0 && strcmp(ch2,p[0].PASSWORD)==0)
	return 0;
	
	else
	{  
	    for(a=1;a<=i;a++)
	    { 
	       if(strcmp(ch1,p[a].Id)==0  && strcmp(ch2,p[a].PASSWORD)==0 )
	         return 1; 

		}
		return 2;
	}}

int Chercher_position (char ch[50], Utilisateur *p,int a)
{ 
    int i;
    
	for(i=0;i<a;i++)
	{
	     if(strcmp(ch,p[i].Id)==0)
	     return i;	
	}
}

Utilisateur changement_password(char ch1[50],char ch2[50])
{
	Utilisateur UTL;
	
	strcpy(UTL.Id,ch1);
	strcpy(UTL.PASSWORD,ch2);
	
	return UTL;
}

Utilisateur* Suppression (int a,Utilisateur *p,int n)
{  int i;

	Utilisateur *pt;
	pt=(Utilisateur*)malloc(20*sizeof(Utilisateur));
	pt=p;
	
	
	for(i=a;i<n-1;i++)
	pt[i]=pt[i+1];

    return pt;
	
}

main()
{

	char ch1[50],ch2[50];
	int i=0,a,ch,pos,j,x,q;
	bool Admin;
	//tableau d'utilisateur
	Utilisateur tab[20],*p;
	p=(Utilisateur*)malloc(20*sizeof(Utilisateur));
    p=tab;
	
	printf("\t\t\t\t ********* BOUNJOUR ********* \t\t\t\t\n");
	
    printf("Pour commencer veuillez entrer votre compte ADMIN afin de configurer le system \n");
    printf("Username:");
    gets(ch1);
    printf("Password:");
    gets(ch2);
    printf("\t\t\t\t\t\t\t\t ------------SUCCES \n");
    
    tab[i]=Ajout_utilisateur (ch1,ch2);
    i++;
do{x=0;

    system("cls"); 
    printf("**************** LOGIN ****************\n");
    printf("Username:");
    fflush(stdin);
    gets(ch1);
    printf("Password:");
    fflush(stdin);
    gets(ch2);
    a=LOGIN (ch1,ch2,p,i);
    printf("\t\t\t\t\t\t\t\t ------------SUCCES \n");
    
do{   switch(a)
    {
    	case 0: {  
    	system("cls");
    Admin=true;
    printf("\nWELCOME (ADMIN) \n");
    printf("\t\t\t\t ************************* \t\t\t\t\n");
    printf("\t\t\t\t *                       * \t\t\t\t\n");
    printf("\t\t\t\t *          MENU         * \t\t\t\t\n");
    printf("\t\t\t\t *                       * \t\t\t\t\n");
    printf("\t\t\t\t ************************* \t\t\t\t\n");
    

    printf("1-Ajouter un utilisateur \n");
    printf("2-Supprimer un utilisateur \n");
    printf("3-changer votre mot de passe \n");
    printf("4-changer le mot de passe d'un utilisateur \n");
    printf("5-Afficher la liste des utilisateurs \n");
    printf("6-LOGOUT \n");
    
    printf("entrer votre choix: ");
    scanf("%d",&ch);
    
			break;
		}
    	case 1: { 
		system("cls"); 
    Admin=false;
    printf("\nWELCOME (USER) \n");
    printf("\t\t\t\t ************************* \t\t\t\t\n");
    printf("\t\t\t\t *                       * \t\t\t\t\n");
    printf("\t\t\t\t *          MENU         * \t\t\t\t\n");
    printf("\t\t\t\t *                       * \t\t\t\t\n");
    printf("\t\t\t\t ************************* \t\t\t\t\n");
    

    printf("1-changer votre mot de passe \n");
    printf("2-Afficher la liste des utilisateurs \n");
    printf("3-LOGOUT \n");
    
    printf("entrer votre choix: ");
    scanf("%d",&ch);
    
			break;
		}
	case 2: {
		printf("Vos coordonnees sont erronees\n");
		x=1;
		break;
	}
	}
	
if (Admin==true)
{
	switch(ch)
	{
		case 1: {j=0;system("cls");
	printf("entrer les coordonnes d'utilisateur a ajouter \n");
    printf("Username:");
    fflush(stdin);
    gets(ch1);
	for(j=0;j<=i;j++)
	    { 
	       if(strcmp(ch1,p[j].Id)==0)
	         {printf("**** l'identifiant deja existe \n");j=1;break;
	    }}
	if(j!=1){
    printf("Password:");
    fflush(stdin);
    gets(ch2);
    tab[i]=Ajout_utilisateur (ch1,ch2);
    i++;
    printf("\t\t\t\t\t\t\t\t ------------SUCCES \n");}
   
    
		break;}
		
	case 2:{system("cls");
	printf("entrer l'identifiant d'utilisateur \n");
    printf("Username:");
    fflush(stdin);
    gets(ch1);
    q=0;
    	for(j=1;j<=i;j++)
	    { 
	       if(strcmp(ch1,p[j].Id)==0)
	         q=1;
       }
    if(q==0)
    {
    	printf("**** l'utilisateur n'existe pas \n");
    	break;
	}
    pos=Chercher_position(ch1,p,i);
    p=Suppression (pos,p,i);
    i--;
    printf("\t\t\t\t\t\t\t\t ------------SUCCES \n");
		break;
	}
	
	case 3:{system("cls");
	printf("entrer votre nouveau mot de passe:");
	fflush(stdin);
    gets(ch2);
    tab[0]=changement_password(tab[0].Id,ch2);
    printf("\t\t\t\t\t\t\t\t ------------SUCCES \n");
		break;
	}
		
	case 4:{system("cls");
	printf("entrer l'identifiant d'utilisateur \n");
    printf("Username:");
    fflush(stdin);
    gets(ch1);
        q=0;
    	for(j=1;j<=i;j++)
	    { 
	       if(strcmp(ch1,p[j].Id)==0)
	         q=1;
       }
    if(q==0)
    {
    	printf("**** l'utilisateur n'existe pas \n");
    	break;
	}
    pos=Chercher_position(ch1,p,i);
    printf("new Password:");
    fflush(stdin);
    gets(ch2);
    tab[pos]=changement_password(ch1,ch2);
    printf("\t\t\t\t\t\t\t\t ------------SUCCES \n");
		break;
	}
	
	case 5:{system("cls");
	printf("\n**LISTE D'UTILISATEURS: \n");
	for(j=0;j<i;j++)
	printf(" -%s \n",tab[j].Id);
		break;
	}
	
	case 6: {
		printf("\t\t ----AUREVOIR---\n");
		x=1;
		break;
	}
	
	default: printf("\n\n\t !! ERREUR DE CHOIX . REESSAYEZ !!\n\n");
	}
}

else if (Admin==false)
{
	switch(ch)
	{
		case 1:{system("cls");
	printf("entrer votre nouveau mot de passe:");
	fflush(stdin);
    gets(ch2);
    pos=Chercher_position(ch1,p,i);
    tab[pos]=changement_password(tab[pos].Id,ch2);
    printf("\t\t\t\t\t\t\t\t ------------SUCCES \n");
		break;
	     }
	     
    case 2:{system("cls");
	printf("\n**LISTE D'UTILISATEURS: \n");
	for(j=0;j<i;j++)
	printf(" -%s \n",tab[j].Id);
		break;
	}
	
	case 3: {system("cls");
		printf("\t\t ----AUREVOIR---\n");
		x=1;break;
	}
	
	default: printf("\n\n\t !! ERREUR DE CHOIX . REESSAYEZ !!\n\n");
	}
}

 }while(1 && x!=1);  
 
}while(x==1);
 
}






