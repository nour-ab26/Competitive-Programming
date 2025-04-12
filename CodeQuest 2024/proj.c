#include <stdio.h>
#include <string.h>
struct shampooing{
    char marque[50];
    char type[50];
    int volume;
    int prix;
      };
struct shampooing tab [10];
void afficher(){
     int i=0;
     while (i<10){
     printf("marque: %s\n type: %s\n volume: %d m\n prix: %d dinars\n ",
           tab[i].marque, tab[i].type, tab[i].volume, tab[i].prix);
    i++;
     }
}
void ajouter(){
    int k;
        printf("donner l'emplacement de l'ajout");
        scanf("%d",&k);
                printf("donner la marque  : ");
                scanf("%s",tab[k].marque);
                printf("donner le type   : ");
                scanf("%s",tab[k].type);
                printf("donner la volume: ");
                scanf("%d",&tab[k].volume);
                printf("donner le prix : ");
                scanf("%d",&tab[k].prix);
                printf("\n\n");
};
void rechercher ()
{
    int i=0;
    char lettre;
    int nbr=0;
    printf("Donner la lettre ");
    scanf("%s",&lettre);
    while (i<10)
    {
            if (strchr(tab[i].marque, lettre)!= NULL)
            {
                nbr++;
            }
            i++;
    }

    printf("La lettre est dans %d Element",nbr);
}
  void modifier()
{
    int position;
    int attribut;
    printf("donner la position ");
    scanf("%d",&position);
    printf("donner le numero de l'attribut :marque1 , type2 , volume 3 , prix 4");
    scanf("%d",&attribut);
    if (attribut==1)
    {
        printf("donner la nouvelle valeur  ");
        scanf("%s",&tab[position].marque);
    }
        if (attribut==2)
    {
        printf("donner la nouvelle valeur ");
        scanf("%s",&tab[position].type);
    }
        if (attribut==3)
    {
        printf("donner la nouvelle valeur ");
        scanf("%d",&tab[position].volume);
    }
        if (attribut==4)
    {
        printf("donner la nouvelle valeur ");
        scanf("%d",&tab[position].prix);
    }

}
void menu(){
    int choix;
    printf("\n\n\n1-Afficher\n2-Ajouter\n3-Rechercher\n4-sModifier\n5-Quitter\n\n");
    scanf("%d",&choix);
    if(choix==1){
        afficher();
    }
    if (choix==2) {
        modifier();
    }
    if (choix==3) {
        ajouter();
    }
    if (choix==4){
        rechercher();
    };
};

int main(){
   struct modifier
   {
    /* data */
   };
    shampooing tab[10]={{"souplesse","raides",5000,350},{"dove"," bouclés",6000,450},{"ultra-doux"," bouclés",7000,350},{"cfresh","frisés",5500,500},{"l'oréal","raides",8000,350}};
    menu();
   return 0 ;
}