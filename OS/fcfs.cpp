#include<iostream>
using namespace std;

int main()
{
int n;

cout<<"Enter no. of processes = ";
cin>>n;

int AT[100],BT[100],CT[100],WT[100],TAT[100],RT[100];

cout<<"Enter Arrival Time(AT) : "<<endl;
for(int i=0;i<n;i++){
    cout<<"For Process "<<i+1<<"= ";
    cin>>AT[i];
}


cout<<"\nEnter Burst Time(BT) : "<<endl;
for(int i=0;i<n;i++){
    cout<<"For Process "<<i+1<<"= ";
    cin>>BT[i];
}


return 0;

}