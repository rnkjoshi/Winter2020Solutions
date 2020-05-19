    #include<bits/stdc++.h>
    #include<string>
    typedef long long int ll;

    using namespace std;

    int main(){
        ll t;
        cin>>t;
        string days[]={" ","sunday", "monday", "tuesday", "wednesday", "thursday","friday","saturday"};
        while(t--){
            string startday,endday;
            ll day1,day2;
            cin>>startday>>endday;
            cin>>day1>>day2;
            ll totaldays = day1-day2;
            ll dayindexstart,dayindexend;
            for(int i=1;i<=7;i++){
                if(startday == days[i])
                    dayindexstart= i;
                if(endday == days[i])
                    dayindexend = i;
            }
            ll daysdifference = 0 ;
            if(dayindexend < dayindexstart){
                daysdifference = 7 + dayindexend - dayindexstart+1;
            }
            else
            {
            cout<<startday<<" is at"<<dayindexstart<<" "<<endday<<" is at"<<dayindexend<<endl;
             daysdifference = dayindexend - dayindexstart +1;
             }
            int daysdifferenceTemp = daysdifference;
            cout<<"days difference="<<daysdifference<<endl;
            int counter = 0;
            int multiple = 0;
            while(daysdifferenceTemp<=day2){
                if(daysdifferenceTemp >= day1 && daysdifferenceTemp <=day2){
                    counter++;
                }
                daysdifferenceTemp += 7;
                multiple++;
            }
            multiple--;
            if(counter == 0){
                cout<<"impossible\n";
            }
            else {
                if(counter == 1)
                    cout<<daysdifference + 7*multiple<<endl;
                else
                    cout<<"many\n";
            }
        }
    }

