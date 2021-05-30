#include<iostream>
#include<time.h>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;
struct Pig{
    float weight=0;
    int days=0;
    int pigpen=0;
    int species=0;
    Pig *next=NULL;
};
struct Pigpen{
    Pig* start=NULL;  
    Pig* end=NULL;
    int judge_black=0;
    int sum=0;
    Pig* pigpen_pig[10]={NULL};
};
class Pighome{
	private:
	Pigpen pigpen[100];
	int allpig=0;
	int num0;
	int num1;
	int num2;
	public:
    void addblackpig(){
    	int mixblack_index=0;
    	int mixflower_index=0;
    	while(num0+1){
    		bool judge=0;
    		for(int i=0;i<100;i++){
    			if(pigpen[i].judge_black==1&&pigpen[i].sum<10){
    				mixblack_index=i;
    				judge=true;
    				break;
				}
			}
			if(judge==true){
				for(int i=0;i<100;i++){
					if(pigpen[i].judge_black==1&&pigpen[i].sum<pigpen[mixblack_index].sum){
						mixblack_index=i;
					}
				}
				add(mixblack_index,0);
				num0--; 
			}
			else{
				for(int i=0;i<100;i++){
					if(pigpen[i].judge_black==0){
						mixflower_index=i;
						break;
					}
				}
				for(int i=0;i<100;i++){
					if(pigpen[i].judge_black==0&&pigpen[i].sum<pigpen[mixflower_index].sum){
						mixflower_index=i;
					}
				}
				if(pigpen[mixflower_index].start!=NULL)movepig(mixflower_index);
				pigpen[mixflower_index].judge_black=1;
				add(mixflower_index,0);
				num0--;
			}
			mixblack_index=0;
			mixflower_index=0;
		}                          
		return; 
	}
	void addflowerpig(){
		int mixflower_index=0;
		while(num1+1){
			for(int i=0;i<100;i++){
				if(pigpen[i].judge_black==0){
					mixflower_index=i;
					break;
				}
			}
			for(int i=0;i<100;i++){
				if(pigpen[i].judge_black==0&&pigpen[i].sum<pigpen[mixflower_index].sum){
					mixflower_index=i;
				}
			}
			add(mixflower_index,1);
			num1--;
			mixflower_index=0;
		}
		while(num2+1){
			for(int i=0;i<100;i++){
				if(pigpen[i].judge_black==0){
					mixflower_index=i;
					break;
				}
			}
			for(int i=0;i<100;i++){
				if(pigpen[i].judge_black==0&&pigpen[i].sum<pigpen[mixflower_index].sum){
					mixflower_index=i;
				}
			}
			add(mixflower_index,2);
			num2--;
			mixflower_index=0; 
		}
		return;
	}
	void add(int i,int s){
		if(pigpen[i].start==NULL){
			Pig *p=new Pig;
			pigpen[i].start=p;
			pigpen[i].end=p;
			p->next=NULL;
			p->weight=((double)(rand()%301)+200)/10.0;
			p->pigpen=i;
			p->species=s;
			pigpen[i].pigpen_pig[pigpen[i].sum]=p;
			pigpen[i].sum++;
		}
		else{
			Pig *p=new Pig;
			pigpen[i].end->next=p;
			pigpen[i].end=p;
			p->next=NULL;
			p->weight=((double)(rand()%301+200))/10.0;
			p->pigpen=i;
			p->species=s;
			pigpen[i].pigpen_pig[pigpen[i].sum]=p;
			pigpen[i].sum++;
		}
		return;
	}
	void movepig(int i){
		while(1)
    {
        int temp_mixflower;
        for(int j =0 ;j<100;j++)
        {
            if(j == i) continue;
            if(pigpen[j].judge_black ==0 )    
            {
                temp_mixflower = j; 
                break;
            }
        }
        for(int j = 0;j < 100 ; j++)
        {
            if(j == i) continue;
            if(pigpen[j].judge_black == 0 && pigpen[j].sum < pigpen[temp_mixflower].sum)
            {
                temp_mixflower = j;
            }
        }
        if(pigpen[i].start == pigpen[i].end)
        {
            Pig *p1 = pigpen[i].start;
            pigpen[i].start = NULL;
            pigpen[i].end = NULL;
            pigpen[i].sum = 0;
            for(int l = 0;l < 10 ;l++)
            {   
                pigpen[i].pigpen_pig[l] = NULL;
            }      
            pigpen[temp_mixflower].end->next = p1;
            pigpen[temp_mixflower].end = p1;
            p1->next = NULL;
            pigpen[temp_mixflower].pigpen_pig[pigpen[temp_mixflower].sum] = p1;
            pigpen[temp_mixflower].sum++;
            p1->pigpen = temp_mixflower;
            break;

        }
        else
        {
            Pig *p1 = pigpen[i].start;
            pigpen[i].start = p1->next;
            p1->next = NULL;
            pigpen[i].sum--;
            pigpen[temp_mixflower].end->next = p1;
            pigpen[temp_mixflower].end = p1;
            pigpen[temp_mixflower].pigpen_pig[pigpen[temp_mixflower].sum] = p1;
            pigpen[temp_mixflower].sum++;
            p1->pigpen = temp_mixflower;
        }
    }
    return;
	}
    void pig_grow(){
    	for(int i=0;i<100;i++){
    		for(int j=0;j<pigpen[i].sum;j++){
    			pigpen[i].pigpen_pig[j]->days+=1;
    			pigpen[i].pigpen_pig[j]->weight+=((double)(rand()%13))/10.0;
			}
		}
		return;
	}
    void set_num0(int i){
    	num0=i;
	} 
	void set_num1(int i){
		num1=i;
	}
	void set_num2(int i){
		num2=i;
	}
	void show_pigpen(int i){
		cout<<"第"<<i<<"号猪圈有"<<pigpen[i].sum<<"头猪"<<endl;
		if(pigpen[i].judge_black==true)cout<<"是黑猪圈";
		if(pigpen[i].judge_black==false)cout<<"是花猪圈";
	}
	void show_pigpendepig(int m,int n){
		cout<<"这头猪的体重为"<<pigpen[m].pigpen_pig[n]->weight<<endl;
		cout<<"饲养天数为"<<pigpen[m].pigpen_pig[n]->days<<endl;
		if(pigpen[m].pigpen_pig[n]->species==0)cout<<"是黑猪"; 
		if(pigpen[m].pigpen_pig[n]->species==1)cout<<"是小白花猪"; 
		if(pigpen[m].pigpen_pig[n]->species==2)cout<<"是大白花猪"; 
	}
	void show_pigpenspecies_situation(int i){
		int all;
		int sum1=0,sum2=0,sum3=0,sum4=0;
		for(int m=0;m<100;m++){
			for(int n=0;n<pigpen[m].sum;n++)
			if(pigpen[m].pigpen_pig[n]->species==i){
				all++;
				if(pigpen[m].pigpen_pig[n]->weight>=20&&pigpen[m].pigpen_pig[n]->weight<=35)sum1++;
				if(pigpen[m].pigpen_pig[n]->weight>35&&pigpen[m].pigpen_pig[n]->weight<=50)sum2++;
				if(pigpen[m].pigpen_pig[n]->weight>50&&pigpen[m].pigpen_pig[n]->weight<=75)sum3++;
				if(pigpen[m].pigpen_pig[n]->weight>50&&pigpen[m].pigpen_pig[n]->weight<=75)sum4++;
			}
		}
		if(i==0)cout<<"黑猪一共有"<<all<<"只"<<endl;
		if(i==1)cout<<"小白花猪一共有"<<all<<"只"<<endl;
		if(i==2)cout<<"大白花猪一共有"<<all<<"只"<<endl;
		cout<<"体重在20~35之间的有"<<sum1<<"只"<<endl;
		cout<<"体重在35~50之间的有"<<sum2<<"只"<<endl;
		cout<<"体重在50~75之间的有"<<sum3<<"只"<<endl;
		cout<<"体重大于75的有"<<sum4<<"只"<<endl; 
	}
	double sellpig_price(){
		int x;
		for(int i = 0;i< 100 ; i++)
        {
            for(int n = 0 ; n < pigpen[i].sum ;n++)
            {
                if(pigpen[i].pigpen_pig[n]->days > 360 || pigpen[i].pigpen_pig[n]->weight > 75.0)
                {
                    if(pigpen[i].pigpen_pig[n] == pigpen[i].start)
                    {
                        pigpen[i].start = pigpen[i].pigpen_pig[n]->next;
                        Pig *p1 = pigpen[i].pigpen_pig[n];
                        for(int k = n;k < pigpen[i].sum-1;k++)
                        {
                            pigpen[i].pigpen_pig[k] = pigpen[i].pigpen_pig[k+1];
                        }
                        pigpen[i].pigpen_pig[pigpen[i].sum-1] = NULL;
                        pigpen[i].sum--;
                        allpig--;
                        if(pigpen[i].sum == 0) pigpen[i].judge_black =0;
                       p1->next = NULL;
                       if(p1->species == 0)
                       {
                           x += p1->weight*30.0;
                       }
                       else if(p1->species == 1)
                       {
                           x += p1->weight*14.0;
                       }
                       else if(p1->species == 2)
                       {
                           x += p1->weight*12.0;
                       }
                       delete p1;
                       n--;
                    }
                    else if(pigpen[i].end == pigpen[i].pigpen_pig[n]&&pigpen[i].start!=pigpen[i].pigpen_pig[n])
                    {
                        pigpen[i].end = pigpen[i].pigpen_pig[n-1];
                        pigpen[i].end->next = NULL;
                        Pig *p1 = pigpen[i].pigpen_pig[n];
                        pigpen[i].pigpen_pig[n] = NULL;
                        pigpen[i].sum--;
                        allpig--;
                        if(p1->species == 0)
                        {
                            x += p1->weight*30.0;
                        }
                        else if(p1->species == 1)
                        {
                            x += p1->weight*14.0;
                        }
                        else if(p1->species == 2)
                        {
                            x += p1->weight*12.0;
                        }


                        delete p1;
                    }
                    else
                    {
                        pigpen[i].pigpen_pig[n-1]->next = pigpen[i].pigpen_pig[n]->next;
                        Pig *p1 = pigpen[i].pigpen_pig[n];
                        for(int k = n;k < pigpen[i].sum - 1 ; k++)
                        {
                            pigpen[i].pigpen_pig[k] =pigpen[i].pigpen_pig[k+1];
                        }
                        pigpen[i].pigpen_pig[pigpen[i].sum-1] = NULL;
                        pigpen[i].sum--;
                        allpig--;
                        if(p1->species == 0 )
                        {
                            x += p1->weight*30;
                        }
                        else if(p1->species == 1)
                        {
                            x += p1->weight*14.0;
                        }
                        else if(p1->species == 2)
                        {
                            x += p1->weight*12.0;
                        }
                        delete p1;
                        n--;
                    }
                }
            }
        }
		return x;
	}
    void sell_pig(){
    ofstream mypig;
	mypig.open("sell.txt");
	mypig<<"下面是卖出猪的目录"<<endl;
	mypig.close ();
		for(int i = 0;i< 100 ; i++)
        {
            for(int n = 0 ; n < pigpen[i].sum ;n++)
            {
                if(pigpen[i].pigpen_pig[n]->days > 360 || pigpen[i].pigpen_pig[n]->weight > 75.0)
                {   
                    mypig.open("sell.txt");
                    if(pigpen[i].pigpen_pig[n]->species==0)mypig<<"黑猪"<<" ";
                    if(pigpen[i].pigpen_pig[n]->species==1)mypig<<"大白花猪"<<" ";
                    if(pigpen[i].pigpen_pig[n]->species==2)mypig<<"小白花猪"<<" ";
                    mypig<<"体重为"<<" "; 
                    mypig<<pigpen[i].pigpen_pig[n]->weight<<" ";
                    mypig<<"饲养天数"<<" ";
					mypig<<pigpen[i].pigpen_pig[n]->days<<" ";
					mypig.close(); 
                    if(pigpen[i].pigpen_pig[n] == pigpen[i].start)
                    {
                        pigpen[i].start = pigpen[i].pigpen_pig[n]->next;
                        Pig *p1 = pigpen[i].pigpen_pig[n];
                        for(int k = n;k < pigpen[i].sum-1;k++)
                        {
                            pigpen[i].pigpen_pig[k] = pigpen[i].pigpen_pig[k+1];
                        }
                        pigpen[i].pigpen_pig[pigpen[i].sum-1] = NULL;
                        pigpen[i].sum--;
                        allpig--;
                        if(pigpen[i].sum == 0) pigpen[i].judge_black =0;
                       p1->next = NULL;
                       delete p1;
                       n--;
                    }
                    else if(pigpen[i].end == pigpen[i].pigpen_pig[n]&&pigpen[i].start!=pigpen[i].pigpen_pig[n])
                    {
                        pigpen[i].end = pigpen[i].pigpen_pig[n-1];
                        pigpen[i].end->next = NULL;
                        Pig *p1 = pigpen[i].pigpen_pig[n];
                        pigpen[i].pigpen_pig[n] = NULL;
                        pigpen[i].sum--;
                        allpig--;
                        delete p1;
                    }
                    else
                    {
                        pigpen[i].pigpen_pig[n-1]->next = pigpen[i].pigpen_pig[n]->next;
                        Pig *p1 = pigpen[i].pigpen_pig[n];
                        for(int k = n;k < pigpen[i].sum - 1 ; k++)
                        {
                            pigpen[i].pigpen_pig[k] =pigpen[i].pigpen_pig[k+1];
                        }
                        pigpen[i].pigpen_pig[pigpen[i].sum-1] = NULL;
                        pigpen[i].sum--;
                        allpig--;
                        delete p1;
                        n--;
                    }
                }
            }
        }
		return;
}
};
int getTime() {//按秒运行函数 
      return clock()/CLOCKS_PER_SEC;
    }
int main(){
	Pighome a;
	srand((unsigned)time(NULL));
	cout<<"先手动输入一批猪,不能太少哦，在300~600之间";
	int num3;
	cin>>num3;
	int x=0;
	int sum00=0;
	int sum01=0;
	int sum02=0;
	for(int i=0;i<num3;i++){
		x=rand()%3;
		if(x==0)sum00++;
		if(x==1)sum01++;
		if(x==2)sum02++;
	} 
	a.set_num0(sum00);
	a.set_num1(sum01);
	a.set_num2(sum02);
	a.addflowerpig();
	a.addblackpig();
	a.set_num0(0);
	a.set_num1(0);
	a.set_num2(0);
	cout<<"生成完毕"<<endl; 
	int choice0;
	cout<<"已经开始养猪了，您要查看哪天的情况呢，还是要自动养猪录入文件呢"<<endl;
	cout<<"输入1：查看某天的情况"<<endl;
	cout<<"输入2：自动养猪录入文件"<<endl; 
	cin>>choice0;
	if(choice0==1){
	cout<<"请输入天数"<<endl; 
	int day;
	cin>>day;
	for(int i=0;i<day;i++){
		a.pig_grow();
		if(i%90==0){
			int b;
			int sum000=0;
	        int sum001=0;
	        int sum002=0;
	        int species1=0;
			b=rand()%5+20;
			for(int j=0;j<b;j++){
	            int species1=0;
				species1=rand()%3;
				if(species1==0)sum000++;
				if(species1==1)sum001++;
				if(species1==2)sum002++;
			}
			a.set_num0(sum000);
			a.set_num1(sum001);
			a.set_num2(sum002);
			a.addflowerpig();
			a.addblackpig();
			a.sell_pig();
			a.set_num0(0);
			a.set_num1(0);
			a.set_num2(0);
		}
	}
	cout<<"您需要查找什么呢?请输入序号"<<endl;
	cout<<"1.某一猪圈猪的数量和种类"<<endl;
	cout<<"2.某一猪圈某头猪的状态信息"<<endl;
	cout<<"3.猪场每个品种猪的数量和体重、饲养时间分布情况"<<endl;
	int choice01;
	cin>>choice01;
	if(choice01==1){
		cout<<"哪一猪圈，说个数"<<endl;
		int gl;
		cin>>gl;
		a.show_pigpen(gl);
	}
	if(choice01==2){
		cout<<"请输入猪圈号及猪的品种：0：黑猪，1：小白花猪，2：大白花猪"<<endl;
		int mn;
		int nm;
		cin>>mn>>nm;
		a.show_pigpendepig(mn,nm);
	}
	if(choice01==3){
		cout<<"请输入品种"<<endl;
		int yu;
		cin>>yu;
		a.show_pigpenspecies_situation(yu); 
	}
    }
    if(choice0==2){
    	cout<<"接下来每间隔90秒进行一次统计，自动输出售价格，并写入文件"<<endl; 
    	int allday=0;
    	int allprice=0;
    	int LastTime=0;
    	while(1){
            int now=getTime();
            if(now-LastTime>0){
        	a.pig_grow();
		    allday++;
		if(allday%90==0){
			int bq;
			int sum010=0;
	        int sum011=0;
	        int sum012=0;
	        int species2=0;
			bq=rand()%5+20;
			for(int j=0;j<bq;j++){
	            int species2=0;
				species2=rand()%3;
				if(species2==0)sum010++;
				if(species2==1)sum011++;
				if(species2==2)sum012++;
			}
			a.set_num0(sum010);
			a.set_num1(sum011);
			a.set_num2(sum012);
			a.addflowerpig();
			a.addblackpig();
			allprice+=a.sellpig_price();
			a.set_num0(0);
			a.set_num1(0);
			a.set_num2(0);
			cout<<"第"<<allday/90<<"次"<<"出售的价格为"<<allprice<<"元"<<endl;
		}
		LastTime=now;
	}
	}
}
	return 0;
} 
