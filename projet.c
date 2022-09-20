#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
///*** DECLARATION DES VARIABLES ***
typedef struct { char code_prdt[10]; char nom_prdt[50]; int quantity_prdt; float prix; } SProduit;// my normal struct
typedef struct // struct for statistics
{
    char nom_produit[10];
    float prixTTc;
    char date[10];
} Pproduit;
Pproduit st[100];// tableau li and5l fih Pproduit
int z;//size dyalou
static int i = 0;//nomal index
static int j = 3;// fin wassel index dyal tab dyali size dyalou
SProduit tab[100] = {
    {"rbt32", "pharma", 23, 643},
    {"fsko", "fewk", 23, 643},
    {"vfx", "fke", 23, 643},
};
int Nmbr_Produit;//number of products that u want to enter for 2
int decision;// list croissant ou decroissant les produit pour 3 et aussi chercher avec code ou bien quantity
char code_product[10];
int product_qnty;// add or deduct quantity

// list croissant ou decroissant les produit pour 3 et aussi chercher avec code ou bien quantity
///*** LES FONCTIONS ***
void    menu();
void    Ajouter_Nv_Produit(int n);

void    list_with_name();
void    list_with_price();   
void Acheter_produit(void);
//void    deduct_products(int code_product [10], int numb_of_product);//permet de mettre à jour la quantité après avoir introduit le code produit et la quantité à déduire, minus in product
void chercher(void);
void Etat_du_stock(void);
void Alimenter_le_stock();
void Supprimer_un_produit(void);
/*void    add_products(int code_product [10], int numb_of_product);//permet de mettre à jour la quantité après avoir introduit le code produit et la quantité à ajouter, minus in product
void    delete_product(int code_product [10]);*/

///*** MENU ***
void menu()
{
    int Choix;//1st choice
    int Nmbr_Produit;//number of products that u want to enter for 2
    int decision;// list croissant ou decroissant les produit pour 3 et aussi chercher avec code ou bien quantity
    char code_product[10];
    int product_qnty;// add or deduct quantity
    do{
    printf("\n ------------------------------------------- MENU ----------------------------------------------------- \n\n");
    printf(" 1 : Ajouter un nouveau produit \n");
    printf(" 2 : Ajouter plusieurs nouveaux produits \n");
    printf(" 3 : Lister tous les produits (Nom, prix, prix TTC) \n");
    printf(" 4 : Acheter produit \n");// produit deja tchra
    printf(" 5 : Rechercher les produits \n");
    printf(" 6 : Etat du stock \n");
    printf(" 7 : Alimenter le stock \n");// produit ana chritou
    printf(" 8 : Supprimer les produits \n");
    printf(" 9 : Statistique de vente \n");
    printf(" 10  : quitter le programme \n");
    printf("\n ------------------------------------------------------------------------------------------------------ \n\n");
    printf("\n taper votre choix : ");
    scanf("%d", &Choix);
    switch(Choix)
    {
        case 1 : Ajouter_Nv_Produit(1);
        break;
        case 2 : 
            printf("\n Entrez le nombre de produits que vous voulez ajouter : ");
            scanf("%d", &Nmbr_Produit);
            Ajouter_Nv_Produit(Nmbr_Produit);
            break;
        case 3 :    printf(" 1  : lister tous les produits selon l’ordre alphabétique croissant du nom. \n");
                    printf(" 2  : * lister tous les produits selon l’ordre écroissant du prix. \n");
                    printf("\nentrez votre choix : ");
                    scanf("%d", &decision);
                    if(decision == 1)
                    {
                        list_with_name();
                    }
                    else if (decision == 2)
                    {
                        list_with_price();
                    }
                    break;
                    
         case 4 :  Acheter_produit();
                    break;

        case 5 :    chercher();
                    break;

               /*     else if(decision == 2)
                    {
                        search_with_number();
                         printf("\n------------- LES RESULTAT DE RECHERCHE ------------- \n\n");
                         printf("");
                    }*/
        case 6 :   Etat_du_stock();
                    break;


        case 7 :    Alimenter_le_stock();
                    break;
        
        case 8 :   Supprimer_un_produit();
                    break;

        /*case 9 :    printf("---------------Statistique de vente---------------");
                    printf(" 1  : Afficher le total des prix des produits vendus en journée courante \n");
                    printf(" 2  : Afficher la moyenne des prix des produits vendus en journée courante \n");
                    printf(" 3  : Afficher le Max des prix des produits vendus en journée courante \n");
                    printf(" 4  : Afficher le Min des prix des produits vendus en journée courante \n");
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
    while(Choix != 10);
}
void Ajouter_Nv_Produit(int n)
{

    for(i=0;i<n;i++){
    printf("Enter the code of the product: ");
    scanf("%s", tab[j].code_prdt);
    //strcpy(ajoutproduit[j].code_prdt,tab[n].code_prdt);
    
    printf("Enter the name of the product: ");
    scanf("%s", tab[j].nom_prdt);
    //strcpy(ajoutproduit[j].nom_prdt,tab[n].nom_prdt);

    printf("Enter the quantity of the product: ");
    scanf("%d", &(tab[j].quantity_prdt));

    
    printf("Enter the price of the product: ");
    scanf("%f", &(tab[j].prix));
    i++;
    j++;
    }
    printf("produit ajoute avec succes");
}
//list products
void    list_with_name()
{
    SProduit nameTmp;
    int x;
for (i = 0; i < j; i++)
{
  for (x = i + 1; x < j ; x++)
  {
    if (strcmp(tab[i].nom_prdt,tab[x].nom_prdt)>0)
    {
        nameTmp=tab[x];
        tab[x]=tab[i];
        tab[i]=nameTmp;
    }
    
  }
}
for (int k = 0; k < j; k++)
    {
       printf("%s\n",tab[k].nom_prdt);
    }

}
//_________________sorting products by price
void    list_with_price()//didnt wanna get excuted tho
{
        SProduit priceTmp;
for (int i = 0; i < j; i++)
{
  for (int x= i + 1; x < j; x++)
  {
    if (tab[i].prix<tab[x].prix)
    {
        priceTmp=tab[i];
        tab[i]=tab[x];
        tab[x]=priceTmp;
    }
    
  }
}
for (int k = 0; k < j; k++)
    {  
       printf("%f\t",tab[k].prix);
       printf("%f HTT\t",tab[k].prix*1.15);
       printf("%s\t",tab[k].nom_prdt);
       printf("%s\t",tab[k].code_prdt);
       printf("%d\t",tab[k].quantity_prdt);
    }

}
//SEARCH FOR A PRODUCT WITH code
void    chercher(void)
{
                    printf("rechercher un produit");
                    printf(" \n 1  : avec code \n");
                    printf(" \n 2  : avec Quantité \n");
                    printf("\ntaper votre choix : \n");
                    scanf("%d", &decision);
                if(decision == 1)
                {
                printf("\n taper le code de produit : ");
                scanf("%s",code_product);
                for(i = 0 ;i < j ; i++)
                {
                   if (strcmp(tab[i].code_prdt, code_product) == 0)
                    { 
                        for (int k = 0; k < j; k++)
                    {
                        printf("%s\n",tab[k].nom_prdt);
                    }
                    
                    }
                }
                }
                else if (decision == 2)
                    {
                        printf("\n taper la quantite de produit : ");
                        scanf("%d", &product_qnty);
                    for(i = 0 ;i < j ; i++)
                {
                   if (tab[i].quantity_prdt = product_qnty)
                    {
                        system("clear");
                        printf("le nom du produit cherché %s\n",tab[i].nom_prdt);
                        printf("la quantite du produit cherché %d\n",tab[i].quantity_prdt);
                    }

                }
                    }
}
       void Etat_du_stock()
       {
                    for(i = 0 ; i < j ; i++)
                    {
                        if (tab[i].quantity_prdt < 3)
                        {
                        system("clear");
                        printf("le produit %s risque d'etre epuise \n",tab[i].nom_prdt);
                        printf("il reste    %d\n",tab[i].quantity_prdt);
                        }
                    }
       }
void Alimenter_le_stock(void)// JOUTER UN NOUVEAU PRODUIT
{   
    /* for(i = 0 ;i < j ; i++)
                {
                   if (strcmp(tab[i].code_prdt, code_product) == 0)
                    { 
                        for (int k = 0; k < j; k++)
                    {
                        printf("%s\n",tab[k].nom_prdt);
                    }
                    
                    }
                }*/
         printf("introduit le code produit\n");
        scanf("%s", code_product);// le code produit
        printf("introduit la quantité pour ajouter\n");
        scanf("%d", &product_qnty); // quantite a ajouter au shop
        for(i = 0 ;i < j ; i++)
                {
                    printf("la quantite avant est %d", tab[i].quantity_prdt);
                   if (strcmp(tab[i].code_prdt, code_product) == 0)
                   {
                     tab[i].quantity_prdt += product_qnty;
                   }
                }
        printf("---------------ALIMENTATION DU STOCK---------------");
        printf("la quantite du produit mnt est %d ",tab[i-1].quantity_prdt );

}

void Supprimer_un_produit(void)
{
    SProduit tmp;
    int x;
        printf("introduit le code produit\n");
        scanf("%s", code_product);// le code produit
         
        for (i = 0; i < j; i++)
        {
        for (x = i + 1; x < j ; x++)
            {
        if (strcmp(tab[i].code_prdt,code_product) == 0)
                {
        tab[i]=tab[x];
                }
    
            }
        }
        j--;
}
        /*
        for(i = 0 ;i < j ; i++)
                {
                   if (strcmp(tab[i].code_prdt, code_product) == 0)
                   {
                     tab[i].quantity_prdt += product_qnty;
                   }
                }*/

void Acheter_produit(void)// JOUTER UN NOUVEAU PRODUIT
{
        printf("introduit le code produit\n");
        scanf("%s", code_product);// le code produit
        printf(" la quantité à déduire\n");
        scanf("%d", &product_qnty); // quantite a ajouter au shop
        printf("\nla quantite avant est %d\n", tab[i].quantity_prdt);
        for(i = 0 ;i < j ; i++)
                {
                    printf("%s", code_product);
                   if (strcmp(tab[i].code_prdt, code_product) == 0)
                   {
                     tab[i].quantity_prdt -= product_qnty;
                     break;
                     // vente faite 
                    time_t t;
                    time(&t);
                    strcpy(st[z].date, ctime(&t));
                    strcpy(st[z].nom_produit, tab[i].nom_prdt);
                  //  st[z].prixTTc =( tab[i].prix*1.15)*product_qnty;
                    z++;
                     
                     
                     
                     
                     
                     /*time_t t;
    time(&t);
    printf("\n current time is : %s",ctime(&t));*/
    
                   }
                }
        printf("\n\n\t\t---------------VARIATION DU STOCK---------------\t\t\n\n\n");
        printf("\nla quantite du produit mnt est %d \n",tab[i].quantity_prdt );

}

int main()
{
    menu();
    return  0;
}