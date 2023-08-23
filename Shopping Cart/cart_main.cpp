#include<iostream>
#include<vector>
#include "datamodel.h"

Product* chooseProduct(){
    vector<Product> allProducts = {
        Product(1,"Apple",40),
        Product(2,"Banana",50),
        Product(3,"Guava",40),
        Product(4,"Mango",20),
        Product(5,"StrAwberry",70),
        Product(6,"Pineapple",35)
    };

    cout<<"Available Products"<<endl;
    for(int i=0;i<allProducts.size();i++){
        cout<<allProducts[i].getDisplayName()<<endl;
    }
    cout<<"-----------------------"<<endl;
    string choice;
    cin>>choice;

    for(int i=0;i<allProducts.size();i++){
        if(choice == allProducts[i].getSortName()){
            return &allProducts[i];
        }
    }
    cout<<"Product not found!"<<endl;
    return NULL;
}

bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    int total = cart.getTotal();
    cout<<"--------------------"<<endl;
    cout<<"Total amount: "<<total<<endl;

    cout<<"Pay in Cash"<<endl;

    int paid;
    cout<<"Enter the amount : "<<endl;
    cin>>paid;

    if(paid>=total){
        cout<<"Change : "<<paid-total<<endl;
        cout<<"Thank you for shopping!"<<endl;
        return true;
    } 
    else{
        cout<<"Not enough cash!"<<endl;
        return false;
    }
}

int main(){
    char action;
    Cart cart;
    
    while(true){
        cout<<"Choose an action -  (a)dd item, (v)iew cart, (c)heckout"<<endl;
        cin>>action;

        if(action == 'a'){
            //add item to cart
            //view product + choose a product + add to the cart
            Product* product = chooseProduct();
            if(product!=NULL){
                cout<<"Added to cart :"<<product->getDisplayName()<<endl;
            }
            //to do
            cart.addProduct(*product);
        }
        else if(action == 'v'){
            //view the cart
            cout<<"-------------------"<<endl;
            cout<<cart.viewCart()<<endl;
            cout<<"--------------------"<<endl;
        }
        else{
            //checkout cart
            cout<<cart.viewCart()<<endl;
            if(checkout(cart)){
                break;
            }
        }
    }

    return 0;
}