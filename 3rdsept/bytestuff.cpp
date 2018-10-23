#include <iostream>
using namespace std;
char a[100],b[100];
int ind=-1,ind1=-1;
void algo(int n);

void input() {
char temp;
int counter=0;

//enter 'd' for data....& enter E & F if data resembles E & F
cout<<"Enter input data!\n";
while(1) {
	cin>>temp;
	//if(temp!='d')
	  //if(temp!='0')
	    //if(temp!='E')
	      //if(temp!='F') {
			//cout<<"wrong input!\n";
			//return;
		//}
	if(temp=='0')
			break;
	else {
		ind++;
		a[ind]=temp;
		counter++;
	}
}
algo(counter);
}

void algo(int n) {
//add flags at the ends of the frame
ind1++;
b[ind1]='F';
cout<<ind<<"test";
int i=ind+1-n;
while(i<=ind) {
//adds escape character if data resembles flag
	if(a[i]=='F' || a[i]=='E') {
		ind1++;
		b[ind1]='E';
		ind1++;
		b[ind1]=a[i];
	}
	else {
		ind1++;
		b[ind1]=a[i];
	}
  i++;
 }

//ind1++;
//b[ind1]='F';

}

void display() {
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
