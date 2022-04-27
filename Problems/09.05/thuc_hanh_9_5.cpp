#include<stdio.h>
#include<string.h>

void xoaKhoangTrang(char S []);
void nhapMangXau(char S[][100],int n);
void xuatMangXau(char S[][100],int n);
void timXauMau(char s1[],char xauMau[]);
int demTu(char S[]);

int main()
{

    char array[100][100],xauMau[100];
    int n , i = 0;

    printf("Nhap so xau n = ");
    scanf("%d",&n);
    fflush(stdin);
    
    nhapMangXau(array,n);
	xuatMangXau(array,n);
	
	printf("Nhap xau mau = ");
	gets(xauMau);
	
	for(i=0;i<n;i++)
    {
    	printf("Tai xau thu %d : ",i+1);
    	timXauMau(array[i],xauMau);
	}
    
    for(i=0;i<n;i++)
    {
    	xoaKhoangTrang(array[i]);
	}
	
	printf("Sau khi chuan hoa:\n");
	xuatMangXau(array,n);
	
	for(i=0;i<n;i++)
    {
    	printf("Xau thu %d co %d tu\n",i+1,demTu(array[i]));
	}

    return 0;

}

void nhapMangXau(char S[][100],int n)
{
	int i=0;
	
	for(i = 0; i < n; i++)
    {
        printf("Nhap xau thu %d:",i);
        gets(S[i]);
    }
	
}

void xuatMangXau(char S[][100],int n)
{
	int i=0;
	
	for(i = 0; i < n; i++)
    {
        puts(S[i]);
    }
	
}

void timXauMau(char s1[],char s2[])
{
	int m=0,n=0,vitri=-1,len = strlen(s2);
	
	while(s1[n] != '\0') 
	{

		if(s1[n] == s2[m]) 
	   	{     // neu ky tu dau tien la giong nhau
			vitri=n;
        	 // tiep tuc so sanh
				
        	while(s1[n] == s2[m]  && s1[n] !='\0') 
		 	{
           		n++;
            		m++;
         	}

         	// Neu day ky tu nay co do dai bang chuoi tim kiem
         	if(m == len && (s1[n] == ' ' || s1[n] == '\0')) 
			{
            	printf("Xau mau xuat hien tai vi tri %d\n",vitri);
        	}
    	}
		else 
		{            // Neu ky tu dau tien khong giong nhau
    	    n++;
    	    if(s1[n] == '\0')
    	    {
    	       	printf("Xau mau khong xuat hien\n");
    	       	break;
			}
    	}
    n++;
    m=0;
	}
	
}

void xoaKhoangTrang(char S [])
{	
   int i,len,j;
   len = strlen(S);
   //xoa khoang trang dau xau
   while(S[0]==32)
   {
   		for (j=0;j<len-1;j++)
	    	{
	    		S[j]=S[j+1];
			}
               
        S[len-1]='\0';
        len-=1;
   }
   
   for (i=0;i<len;i++)
   {
   	//Xoa khoang trang giua xau
     if (S[i]==32)
     {
      	if (S[i+1]==32)
        {
	    	for (j=i+1;j<len-1;j++)
	    	{
	    		S[j]=S[j+1];
			}
               
        	S[len-1]='\0';
        	len-=1;
        	i--;
        }
      }
	}
	
	if(S[len-1]==32)
	{
		S[len-1]='\0';
	}
	
}

int demTu(char S[])
{
	int dem =1,i=0;
	for(i=0;i<strlen(S);i++)
	{
		if(S[i]==32)
		{
			dem++;
		}
	}
	return dem;
}


