#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,temp,m;
    cin>>t;
    while(t--){
        int totalDist =0;
        cin>>n>>m;
        vector<vector<int> > dist(n,vector<int>(3,0));
        for(int i=0;i<m;i++){
            cin>>temp;
            dist[i][0]=temp;
            cin>>temp;
            dist[i][1]=temp;
            totalDist += abs(dist[i][0]-dist[i][1]);
        }
        cout<<"totaldist="<<totalDist<<endl;
        int DragonA = 0, DragonB = 0;
        DragonA = dist[0][1];
        int minimumDist = 0 , finalMinDist = INT_MAX;
        if(m==1){
            cout<<totalDist<<endl;
            continue;
        }
        for(int i=1;i<m;i++){
            DragonA = dist[0][1];
            minimumDist=0;
            cout<<"dragonB took = "<<i<<endl;
            DragonB = dist[i][1];
            for(int j=1;j<m;j++){
                if(j<i){
                        cout<<"check1\n";
                    minimumDist += abs(dist[j][0]-DragonA);
                    cout<<"new starting point="<<dist[j][0]<<"last dragonA loc="<<DragonA<<endl;
                    DragonA = abs(dist[j][1]);
                    cout<<"new position of A = "<<DragonA<<"and min dist="<<minimumDist<<endl;
                }
                if(j>i){
                    if(abs(dist[j][0]-DragonA) < abs(dist[j][0]-DragonB)){
                        cout<<"check2.1\n";
                        minimumDist += abs(dist[j][0]-DragonA);
                        DragonA = abs(dist[j][1]);
                        cout<<"new position of A = "<<DragonA<<"and min dist="<<minimumDist<<endl;
                    }
                    else{
                        cout<<"check2.2\n";
                        minimumDist += abs(dist[j][0]-DragonB);
                        DragonB = abs(dist[j][1]);
                        cout<<"new position of B = "<<DragonB<<"and min dist="<<minimumDist<<endl;
                    }
                }
            }
            cout<<"temp min dist = "<<minimumDist<<endl;
            if(minimumDist<finalMinDist)
                finalMinDist=minimumDist;
        }
        //for(int i=1;i<m;i++)
          //  finalMinDist+=dist[i][2];
        cout<<finalMinDist+totalDist<<endl;
    }
}
