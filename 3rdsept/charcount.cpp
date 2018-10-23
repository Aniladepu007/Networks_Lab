#include <iostream>
using namespace std;

//arrays for storing input data
int arr[100],b[100],ind=0,ind1=-1;

//displays
void display() {
for(int i=0;i<ind1;i++)
	cout<<b[i]<<" ";
cout<<endl<<endl<<endl;

}

//stuffs a bit indicating frame size
void char_count(int n) {
ind1++;
b[ind1]=n+1;

for(int i=ind-n;i<=ind;i++) {
	ind1++;
	b[ind1]=arr[i];
}
}

void input() {
//	cout<<"test!\n";
int temp;
int counter=0;

cout<<"Enter data bits!\n";
while(1) {
	cin>>temp;
	if(temp!=-1) {
		arr[ind]=temp;
		ind++;
		counter++;
	}
	else
		break;
}

char_count(counter);

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
return 0;
}
