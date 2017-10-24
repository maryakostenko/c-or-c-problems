#include<iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctime>

using namespace std;

//Functia gasirei calitatei membrului a populatiei//
 int gas(int x){
int y=-1*(x-4)*(x-15)*(x-20)*(x-26)*(x-40)*(x-45)*(x-51)*(x-57);
 return y;
 }
//Functia transformarei din numar binar in zecimal//
long long  trmBinToDec(long long n){
 int d = 0, i = 0, p;
    while (n!=0)
    {
        p = n%10;
        n /= 10;
        d += p*pow(2,i);
        ++i;
    }
    return d;
}

//Functia transformarei din numar zecimal in  binar//
int trDecToBin(int n){long long b = 0;
    int u, i = 1;

    while (n!=0)
    {
        u = n%2;
               n /= 2;
        b += u*i;
        i *= 10;
}
return b;}
//Functia adaugarii 0zerourilor la inceputul numarului binar, pentru a avea 7 pozitii in numar//
string tpo(long long h ){
char f[7];
string p;
itoa(h,f,10);
char f1[7]="0",f2[7]="00" ,f3[7]="000",f4[7]="0000",f5[7]="00000",f6[7]="000000";
int n=strlen(f);
switch(n){
case 6:
{strcat(f1,f);
p=string(f1);
break;}
case 5:
{strcat(f2,f);
p=string(f2);
break;}
case 4:
{strcat(f3,f);
p=string(f3);
break;}
case 3:
{strcat(f4,f);
p=string(f4);
break;}
case 2:
{strcat(f5,f);
p=string(f5);
break;}
case 1:
{strcat(f6,f);
p=string(f6);
break;}
case 7:
{p=string(f);
break;}
}
return p;
}

//Functia principala//
int main(){
    srand(time(NULL));
string j,a1,a2,r1,r;
int v[10],i,y[10],d,d1,m1,m2,m3,m4,n,w,w1,q1,q2,q3,q4,u;
char t2,t4;
long long sp,sp1;
//Introducem nr. de generatii//
cout <<"Introduceti numarul de generatii:"<<endl;
cin>>n;
sp=0;

//Generam prima generatie//

for(i=0;i<4;i++)
v[i] = rand()%63;
cout <<"Prima generatie:"<<endl;
for(i=0;i<4;i++){
y[i]=gas(v[i]);
//Calculam calitatea generatiei 1//
sp+=gas(v[i]);
//Afisem membrii generatiei 1, in forma decimala, binara si calitatea//
 cout << "pentru x= "<<v[i]<<" y= "<<y[i]<<" numar binar  "<<tpo(trDecToBin(v[i]))<< endl;}
 cout <<endl;

//Afisem calitatea generatiei 1//

  cout <<"Calitatea generatiei 1"<<" = "<<sp<<endl;
 u=1;while(u<n){
 cout<<"Generatie"<<u+1<<endl;
  w=rand()%6+1;
w1=rand()%6+1;
 q1=rand()%4;
 q2=rand()%4;
  while(q2==q1){
    q2=rand()%4;}
  q3=rand()%4;
     while(q3==q1||q3==q2){
    q3=rand()%4;}
   q4=rand()%4;
     while(q4==q1||q4==q2||q4==q3){
    q4=rand()%4;}

   cout <<"Avem urmatoare cupluri parintale: "<<q1<<"+"<< q2<<" in "<<w<<endl;
   cout  <<"Avem urmatoare cupluri parintale: "<<q3<<"+"<< q4<<"in "<<w1<<endl;
   //Creem cupluri parentale//

       a1=(tpo(trDecToBin(v[q1])).substr(0,w))+(tpo(trDecToBin(v[q2])).substr(w,6));
    a2=(tpo(trDecToBin(v[q3])).substr(0,w1))+(tpo(trDecToBin(v[q4])).substr(w1,6));
          cout <<"Copii fara mutatie"<< endl;
           cout <<a1<<endl;
            cout <<a2<< endl;

//Verificam la mutatie//

m1=rand()%2;
if(m1==1){
        m2=rand()%6+0;
 r=a1.substr(m2,1);
if(r=="1")
    t2='0';
else t2='1';
a1[m2]=t2;
}
m3=rand()%2;
if(m3==0){
                m4=rand()%6+0;
 r1=a2.substr(m4,1);
if(r1=="1")
    t4='0';
else t4='1';
a2[m4]=t4;
}
cout <<"Copii dupa verificare ,daca a fost mutatie"<< endl;


long long s1=atoi(a1.c_str());
long long s2=atoi(a2.c_str());
d=trmBinToDec(s1);
d1=trmBinToDec(s2);
  cout <<a1<<"= "<<d<<" cu calitatea = "<<gas(d)<< endl;
            cout <<a2<<" = "<<d1<<" cu calitatea ="<<gas(d1)<< endl;
            int ji=0;
            int ma1=gas(v[0]);
            for( i=1;i<3;i++){
                    if(gas(v[i])<ma1){
                    ma1=gas(v[i]);
                   ji=i;}}
                   //Verificam daca calitatea copilului 1 creat este mai mere ,
                   //decat calitatea minimala a grupei, daca e adevarat inlocuim
                   //membrul cel mai slab cu copilul cret //
if(gas(d)>ma1)
   v[ji]=d;
int ji1=0;
int ma3=gas(v[0]);
            for( i=1;i<3;i++){
                    if(gas(v[i])<ma3){
                    ma3=gas(v[i]);
                    ji1=i;}}
  //Verificam daca calitatea copilului 2 creat este mai mere ,
                   //decat calitatea minimala a grupei, daca e adevarat inlocuim
                   //membrul cel mai slab cu copilul cret //
   if(gas(d1)>ma3)
   v[ji1]=d1;
sp1=0;
 cout<<"Avem urmatoarele membrii a generatiei"<< endl;
    for(i=0;i<4;i++){
         //Calculam calitatea generatiei u//
            sp1+=gas(v[i]);
//Afisem membrii generatiei u, in forma decimala, binara si calitatea//
        cout << "pentru x= "<<v[i]<<" y= "<<gas(v[i])<<" numar binar  "<<tpo(trDecToBin(v[i]))<< endl;}
 //Afisem calitatea generatiei u//
 cout <<"Calitatea generatiei nr."<<u+1<<" = "<<sp1<<endl;
 u++;
  cout<<endl;
}
 }




