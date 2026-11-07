


#include <iostream>




class Node
{
public:
    int data;
    Node*prev;
    Node*next;

    Node(int value)
    {
        data=value;
        prev=nullptr;
        next=nullptr;
    }
};

class DLL
{
private:
    Node*head;
    Node*tail;
    int length;

public:
    DLL()
    {
        head=nullptr;
        tail=nullptr;
        length=0;
    }
    ~DLL()
    {
        while(head!=nullptr)
        {
            deleteHead();
        }
    }
    void display()
    {
        Node*p=head;

        while(p!=nullptr)
        {
            std::cout<<p->data<<" ";
            p=p->next;
        }

        std::cout <<"NULL\n";
    }

    int count()
    {
        return length;
    }

    int sum()
    {
        long long total=0;
        Node*p=head;

        while(p!=nullptr)
        {
            total+=p->data;
            p=p->next;
        }

        return total;
    }

    int max()
    {
        if (head==nullptr)
        {
            std::cout<<"NULL\n";
            return -1;
        }

        int maximum=head->data;
        Node*p=head->next;

        while(p!=nullptr)
        {
            if (p->data>maximum)
            {
                maximum=p->data;

            }
            p = p->next;
        }

        return maximum;
    }
    int min()
    {
        if (head==nullptr)
        {
            std::cout<<"NULL\n";
            return -1;
        }

        int minimum=head->data;
        Node*p=head->next;

        while(p!=nullptr)
        {
            if(p->data<minimum)
            {
                minimum = p->data;
            }
            p=p->next;
        }

        return minimum;
    }
    void insertHead(int value)
    {
        Node*n=new Node(value);

        n->next=head;

        if (head!=nullptr)
        {
            head->prev=n;
        }   
        else
        {
            tail=n;
        }
        head=n;
        length++;
    }

    void insertEnd(int value)
    {
        Node*n=new Node(value);

        n->prev=tail;

        if (tail!=nullptr)
        {
            tail->next=n;
        }  
        else
        {
            head=n;
        }
        tail=n;
        length++;
    }

    bool insertPos(int pos,int value)
    {
        if(pos<1 || pos>length+1)
        {
            return false;
        }
        if(pos==1)
        {
            insertHead(value);
            return true;
        }

        if(pos==length+1)
        {
            insertEnd(value);
            return true;
        }

        Node*p=head;

        for(int i=1;i<pos;i++)
        {
            p=p->next;
        }
    
        Node*n=new Node(value);

        n->next=p;
        n->prev=p->prev;

        p->prev->next=n;
        p->prev=n;

        length++;
        return true;
    }

    bool deleteHead()
    {
        if(head==nullptr)
        {
            return false;
        }
        Node*temp=head;
        head=head->next;

        if(head!=nullptr)
        {
            head->prev=nullptr;
        }   
        else
        {
            tail=nullptr;
        }
            

        delete temp;
        length--;
        return true;
    }
    bool deleteEnd()
    {
        if(tail==nullptr)
        {
            return false;
        }

        Node*temp=tail;
        tail=tail->prev;

        if(tail!=nullptr)
        {
            tail->next = nullptr;
        }   
        else
        {
            head=nullptr;
        }
        delete temp;
        length--;
        return true;
    }

    bool deletePos(int pos)
    {
        if(pos < 1 || pos > length)
        {
            return false;
        }
        if(pos==1)
        {
            return deleteHead();
        }
        if(pos == length)
        {
            return deleteEnd();
        }
            
        Node*p=head;

        for(int i=1;i<pos;i++)
        {
            p = p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;

        delete p;
        length--;
        return true;
    }
};

int main()
{
    DLL list;

    list.insertHead(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertPos(2, 15);

    list.display();

    std::cout<<"Count: "<<list.count()<<std::endl;
    std::cout<<"Sum:"<<list.sum()<<std::endl;
    std::cout<<"Max:"<<list.max()<<std::endl;
    std::cout<<"Min:"<<list.min()<<std::endl;

    list.deleteHead();
    list.deleteEnd();
    list.deletePos(1);

    list.display();

    return 0;
}
