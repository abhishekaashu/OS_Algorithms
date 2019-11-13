//page repalcement algo-optimal
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
    initialize();
    int near[50];
    for(i=0; i<n; i++)
    {
 
        cout<<"\nFor"<<" "<<in[i]<<":";
 
        if(isHit(in[i])==0)
        {
 
            for(j=0; j<nf; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i; k<n; k++)
                {
                    if(pg==in[k])
                    {
                        near[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    near[j]=9999;
            }
            int max=-9999;
            int repindex;
            for(j=0; j<nf; j++)
            {
                if(near[j]>max)
                {
                    max=near[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i];
            pgfaultcnt++;
 
            dispages();
        }
        else
            cout<<"No page fault";
    }
    dispgfaultcnt();
}