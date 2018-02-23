#include "ns3/core-module.h"
#include "ns3/mobility-module.h"
#include "ns3/mobility-module.h"
#include "ns3/ns2-mobility-helper.h"
#include "ns3/network-module.h"
#include "ns3/applications-module.h"
#include "ns3/config-store-module.h"
#include "ns3/wifi-module.h"
#include "ns3/internet-module.h"
#include "ns3/olsr-helper.h"
#include "ns3/ipv4-static-routing-helper.h"
#include "ns3/ipv4-list-routing-helper.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/netanim-module.h"
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include<string>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <cstring>
struct nodem{
       int id;
	int t;
	float x,y;
	float velx;
        float vely;
        float velocity;
	int event;
	int traffic;
	float prio;
	float ttl;
	float W;
        int neighbour[10];
}nod[10];
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";

int main()
{
  int j,k=1;
  float distance[k];
memset( distance, 0, k*k*sizeof(float) );
  int rangeZ=2000;
  float xm=5000,ym=5000;
  // create a file-reading object
  ifstream fin;

  fin.open("/home/hbg/ns3/ns-allinone-3.19/ns-3.19/testmob.log"); // open a file

  if (!fin.good()) 
    return 1; // exit if file not found
  
  // read each line of the file
  while (!fin.eof())
  {
    // read an entire line into memory
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE);
    
    // parse the line into blank-delimited tokens
    int n = 0; // a for-loop index
    
    // array to store memory addresses of the tokens in buf
    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0
    for (j=1;j< 5; j++)
    {
      nod[j].event=rand()%2;
     if (nod[j].event==0)
      {nod[j].traffic=1;}
     else
      { 
	nod[j].traffic=2;
      }
    if(nod[j].event==1)
    {	
    // parse the line
    token[0] = strtok(buf, DELIMITER); // first token
    if (token[0]) // zero if line is blank
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
        if (n==1)
        nod[j].t=atoi(token[1]);
        if (n==3)
        nod[j].id=atoi(token[3]);
        if (n==5)
        nod[j].x=atof(token[5]);
        if (n==7)
        nod[j].y=atof(token[7]);
        if (n==11)
        nod[j].velx=atof(token[11]);
        if (n==13)
        nod[j].vely=atof(token[13]);
      }
    }
}

    // process (print) the tokens
for (int k=1;k<5;k++)
{   
 //if ((nod[j].velx!=0) && (nod[j].vely!=0))
 /*for (int i = 0; i < n; i++) // n = #of tokens
{
   
      //cout << "Token[" << i << "] = " << token[i] << endl;
   //edited by trp      
  cout << "nod[" << j << "].t = " << nod[j].t << " nod[" << j << "].id = " << nod[j].id<< " nod[" << j << "].x = " << nod[j].x<< " nod[" << j << "].y = " << nod[j].y<<" nod[" << j << "].velx = " << nod[j].velx<<" nod[" << j << "].vely = " << nod[j].vely <<endl;
   cout << endl;
 
  }*/

//{
  nod[k].velocity=sqrt(((nod[k].velx)*(nod[k].velx))+((nod[k].vely)*(nod[k].vely)));
  distance[k]=sqrt(pow((xm-nod[k].x),2)-pow((ym-nod[k].y),2));
 cout<<"\nThe velocity="<< nod[k].velocity<<"\n";
 cout<<"\nThe distance="<<distance[k]<<"\n";
  cout<<"\nThe traffic= "<< nod[k].traffic<<"\n";
			if(distance[k]<rangeZ)
			{
				for (int m=0;m<5;m++)
			{
			  nod[j].ttl=distance[j]/nod[j].velocity;
 			cout<<"\nThe residence time="<< nod[k].ttl<<"\n";
			 nod[j].prio=nod[j].ttl*(nod[j].traffic/2);
			cout<<"\nThe priority= "<< nod[k].prio<<"\n";
			}
                        }	
				
			
				//cout<<nod[j].velocity;
			}
			/*else
			{
				continue;
			}	*/


}
}
}




