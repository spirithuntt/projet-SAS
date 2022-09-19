#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
///*** DECLARATION DES VARIABLES ***
typedef struct SProduit { char code_prdt[10]; char nom_prdt[50]; int quantity_prdt; float prix; } SProduit;
static int i = 0;
static int j = 0;// fin wassel index
struct SProduit tab[100];
///*** LES FONCTIONS ***
void    menu();
void    Ajouter_Nv_Produit(int n);

void    list_with_name();
//void    list_with_price();   
/*void    deduct_products(int code_product [10], int numb_of_product);//permet de mettre à jour la quantité après avoir introduit le code produit et la quantité à déduire, minus in product
void    search_with_code();
void    search_with_number();
void    add_products(int code_product [10], int numb_of_product);//permet de mettre à jour la quantité après avoir introduit le code produit et la quantité à ajouter, minus in product
void    delete_product(int code_product [10]);*/

///*** MENU ***
void menu()
{
    int Choix;//1st choice
    int Nmbr_Produit;//number of products that u want to enter for 2
    int decision;// list croissant ou decroissant les produit pour 3 et aussi chercher avec code ou bien quantity
    char code_product[10];
    int numb_of_product;// add or deduct
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
        case 3 :    printf(" 1  : lister tous les produits selon l’ordre alphabétique  croissant du nom. \n");
                    printf(" 2  : * lister tous les produits selon l’ordre  décroissant du prix. \n");
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
        /*case 4 :    printf("introduit le code produit\n");
                    scanf("%s", code_product);
                    printf("introduit la quantité à déduire\n");
                    scanf("%d", &numb_of_product); 
                    deduct_products(code_product, numb_of_product); */
        case 5 :    printf("rechercher un produit");
                    printf(" 1  : avec code \n");
                    printf(" 2  : avec Quantité \n");
                    printf("\ntaper votre choix : ");
                    scanf("%d", &decision);
                    if(decision == 1)
                    {
                printf("\n taper le code de produit : ");
                scanf("%s",code_prdt);
                int CODE=search_with_code(code_prdt);// i decleard a variable bach bach n5dm bih nichan f blasst l fonction
                if(CODE!=0)
                {
                    printf("\n------------- LES RESULTAT DE RECHERCHE ------------- \n\n");
                    printf("%f\t",tab[CODE].prix);
                    printf("%f HTT\t",tab[CODE].prix*1.15);
                    printf("%s\t",tab[CODE].nom_prdt);
                    printf("%s\t",tab[CODE].code_prdt);
                    printf("%d\t",tab[CODE].quantity_prdt);
                }

                    }
               /*     else if(decision == 2)
                    {
                        search_with_number();
                         printf("\n------------- LES RESULTAT DE RECHERCHE ------------- \n\n");
                         printf("");
                    }
        case 6 :    printf("les produits bientôt en rupture de stock sont : \n");//soon out of stock


        case 7 :    printf("introduit le code produit :\n");
                    scanf("%s", code_product;);
                    printf("introduit la quantité à ajouter :\n");
                    scanf("%d", numb_of_product);
                    add_products(code_product, numb_of_product);

        case 8 :    printf("introduit le code de produit :\n");
                    scanf("%d", &code_product);
                    delete_product(code_product);

        case 9 :    printf("---------------Statistique de vente---------------");
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
                        
                    }*/
        default :if(decision<1 && decision > 11)
        printf("error");
        break;
    }
    }
    while(Choix != 10);

}
void    Ajouter_Nv_Produit(int n)
{

    for(i=0;i<n;i++){     
           struct SProduit produit;
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
void    list_with_price()
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
//SEARCH FOR A PRODUCT WITH NUMB
int  recherche(char code_prdt[10])
{
    int val=0;
    for(int i=0;i<j;i++){ if(strcmp(tab[i].nom_prdt,code_prdt)==0){val=i+1;}}
    return val;
}













///*** int main ***
int main()
{
    menu();
    return 0;
}
