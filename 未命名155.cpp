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
		cout<<"��"<<i<<"����Ȧ��"<<pigpen[i].sum<<"ͷ��"<<endl;
		if(pigpen[i].judge_black==true)cout<<"�Ǻ���Ȧ";
		if(pigpen[i].judge_black==false)cout<<"�ǻ���Ȧ";
	}
	void show_pigpendepig(int m,int n){
		cout<<"��ͷ�������Ϊ"<<pigpen[m].pigpen_pig[n]->weight<<endl;
		cout<<"��������Ϊ"<<pigpen[m].pigpen_pig[n]->days<<endl;
		if(pigpen[m].pigpen_pig[n]->species==0)cout<<"�Ǻ���"; 
		if(pigpen[m].pigpen_pig[n]->species==1)cout<<"��С�׻���"; 
		if(pigpen[m].pigpen_pig[n]->species==2)cout<<"�Ǵ�׻���"; 
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
		if(i==0)cout<<"����һ����"<<all<<"ֻ"<<endl;
		if(i==1)cout<<"С�׻���һ����"<<all<<"ֻ"<<endl;
		if(i==2)cout<<"��׻���һ����"<<all<<"ֻ"<<endl;
		cout<<"������20~35֮�����"<<sum1<<"ֻ"<<endl;
		cout<<"������35~50֮�����"<<sum2<<"ֻ"<<endl;
		cout<<"������50~75֮�����"<<sum3<<"ֻ"<<endl;
		cout<<"���ش���75����"<<sum4<<"ֻ"<<endl; 
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
	mypig<<"�������������Ŀ¼"<<endl;
	mypig.close ();
		for(int i = 0;i< 100 ; i++)
        {
            for(int n = 0 ; n < pigpen[i].sum ;n++)
            {
                if(pigpen[i].pigpen_pig[n]->days > 360 || pigpen[i].pigpen_pig[n]->weight > 75.0)
                {   
                    mypig.open("sell.txt");
                    if(pigpen[i].pigpen_pig[n]->species==0)mypig<<"����"<<" ";
                    if(pigpen[i].pigpen_pig[n]->species==1)mypig<<"��׻���"<<" ";
                    if(pigpen[i].pigpen_pig[n]->species==2)mypig<<"С�׻���"<<" ";
                    mypig<<"����Ϊ"<<" "; 
                    mypig<<pigpen[i].pigpen_pig[n]->weight<<" ";
                    mypig<<"��������"<<" ";
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
int getTime() {//�������к��� 
      return clock()/CLOCKS_PER_SEC;
    }
int main(){
	Pighome a;
	srand((unsigned)time(NULL));
	cout<<"���ֶ�����һ����,����̫��Ŷ����300~600֮��";
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
	cout<<"�������"<<endl; 
	int choice0;
	cout<<"�Ѿ���ʼ�����ˣ���Ҫ�鿴���������أ�����Ҫ�Զ�����¼���ļ���"<<endl;
	cout<<"����1���鿴ĳ������"<<endl;
	cout<<"����2���Զ�����¼���ļ�"<<endl; 
	cin>>choice0;
	if(choice0==1){
	cout<<"����������"<<endl; 
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
	cout<<"����Ҫ����ʲô��?���������"<<endl;
	cout<<"1.ĳһ��Ȧ�������������"<<endl;
	cout<<"2.ĳһ��Ȧĳͷ���״̬��Ϣ"<<endl;
	cout<<"3.��ÿ��Ʒ��������������ء�����ʱ��ֲ����"<<endl;
	int choice01;
	cin>>choice01;
	if(choice01==1){
		cout<<"��һ��Ȧ��˵����"<<endl;
		int gl;
		cin>>gl;
		a.show_pigpen(gl);
	}
	if(choice01==2){
		cout<<"��������Ȧ�ż����Ʒ�֣�0������1��С�׻���2����׻���"<<endl;
		int mn;
		int nm;
		cin>>mn>>nm;
		a.show_pigpendepig(mn,nm);
	}
	if(choice01==3){
		cout<<"������Ʒ��"<<endl;
		int yu;
		cin>>yu;
		a.show_pigpenspecies_situation(yu); 
	}
    }
    if(choice0==2){
    	cout<<"������ÿ���90�����һ��ͳ�ƣ��Զ�����ۼ۸񣬲�д���ļ�"<<endl; 
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
			cout<<"��"<<allday/90<<"��"<<"���۵ļ۸�Ϊ"<<allprice<<"Ԫ"<<endl;
		}
		LastTime=now;
	}
	}
}
	return 0;
} 
