#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
int main(){
	int t;
	string command, parameter, temp;
	vector<string>v;
	
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		cin>>command;
		if(command=="pwd"){
			cout<<"/";
			for(int i=0; i<v.size(); i++){
				cout<<v[i]<<"/";
			}
			cout<<endl;
		}
		else{
			cin>>parameter;
			int flag=0;
			if(parameter[0]=='/'){
				v.clear();
				flag++;
			}
			//selama '/' lebih keecil dari ukuran input
			while(flag<parameter.size()){
				while(parameter[flag]!='/' && flag<parameter.size()){
					temp=temp+parameter[flag];
					flag++;
				}
				if(temp==".."){
					v.pop_back();
				}
				else{
					v.push_back(temp);
				}
				temp="";
				flag++;
			}
		}
	}
	
	
	
	
	return 0;
}