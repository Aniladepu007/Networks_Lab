/*
CED16I002
Anil Kumar Adepu
Implements leaky bucket algorithm using FIFO queue (array implementation)

if a packet is larger than the bucket size, then it is dropped else transmitted provided if a packet causes overflow
then bucket is emptied first and then the packet is trasmitted
*/

#include <iostream>
using namespace std;

int main() {
int NoF_packets, t_rate, b_size;
cout<<"Enter no. of packets!\n";
      cin>>NoF_packets;

int packets[NoF_packets];
cout<<"Enter sizes of packets\n";
for(int i=1;i<=NoF_packets;i++)
      cin>>packets[i];

cout<<"\nEnter transmission rate(in Mbps)!\n";
      cin>>t_rate;
cout<<"Enter bucket size!\n";
      cin>>b_size;

int rem_size=0;
//initialize 'i' for iterating  thru' packets
int i=1;
while(i<=NoF_packets) {
      //case where incoming packet is rejected(size > bucket size)
      if(packets[i] > b_size) {
            cout<<"\n\nPacket size " <<packets[i]<<" is greater than the b_size! hence rejected!\n";
            i++;
      }
      else {
            //overflow case where incoming packet could overload the bucket although having a smaller size than the bucket
            if(packets[i] + rem_size > b_size) {
                  cout<<"\n\nBucket overflowed ...hence packet "<<i<<" of size "<<packets[i]<<" is not currently accepted!\n\n";
                  cout<<"present size(before transmission) : "<<rem_size<<endl;
                  while(rem_size >= t_rate) {
                        rem_size -= t_rate;
                        cout<<"rem size after 1 transmission     : "<<rem_size<<endl;
                  }
            }
            else {
                  //case where incoming packet is accepted
                  rem_size += packets[i];
                  cout<<"\n\npacket "<<i<<" of size "<<packets[i]<<" is accepted!\n";
                  cout<<"present size(before transmission) : "<<rem_size<<endl;
                  rem_size -= t_rate;
                  cout<<"rem size after 1 transmission     : "<<rem_size<<endl;
                  i++;
            }
//i++;
      }
}
cout<<"\n\nEmptying the bucket after n iterations\n";
if(rem_size!=0) {
      cout<<"present size(before transmission) : "<<rem_size<<endl;
      while(rem_size >= t_rate) {
            rem_size -= t_rate;
            cout<<"rem size after 1 transmission     : "<<rem_size<<endl;
      }
}
      return 0;
}
