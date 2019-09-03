#ifndef QUEUE_H
#define QUEUE_H
#include<stdlib.h>
#include<iostream>
using namespace std;

template<typename t>
struct node
{
	t id;
	t fuel;
	node<t> *next;
	node()
	{
		id=0; fuel=0; next=NULL;	
	}
	node(node<t>& n)
	{
		id=n.id;
		fuel=n.fuel;
		next=n.next;
	}
	node operator =(const node<t> & n)
	{
		id=n.id;
		fuel=n.fuel;
		next=n.next;
	}
	node(t _id,t _fuel, node<t> *_next){id=_id; fuel=_fuel; next=_next;}
};


template <typename t>
class queue
{
private:
	node<t> *front;
	node<t> *back;
	int elements;
public:
	queue();
	void addfront_for_landing(const t );
	void addfront_for_takeoff(const t );
	node<t> *find(const t &);
	t max_id_for_landing();
	t max_id_for_takeoff();
	node<t> * ret_front();
	node<t> * ret_back();
	node<t> * get_plane();
	void add_landing_plane(node<t> *);
	void dec_fuel();
	t ret_time();
	void clear_queue();
	void Printqueue ();
	t get_elements();
	bool delete_();
	/*~queue()
	{
		node<t>* curr=front, *prev=front;
		while(curr!=back)
		{
			prev=curr;
			curr=curr->next;
			delete prev;
		}
		delete back;
	}*/
	
};
#endif