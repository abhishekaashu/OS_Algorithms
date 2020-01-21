//page repalcement algo-LFU
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

    int usedcnt[100];
    int least,repin,sofarcnt=0,bn;
    initialize();
    for(i=0; i<nf; i++)
        usedcnt[i]=0;
 
    for(i=0; i<n; i++)
    {
 
       
        cout<<"\nFor"<<" "<<in[i]<<":";
        if(isHit(in[i]))
        {
            int hitind=getHitIndex(in[i]);
            usedcnt[hitind]++;
            cout<<"No page fault!";
        }
        else
        {
            pgfaultcnt++;
            if(bn<nf)
            {
                p[bn]=in[i];
                usedcnt[bn]=usedcnt[bn]+1;
                bn++;
            }
            else
            {
                least=9999;
                for(k=0; k<nf; k++)
                    if(usedcnt[k]<least)
                    {
                        least=usedcnt[k];
                        repin=k;
                    }
                p[repin]=in[i];
                sofarcnt=0;
                for(k=0; k<=i; k++)
                    if(in[i]==in[k])
                        sofarcnt=sofarcnt+1;
                usedcnt[repin]=sofarcnt;
            }
 
            dispages();
        }
 
    }
    dispgfaultcnt();
}