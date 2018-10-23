#include<iostream>
#include<math.h>
using namespace std;
int rfinder(int n)
{
// 2^r >= m+r+1....find least r value
int r=1;
	while(pow(2,r) < (n+r+1))
		r++;

return r;
}

int main() {
int n;
cout<<"\nEnter the no of data bits!\n";
cin>>n;
//int arr[n+1];
int r=rfinder(n);
int arr[n+r+1];
int b[n+r+1];

cout<<"\nEnter data bits!\n";

for(int i=1;i<=n+r;i++)
{
	if(i!=1 && i!=2 && i!=4 && i!=8 && i!=16){
		cin>>arr[i];
		b[i]=i;
	}
	else
		arr[i]=9;
}

for(int i=1;i<=n+r;i++)
cout<<" "<<arr[i];



int k=1;
int temp,sum;
while(k<=n+r)
{
	sum=0;
	if(arr[k]==9)
	{

//run a for loop and divide by 2...if remainder=1 add that
		for(int i=1;i<=n+r;i++)
		{
			if(i!=1 && i!=2 && i!=4 && i!=8 && i!=16){

				temp=b[i]%2;
				b[i]=b[i]/2;
				if(temp==1)
					sum=sum+arr[i];


				}

		}

		arr[k]=sum%2;

	}


k++;
}

cout<<"\n\n\nHamming Code!\n";
for(int i=1;i<=n+r;i++)
cout<<" "<<arr[i];
cout<<endl;
	return 0;
}

