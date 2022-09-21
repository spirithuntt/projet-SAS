#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
///*** DECLARATION DES VARIABLES ***
typedef struct
{
  char code_prdt[10];
  char nom_prdt[50];
  int quantity_prdt;
  float prix;
} SProduit;			// my normal struct
typedef struct			// struct for statistics
{
  
char nom_produit[10];
   
float prixTTc;
   
char date[10];
 
} Pproduit;

Pproduit st[100];		// tableau li and5l fih Pproduit
int z;				//size dyalou
float total;

static int i = 0;		//nomal index
static int j = 3;		// fin wassel index dyal tab dyali size dyalou
SProduit tab[100] = { 
    {"9898", "doliprane", 23, 635}, 
  {"gi813", "fewk", 23, 63}, 
{"1200", "fke", 23, 100}, 
};


int Nmbr_Produit;		//number of products that u want to enter for 2
int decision;			// list croissant ou decroissant les produit pour 3 et aussi chercher avec code ou bien quantity
char code_product[10];

int product_qnty;		// add or deduct quantity
///*** LES FONCTIONS ***
void menu ();

void Ajouter_Nv_Produit (int n);

 
void list_with_name ();

void list_with_price ();

void Acheter_produit (void);

void chercher (void);

void Etat_du_stock (void);

void Alimenter_le_stock ();

void Supprimer_un_produit (void);

void Statistique_de_vente (void);

 
///*** MENU ***
  void
menu () 
{
  
int Choix;			//1st choice
  int Nmbr_Produit;		//number of products that u want to enter for 2
  int decision;			// list croissant ou decroissant les produit pour 3 et aussi chercher avec code ou bien quantity
  char code_product[10];
  
int product_qnty;		// add or deduct quantity
  do
    {
      
printf
	("\n ------------------------------------------- MENU ----------------------------------------------------- \n\n");
      
printf (" 1 : Ajouter un nouveau produit \n");
      
printf (" 2 : Ajouter plusieurs nouveaux produits \n");
      
printf (" 3 : Lister tous les produits (Nom, prix, prix TTC) \n");
      
printf (" 4 : Acheter produit \n");	// produit deja tchra
      printf (" 5 : Rechercher les produits \n");
      
printf (" 6 : Etat du stock \n");
      
printf (" 7 : Alimenter le stock \n");	// produit ana chritou
      printf (" 8 : Supprimer les produits \n");
      
printf (" 9 : Statistique de vente \n");
      
printf (" 10  : quitter le programme \n");
      
printf
	("\n ------------------------------------------------------------------------------------------------------ \n\n");
      
printf ("\n taper votre choix : ");
      
scanf ("%d", &Choix);
      
switch (Choix)
	
	{
	
case 1:
	system("cls"); 
	Ajouter_Nv_Produit (1);
	  
break;
	
case 2:

printf("\n Entrez le nombre de produits que vous voulez ajouter : ");
	  	system("cls"); 
scanf("%d", &Nmbr_Produit);
	Ajouter_Nv_Produit (Nmbr_Produit);
	  
break;
	
case 3:
printf(" 1  : lister tous les produits selon lb ordre alphabC)tique croissant du nom. \n");
	  
printf(" 2  : * lister tous les produits selon lb ordre C)croissant du prix. \n");
	  
printf ("\nentrez votre choix : ");

system("cls"); 
scanf ("%d", &decision);
	  
if (decision == 1)
	    
	    {
	      
list_with_name ();
	    
}
	  
	  else if (decision == 2)
	    
	    {
	system("cls"); 
list_with_price ();
	    
}
	  
break;
	
 
case 4:
		system("cls"); 
	  Acheter_produit ();
	  
break;
	
 
case 5:
		system("cls"); 
	  chercher ();
	  
break;
	  
	case 6:
		system("cls"); 
	  Etat_du_stock ();
	  
break;
	
 
 
case 7:
		system("cls"); 
	  Alimenter_le_stock ();
	  
break;
	
 
case 8:
			system("cls"); 
	  Supprimer_un_produit ();
	  
break;
	
 
case 9:
		system("cls"); 
	  Statistique_de_vente ();
	  
break;
	  
	    /*printf("---------------Statistique de vente---------------");
	       printf(" 1  : Afficher le total des prix des produits vendus en journC)e courante \n");
	       printf(" 2  : Afficher la moyenne des prix des produits vendus en journC)e courante \n");
	       printf(" 3  : Afficher le Max des prix des produits vendus en journC)e courante \n");
	       printf(" 4  : Afficher le Min des prix des produits vendus en journC)e courante \n");
	       printf("\ntaper votre choix : ");
	       scanf("%d", &decision);
	       if(decision == 1)
	       {
	       }
	       else if(decision == 2)
	       {
	       
	       }
	       if(decision == 3)
	       {
	       
	       }
	       else if(decision == 4)
	       {
	       
	     */ 
	}
    
}
  
while (Choix != 10);

}


void
Ajouter_Nv_Produit (int n) 
{
  
 
for (i = 0; i < n; i++)
    {
      
printf ("Enter the code of the product: ");
      
scanf ("%s", tab[j].code_prdt);
	
printf ("Enter the name of the product: ");
      
scanf ("%s", tab[j].nom_prdt);
	
printf ("Enter the quantity of the product: ");
      
scanf ("%d", &(tab[j].quantity_prdt));
      
 
 
printf ("Enter the price of the product: ");
      
scanf ("%f", &(tab[j].prix));
      
i++;
      
j++;
    
}
  
printf ("produit ajoute avec succes");

}


//list products
  void
list_with_name () 
{
  
SProduit nameTmp;
  
int x;
  
for (i = 0; i < j; i++)
    
    {
      
for (x = i + 1; x < j; x++)
	
	{
	  
if (strcmp (tab[i].nom_prdt, tab[x].nom_prdt) > 0)
	    
	    {
	      
nameTmp = tab[x];
	      
tab[x] = tab[i];
	      
tab[i] = nameTmp;
	    
}
	
 
}
    
}
  
for (int k = 0; k < j; k++)
    
    {
      
printf ("%s\n", tab[k].nom_prdt);

} 
 
} 

//_________________sorting products by price
  void
list_with_price ()		//didnt wanna get excuted tho
{
  
SProduit priceTmp;
  
for (int i = 0; i < j; i++)
    
    {
      
for (int x = i + 1; x < j; x++)
	
	{
	  
if (tab[i].prix < tab[x].prix)
	    
	    {
	      
priceTmp = tab[i];
	      
tab[i] = tab[x];
	      
tab[x] = priceTmp;
	    
}
	
 
}
    
}
  
for (int k = 0; k < j; k++)
    
    {
      
printf ("%f\t \n:", tab[k].prix);
      
printf ("%f HTT :\n", tab[k].prix * 1.15);
      
printf ("%s\t :\n", tab[k].nom_prdt);
      
printf ("%s\t :\n", tab[k].code_prdt);
      
printf ("%d\t :\n", tab[k].quantity_prdt);

} 
 
} 

//SEARCH FOR A PRODUCT WITH code
  void
chercher (void) 
{
printf ("rechercher un produit");
  
printf (" \n 1  : avec code \n");
  
printf (" \n 2  : avec Quantite) \n");
  
printf ("\ntaper votre choix : \n");
  
scanf ("%d", &decision);
  
if (decision == 1)
    
    {
      
printf ("\n taper le code de produit : ");
      
scanf ("%s", code_product);
      
for (i = 0; i < j; i++)
	
	{
	  
if (strcmp (tab[i].code_prdt, code_product) == 0)
	    
	    {
	      
for (int k = 0; k < j; k++)
		
		{
		  
printf ("%s\n", tab[k].nom_prdt);
	    
} 
 
}
    
} 
}
  
  else if (decision == 2)
    
    {
      
printf ("\n taper la quantite de produit : ");
      
scanf ("%d", &product_qnty);
      
for (i = 0; i < j; i++)
	
	{
	  
if (tab[i].quantity_prdt = product_qnty)
	    
	    {
	      
system ("clr");
	      
printf ("le nom du produit cherche) %s\n", tab[i].nom_prdt);
	      
printf ("la quantite du produit cherche) %d\n",
		       tab[i].quantity_prdt);
	    
}
	
 
}
    
}

}


void
Etat_du_stock () 
{
  
for (i = 0; i < j; i++)
    
    {
      
if (tab[i].quantity_prdt < 3)
	
	{
	  
system ("clr");
	  
printf ("le produit %s risque d'etre d epuise \n", tab[i].nom_prdt);
	  
printf ("il reste    %d\n", tab[i].quantity_prdt);
	
}
    
}

}


void
Alimenter_le_stock (void)	// JOUTER UN NOUVEAU PRODUIT
{
    printf ("introduit le code produit\n");
  
scanf ("%s", code_product);	// le code produit
  printf ("introduit la quantite) pour ajouter\n");
  
scanf ("%d", &product_qnty);	// quantite a ajouter au shop
  for (i = 0; i < j; i++)
    
    {
      
printf ("la quantite avant est %d", tab[i].quantity_prdt);
      
if (strcmp (tab[i].code_prdt, code_product) == 0)
	
	{
	  
tab[i].quantity_prdt += product_qnty;
	
}
    
}
  
printf ("---------------ALIMENTATION DU STOCK---------------");
  
printf ("la quantite du produit mnt est %d ", tab[i - 1].quantity_prdt);

 
}


 
void
Supprimer_un_produit (void) 
{
  
SProduit tmp;
  
int x;
  
printf ("introduit le code produit\n");
  
scanf ("%s", code_product);	// le code produit
  
for (i = 0; i < j; i++)
    
    {
      
for (x = i + 1; x < j; x++)
	
	{
	  
if (strcmp (tab[i].code_prdt, code_product) == 0)
	    
	    {
	      
tab[i] = tab[x];
	    
}
	
 
}
    
}
  
j--;

}
   
void
Acheter_produit (void)		// JOUTER UN NOUVEAU PRODUIT
{
  
printf ("introduit le code produit\n");
  
scanf ("%s", code_product);	// le code produit
  printf (" la quantite a deduire\n");
  
scanf ("%d", &product_qnty);	// quantite a ajouter au shop
  printf ("\nla quantite avant est %d\n", tab[i].quantity_prdt);
  
for (i = 0; i < j; i++)
    
    {
      
if (strcmp (tab[i].code_prdt, code_product) == 0)
	
	{
	  
tab[i].quantity_prdt -= product_qnty;
	  
	    //
	    // vente faite 
	    time_t t = time (NULL);
	  
strcpy (st[z].date, ctime (&t));
	  
strcpy (st[z].nom_produit, tab[i].nom_prdt);
	  
st[z].prixTTc = tab[z].prix * 1.15 * product_qnty;
	  
total += st[z].prixTTc;
	  
z++;
	  
break;
	
}
    
}
  
 
printf
    ("\n\n\t\t---------------VARIATION DU STOCK---------------\t\t\n\n\n");
  
printf ("%d", i);
  
printf ("\nla quantite mnt est %d\n", tab[i].quantity_prdt);
  
for (int k = 0; k < z; k++)
    
    {
      
printf ("\nla date %s \n", st[k].date);
      
printf ("\nle nom %s \n", st[k].nom_produit);
      
printf ("\nprix %f \n", st[k].prixTTc);

} 
 
} 
 
 
void

Statistique_de_vente () 
{
  
float la_moyenne;
  
la_moyenne = total / z;
  
float max, min;
  
max = 0;
min =0;

  
printf ("le total est %f\n", total);
  
printf ("le total est %f\n", la_moyenne);
  
for (i = 0; i < z; i++)
    
    {
      
if (max < st[i].prixTTc)
	
        max = st[i].prixTTc;
if (min > st[i].prixTTc || min == 0)
	
        min = st[i].prixTTc;

    }
printf ("max est %f\n", max);
printf ("min %f\n", min);
 
}

 
int
main () 
{
  
menu ();
return 0;

}