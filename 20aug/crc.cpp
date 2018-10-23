#include <iostream>
#include <cstring>
#include <array>
using namespace std;

void xor_div(int size,int n2,bool m[],bool crc[]) {

int j;
int SIZE=size;
bool div[size];
memcpy(div,m,size*sizeof(bool));

for(int i=0;i<n2;i++)
	div[i]= div[i] ^ crc[i];

while(SIZE--) {
//memcpy(div,m,size*sizeof(bool));
for(int i=0;i<size;i++) {
	if(div[i]!=0) {
		j=i;
		break;
	}
}
for(int i=j;i<j+n2;i++)
	div[i]= (div[i] + crc[i])%2;
//if(j+3>size)
//	break;

}

cout<<endl<<endl;
for(int i=0;i<size;i++)
	cout<<m[i];

cout<<endl<<endl;
for(int i=0;i<size;i++)
	cout<<div[i];
//for(int i=0;i<n2;i++)
//	cout<<crc[i];
cout<<"\ntest!";

}



int main() {
int n1,n2;
cout<<"Enter the sizes of the message and CRC generator!\n";
cin >>n1>>n2;
//array<bool,n1> msg;
//array<bool,n2> crc;
bool msg[n1],crc[n2];
cout<<"Enter the message!\n";
for(int i=0;i<n1;i++)
	cin>>msg[i];
cout<<"Enter the crc_gen!\n";
for(int i=0;i<n2;i++)
	cin>>crc[i];
int size = n1+n2-1;
//array<bool,size> m;
bool m[size];

for(int i=0;i<size;i++) {
	if(i>n1)
		m[i]=0;
	else
		m[i]=msg[i];
}

xor_div(size,n2,m,crc);

	return 0;
}	




//for(int i=0;i<n1;i++)
//	cout<<msg[i];
//for(int i=0;i<n2;i++)
//	cout<<crc[i];
//cout<<endl<<endl;
