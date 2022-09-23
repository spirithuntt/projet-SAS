#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdio_ext.h>
///*** DECLARATION DES VARIABLES ***
typedef struct
{
  char code_prdt[10];
  char nom_prdt[50];
  int quantity_prdt;
  float prix;
} SProduit;    // my normal struct
typedef struct // struct for statistics
{

  char nom_produit[10];

  float prixTTc;
  float prixt;

  char date[10];
  char product_code[10];

} Pproduit;

Pproduit st[100]; // tableau li and5l fih Pproduit
int z;            // size dyalou
float total;

static int i = 0; // nomal index
static int j = 0; // fin wassel index dyal tab dyali size dyalou
SProduit tab[100];
int Nmbr_Produit; // number of products that u want to enter for 2
int decision;     // list croissant ou decroissant les produit pour 3 et aussi chercher avec code ou bien quantity
char code_product[10];

int product_qnty;
float snb = 0;
float numbofproducts = 0;
// Total number of items sold
// add or deduct quantity
///*** LES FONCTIONS ***//prototype
void menu();

void Ajouter_Nv_Produit(int n);

void list_with_name();

void list_with_price();

void Acheter_produit(void);

void chercher(void);

void Etat_du_stock(void);

void Alimenter_le_stock();

void Supprimer_un_produit(void);

void Statistique_de_vente(void);

///*** MENU ***
void menu()
{
  int Choix;        // 1st choice
  int Nmbr_Produit; // number of products that u want to enter for 2
  int decision;     // list croissant ou decroissant les produit pour 3 et aussi chercher avec code ou bien quantity
  char code_product[10];

  int product_qnty; // add or deduct quantity
  do
  {
    printf("\033[0;34m"); // BPurple
    printf("\n ------------------------------------------- MENU ----------------------------------------------------- \n\n");

    printf(" 1 : Ajouter un nouveau produit \n");

    printf(" 2 : Ajouter plusieurs nouveaux produits\n");

    printf(" 3 : Lister tous les produits (Nom, prix, prix TTC) \n");

    printf(" 4 : Acheter produit \n"); // produit deja tchra

    printf(" 5 : Rechercher les produits \n");

    printf(" 6 : Etat du stock \n");

    printf(" 7 : Alimenter le stock \n"); // produit ana chritou

    printf(" 8 : Supprimer les produits \n");

    printf(" 9 : Statistique de vente \n");

    printf(" 10  : quitter le programme \n");

    printf("\n ------------------------------------------------------------------------------------------------------ \n\n");

    printf("\n taper votre choix : ");

    scanf("%d", &Choix);

    switch (Choix)

    {

    case 1:
      system("clear");
      Ajouter_Nv_Produit(1);

      break;

    case 2:
      system("clear");
      printf("\n Entrez le nombre de produits que vous voulez ajouter : ");
      scanf("%d", &Nmbr_Produit);
      Ajouter_Nv_Produit(Nmbr_Produit);

      break;

    case 3:
      system("clear");
      printf("\n\n\t 1  : lister tous les produits selon l ordre alphabetique croissant du nom. \n");

      printf("\n\n\t 2  : lister tous les produits selon ordre croissant du prix. \n");

      printf("\n\n\t\t\t entrez votre choix : ");

      scanf("%d", &decision);

      if (decision == 1)

      {
        list_with_name();
      }

      else if (decision == 2)

      {
        system("clear");
        list_with_price();
      }

      break;

    case 4:
      system("clear");
      Acheter_produit();

      break;

    case 5:
      system("clear");
      chercher();

      break;

    case 6:
      system("clear");
      Etat_du_stock();

      break;

    case 7:
      system("clear");
      Alimenter_le_stock();

      break;

    case 8:
      system("clear");
      Supprimer_un_produit();

      break;

    case 9:
      system("clear");
      Statistique_de_vente();

      break;
    default:
      __fpurge(stdin);
      break;
    }

  }

  while (Choix != 10);
}
// the insterted code

void Ajouter_Nv_Produit(int n)
{
  int x;
  char code_p[10]; // the inserted code
  for (i = 0; i < n; i++)
  {
  N1:
    printf("\n\t\t Enter the code of the product: ");
    scanf("%s", code_p);
    for (x = 0; x < j; x++)
    {
      if (strcasecmp(tab[x].code_prdt, code_p) == 0)
      {
        printf("\n\t\tThis product already exists");
        goto N1;
      }
    }
    strcpy(tab[i].code_prdt, code_p);
    printf("\n\t\tEnter the name of the product: ");
    scanf("%s", tab[i].nom_prdt);
  N2:
    printf("\n\t\tEnter the quantity of the product: ");
    scanf("%d", &(tab[i].quantity_prdt));
    if (tab[i].quantity_prdt < 0)
    {
      printf("\n\t\t you need to enter a positive quantity !!!!: ");
      goto N2;
    }
  N3:
    printf("\n\t\tEnter the price of the product: ");
    scanf("%f", &(tab[i].prix));
    if (tab[i].prix < 0)
    {
      printf("le prix doit etre positif!!!");
      goto N3;
    }
    j++;
  }
  printf("\n\t\t\t************produit ajoute avec succes***********");
}

void list_with_name()
{

  SProduit nameTmp;

  int x;

  for (i = 0; i < j; i++)

  {

    for (x = i + 1; x < j; x++)

    {

      if (strcasecmp(tab[i].nom_prdt, tab[x].nom_prdt) > 0)

      {
        nameTmp = tab[x];

        tab[x] = tab[i];

        tab[i] = nameTmp;
      }
    }
    printf("\n\tName: %s\t\t\tQuantity: %d\t\t\tCode : %s\t\t\t", tab[i].nom_prdt, tab[i].quantity_prdt, tab[i].code_prdt);
  }
}

//_________________sorting products by price
void list_with_price() // didnt wanna get excuted tho
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
    printf("\n\tName: %s\t\t\tQuantity: %d\t\t\tCode : %s\t\t\t", tab[i].nom_prdt, tab[i].quantity_prdt, tab[i].code_prdt);
  }
}
// SEARCH FOR A PRODUCT WITH code
void chercher(void)
{
  printf("rechercher un produit");

  printf(" \n\t\t\t1  : avec code \n");

  printf(" \n\t\t\t 2  : avec Quantite) \n");

  printf("\ntaper votre choix : \n");

  scanf("%d", &decision);

  if (decision == 1)

  {
    int trouve = 0;

    printf("\n\t\t\t taper le code de produit : ");

    scanf("%s", code_product);

    for (i = 0; i < j; i++)

    {

      if (strcasecmp(tab[i].code_prdt, code_product) == 0)

      {

        printf("\n\tName: %s\t\t\tQuantity: %d\t\t\tCode : %s\t\t\t", tab[i].nom_prdt, tab[i].quantity_prdt, tab[i].code_prdt);
        trouve++;
      }
    }
    if (trouve == 0)
      printf("\t\t\tproduit introuvable");
  }

  else if (decision == 2)

  {

    printf("\n taper la quantite de produit : ");

    scanf("%d", &product_qnty);

    for (i = 0; i < j; i++)

    {

      if (tab[i].quantity_prdt = product_qnty)
      {
        system("clr");

        printf("\n\t\t\tle nom du produit cherche %s\n", tab[i].nom_prdt);

        printf("\n\t\t\tla quantite du produit cherche %d\n", tab[i].quantity_prdt);
      }
      else
        printf("\t\t\t produit introuvable");
    }
  }
}

void Etat_du_stock()
{

  for (i = 0; i < j; i++)

  {

    if (tab[i].quantity_prdt < 3)

    {

      system("clr");

      printf("\t\t\tle produit %s risque d'etre d epuise \n", tab[i].nom_prdt);

      printf("\t\t\til reste    %d\n", tab[i].quantity_prdt);
    }
  }
}

void Alimenter_le_stock(void) // JOUTER UN NOUVEAU PRODUIT
{
  for (i = 0; i < j; i++)
  {
    printf("\n\tName: %s\t\t\tQuantity: %d\t\t\tCode : %s\t\t\t", tab[i].nom_prdt, tab[i].quantity_prdt, tab[i].code_prdt);
  }
  printf("\n\tEntrez le code du produit:\t");
  scanf("%s", code_product);
  int c = 0; // check if there is a product
  for (i = 0; i < j; i++)
  {
    if (strcasecmp(tab[i].code_prdt, code_product) == 0)
    {
    NO:
      printf("\n\t Entrez la quantite s il vous plait:\t");
      scanf("%d", &product_qnty);
      if (product_qnty < 0)
      {
        printf("\n\t Vous ne pouvez pas entrer un nombre negatif");
        goto NO;
      }
      printf("\n\t Quantite avant livraison: ");
      printf("\n\tName: %s\t\t\tQuantity: %d\n", tab[i].nom_prdt, tab[i].quantity_prdt);
      tab[i].quantity_prdt += product_qnty;
      c++;
      break;
    }
  }
  if (c == 0)
  {
    printf("\n\t Il n y a pas un tel produit");
  }
  printf("\n\n\t Quantite apres approvisionnement: ");
  printf("\n\tName: %s\t\t\tQuantity: %d\n", tab[i].nom_prdt, tab[i].quantity_prdt);
}
void Supprimer_un_produit(void) // strcmp for if there is a product or not
{

  SProduit tmp;

  int x;

  printf("\t\t\tintroduit le code produit\n");

  scanf("%s", code_product); // le code produit

  for (i = 0; i < j; i++)

  {

    for (x = i + 1; x < j; x++)

    {

      if (strcasecmp(tab[i].code_prdt, code_product) == 0)

      {

        tab[i] = tab[x];
      }
    }
  }
  j--;
}

void Acheter_produit()
{
  int nb;               // number of items to buy
  printf("\033[1;36m"); // Cyan Color
  printf("\n\t||-----------------------------|| Acheter_produit ||-----------------------------||\n\n");
NO:
  printf("\033[1;36m"); // Cyan Color
  for (i = 0; i < j; i++)
  {
    printf("\n\tName: %s\t\t\tQuantity: %d\t\t\tTTC Price: %.2f\t\t\tCode : %s\t\t\t", tab[i].nom_prdt, tab[i].quantity_prdt, tab[i].prix * 1.15, tab[i].code_prdt);
  }
  printf("\n\tEntrez le code du produit que vous souhaitez acheter:\t");
  scanf("%s", code_product);
  int c = 0; // check if there is a product
  for (i = 0; i < j; i++)
  {
    if (strcmp(tab[i].code_prdt, code_product) == 0)
    {
    NO2:
      printf("\n\t Entrez le nombre d'articles que vous souhaitez acheter:\t");
      scanf("%d", &nb);
      if (nb > tab[i].quantity_prdt)
      {
        printf("\n\t Il ne reste que %d articles de ce produit", tab[i].quantity_prdt);
        goto NO2;
      }
      if (nb < 0)
      {
        printf("\n\tVous ne pouvez pas entrer un nombre négatif!!!");
        goto NO2;
      }
      printf("\n\tQuantite avant achat: ");
      printf("\n\tName: %s\t\t\tQuantity: %d\t\t\tTTC Price: %.2f\t\t\tCode : %s\t\t\t", tab[i].nom_prdt, tab[i].quantity_prdt, tab[i].prix * 1.15, tab[i].code_prdt);
      tab[i].quantity_prdt = tab[i].quantity_prdt - nb;
      strcpy(st[z].nom_produit, tab[i].nom_prdt);
      strcpy(st[z].product_code, tab[i].code_prdt);
      st[z].prixt = tab[i].prix * 1.15;
      st[z].prixTTc = tab[i].prix * 1.15 * nb; // prob
      time_t t = time(NULL);
      strcpy(st[z].date, ctime(&t));
      z++;
      numbofproducts += nb;
      c++;
      break;
    }
  }
  if (c == 0)
  {
    printf("\n\t Il n y a pas un tel produit");
    goto NO;
  }
  printf("\n\t Quantite apres achat: ");
  printf("\n\t Name: %s\t\t\tQuantity: %d\t\t\tTTC Price: %.2f\t\t\tCode : %s\t\t\t", tab[i].nom_prdt, tab[i].quantity_prdt, tab[i].prix * 1.15, tab[i].code_prdt);
}
// statististiques
void Statistique_de_vente()
{
  float max, min;

  max = 0;
  min = 0;

  printf("\n\t||-----------------------|| Sales statistics ||-----------------------||\n\n");
  sleep(1);
  printf("\n\n\ tLe prix total des produits vendus:\t%.2f", total);
  printf("\n\n\t le prix moyen des produits vendus:\t%.2f", total / numbofproducts);
  for (i = 0; i < z; i++)

  {

    if (max < st[i].prixTTc)
      max = st[i].prixTTc;
    if (min > st[i].prixTTc || min == 0)
      min = st[i].prixTTc;
  }
  printf("\n\n\t Le Min des prix des produits vendus est de :: %f\n", min);
  printf("\n\n\t Le Max des prix des produits vendus est de ::max est %f\n", max);
}

int main()
{

  menu();
  return 0;
}
