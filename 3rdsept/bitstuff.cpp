#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
char a[100],b[100];
int index=-1,ind1=-1;
void algo(int n);

char itoa(int i) {
char x;
if(i==0)
      x='0';
else
      x='1';
return x;
}

void input() {
int temp;
int counter=0;
//enter '0' or '1' for data...
cout<<"Enter input data!\n";
while(1) {
	cin>>temp;
      if(temp==-1)
		break;
      else {
      	index++;
            a[index] = itoa(temp);
      	//itoa(temp,a[ind],10);
      	counter++;
      }
  }
algo(counter);
}

void algo(int n) {
int i,j,count=0;
//add flags at the ends of the frame
ind1++;
b[ind1]='F';
i=index+1-n;
while(i<=index) {
      if(a[i]=='1') {
        if(a[i+1]=='1')
          if(a[i+2]=='1')
            if(a[i+3]=='1')
              if(a[i+4]=='1')
                if(a[i+5]=='1') {
                    for(j=i;j<=i+4;j++) {
                         ind1++;
                         b[ind1] = a[j];
                    }
                    count=5;
                    ind1++;
                    i=j+1;
                    b[ind1] = '0';
                    ind1++;
                    b[ind1] = a[i];
              }
             ind1++;
             b[ind1] = a[i];
      }
      else {
            ind1++;
            b[ind1] = a[i];
      }
   ++i;
  }
}

void display() {
      for(int i=0;i<=index;i++)
		cout<<a[i]<<"  ";
cout<<endl;
	for(int i=0;i<=ind1;i++)
		cout<<b[i]<<"  ";
cout<<endl;
}

int main() {
int ch;
while(1) {
cout<<"Enter yo' choice !\n1.Input\t2.display_stuffed_data\n";
cin>>ch;
   switch(ch) {
	case 1 : {
		input();
		break;
	}
	case 2 : {
		display();
		break;
	}
	default : { cout<<"Wrong choice!\n";
		break;
		//return 0;
		}
  }
}
//display();

return 0;
}




















/*
#include<stdio.h>
#include<string.h>
int main()
{
int a[20],b[30],i,j,k,count,n;
printf("Enter frame size!\n:");
scanf("%d",&n);
printf("Enter input data!\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
i=0; count=1; j=0;
while(i<n)
{
if(a[i]==1)
{
b[j]=a[i];
for(k=i+1;a[k]==1 && k<n && count<5;k++)
{
j++;
b[j]=a[k];
count++;
if(count==5)
{
j++;
b[j]=0;
}
i=k;
}}
else
{
b[j]=a[i];
}
i++;
j++;
}
printf("Stuffed code !\n");
for(i=0;i<j;i++)
printf("%d",b[i]);

return 0;
}*/
