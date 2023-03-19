 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct n
{
	char data[100];
	n * left;
	n * right;
};


typedef n node;


node* ekle(node*agac,char kelime[])  
{	
	kelime= strlwr(kelime);
	
	if(agac==NULL)
	{
		node*root=(node*)malloc(sizeof(node));
		strcpy(root->data,kelime);
		root->right = NULL;
		root->left = NULL;
		return root;
		
		
	}
	
	else if(strcmp(kelime,(agac)->data)<0)
	{	
		agac->left=ekle(agac->left,kelime);
	 	return agac;
	 	
    }
    else if (strcmp(kelime,(agac)->data)>0)
	{
       	agac->right=ekle(agac->right,kelime);
		return agac;
	}
	else if(strcmp(kelime,(agac)->data)==0)
	{
		return agac;
	}
	
}
	

void words(char aranan[])
{	
	
	FILE *dosya;
	dosya = fopen("Words.txt","r");
	int sayi=0;
	char kelime[100];
	
	
	while(fscanf(dosya,"%s",&kelime)!=EOF)
		{	
			
			if(strcmp(strlwr(kelime),aranan)==0)
			sayi++;
						
	 	}	
	printf("Words: %s Times:%d\n",aranan,sayi);
	if(sayi==0)
	{
		printf("Not found");
	}
	fclose(dosya);
}


void search(node * agac,char aranan[])
{	
    aranan=strlwr(aranan);
	words(aranan);
	
	
}

void dolas(node*agac)
{
	if (agac == NULL) 
	return;

		dolas(agac->left);		
		words(agac->data);
		dolas(agac->right);
		
}

int dugum(node*agac)
{
	if(agac==NULL)
	return 0;
	else
	return dugum(agac->left)+ 1 + dugum(agac->right);
}

int main()
{	
	char kelime[100];
	int kelime_sayisi=0;
	node*agac=NULL;
	 
	FILE *dosya;
	dosya = fopen("Words.txt","r");

	if(dosya!=NULL)
	{
			
			while(fscanf(dosya,"%s",&kelime)!=EOF)
		{	
			agac=ekle(agac,kelime);
			kelime_sayisi++;			
	 	}	
		
	}
	
	else 
	{
		printf("No file found");
	}
	fclose(dosya);
	
	
	printf("In total %d the word was read from the file and saved in the binary search tree.\n",kelime_sayisi);
	printf("Number of nodes of the binary search tree:%d\n",dugum(agac));
	printf("The depth of binary search tree: \n");
	
	int secim;
	
	
	
	while(secim!=4)
	{	printf("\n\n1->Print Different Words\n2->Different Words in Alphabetical Order \n3->Search word\n4->Exit\n");
		printf("Enter choice=> ");
		scanf("%d",&secim);
		printf("\n");
	
		switch(secim)
		{
			case 1:
				{
					FILE *dosya;
					dosya = fopen("Words.txt","r");
					while(fscanf(dosya,"%s",&kelime)!=EOF)
					{	
						words(strlwr(kelime));
									
	 				}	
					break;
				}
			case 2:
				{		
					dolas(agac);
					break;
				}
			case 3:
				{
					char aranan[100];
					printf("search word: ");
					scanf("%s",aranan);
					search(agac,aranan);
					break;
				}
			case 4:
				{
					break;
				}
			default:
				{
					printf("Entered Wrong Number.\n");
					break;
				}
				
		}
	}
}
