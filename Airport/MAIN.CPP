#include"queue.h"
#include"queue.cpp"
#include<windows.h>
#include<iostream>
#include<time.h>
using namespace std;


int arriving_planes()
{
	
	int a;
	a=rand()%4;
	return a;
}

int no_of_takeoff_planes()
{

	int b;
	b=rand()%4;
	return b;
}
template<typename t>
void landing_planes(queue<t> &_r1_landing_q1,queue<t> &_r1_landing_q2,queue<t> &_r2_landing_q1,queue<t> &_r2_landing_q2,queue<t> &_r3_takeoff_q,queue<t> &temp_q,t &_no_of_crashing_planes)
{
	node<t> *temp=temp_q.ret_front();
	t no_of_planes=temp_q.get_elements();
	while(no_of_planes!=0)
	{
		cout<<"plane is landing .......\n";
     	Sleep(1800);

		if(temp->fuel<=-1)
		{
			cout<<"ooo nooo plane is crashing 0-0 \n"; 
			Sleep(1800);
			_no_of_crashing_planes++;}
		if(temp->fuel==0)
		{
			cout<<"emergency landing on runway 3 due to lack of fuel \n";
			Sleep(1800);
			_r3_takeoff_q.add_landing_plane(temp);}
		else
		{
			if(_r1_landing_q1.get_elements() || _r1_landing_q2.get_elements() < _r2_landing_q1.get_elements() || _r2_landing_q2.get_elements())
			{
				if(_r1_landing_q1.get_elements()<_r1_landing_q2.get_elements())
					_r1_landing_q1.add_landing_plane(temp);
				else
					_r1_landing_q2.add_landing_plane(temp);
			}
			else
			{
				if(_r2_landing_q1.get_elements()<_r2_landing_q2.get_elements())
					_r2_landing_q1.add_landing_plane(temp);
				else
					_r2_landing_q2.add_landing_plane(temp);
			}
		}
		cout<<"fuels are decrementing\n";
		temp_q.dec_fuel();
		Sleep(1800);
		temp=temp->next;
		temp_q.delete_();
		no_of_planes--;
	}
}
template<typename t>
void takeoff_planes(queue<t> &_r1_takeoff_q,queue<t> &_r2_takeoff_q,queue<t> &_r3_takeoff_q, queue<t> &temp_q)
{
	cout<<"planes are taking off \n";
	Sleep(1800);
	node<t> *temp=temp_q.ret_front();
	t no_of_planes=temp_q.get_elements();
	while(no_of_planes!=0)
	{
		if(_r1_takeoff_q.get_elements() <= _r2_takeoff_q.get_elements() || _r3_takeoff_q.get_elements())
			_r1_takeoff_q.add_landing_plane(temp);
		else
			{if(_r2_takeoff_q.get_elements() <= _r1_takeoff_q.get_elements() || _r3_takeoff_q.get_elements())
			_r2_takeoff_q.add_landing_plane(temp);
			else 
			_r3_takeoff_q.add_landing_plane(temp);
		}
		temp_q.dec_fuel();
		temp=temp->next;
		temp_q.delete_();
		no_of_planes--;
	}
}
int main()
{   
	char input;
	srand(time(NULL));
	node<int> *temp1,*temp2;
	int no_of_planes_for_landing, no_of_planes_for_takeoff,no_of_crashing_planes=0,average_fuel_holding=0,average_fuel_landing=0,average_waiting_time=0,average_holding_takeoff_time1=0,average_holding_takeoff_time2=0;
	int waiting_time_for_landing=0;
	queue<int> holding_q1,holding_q2, holding_q3, holding_q4, holding_q_t;
	queue<int> r1_landing_q1, r1_landing_q2, r1_takeoff_q, r2_landing_q1, r2_landing_q2, r2_takeoff_q, r3_takeoff_q;
	cout<<"what do you want to do   1)start   2)terminate\n";
	cin>>input;
	int i=0;
	while(input!='2')
	{
		no_of_planes_for_landing=arriving_planes();
		no_of_planes_for_takeoff=no_of_takeoff_planes();
		cout<<"no of planes for landing\n"<<no_of_planes_for_landing<<endl;
		cout<<"no of planes for takeoff\n"<<no_of_planes_for_takeoff<<endl;
		holding_q1.addfront_for_landing(no_of_planes_for_landing);
		holding_q_t.addfront_for_takeoff(no_of_planes_for_takeoff);
		cout<<"holding queue planes for landing\n";
		holding_q1.Printqueue();
		cout<<"holding queue planes for takeoff\n";
		holding_q_t.Printqueue();
		average_fuel_holding=holding_q1.ret_time();
		average_holding_takeoff_time1=holding_q_t.ret_time();
		temp1=holding_q1.ret_front();
		temp2=holding_q_t.ret_front();
		if(temp1==nullptr && temp2!=nullptr)
			takeoff_planes(r1_takeoff_q,r2_takeoff_q,r3_takeoff_q,holding_q_t);
		else if(temp2==nullptr && temp1!=nullptr)
			landing_planes(r1_landing_q1,r1_landing_q2,r2_landing_q1,r2_landing_q2,r3_takeoff_q,holding_q1,no_of_crashing_planes);
		else if(temp1==nullptr && temp2==nullptr)
		{
		}
		else
		{
			if(temp1->fuel>=temp2->fuel){
				landing_planes(r1_landing_q1,r1_landing_q2,r2_landing_q1,r2_landing_q2,r3_takeoff_q,holding_q1,no_of_crashing_planes);
				Sleep(1800);
				takeoff_planes(r1_takeoff_q,r2_takeoff_q,r3_takeoff_q,holding_q_t);}
			else
			{takeoff_planes(r1_takeoff_q,r2_takeoff_q,r3_takeoff_q,holding_q_t);
			Sleep(1800);
			landing_planes(r1_landing_q1,r1_landing_q2,r2_landing_q1,r2_landing_q2,r3_takeoff_q,holding_q1,no_of_crashing_planes);}
		}
		average_holding_takeoff_time2=holding_q_t.ret_time();
		average_fuel_landing=average_fuel_landing+r1_landing_q1.ret_time()+r1_landing_q2.ret_time()+r2_landing_q1.ret_time()+r2_landing_q2.ret_time();
		average_fuel_landing=average_fuel_landing/4;
		average_waiting_time=average_holding_takeoff_time1-average_holding_takeoff_time2;
	
		cout<<"landing planes for runway 1\n";
		r1_landing_q1.Printqueue();cout<<endl;
		r1_landing_q2.Printqueue();cout<<endl;
		cout<<"landing planes for runway 2\n";
		r2_landing_q1.Printqueue();cout<<endl;
		r2_landing_q2.Printqueue();cout<<endl;
		cout<<"takeoff planes for runway 1,2 and 3\n";
		r1_takeoff_q.Printqueue();
		r2_takeoff_q.Printqueue();
		r3_takeoff_q.Printqueue();
		cout<<"no of planes that crashes\n"<<no_of_crashing_planes<<endl;
		if(i%3==0 && i!=0)
		{
			r1_landing_q1.clear_queue();
			r1_landing_q2.clear_queue();
			r1_takeoff_q.clear_queue();
			r2_landing_q1.clear_queue();
			r2_landing_q2.clear_queue();
			r2_takeoff_q.clear_queue();
			r3_takeoff_q.clear_queue();
		}
		cout<<"average time for landing_holding queue\n";
		cout<<average_fuel_holding<<endl;
		cout<<"average time  after landing\n";
		cout<<average_fuel_landing<<endl;
		cout<<"average waiting time for landing\n";
		waiting_time_for_landing=average_fuel_holding-average_fuel_landing;
		cout<<waiting_time_for_landing<<endl;
		cout<<"waiting time for takeoff\n";
		cout<<average_waiting_time<<endl;
		cout<<"what do you want to do 1)start again 2)terminate\n";
		cin>>input;
		system("cls");
		Sleep(1800);
		system("cls");
		if(input=='2')
			exit(1);
		cout<<"new planes are arriving\n";
		Sleep(1800);
		i++;
	}
	return 0;
}

