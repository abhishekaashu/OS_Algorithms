#include<iostream>
using namespace std;

void find_waiting_time(int processes[], int n, int bt[], int wt[]){

    wt[0]= 0;

    for(int i=1; i<n; i++){
        wt[i] = bt[i-1]+ wt[i-1];
    }
}

void find_turnaround_time(int processes[], int n, int bt[], int wt[], int tat[]){
     
     for(int i=0; i<n; i++){
         tat[i] = wt[i] + bt[i];
     }
}

void findavgtime(int processes[],int n,int bt[]){
    int wt[n], tat[n], total_wt=0, total_tat=0;

    find_waiting_time(processes, n, bt, wt);
    find_turnaround_time(processes, n, bt, wt, tat);
    
    cout<<"process "<<"burst_time "<<"waiting_time "<<"turnaround_time "<<endl;

    for(int i=0; i<n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout<<" " <<processes[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;

    }

    cout<<"Average waiting_time = "<<(float)total_wt/(float)n<<endl;
    cout<<"Average turnaround_time = "<<(float)total_tat/(float)n;

}

int main(){
    int processes[]={1,2,3,4,5};
    int n = sizeof processes/sizeof processes[0];
    int burst_time[] = {4,3,2,1,3};
    int pr[] = {2,3,4,5,5};
    
    //sorting burst time in ascending order using selection sort
    int pos,temp,i,j;
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
        
            if(pr[j]>pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
 
        temp= processes[i];
        processes[i]= processes[pos];
        processes[pos]=temp;
    }
    findavgtime( processes, n, burst_time);

}    