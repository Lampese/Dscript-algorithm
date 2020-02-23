#include<bits\stdc++.h>
using namespace std;
struct Dcode{
	string type;
	string lang;
	string tg;
	int mid=1000000;
};
Dcode rd[1000000];
int rds=0;
bool cmp(Dcode a,Dcode b){
	return a.mid<b.mid?true:false;
}
void CCL(string code){
	code+="$";
	int cd=code.find('{');
	while(cd<code.size()){
			int er1=100988,er2;
			er2=code.find('}');
			string tg="";
			string lang="";
			for(int i=cd-1;i>=0;i--){
				if(code[i]=='\n'||code[i]==';'||code[i]=='}')break;
				er1=i;
				tg.insert(0,1,code[i]);
			}
			for(int i=cd+1;i<code.size();i++){
				if(code[i]=='}')break;
				lang+=code[i];
			}
			code.erase(er1,er2-er1+1);
			code.insert(er1,1,'$');
			rd[rds].type="kh";
			rd[rds].lang=lang;
			rd[rds].tg=tg;
			rd[rds].mid=(er1+er2)/2;
			rds++;
			cd=code.find('{');
	}
	string temp_lang="";
	for(int i=0;i<code.size();i++){
		if(code[i]=='$'){
			rd[rds].type="normal";
			rd[rds].lang=temp_lang;
			rd[rds].tg="";
			rd[rds].mid=i;
			rds++;
			temp_lang="";
		}
		else
			temp_lang+=code[i];
	}
	sort(rd,rd+rds+1,cmp);
}
