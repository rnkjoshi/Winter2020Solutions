#include <bits/stdc++.h>
#include<string>
using namespace std;
int counter = 0;
bool compareStrings(string a, string b){
	if(a<b)
	    counter++;
	return a<b;
}

int main()
{
	int t;
	cin>>t;
	for(int test=1;test<=t;test++){
    	int n;

    	cin>>n;
        vector< pair<string,int> > namesNew;
        vector<string> names;
        string name;
        cin.ignore();
    	for(int i=0;i<n;i++){
            getline(cin,name);
    		namesNew.push_back(make_pair(name,i));
    	}
        counter=0;
        for(int i=n-1;i>0;i--){
            for(int j=i-1;j>=0;j--){
                if(namesNew[i].first < namesNew[j].first){
                    counter++;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",test,counter);
	}
	return 0;
}
