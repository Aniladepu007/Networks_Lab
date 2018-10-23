#include<iostream>
using namespace std;

void ff(int n1,int n2,int pos,int a[],int g[])
{

for(int i=0;i<n2;i++)
	{
		a[pos+i]=(a[pos+i]+g[i])%2;
	}

while(a[pos]==0)
	pos++;
}

int main() {
int n1,n2;
cout<<"Enter n1(msg) and n2(crc_gen) values!\n";
cin>>n1;
cin>>n2;

int msg[n1+n2-1],a[n1+n2-1];
int g[n2];
for(int i=n1;i<n1+n2-1;i++){
	msg[i]=0;
	a[i]=0;
}

cout<<"\nEnter message!\n";
for(int i=0;i<n1;i++){
	cin>>msg[i];
	a[i]=msg[i];
}
cout<<"\nEnter generator\n";
for(int i=0;i<n2;i++)
	cin>>g[i];

int pos=0;
while(pos<=n1-1)
{

for(int i=0;i<n2;i++)
	{
		a[pos+i]=(a[pos+i]+g[i])%2;

	}

while(a[pos]==0)
	pos++;
}

for(int i=n1+n2-1-1;i>=n1;i--)
{
	msg[i]=a[i];
}
cout<<"\nresult:\n";
for(int i=0;i<=n1-1+n2-1;i++)
	cout<<" "<<msg[i];
	
int msg2[n1+n2];
cout<<"\nEnter the message string at the receiver end!\n";
for(int i=0;i<n1+n2-1;i++)
	cin>>msg2[i];

pos=0;
while(pos<=n1-1)
{
for(int i=0;i<n2;i++)
		msg2[pos+i]=(msg2[pos+i]+g[i])%2;

while(msg2[pos]==0)
	pos++;
}
int counter=0;
for(int i=pos;i<n1+n2-1;i++)
	if(msg2[i]==1)
		counter++;
if(counter>0)
	cout<<"\nError detected!!\n";
else
	cout<<"\nNo Error!\n\n";
	return 0;
}










