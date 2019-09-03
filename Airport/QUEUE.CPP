#include"queue.h"

template<typename t>
queue<t>::queue()
{
	front=nullptr;
	back=nullptr;
	elements=0;
}
template<typename t>
void queue<t>::addfront_for_landing(const t _no_of_planes)
{
	node<t> *temp=nullptr,*temp1;
	t _id=max_id_for_landing();;
	t _fuel=0;
	t n=_no_of_planes;
	while(n!=0)
	{
	_id=_id+2;
	_fuel=rand()%10;
	temp=find(_fuel);
	if(temp==nullptr)
	{
		if(front==nullptr)
		{temp=new node<t>(_id,_fuel,nullptr);
		 front=temp;
		 back=temp;
		 elements++;}
		else
		{
			temp=new node<t>(_id, _fuel,front);
			front=temp;
			elements++;
		}

	}
	else
	{
		if(temp==back)
		{
		temp=new node<t>(_id,_fuel,nullptr);
		back->next=temp;
		back=back->next;
		elements++;}
		else
		{
			temp1=new node<t>(_id,_fuel,temp->next);
			temp->next=temp1;
			elements++;
		}
	}
	n--;
	}
}
template<typename t>
void queue<t>::addfront_for_takeoff(const t _no_of_planes)
{
	node<t> *temp=nullptr,*temp1;
	t _id=max_id_for_takeoff();;
	t _fuel=0;
	t n=_no_of_planes;
	while(n!=0)
	{
	_id=_id+2;
	_fuel=rand()%10;
	temp=find(_fuel);
	if(temp==nullptr)
	{
		if(front==nullptr)
		{temp=new node<t>(_id,_fuel,nullptr);
		 front=temp;
		 back=temp;
		 elements++;}
		else
		{
			temp=new node<t>(_id, _fuel,front);
			front=temp;
			elements++;
		}

	}
	else
	{
		if(temp==back)
		{
		temp=new node<t>(_id,_fuel,nullptr);
		back->next=temp;
		back=back->next;
		elements++;}
		else
		{
			temp1=new node<t>(_id,_fuel,temp->next);
			temp->next=temp1;
			elements++;
		}
	}
	n--;
	}
}
template<typename t>
void queue<t>::add_landing_plane(node<t> *temp)
{
	node<t>* temp1;
	temp1=new node<t>(temp->id,temp->fuel,nullptr);
	if(front==nullptr)
	{
		front=temp1;
		back=temp1;
		elements++;
	}
	else
	{
		back->next=temp1;
		back=back->next;
		elements++;
	}
}
template<typename t>
t queue<t>::max_id_for_landing()
{
	node<t> *temp=front;
	t max=0;
	if(temp==nullptr)
		return max;
	while(temp!=back->next)
	{
		if(max<temp->id)
			max=temp->id;
		temp=temp->next;
	}
	return max;
}
template<typename t>
t queue<t>::max_id_for_takeoff()
{
	node<t> *temp=front;
	t max=1;
	if(temp==nullptr)
		return max;
	while(temp!=back->next)
	{
		if(max<temp->id)
			max=temp->id;
		temp=temp->next;
	}
	return max;
}
template<typename t>
t queue<t>::ret_time()
{
	node<t> *temp=front; 
	t counter=0,sum=0;
	if(temp==nullptr)
		return 0;
	while(temp!=back->next)
	{
		sum=sum+temp->fuel;
		temp=temp->next;
		counter++;
	}
	sum=sum/counter;
	return sum;

}
template<typename t>
node<t> * queue<t>::ret_front()
{
	
	//assert(front != nullptr);
	return front;
} 
template <typename t>
node<t> * queue<t>::ret_back()
{
	//assert(back!= nullptr);
	return back;
} 
template< typename t>
t queue<t>::get_elements()
{
	return elements;
}
template<typename t>
void queue<t>::dec_fuel()
{
	node<t> *temp=front;
	if(temp==nullptr)
		return ;
	while(temp!=back->next)
	{
		temp->fuel=temp->fuel-1;
		temp=temp->next;
	}

}
template<typename t>
node<t> * queue<t>::get_plane()
{
	node<t> *temp=front;
	front=front->next;
	return temp;
}
template <typename t>
bool queue<t>::delete_()
{
	node<t> *curr=front;
	if(elements!=0)
	{
		curr=front;
		front=front->next;
		delete curr;
		elements--;
		if(front==nullptr)
			back=nullptr;
		return true;
	}
	else
		return false;
}
template<typename t>
node<t> * queue<t>::find(const t &_fuel)
{
	node<t> *curr=front, *prev=nullptr;
	while(curr)
	{
		if(curr->fuel<_fuel)
		{
			prev=curr;
			curr=curr->next;
		}
		else
			break;
	}
	return prev;
}
	
template<typename t>
void queue<t>::clear_queue()
{
	node<t> *curr=front;
	if(curr==nullptr)
		return ;
	while(elements!=0)
	{
		curr=front;
		front=front->next;
		delete curr;
		elements--;
		if(front==nullptr)
			back=nullptr;
	}

}

template <typename t>
void queue<t>::Printqueue ()
{
	node<t> *temp=front;
	if(temp==nullptr)
	{
		return;
	}
	cout<<"id   fuel"<<endl;
	while(temp!=back->next)
	{
		cout<<temp->id<<"    "<<temp->fuel<<endl;
	    temp=temp->next;   
	}
}
