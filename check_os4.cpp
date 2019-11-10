//first fit
#include<iostream>
using namespace std;

int main(){
    int bno, pno, i, j;
    int bsize[10], psize[10], flag[10], alloc[10];

    for(i=0; i<10; i++){
        flag[i] = 0;
        alloc[i] = -1;
    }

    cout<<"Enter no. of blocks: ";
    cin>>bno;
    
    cout<<"\nEnter size of each block: ";
    for( i=0; i<bno; i++){
        cin>>bsize[i];
    }
    cout<<"\nEnter no. of processes: ";
    cin>>pno;

    cout<<"\nEnter size of each process: ";
    for(i=0; i<pno; i++){
        cin>>psize[i];
    }

    for(i=0; i<pno; i++){
        for(j=0; j<bno; j++){
            if(flag[j]==0 && bsize[j]>= psize[i])
            {
                alloc[j] = i;
                flag[j] = 1;
                break;
            }
        }
    }

    cout<<"Block-no"<<"\t"<<"block_size"<<"\t"<<"process_no"<<"\t"<<"size";
    for(i=0; i<bno; i++){
        cout<<"\n"<<i+1<<"\t\t"<<bsize[i]<<"\t\t";
        if(flag[i] == 1){
            cout<<alloc[i]+1<<"\t\t"<<psize[alloc[i]]<<endl;
        }
        else{
            cout<<"Not allocated";
        }
       
    }
     return 0;

}

