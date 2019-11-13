//page repalcement algo-fifo
#include<iostream>
using namespace std;

int n, nf, i, j, k, pgfaultcnt = 0, hit = 0;
int in[100],p[50];

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
    pgfaultcnt =0;
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
    for(i=0; i<n; i++){
        cout<<"\nfor "<<in[i]<<": ";

        if(isHit(in[i]) == 0){
            for(k=0; k<nf-1; k++){
                p[k] = p[k+1];
            }
            p[k]=in[i];
            pgfaultcnt++;
            dispages();

        }
        else{
            cout<<"No page fault";
        }
    }
    dispgfaultcnt();
   
}