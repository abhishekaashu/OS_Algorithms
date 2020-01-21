//page repalcement algo-Second Chance
#include<iostream>
using namespace std;

int n, nf, i, j, k, pgfaultcnt = 0, hit = 0;
int in[100],p[50],count[20];

void getdata(){
    cout<<"Enter the length of page refrence seq:"<<endl;
    cin>>n;
    cout<<"Enter the page refrence seq:"<<endl;
    for(i =0; i<n; i++){
        cin>>in[i];
    }
    cout<<"Enter no of frames:"<<endl;
    cin>>nf;
}

void initialize(){
    pgfaultcnt = 0;
    for(i=0; i<nf; i++)
    p[i] = -1;

}

int isHit(int data){
    hit = 0;
    for(j = 0; j<nf; j++){
        if(p[j] == data){
            hit = 1;
            break;
        }
    }
    return hit;
}

int getHitIndex(int data)
{
    int hitind;
    for(k=0; k<nf; k++)
    {
        if(p[k]==data)
        {
            hitind=k;
            break;
        }
    }
    return hitind;
}
void dispages(){
    for(k=0; k<nf; k++){
     
        if(p[k]!=-1){
            cout<<p[k]<<" ";
        }
    }
      
}

void dispgfaultcnt(){
    cout<<"\nTotal no of page faults:"<<pgfaultcnt;
}
int main(){
    getdata();
    int usedbit[50];
    int victimptr=0;
    initialize();
    for(i=0; i<nf; i++)
        usedbit[i]=0;
    for(i=0; i<n; i++)
    {
        cout<<"\nFor"<<" "<<in[i]<<":";
        if(isHit(in[i]))
        {
            cout<<"No page fault!";
            int hitindex=getHitIndex(in[i]);
            if(usedbit[hitindex]==0)
                usedbit[hitindex]=1;
        }
        else
        {
            pgfaultcnt++;
            if(usedbit[victimptr]==1)
            {
                do
                {
                    usedbit[victimptr]=0;
                    victimptr++;
                    if(victimptr==nf)
                        victimptr=0;
                }
                while(usedbit[victimptr]!=0);
            }
            if(usedbit[victimptr]==0)
            {
                p[victimptr]=in[i];
                usedbit[victimptr]=1;
                victimptr++;
            }
            dispages();
 
        }
        if(victimptr==nf)
            victimptr=0;
    }
    dispgfaultcnt();
}