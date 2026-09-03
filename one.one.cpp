
#include<iostream>
using namespace std;
void swapRef(int&a, int&b) {int t=a; a=b; b=t; }
void swapPtr(int *a, int *b) {int t=*a; *a=*b; *b=t;}
int main(){ 
    int x=10, y=20;
    swapRef (x,y);
    cout<< "after swapref : x=" << x << "y=" << y << endl;
     swapPtr( &x,&y);
     cout<< "after swapptr : x=" << x << " y="<< y << endl;
 int &alias = x;
 alias = 99;
cout << "x via alisa =" << x << endl;
return 0;
}