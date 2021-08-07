#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

int counter=0;
int index=0;
 string save;

class node{
public:
    string name;
    string phone;
    node*next;

    node(){
        name="";
        phone="";
        next=NULL;
    }
    node (string name,string phone){
        this->name=name;
        this->phone=phone;
        this->next=NULL;
    }

};



class linkedlist{
    public:
    node*head;

    linkedlist(){
    head=NULL;
    }
    bool isEmpty(){
        if (head==NULL){
            return true;

        }
        else {
            return false;
        }
    }
     void addfirst( string name,string phone){
        node*n=new node(name,phone);
        if(isEmpty()==true){
           head=n;
        }
        else{
            n->next=head;
            head=n;
        }
    }
    void addlast(string name,string phone){
        node*n=new node(name,phone);
        if(isEmpty()==true){
            addfirst(name,phone);
        }
        else{
            node*c=head;
            while(c->next!=NULL){
                c=c->next;
            }
            c->next=n;
        }
    }
    bool checkall(string name,string phone){
        if(isEmpty()==false){

            node*c=head;
            while(c!=NULL){
                if(c->name==name||c->phone==phone){
                    return true;
                }
                c=c->next;

            }
        }
        else{
        return false;
        }

    }

       void editname(string name,string newname){

            node*c=head;
            while(c!=NULL){
                if(c->name==name){
                  c->name=newname;
                }
                c=c->next;
            }
        }

          void editphone(string phone,string newphone){

            node*c=head;
            while(c!=NULL){
                if(c->phone==phone){
                  c->phone=newphone;
                }
                c=c->next;
            }
        }

          bool checkphone(string phone){
        if(isEmpty()==false){
            node*c=head;
            while(c!=NULL){
                if(c->phone==phone){
                     save= c->phone;
                    return true;
                }
                c=c->next;
            }
        }
        else{
            return false;
        }
    }





    bool checkname(string name){
        if(isEmpty()==false){
            node*c=head;
            while(c!=NULL){
                if(c->name==name){
                     save= c->phone;
                    return true;
                }
                c=c->next;
            }
        }
        else{
            return false;
        }
    }
    void deletecontact(string name){
        node*temp=head;
        if(temp->name==name){

            head=head->next;
            delete temp;
        }
        else{
            node*c=head;
            while(c->next!=NULL){
                if(c->next->name==name){
                    temp=c->next;
                    c->next=c->next->next;
                    delete temp;
                }
                else{
                    c=c->next;
                }
            }
        }
    }


   void print(){
       counter=0;
       node*temp=head;
       while(temp!=NULL){
           counter++;



        cout<< counter<<")"<<"Name : "<<temp->name<<endl;
        cout<<"  "<<"Phone : "<<temp->phone<<endl;
        cout<<"--------------"<<endl;


        temp=temp->next;

       }
   }







};
int main(){
    linkedlist x;

    int choose;
    string name,phone,newname,newphone;
  while (true){
        cout<<"1) Add New Contact  "<<endl;
        cout<<"2) Edit a Contact "<<endl;
        cout<<"3) Remove a Contact "<<endl;
        cout<<"4) View All "<<endl;
        cout<<"5) Search By Name "<<endl;
        cout<<"6) Exit"<<endl;
        cin>>choose;

        if (choose==1){
            cout<<"Enter The Contact Name : ";
            cin>>name;
            cout<<"Enter The Contact Phone : ";
            cin>>phone;
               if(x.checkall(name,phone)==true){
                cout<<"Sry Name Or Phone Already EXIST !"<<endl;
                cout<<"------------------"<<endl;
            }
            else{

            x.addlast(name,phone);
            index++;

            cout<<" Contact Has Been Added Successfuly!"<<endl;
            cout<<"------------------"<<endl;
        }
    }

    else if (choose==2){
            cout<<"Enter The Name Of The Contact You Want To Edit : "<<endl;
            cin>>name;
            if(x.checkname(name)==true){
                cout<<"Contact Name : "<<name<<endl;
                cout<<"Contact Phone : "<<save<<endl;
                cout<<"-------------"<<endl;
                cout<<"1) To Edit The Name : "<<endl;
                cout<<"2) to Edit The Phone : "<<endl;
                cin>>choose;
                if(choose==1){
                    cout<<"Enter The New Name : "<<endl;
                    cin>>newname;
                    if(x.checkname(newname)==false){
                       x.editname(name,newname);
                       cout<<"Name Has Been Changed Successfuly !"<<endl;
                       cout<<"------------"<<endl;
                    }
                    else{
                        cout<<"Name Already EXIST !"<<endl;
                        cout<<"-----------"<<endl;
                    }
                }
                else if (choose==2){

                        cout<<"Enter The New Phone : "<<endl;
                        cin>>newphone;
                        if(x.checkphone(newphone)==false){
                            x.editphone(phone,newphone);
                            cout<<"Phone Has Been Changed Successfuly !"<<endl;
                            cout<<"--------------"<<endl;
                        }
                        else{
                            cout<<"Phone Already EXIST !"<<endl;
                            cout<<"-------------"<<endl;
                        }

                }
                else{
                    cout<<"Wrong Input"<<endl;
                    cout<<"--------------"<<endl;
                }
            }
            else{
                cout<<"Contact Doesn't EXIST !!"<<endl;
                cout<<"-------------------"<<endl;
            }

    }
    else if(choose==3){
            cout<<"Enter The Name Of The Contact You Want To Delete : "<<endl;
            cin>>name;
            if(x.checkname(name)==true){
                x.deletecontact(name);
               cout<<"Contact Removed Successfully!"<<endl;
               cout<<"----------------"<<endl;

            }
            else{
                cout<<"Contact Doesn't EXIST !"<<endl;
                cout<<"-------------------"<<endl;
            }

    }

    else if(choose==4){
        x.print();
    }
    else if (choose==5){
            cout<<"Enter The Name Of The Contact You Want To Search For : "<<endl;
             cin>>name;
             if(x.checkname(name)==true){
                    cout<<"Contact Found !"<<endl;
                    cout<<"--------------"<<endl;
                    cout<<"Contact Name : "<<name<<endl;
                    cout<<"Contact Phone : "<<save<<endl;
                    cout<<"--------------"<<endl;

             }
             else{
                cout<<"Name Doesn't EXIST !"<<endl;
                cout<<"-----------"<<endl;
             }

    }
    else if(choose==6){
        break;
    }




  }


}





